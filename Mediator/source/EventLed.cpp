/**
* @file EventLed.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include "EventContainer.h"
#include "EventLed.h"

// コンストラクタ
EventLed::EventLed()
{
}

void EventLed::setLed(int state)
{
	m_state = state;
}

int EventLed::getLed(void)
{
	return m_state;
}
