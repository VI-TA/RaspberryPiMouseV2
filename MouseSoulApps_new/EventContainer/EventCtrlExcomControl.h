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

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:
};

#endif	// _EVENT_CTRL_EXCOM_CONTROL_H
