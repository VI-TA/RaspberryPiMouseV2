/**
* @file EventContainer.cpp
* @brief イベント基底クラス
* @details イベント基底クラス
*/

#include <stdio.h>
#include "EventContainer.h"

// コンストラクタ
EventContainer::EventContainer()
{
}

// コンストラクタ
EventContainer::~EventContainer()
{
}

// イベントタイプを設定する。
// A.I 継承先で固定で定義すべきか。
void EventContainer::setEventType(const EVENT_TYPE type)
{
	m_type = type;
}

// イベントタイプを取得する。
EVENT_TYPE EventContainer::getEventType()
{
	return m_type;
}

// [DEGUB] イベント名表示
void EventContainer::printEventName(EVENT_TYPE type)
{
	switch(type) {
        case EVENT_SENSOR_VALUE:
		printf("EVENT_SENSOR_VALUE:\n");
		break;
        case EVENT_MOTER_CONTROL:
		printf("EVENT_MOTER_CONTROL:\n");
		break;
        case EVENT_LED_CONTROL:
		printf("EVENT_LED_CONTROL:\n");
		break;
        case EVENT_SOUND_CONTROL:
		printf("EVENT_SOUND_CONTROL:\n");
		break;
        case EVENT_REMOTE_CONTROL:
		printf("EVENT_REMOTE_CONTROL:\n");
		break;
        case EVENT_AUTO_CONTROL:
		printf("EVENT_AUTO_CONTROL:\n");
		break;
	}
}
