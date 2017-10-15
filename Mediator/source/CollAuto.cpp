/**
* @file CollAuto.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include <stdio.h>
#include <pthread.h>
#include "Colleague.h"
#include "CollAuto.h"
#include "EventContainer.h"
#include "EventAuto.h"
#include "EventType.h"

// コンストラクタ
CollAuto::CollAuto()
{
}

void CollAuto::eventHandler(EventContainer *pEc)
{
	printf("CollAuto::eventHandler\n");
	pEc->printEventName(pEc->getEventType());
}
