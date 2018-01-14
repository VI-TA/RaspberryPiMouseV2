/**
* @file EventRouter.cpp
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
EventRouter::EventRouter()
{
}

// デストラクタ
EventRouter::~EventRouter()
{
}

// イベントリスナ登録
void EventRouter::addEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode)
{
	// 独自処理定義

	// 基底クラスへ通知
	EventRouterBase::addEventListener(type, pFuncNode);
}

// イベントリスナ抹消
void EventRouter::removeEventListener(EventContainer::EVENT_TYPE type, FunctionNode *pFuncNode)
{
	// 独自処理定義

	// 基底クラスへ通知
	EventRouterBase::removeEventListener(type, pFuncNode);
}

// イベント配信
void EventRouter::eventThrow(EventContainer *pEvent)
{
	// 独自処理定義

	// 基底クラスへ通知
	EventRouterBase::eventThrow(pEvent);
}