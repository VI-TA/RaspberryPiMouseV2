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
	// 入力値チェック
	if(EventCtrlMoterControl::BEGIN <= command &&
	   EventCtrlMoterControl::END >= command) {
		// コマンド値外
		// 暴走抑止のためモーターを止める。
		m_command = CTRL_STOP;
	} else {
		// モーター制御コマンド設定
		m_command = command;
	}
}

int EventCtrlMoterControl::getMoterCommand(void)
{
	return m_command;
}
