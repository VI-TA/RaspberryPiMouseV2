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
