/**
* @file EventSensor.cpp
* @brief 距離センサーイベント
* @details 距離センサーイベント
*/

#include "EventContainer.h"
#include "EventSensor.h"

// コンストラクタ
EventSensor::EventSensor()
{
}

void EventSensor::setSensorValue(int left, int leftCenter, int rightCenter, int right)
{
	m_left = left;
	m_leftCenter = leftCenter;
	m_rightCenter = rightCenter;
	m_right = right;
}

void EventSensor::getSensorValue(int &left, int &leftCenter, int &rightCenter, int &right)
{
	left = m_left;
	leftCenter = m_leftCenter;
	rightCenter = m_rightCenter;
	right = m_right;
}


