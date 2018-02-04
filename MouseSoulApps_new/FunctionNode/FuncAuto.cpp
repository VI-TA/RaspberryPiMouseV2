/**
* @file FuncAuto.cpp
* @brief 自走制御機能
* @details 自走制御機能
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

// コンストラクタ
FuncAuto::FuncAuto()
{
	m_autoMode = false;

	// モーター制御スレッド起動
	m_thread = std::thread(&FuncAuto::autoThread, this);
}

// デストラクタ
FuncAuto::~FuncAuto()
{
}

// イベントルータークラス登録
void FuncAuto::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncAuto::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncAuto::eventHandler() : IN" << std::endl;

	if (EventContainer::EVENT_CTRL_AUTO_SWITCH == pEc->getEventType()) {
		std::cout << "FuncAuto::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;

		// 自走モード切り替え
		if(pEc->toBool()) {
			m_autoMode = true;
		}else{
			m_autoMode = false;
		}

		std::lock_guard<std::mutex> uniq_lk(mtx);
		cv.notify_all();
	}

	std::cout << "FuncAuto::eventHandler() : OUT" << std::endl;
}

// 自走モードスレッド
void FuncAuto::autoThread()
{
	std::cout << "FuncMotor::motorControlThread()" << std::endl;

	while(1) {

	// ----- イベントトリガあるまで停止 -----
	std::unique_lock<std::mutex> uniq_lk(mtx);
	cv.wait(uniq_lk, [this] { return m_autoMode; });
	// -----


	// 自走モード
	// 自走モードは、センサー値を元に、モーター制御イベントを発信する。


	std::cout << "FuncAuto::autoThread()" << std::endl;

	}
}

