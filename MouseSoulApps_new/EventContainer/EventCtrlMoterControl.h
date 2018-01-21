#pragma once
#ifndef _EVENT_CTRL_MOTER_CONTROL_H
#define _EVENT_CTRL_MOTER_CONTROL_H

/**
* @file EventCtrlMoterControl.h
* @brief モーター制御イベント
* @details モーター制御イベント
*/

#include "EventType.h"

class EventContainer;

class EventCtrlMoterControl : public EventContainer
{
public:
	// モーター制御コマンド
	enum MOTER_COMMAND {
		BEGIN,
		CTRL_STOP,
		CTRL_FORWARD,
		CTRL_BACK,
		CTRL_RIGHT_TRUN,
		CTRL_LEFT_TRUN,
		END,
	};

	// コンストラクタ
	EventCtrlMoterControl();

	// デストラクタ
	~EventCtrlMoterControl();

	// モーターコマンド登録
	void setMoterCommand(int command);

	// モーターコマンド取得
	int getMoterCommand(void);
private:
	// モーターコマンド
	int m_command;
};

#endif	// _EVENT_CTRL_MOTER_CONTROL_H
