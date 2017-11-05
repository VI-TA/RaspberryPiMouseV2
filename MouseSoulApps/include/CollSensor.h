#pragma once
#ifndef _COLLSENSOR_H
#define _COLLSENSOR_H

/**
* @file CollSensor.h
* @brief 距離センサー計測制御
* @details 距離センサー計測制御
*/

class Mediator;
class Colleague;
class EventContainer;

class CollSensor : public Colleague
{
public:
	//! コンストラクタ
	CollSensor();

	//! センサー計測開始
	void startMeasureSensor();

	//! センサー計測停止
	void stopMeasureSensor();

	//! イベント処理
	void eventHandler(EventContainer *pEc);

	//! [DEBUG]
	void test1();

	//! [DEBUG]
	void test2();

private:
	// センサー値取得
	void measureSensor();

private:
	//! スレッドインスタンス
	std::thread m_thread;

	//! センサー計測状態
	bool m_sensorState;

};

#endif	// _COLLSENSOR_H
