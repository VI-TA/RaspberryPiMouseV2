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

	// vectorにも設定する。
	std::vector<int> tmpSensor = {m_left, m_leftCenter, m_rightCenter, m_right};;
	setData(tmpSensor);
}

void EventInfoSensorValue::getSensorValue(int &left, int &leftCenter, int &rightCenter, int &right)
{
	left = m_left;
	leftCenter = m_leftCenter;
	rightCenter = m_rightCenter;
	right = m_right;
}

// シリアライズデータ設定
bool EventInfoSensorValue::setSerializeString(std::string serializeString)
{
	return true;
}

// シリアライズ文字列取得
std::string EventInfoSensorValue::toSerializeString() const
{
	std::string	tmpStr;

	tmpStr = "EVENT_INFO_SENSOR_VALUE,";
	tmpStr += std::to_string(m_left);
	tmpStr += ",";
	tmpStr += std::to_string(m_leftCenter);
	tmpStr += ",";
	tmpStr += std::to_string(m_rightCenter);
	tmpStr += ",";
	tmpStr += std::to_string(m_right);

	return tmpStr;
}
