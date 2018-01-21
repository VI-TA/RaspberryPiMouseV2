/**
* @file EventCtrlAutoSwitch.cpp
* @brief 自走機能 開始／停止イベント
* @details 自走機能 開始／停止イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlAutoSwitch.h"

// コンストラクタ
EventCtrlAutoSwitch::EventCtrlAutoSwitch()
{
	setEventType(EVENT_CTRL_AUTO_SWITCH);
}

// デストラクタ
EventCtrlAutoSwitch::~EventCtrlAutoSwitch()
{
}
