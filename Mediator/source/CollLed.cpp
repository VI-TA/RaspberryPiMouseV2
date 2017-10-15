/**
* @file CollLed.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include <stdio.h>
#include <pthread.h>
#include "Colleague.h"
#include "CollLed.h"
#include "EventContainer.h"

CollLed::CollLed()
{
}

void CollLed::eventHandler(EventContainer *pEc)
{
	printf("CollLed::eventHandler\n");
	pEc->printEventName(pEc->getEventType());
}
