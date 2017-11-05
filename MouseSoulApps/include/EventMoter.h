#pragma once
#ifndef _EVENTMOTER_H
#define _EVENTMOTER_H

/**
* @file EventMoter.h
* @brief モーター制御イベント
* @details モーター制御イベント
*/

#include "EventType.h"

class EventContainer;

class EventMoter : public EventContainer
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
	EventMoter(EVENT_TYPE eventType);

	// モーターコマンド登録
	void setMoterCommand(int command);

	// モーターコマンド取得
	int getMoterCommand(void);
private:
	// モーターコマンド
	int m_command;
};

#endif	// _EVENTMOTER_H
