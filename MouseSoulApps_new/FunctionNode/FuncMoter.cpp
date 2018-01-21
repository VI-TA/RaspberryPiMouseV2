/**
* @file FuncMoter.cpp
* @brief モーター制御
* @details モーター制御
*/

#include "stdafx.h"

#include <iostream>

#include "FunctionNode.h"
#include "FuncMoter.h"

#include "EventContainer.h"
#include "EventCtrlMoterSwitch.h"
#include "EventCtrlMoterControl.h"

// コンストラクタ
FuncMoter::FuncMoter()
{
}

// デストラクタ
FuncMoter::~FuncMoter()
{
}

// イベントルータークラス登録
void FuncMoter::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncMoter::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncMoter::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;

	// モーター制御イベント
	if (EventContainer::EVENT_CTRL_MOTER_CONTROL == pEc->getEventType()) {


	}
}
