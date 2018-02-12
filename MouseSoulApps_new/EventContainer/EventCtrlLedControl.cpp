/**
* @file EventCtrlLedControl.cpp
* @brief ＬＥＤ制御イベント
* @details ＬＥＤ制御イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlLedControl.h"

// コンストラクタ
EventCtrlLedControl::EventCtrlLedControl()
{
	setEventType(EVENT_CTRL_LED_CONTROL);
}

// デストラクタ
EventCtrlLedControl::~EventCtrlLedControl()
{
}

void EventCtrlLedControl::setLed(int state)
{
	m_state = state;
}


int EventCtrlLedControl::getLed(void)
{
	return m_state;
}

// シリアライズデータ設定
bool EventCtrlLedControl::setSerializeString(std::string serializeString)
{
	return true;
}

// シリアライズ文字列取得
std::string EventCtrlLedControl::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
