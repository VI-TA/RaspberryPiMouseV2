/**
* @file EventCtrlMoterSwitch.cpp
* @brief モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
* @details モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlMoterSwitch.h"

// コンストラクタ
EventCtrlMoterSwitch::EventCtrlMoterSwitch()
{
	setEventType(EVENT_CTRL_MOTER_SWITCH);
}

// デストラクタ
EventCtrlMoterSwitch::~EventCtrlMoterSwitch()
{
}

void EventCtrlMoterSwitch::setMoterCommand(int command)
{
}

int EventCtrlMoterSwitch::getMoterCommand(void)
{
	return 0;
}
