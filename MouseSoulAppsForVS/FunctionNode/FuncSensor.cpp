/**
* @file FuncSensor.cpp
* @brief センサー値読み取り、配信制御
* @details 1) 一定間隔でセンサー値を読み取る。
* @details 2) 読み取った値をイベントコンテナに設定して配信する。
* @details 3) センサー値読み取りは外部からON/OFFできる。
* @note
* @todo センサー値は丸める。
* @todo 前回値と同じなら配信しない。
*/

//#include <stdio.h>
//#include <pthread.h>
//#include <cstring>		// std::thread

#include "stdafx.h"

#include <iostream>
#include <thread>

#include "FunctionNode.h"
#include "FuncSensor.h"

#include "EventContainer.h"

#include "EventRouterBase.h"
#include "EventRouter.h"
#include "EventCtrlSensorSwitch.h"
#include "EventInfoSensorValue.h"

//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>

// コンストラクタ
FuncSensor::FuncSensor()
{
	m_threadState = false;	// スレッド停止
	m_sensorState = false;	// 計測停止
}

// デストラクタ
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
	m_threadState = true;	// スレッド開始
	m_thread = std::thread(&FuncSensor::measureSensor, this);
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
	if (EventContainer::EVENT_CTRL_SENSOR_SWITCH == pEc->getEventType()) {
		// センサー計測開始／停止スイッチ切り替え
		if (m_sensorState) {
			m_sensorState = false;
		} else {
			m_sensorState = true;
		}
	}
	
#if 0
	int left, leftCenter, rightCenter, right;
	EventSensor *pEs;

	pEc->printEventName(pEc->getEventType());

	if (pEc->getEventType() == EVENT_SENSOR_VALUE) {
		pEs = dynamic_cast<EventSensor*>(pEc);
		if (pEs == nullptr) {
//			printf("ERROR dynamic_cast");
		}
		pEs->getSensorValue(left, leftCenter, rightCenter, right);
//		printf("CollSensor::eventHandler Value[%d][%d][%d][%d]",
//			left, leftCenter, rightCenter, right
//		);
	}
	else {
//		printf("CollSensor::eventHandler");
	}
#endif
}

/**
* @fn void CollSensor::measureSensor()
* @brief
* @param[in]
* @param[out]
* @return
* @sa
* @details
* @details
*/
void FuncSensor::measureSensor()
{
	char buf[50];
	int sensor;
	int data[4];

	while (1)
	{
		if (false == m_threadState)
		{
			break;
		}

#if _FOR_LINUX_DRIVER
		sensor = open("/dev/rtlightsensor0", O_RDONLY);

		std::memset(buf, 0, sizeof(buf));
		read(sensor, buf, 20);
		sscanf(buf, "%d %d %d %d", data, data + 1, data + 2, data + 3);
		std::memset(buf, 0, sizeof(buf));
		sprintf(buf, "%4d %4d %4d %4d", data[3], data[2], data[1], data[0]);

		close(sensor);
#endif

		EventInfoSensorValue ev;
		ev.setSensorValue(10, 20, 30, 40);
		std::cout << "FuncSensor event throw!!" << std::endl;
		eventThrow(&ev);

		std::this_thread::sleep_for(std::chrono::seconds(1));
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}






///// テスト ////
void FuncSensor::sendEvent()
{
	EventInfoSensorValue ev;
	ev.setSensorValue(10, 20, 30, 40);

	m_pEventRouter->eventThrow(&ev);
}