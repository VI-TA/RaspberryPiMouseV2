/**
* @file CollMoter.cpp
* @brief モーター制御
* @details モーター制御
*/

#include <stdio.h>
#include <pthread.h>
#include "Colleague.h"
#include "CollMoter.h"
#include "EventContainer.h"

CollMoter::CollMoter()
{
}

void CollMoter::eventHandler(EventContainer *pEc)
{
	printf("CollMoter::eventHandler\n");
	pEc->printEventName(pEc->getEventType());
}
