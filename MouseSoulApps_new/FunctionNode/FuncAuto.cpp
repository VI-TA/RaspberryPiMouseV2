/**
* @file FuncAuto.cpp
* @brief 自走制御機能
* @details 
* @note
* @todo
*/

#include "stdafx.h"

#include <thread>
#include <mutex>
#include <condition_variable>

#include <iostream>

#include "FunctionNode.h"
#include "FuncAuto.h"

#include "EventRouterBase.h"
#include "EventContainer.h"
#include "EventCtrlAutoSwitch.h"
#include "EventCtrlAutoControl.h"
#include "EventCtrlMotorControl.h"

/**
* @fn FuncAuto::FuncAuto()
* @brief コンストラクタ
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
FuncAuto::FuncAuto()
{
	m_eventTrigger = false;
	m_autoMode = false;

	// モーター制御スレッド起動
	m_thread = std::thread(&FuncAuto::autoThread, this);
}

/**
* @fn FuncAuto::~FuncAuto()
* @brief デストラクタ
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
FuncAuto::~FuncAuto()
{
}

/**
* @fn FuncAuto::setEventRouter()
* @brief イベントルータークラス登録
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
void FuncAuto::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

/**
* @fn FuncAuto::eventHandler()
* @brief イベントハンドラ
* @param[in] *pEc イベントコンテナ
* @param[out]
* @return
* @sa
* @details 
*/
void FuncAuto::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncAuto::eventHandler() : IN" << std::endl;

	// 自走モード切替イベント
	if (EventContainer::EVENT_CTRL_AUTO_SWITCH == pEc->getEventType()) {
		std::cout << "FuncAuto::eventHandler auto switch" << "[" << pEc->getEventType() << "]" << std::endl;

		// 自走モード切り替え
		if(pEc->toBool()) {
			// モードOFF -> ONはモードの切り替えのみ。
			// スレッドの動作はセンサー読み取りイベントにて行う。
			m_autoMode = true;
		}else{
			m_autoMode = false;

			// モードON -> OFFで１度のみスレッドを動作させる。
			std::lock_guard<std::mutex> uniq_lk(mtx);
			m_eventTrigger = true;
			cv.notify_all();
		}

//		std::lock_guard<std::mutex> uniq_lk(mtx);
//		m_eventTrigger = true;
//		cv.notify_all();
	}
	else
	// センサー読み取り値
	if (EventContainer::EVENT_INFO_SENSOR_VALUE == pEc->getEventType() && true == m_autoMode) {
		std::cout << "FuncAuto::eventHandler sensor value" << "[" << pEc->getEventType() << "]" << std::endl;

		// センサ―読み取り値を取得
		m_sensorValue = pEc->toIntArray();	

		std::lock_guard<std::mutex> uniq_lk(mtx);
		m_eventTrigger = true;
		cv.notify_all();
	}

	std::cout << "FuncAuto::eventHandler() : OUT" << std::endl;
}

/**
* @fn FuncAuto::autoThread()
* @brief 自走モードスレッド
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
void FuncAuto::autoThread()
{
	std::vector<int> sensorValue;
	bool avoidanceMode = false;	// 回避運動モード

	std::cout << "FuncAuto::autoThread() start" << std::endl;

	while(1) {

	// ----- イベントトリガあるまで停止 -----
	std::unique_lock<std::mutex> uniq_lk(mtx);
	cv.wait(uniq_lk, [this] { return m_eventTrigger; });
	m_eventTrigger = false;
	// -----

	if(!m_autoMode) {
		// 自動モードOFFの場合
		std::cout << "FuncAuto::autoThread() Auto Mode OFF!! [" << std::endl;

		EventCtrlMotorControl ev;
		ev.setMotorCommand(EventCtrlMotorControl::CTRL_STOP);	// 停止
		std::cout << "FuncAuto::autoThread motor control STOP event throw!!" << std::endl;
		eventThrow(&ev);

		continue;
	}

	// センサー値を取得
	sensorValue = m_sensorValue;

	// ========== 進路決定ロジック ==========

	// ========================================
	// 壁を検知して自身をターンさせる。
	// 一度ターン開始したら、進路クリアするまでターン方向を変えない。(avoidanceModeを参照)

	if(false == avoidanceMode && (300 < sensorValue[0] || 300 < sensorValue[1] || 300 < sensorValue[2] || 300 < sensorValue[3]) ) {
		std::cout << "FuncAuto::autoThread() WALL!! [" << sensorValue[0] << "," << sensorValue[3] << "]" << std::endl;

		EventCtrlMotorControl ev;
		if(sensorValue[0]+sensorValue[1] > sensorValue[2]+sensorValue[3]) {
			// 比較的、右側に空きがある。
			ev.setMotorCommand(EventCtrlMotorControl::CTRL_RIGHT_TRUN);	// 右回り
			std::cout << "FuncAuto::autoThread motor control RIGHT_TRUN event throw!!" << std::endl;
		}else{
			// 比較的、左側に空きがある。
			ev.setMotorCommand(EventCtrlMotorControl::CTRL_LEFT_TRUN);	// 右回り
			std::cout << "FuncAuto::autoThread motor control LEFT_TRUN  event throw!!" << std::endl;
		}	
		eventThrow(&ev);
		avoidanceMode = true;		// 回避運動モード設定
	}	

	// ========================================
	// 全センサーが障害物を遠い＝進めるであるか検出する。
	if(300 >= sensorValue[0] && 300 >= sensorValue[1] && 300 >= sensorValue[2] && 300 >= sensorValue[3] ) {
		std::cout << "FuncAuto::autoThread() CLEAR! [" << sensorValue[0] << "," << sensorValue[3] << "]" << std::endl;

		EventCtrlMotorControl ev;
		ev.setMotorCommand(EventCtrlMotorControl::CTRL_FORWARD);	// 	前進
		std::cout << "FuncAuto::autoThread motor control FORARD event throw!!" << std::endl;
		eventThrow(&ev);
		avoidanceMode = false;		// 回避運動モード解除
	}	

	}
}

