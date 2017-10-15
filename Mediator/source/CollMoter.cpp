/**
* @file CollMoter.cpp
* @brief 簡単な説明
* @details 詳細な説明
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
