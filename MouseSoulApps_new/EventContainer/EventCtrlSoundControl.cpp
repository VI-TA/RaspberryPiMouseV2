/**
* @file EventCtrlSoundControl.cpp
* @brief ブザー鳴動 制御イベント
* @details ブザー鳴動 制御イベント
*/

#include "stdafx.h"

#include "EventContainer.h"
#include "EventCtrlSoundControl.h"

// コンストラクタ
EventCtrlSoundControl::EventCtrlSoundControl()
{
	setEventType(EVENT_CTRL_SOUND_CONTROL);
}

// デストラクタ
EventCtrlSoundControl::~EventCtrlSoundControl()
{
}

void EventCtrlSoundControl::setSoundScore(std::vector<int> score)
{
	m_score = score;
}

std::vector<int> EventCtrlSoundControl::getSoundScore(void)
{
	return m_score;
}
