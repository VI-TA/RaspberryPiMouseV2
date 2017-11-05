#pragma once
#ifndef _EVENTSENSOR_H
#define _EVENTSENSOR_H

/**
* @file EventSensor.h
* @brief 距離センサーイベント
* @details 距離センサーイベント
*/

#include "EventType.h"

class EventContainer;

class EventSensor : public EventContainer
{
public:
	// コンストラクタ
	EventSensor(EVENT_TYPE eventType);

	// センサー測定値設定
	void setSensorValue(int left, int leftCenter, int rightCenter, int right);

	// センサー測定値取得
	void getSensorValue(int &left, int &leftCenter, int &rightCenter, int &right);
private:
	// センサー測定値(左センサー）
	int m_left;

	// センサー測定値(中央左センサー）
	int m_leftCenter;

	// センサー測定値(中央右センサー）
	int m_rightCenter;

	// センサー測定値(右センサー）
	int m_right;
};

#endif	// _EVENTSENSOR_H
