/**
* @file EventSound.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include "EventContainer.h"
#include "EventSound.h"

// コンストラクタ
EventSound::EventSound()
{
}

void EventSound::setSoundScore(std::vector<int> score)
{
	m_score = score;
}

std::vector<int> EventSound::getSoundScore(void)
{
	return m_score;
}
