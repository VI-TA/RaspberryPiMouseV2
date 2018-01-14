/**
* @file EventInfoSensorValue.cpp
* @brief センサー値配信イベント
* @details センサー値配信イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventInfoSensorValue.h"

// コンストラクタ
EventInfoSensorValue::EventInfoSensorValue()
{
	setEventType(EVENT_INFO_SENSOR_VALUE);
}

// デストラクタ
EventInfoSensorValue::~EventInfoSensorValue()
{
}

void EventInfoSensorValue::setSensorValue(int left, int leftCenter, int rightCenter, int right)
{
	m_left = left;
	m_leftCenter = leftCenter;
	m_rightCenter = rightCenter;
	m_right = right;
}

void EventInfoSensorValue::getSensorValue(int &left, int &leftCenter, int &rightCenter, int &right)
{
	left = m_left;
	leftCenter = m_leftCenter;
	rightCenter = m_rightCenter;
	right = m_right;
}


