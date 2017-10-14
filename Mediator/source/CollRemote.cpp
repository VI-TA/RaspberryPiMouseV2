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
