#pragma once
#ifndef _EVENT_CTRL_MOTER_SWITCH_H
#define _EVENT_CTRL_MOTER_SWITCH_H

/**
* @file EventCtrlMoterSwitch.h
* @brief モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
* @details モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
*/

#include "EventType.h"

class EventContainer;

class EventCtrlMoterSwitch : public EventContainer
{
public:
	// モーター制御コマンド
	enum MOTER_COMMAND {
		FORWARD,
		BACK,
		RIGHT_TRUN,
		LEFT_TRUN,
	};

	// コンストラクタ
	EventCtrlMoterSwitch();

	// デストラクタ
	~EventCtrlMoterSwitch();

	// モーターコマンド登録
	void setMoterCommand(int command);

	// モーターコマンド取得
	int getMoterCommand(void);
private:
	// モーターコマンド
	int m_command;
};

#endif	// _EVENT_CTRL_MOTER_SWITCH_H
