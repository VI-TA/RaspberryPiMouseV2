/**
* @file FuncLed.cpp
* @brief LED制御
* @details LED制御
*/

#include "stdafx.h"

#include <iostream>

#include "FunctionNode.h"
#include "FuncLed.h"

#include "EventContainer.h"
#include "EventCtrlLedControl.h"

// コンストラクタ
FuncLed::FuncLed()
{
}

// デストラクタ
FuncLed::~FuncLed()
{
}

// イベントルータークラス登録
void FuncLed::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncLed::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncLed::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;
	pEc->printEventName(pEc->getEventType());
}
