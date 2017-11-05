#pragma once
#ifndef _EVENTREMOTE_H
#define _EVENTREMOTE_H

/**
* @file EventRemote.h
* @brief リモートイベント
* @details リモートイベント
*/

#include "EventType.h"

class EventContainer;

class EventRemote : public EventContainer
{
public:
	// コンストラクタ
	EventRemote(EVENT_TYPE eventType);
private:
};

#endif	// _EVENTREMOTE_H
