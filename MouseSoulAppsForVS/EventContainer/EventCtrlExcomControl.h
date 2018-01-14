#pragma once
#ifndef _EVENT_CTRL_EXCOM_CONTROL_H
#define _EVENT_CTRL_EXCOM_CONTROL_H

/**
* @file EventCtrlExcomControl.h
* @brief リモートイベント
* @details リモートイベント
*/

#include "EventType.h"

class EventContainer;

class EventCtrlExcomControl : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlExcomControl();

	// デストラクタ
	~EventCtrlExcomControl();
private:
};

#endif	// _EVENT_CTRL_EXCOM_CONTROL_H
