/**
* @file EventCtrlMoterControl.cpp
* @brief モーター制御イベント
* @details モーター制御イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlMoterControl.h"

// コンストラクタ
EventCtrlMoterControl::EventCtrlMoterControl()
{
	setEventType(EVENT_CTRL_MOTER_CONTROL);
}

// デストラクタ
EventCtrlMoterControl::~EventCtrlMoterControl()
{
}

void EventCtrlMoterControl::setMoterCommand(int command)
{
}

int EventCtrlMoterControl::getMoterCommand(void)
{
	return 0;
}
