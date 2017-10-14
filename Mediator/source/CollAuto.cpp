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
