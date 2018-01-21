#pragma once
#ifndef _EVENT_CTRL_LED_CONTROL_H
#define _EVENT_CTRL_LED_CONTROL_H

/**
* @file EventCtrlLedControl.h
* @brief LED制御イベント 
* @details LED制御イベント 
*/

#include "EventType.h"

class EventContainer;

class EventCtrlLedControl : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlLedControl();

	// デストラクタ
	~EventCtrlLedControl();

	// LED状態設定
	void setLed(int state);

	// LED状態取得
	int getLed(void);
private:
	// LED状態
	int m_state;
};

#endif	// _EVENT_CTRL_LED_CONTROL_H
