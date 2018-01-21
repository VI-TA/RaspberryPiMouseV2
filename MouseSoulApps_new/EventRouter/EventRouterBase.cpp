/**
* @file EventRouterBase.cpp
* @brief 
* @details 
*/

#include <map>

#include "stdafx.h"

#include "EventRouterBase.h"
#include "EventRouter.h"
#include "FunctionNode.h"
#include "EventContainer.h"
#include "EventType.h"

// コンストラクタ
EventRouterBase::EventRouterBase()
{
}

// デストラクタ
EventRouterBase::~EventRouterBase()
{
}

// イベントリスナ登録
void EventRouterBase::addEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode)
{
	// キー、値 重複チェック
	if(0 < eventListener.count(type)) {
		// 重複キー有り。
		auto p = eventListener.equal_range(type);
		for (auto itr = p.first; itr != p.second; itr++) {
			if (pFuncNode == itr->second) {
				// 同一値有り。
				return;
			}
		}
	}

	// 要求イベントと配信先クラスを連想コンテナに登録する。
	eventListener.insert(std::make_pair(type, pFuncNode));

	// 配信先クラスに、イベントルータークラスを登録する。
//やらない	pFuncNode->setEventRouter(this);
}

// イベントリスナ抹消
void EventRouterBase::removeEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode)
{
	// 同一キーの要素を抽出する。
	auto p = eventListener.equal_range(type);

	// 同一キー要素の最初～最後までループする。
	for (auto itr = p.first; itr != p.second;) {
		// 同一値は削除対象
		if (pFuncNode == itr->second) {
			eventListener.erase(itr++);		// itr++をカッコ内で実装しないとエラーになる。
		}
		else {
			itr++;
		}
	}
}

// イベント配信
void EventRouterBase::eventThrow(EventContainer *pEvent)
{
	EventContainer::EVENT_TYPE		type;
	FunctionNode	*pFuncNode;

	type = pEvent->getEventType();

	// 同一キーの要素を抽出する。
	auto p = eventListener.equal_range(type);

	// 同一キー要素の最初～最後までループする。
	for (auto itr = p.first; itr != p.second; itr++) {
		pFuncNode = itr->second;
		pFuncNode->eventHandler(pEvent);
	}
}
