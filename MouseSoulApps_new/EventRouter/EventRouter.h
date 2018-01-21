#pragma once
#ifndef _EVENT_ROUTER_H
#define _EVENT_ROUTER_H

/**
* @file EventRouter.h
* @brief 機能制御オブジェクト間イベント中継制御
* @details 機能制御オブジェクト間イベント中継制御
*/

#include "EventType.h"

class EventRouterBase;

class EventRouter : public EventRouterBase
{
public:
	// コンストラクタ
	EventRouter();

	// デストラクタ
	virtual ~EventRouter();

	// イベントリスナ登録
	virtual void addEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode);

	// イベントリスナ抹消
	virtual void removeEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode);

	// イベント配信
	virtual void eventThrow(EventContainer *pEvent);
private:
};

#endif	// _EVENT_ROUTER_H
