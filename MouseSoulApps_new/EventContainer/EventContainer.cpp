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


bool EventContainer::toBool() const
{
	return m_bool;
}

int EventContainer::toInt() const
{
	return m_int;
}

unsigned long EventContainer::toULong() const
{
	return m_uLong;
}

float EventContainer::toFloat() const
{
	return m_float;
}

std::vector<int> EventContainer::toIntArray() const
{
	return m_intArray;
}

std::vector<unsigned long> EventContainer::toULongArray() const
{
	return m_uLontArray;
}

std::vector<float> EventContainer::toFloatArray() const
{
	return m_floatArray;
}

std::string EventContainer::toString() const
{
	return m_string;
}

std::string EventContainer::toSerializeString() const
{
	return m_serializeStr;
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
