#ifndef _EVENTSOUND_H
#define _EVENTSOUND_H

#include <vector>
#include "EventType.h"

class EventContainer;

class EventSound : public EventContainer
{
public:
	// コンストラクタ
	EventSound();

	// 楽譜登録
	void setSoundScore(std::vector<int> score);

	// 楽譜取得
	std::vector<int> getSoundScore(void);
private:
	// 楽譜
	std::vector<int> m_score;
};

#endif	// _EVENTSOUND_H
