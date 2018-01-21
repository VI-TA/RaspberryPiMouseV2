/**
* @file EventContainer.cpp
* @brief 
* @details 
*/

#include "stdafx.h"

#include "EventContainer.h"

// コンストラクタ
EventContainer::EventContainer()
{
	// 空データ
}

EventContainer::EventContainer(bool data)
{
	setData(data);
}

EventContainer::EventContainer(int data)
{
	setData(data);
}

EventContainer::EventContainer(unsigned long data)
{
	setData(data);
}

EventContainer::EventContainer(float data)
{
	setData(data);
}

EventContainer::EventContainer(std::vector<int> data)
{
	setData(data);
}

EventContainer::EventContainer(std::vector<unsigned long> data)
{
	setData(data);
}

EventContainer::EventContainer(std::vector<float> data)
{
	setData(data);
}

EventContainer::EventContainer(std::string data)
{
	setData(data);
}

// デストラクタ
EventContainer::~EventContainer()
{
}

// イベントタイプ取得
EventContainer::EVENT_TYPE EventContainer::getEventType(void) const
{
	return m_type;
}


bool EventContainer::toBool()
{
	return m_bool;
}

int EventContainer::toInt()
{
	return m_int;
}

unsigned long EventContainer::toULong()
{
	return m_uLong;
}

float EventContainer::toFloat()
{
	return m_float;
}

std::vector<int> EventContainer::toIntArray()
{
	return m_intArray;
}

std::vector<unsigned long> EventContainer::toULongArray()
{
	return m_uLontArray;
}

std::vector<float> EventContainer::toFloatArray()
{
	return m_floatArray;
}

std::string EventContainer::toString()
{
	return m_string;
}

// ////////////////////////////////////////////////////////////////////////////////
// 情報
// ////////////////////////////////////////////////////////////////////////////////

void EventContainer::printEventName(EVENT_TYPE type) const
{
	switch(type) {
        case EVENT_INFO_SENSOR_VALUE:
//		std::cout << "EVENT_SENSOR_VALUE:" << endl;
		break;
        case EVENT_CTRL_MOTER_CONTROL:
//		cout << "EVENT_MOTER_CONTROL:" << endl;
		break;
        case EVENT_CTRL_MOTER_SWITCH:
//		cout << "EVENT_LED_CONTROL:" << endl;
		break;
        case EVENT_CTRL_LED_CONTROL:
//		cout << "EVENT_SOUND_CONTROL:" << endl;
		break;
        case EVENT_CTRL_SOUND_CONTROL:
//		cout << "EVENT_REMOTE_CONTROL:" << endl;
		break;
        case EVENT_CTRL_EXCOM_CONTROL:
//		cout << "EVENT_AUTO_CONTROL:" << endl;
		break;
	}
}

// ////////////////////////////////////////////////////////////////////////////////
// Private:
// ////////////////////////////////////////////////////////////////////////////////

void EventContainer::setData(bool data)
{
	m_bool = data;
}

void EventContainer::setData(int data)
{
	m_int = data;
}

void EventContainer::setData(unsigned long data)
{
	m_uLong = data;
}

void EventContainer::setData(float data)
{
	m_float = data;
}

void EventContainer::setData(std::vector<int> data)
{
	m_intArray = data;
}

void EventContainer::setData(std::vector<unsigned long> data)
{
	m_uLontArray = data;
}

void EventContainer::setData(std::vector<float> data)
{
	m_floatArray = data;
}

void EventContainer::setData(std::string data)
{
	m_string = data;
}

// ////////////////////////////////////////////////////////////////////////////////
// Protected:
// ////////////////////////////////////////////////////////////////////////////////

void EventContainer::setEventType(EVENT_TYPE type)
{
	m_type = type;
}
