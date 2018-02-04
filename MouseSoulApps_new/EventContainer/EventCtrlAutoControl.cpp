/**
* @file EventCtrlAutoControl.cpp
* @brief 自走機能制御イベント
* @details 自走機能制御イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlAutoControl.h"

// コンストラクタ
EventCtrlAutoControl::EventCtrlAutoControl()
{
	setEventType(EVENT_CTRL_AUTO_CONTROL);
}

// デストラクタ
EventCtrlAutoControl::~EventCtrlAutoControl()
{
}

// シリアライズデータ設定
bool EventCtrlAutoControl::setSerializeString(std::string serializeString)
{
}

// シリアライズ文字列取得
std::string EventCtrlAutoControl::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
