#pragma once
#ifndef _EVENT_CTRL_MOTOR_SPEED_H
#define _EVENT_CTRL_MOTOR_SPEED_H

/**
* @file EventCtrlMotorSpeed.h
* @brief モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
* @details モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
*/

#include "EventType.h"

class EventContainer;

class EventCtrlMotorSpeed : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlMotorSpeed();

	// デストラクタ
	~EventCtrlMotorSpeed();

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:
};

#endif	// _EVENT_CTRL_MOTOR_SPEED_H
