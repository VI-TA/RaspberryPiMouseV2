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
	// コンストラクタ
	CollSensor();

	// イベント処理
	void eventHandler(EventContainer *pEc);

	// [DEBUG]
	void test1();

	// [DEBUG]
	void test2();
private:
	// センサー値取得
	void measureSensor();
};

#endif	// _COLLSENSOR_H
