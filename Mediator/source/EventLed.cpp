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
