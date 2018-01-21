#pragma once
#ifndef _EVENT_ROUTER_BASE_H
#define _EVENT_ROUTER_BASE_H

/**
* @file EventRouterBase.h
* @brief イベント中継基底クラス
* @details イベント中継基底クラス
*/

#include <map>
#include "EventContainer.h"

// std:: を省けるが学習のため明示する。
//using namespace std;

class FunctionNode;
class EventContainer;

class EventRouterBase
{
public:
	// コンストラクタ
	EventRouterBase();

	// デストラクタ
	virtual ~EventRouterBase();

	// イベントリスナ登録
	virtual void addEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode);

	// イベントリスナ抹消
	virtual void removeEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode);

	// イベント配信
	virtual void eventThrow(EventContainer *pEvent);
private:
	// イベントリスナリスト
	std::multimap<EventContainer::EVENT_TYPE, FunctionNode*> eventListener;
protected:

};

#endif	// _EVENT_ROUTER_BASE_H
