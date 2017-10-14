#include <map>
#include "Mediator.h"
#include "Colleague.h"
#include "EventContainer.h"
#include "EventType.h"

// コンストラクタ
Mediator::Mediator()
{
}

// イベントリスナ登録
void Mediator::addEventListener(EVENT_TYPE type, Colleague *pColl)
{
	eventListener.insert(std::make_pair(type, pColl));
}

// イベントリスナ抹消
void Mediator::removeEventListener(EVENT_TYPE type, Colleague *pColl)
{
}

// イベント配信
void Mediator::eventThrow(EventContainer *pEvent)
{
	EVENT_TYPE	type;
	Colleague	*pColl;

	type = pEvent->getEventType();

	auto p = eventListener.equal_range(type);
	for(auto itr = p.first; itr != p.second; itr++) {
		pColl = itr->second;
		pColl->eventHandler(pEvent);
	}
}
