/**
* @file CollRemote.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include <stdio.h>
#include <pthread.h>
#include "Colleague.h"
#include "CollRemote.h"
#include "EventContainer.h"
#include "EventRemote.h"

// コンストラクタ
CollRemote::CollRemote()
{
}

void CollRemote::eventHandler(EventContainer *pEc)
{
	printf("CollRemote::eventHandler\n");
	pEc->printEventName(pEc->getEventType());
}
