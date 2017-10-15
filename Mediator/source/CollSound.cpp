/**
* @file CollSound.cpp
* @brief 音源制御
* @details 音源制御
*/

#include <stdio.h>
#include <pthread.h>
#include "Colleague.h"
#include "CollSound.h"
#include "EventContainer.h"

CollSound::CollSound()
{
}

void CollSound::eventHandler(EventContainer *pEc)
{
	printf("CollSound::eventHandler\n");
	pEc->printEventName(pEc->getEventType());
}
