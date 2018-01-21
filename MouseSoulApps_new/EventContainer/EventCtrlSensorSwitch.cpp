/**
* @file EventCrltSensorSwitch.cpp
* @brief 距離センサー読み取り 開始／停止イベント
* @details 距離センサー読み取り 開始／停止イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlSensorSwitch.h"

// コンストラクタ
EventCtrlSensorSwitch::EventCtrlSensorSwitch()
{
	setEventType(EVENT_CTRL_SENSOR_SWITCH);
}

// デストラクタ
EventCtrlSensorSwitch::~EventCtrlSensorSwitch()
{
}

