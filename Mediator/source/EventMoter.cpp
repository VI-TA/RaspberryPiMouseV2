/**
* @file EventMoter.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include "EventContainer.h"
#include "EventMoter.h"

// コンストラクタ
EventMoter::EventMoter()
{
}

void EventMoter::setMoterCommand(int command)
{
	m_command = command;
}

int EventMoter::getMoterCommand(void)
{
	return m_command;
}
