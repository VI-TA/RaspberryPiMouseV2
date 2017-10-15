#pragma once
#ifndef _EVENTLED_H
#define _EVENTLED_H

/**
* @file EventLed.h
* @brief LED制御イベント 
* @details LED制御イベント 
*/

#include "EventType.h"

class EventContainer;

class EventLed : public EventContainer
{
public:
	// コンストラクタ
	EventLed();

	// LED状態設定
	void setLed(int state);

	// LED状態取得
	int getLed(void);
private:
	// LED状態
	int m_state;
};

#endif	// _EVENTLED_H
