/**
* @file EventCtrlExcomControl.cpp
* @brief 削除予定
* @details 削除予定
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlExcomControl.h"

// コンストラクタ
EventCtrlExcomControl::EventCtrlExcomControl()
{
	setEventType(EVENT_CTRL_EXCOM_CONTROL);
}

// デストラクタ
EventCtrlExcomControl::~EventCtrlExcomControl()
{
}

// シリアライズデータ設定
bool EventCtrlExcomControl::setSerializeString(std::string serializeString)
{
	return true;
}

// シリアライズ文字列取得
std::string EventCtrlExcomControl::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
