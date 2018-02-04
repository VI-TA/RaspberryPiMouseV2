#pragma once
#ifndef _EVENT_CTRL_MOTOR_CONTROL_H
#define _EVENT_CTRL_MOTOR_CONTROL_H

/**
* @file EventCtrlMotorControl.h
* @brief モーター制御イベント
* @details モーター制御イベント
*/

#include "EventType.h"

class EventContainer;

class EventCtrlMotorControl : public EventContainer
{
public:
	// モーター制御コマンド
	enum MOTOR_COMMAND {
		BEGIN = 0,
		CTRL_SW_OFF = 1,
		CTRL_SW_ON,
		CTRL_STOP = 10,
		CTRL_FORWARD,
		CTRL_BACK,
		CTRL_RIGHT_TRUN,
		CTRL_LEFT_TRUN,
		END,
	};

	// コンストラクタ
	EventCtrlMotorControl();

	// デストラクタ
	~EventCtrlMotorControl();

	// モーターコマンド登録
	void setMotorCommand(int command);

	// モーターコマンド取得
	int getMotorCommand(void);

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;

private:
	// モーターコマンド
	int m_command;
};

#endif	// _EVENT_CTRL_MOTOR_CONTROL_H
