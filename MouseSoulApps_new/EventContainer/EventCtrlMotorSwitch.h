#pragma once
#ifndef _EVENT_CTRL_MOTOR_SWITCH_H
#define _EVENT_CTRL_MOTOR_SWITCH_H

/**
* @file EventCtrlMotorSwitch.h
* @brief モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
* @details モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
*/

#include "EventType.h"

class EventContainer;

class EventCtrlMotorSwitch : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlMotorSwitch();

	// デストラクタ
	~EventCtrlMotorSwitch();

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:
};

#endif	// _EVENT_CTRL_MOTOR_SWITCH_H
