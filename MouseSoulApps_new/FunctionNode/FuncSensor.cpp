/**
* @file FuncSensor.cpp
* @brief センサー値読み取り、配信制御
* @details 1) 一定間隔でセンサー値を読み取る。
* @details 2) 読み取った値をイベントコンテナに設定して配信する。
* @details 3) センサー値読み取りは外部からON/OFFできる。
* @note
* @todo
*/

#include "stdafx.h"

#include <iostream>
#include <thread>
#include <cstring>

#include "FunctionNode.h"
#include "FuncSensor.h"

#include "EventContainer.h"

#include "EventRouterBase.h"
#include "EventRouter.h"
#include "EventCtrlSensorSwitch.h"
#include "EventInfoSensorValue.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* @fn FuncSensor::FuncSensor()
* @brief コンストラクタ
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
FuncSensor::FuncSensor()
{
	m_intervalValue = 100;	// センサー読み取り間隔

	m_sensorState = false;	// 計測停止

	m_threadState = true;	// スレッド開始
	m_thread = std::thread(&FuncSensor::measureSensor, this);
}

/**
* @fn FuncSensor::~FuncSensor()
* @brief デストラクタ
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
FuncSensor::~FuncSensor()
{
}

// イベントルータークラス登録
void FuncSensor::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncSensor::startMeasureSensor()
{
}

void FuncSensor::stopMeasureSensor()
{
	if (m_threadState)
	{
		m_threadState = false;	// スレッド停止

		m_thread.join();
	}
}

void FuncSensor::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncSensor::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;

	// センサースイッチ制御イベントの場合
	if (EventContainer::EVENT_CTRL_SENSOR_SWITCH == pEc->getEventType()) {
		// センサー計測開始／停止スイッチ切り替え
		bool switchValue = pEc->toBool();

		std::lock_guard<std::mutex> uniq_lk(mtx);
		m_sensorState = switchValue;
		cv.notify_all();

		std::cout << "FuncSensor::eventHandler" << "[" << m_sensorState << "]" << std::endl;
	}else
	// センサー読み取り間隔設定イベントの場合
	if (EventContainer::EVENT_CTRL_SENSOR_INTERVAL == pEc->getEventType()) {
		// センサー計測開始／停止スイッチ切り替え
		m_intervalValue  = pEc->toInt();
		std::cout << "FuncSensor::eventHandler() : IntervalValue" << "[" << m_intervalValue << "]" << std::endl;
	}
}

/**
* @fn void CollSensor::measureSensor()
* @brief センサー値読み取り
* @param[in]
* @param[out]
* @return
* @sa
* @details センサードライバは都度クローズしなければ次の読み取りができない。
* @details
*/
void FuncSensor::measureSensor()
{
#ifdef _FOR_LINUX_DRIVER
	char buf[50];
	int sensor;
#endif
	int data[4];

	while (1)
	{
		// wait
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		std::this_thread::sleep_for(std::chrono::milliseconds(m_intervalValue));

		// センサースイッチがFLASEの場合はセンサー読み取り停止
		if(false == m_sensorState) {
//			continue;
			std::cout << "FuncSensor::measureSensor()" << "[SENSOR OFF]" << std::endl;
			// センサースイッチがONになるまでスレッド停止
			std::unique_lock<std::mutex> uniq_lk(mtx);
			cv.wait(uniq_lk, [this] { return m_sensorState; }); 
			std::cout << "FuncSensor::measureSensor()" << "[SENSOR ON]" << std::endl;
		}

		if (false == m_threadState)
		{
			break;
		}

#ifdef _FOR_LINUX_DRIVER
		// ドライバを開く
		sensor = open("/dev/rtlightsensor0", O_RDONLY);

		// 計測値の読み取る。
		std::memset(buf, 0, sizeof(buf));
		read(sensor, buf, 20);

		std::cout << "Sensor data =" << buf << std::endl;

		// データを配信用に加工する。
		sscanf(buf, "%d %d %d %d", data, data + 1, data + 2, data + 3);

		// ドライバを閉じる（都度閉じないと次が読み取れない）
		close(sensor);
#else
		// ダミーデータ設定
		data[0]=10;
		data[1]=20;
		data[2]=30;
		data[3]=40;
#endif

		// センサー読み取り値を配信
		EventInfoSensorValue ev;
		// 左、左中央、右中央、右 センサー順に設定する。
		ev.setSensorValue(data[3], data[2], data[1], data[0]);
		std::cout << "FuncSensor event throw!!" << std::endl;
		eventThrow(&ev);

	}
}

///// テスト ////
void FuncSensor::sendEvent()
{
	EventInfoSensorValue ev;
	ev.setSensorValue(10, 20, 30, 40);

	m_pEventRouter->eventThrow(&ev);
}
