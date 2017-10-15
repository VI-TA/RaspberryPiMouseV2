/**
* @file CollLed.cpp
* @brief LED制御
* @details LED制御
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
