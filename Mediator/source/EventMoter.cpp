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
