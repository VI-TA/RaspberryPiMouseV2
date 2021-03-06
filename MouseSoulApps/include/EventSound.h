#pragma once
#ifndef _EVENTSOUND_H
#define _EVENTSOUND_H

/**
* @file EventSound.h
* @brief 音源制御イベント
* @details 音源制御イベント
*/

#include <vector>
#include "EventType.h"

class EventContainer;

class EventSound : public EventContainer
{
public:
	// コンストラクタ
	EventSound(EVENT_TYPE eventType);

	// 楽譜登録
	void setSoundScore(std::vector<int> score);

	// 楽譜取得
	std::vector<int> getSoundScore(void);
private:
	// 楽譜
	std::vector<int> m_score;
};

#endif	// _EVENTSOUND_H
