/**
* @file CollSensor.cpp
* @brief 距離センサー計測制御
* @details 距離センサー計測制御
*/

#include <stdio.h>
//#include <pthread.h>
#include <thread>		// std::thread
#include <cstring>		// std::thread
#include "Mediator.h"
#include "Colleague.h"
#include "CollSensor.h"
#include "EventContainer.h"
#include "EventSensor.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

CollSensor::CollSensor()
{
}

void CollSensor::startMeasureSensor()
{
	m_sensorState = false;

	// センサー計測スレッド起動
	m_thread = std::thread(&CollSensor::measureSensor, this);
}

void CollSensor::stopMeasureSensor()
{
	if(!m_sensorState)
	{
		// スレッド停止フラグON
		m_sensorState = true;

		// スレッド停止待ち
		m_thread.join();
	}
}

void CollSensor::eventHandler(EventContainer *pEc)
{
	int left, leftCenter, rightCenter, right;
	EventSensor *pEs;

	pEc->printEventName(pEc->getEventType());

	// センサー測定値イベントの場合は値を表示
	if(pEc->getEventType() == EVENT_SENSOR_VALUE) {
		pEs = dynamic_cast<EventSensor*>(pEc);
		if(pEs == NULL) {
			printf("ERROR dynamic_cast¥n");
		}
		pEs->getSensorValue(left, leftCenter, rightCenter, right);
		printf("CollSensor::eventHandler Value[%d][%d][%d][%d]\n",
			left, leftCenter, rightCenter, right
		);
	} else {
		printf("CollSensor::eventHandler\n");
	}
}

/**
* @fn void CollSensor::measureSensor()
* @brief 距離センサー計測
* @param[in] なし
* @param[out] なし
* @return なし
* @sa
* @details 一定時間間隔でセンサー値を読み取りイベントルーターに通知する。
* @details なお、本関数はサブスレッド上で動作させる。
*/
void CollSensor::measureSensor()
{
	char buf[50];
	int sensor;
	int data[4];

	while(1)
	{
		if(true == m_sensorState)
		{
			// スレッド停止シグナル受信
			// スレッドループから抜ける。
			break;
		}


		// センサーオープン
		sensor = open("/dev/rtlightsensor0", O_RDONLY);

		std::memset(buf, 0, sizeof(buf));
		read(sensor, buf, 20);
		sscanf(buf, "%d %d %d %d", data, data+1, data+2, data+3);
		std::memset(buf, 0, sizeof(buf));
		sprintf(buf, "%4d %4d %4d %4d", data[3], data[2], data[1], data[0]);

		// T.B.D:イベントルーターに通知。

		// センサークローズ
		// NOTE: 都度クローズしない場合、次の読み取りが不可である。
		close(sensor);

		// 1秒間スリープ
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void CollSensor::test1()
{
	printf("test1\n");
	// [DEBUG] モータイベントをリスナーに登録する。
	Colleague::pMediator->addEventListener(EVENT_MOTER_CONTROL, this);
}

void CollSensor::test2()
{
	EventSensor     eventSensor;

	printf("test2\n");

	eventSensor.setEventType(EVENT_SENSOR_VALUE);
	// [DEBUG] モータイベントをリスナーに登録する。
	pMediator->eventThrow(&eventSensor);
}
