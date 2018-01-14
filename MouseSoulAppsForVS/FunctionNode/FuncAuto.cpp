/**
* @file FuncAuto.cpp
* @brief 自走制御機能
* @details 自走制御機能
*/

#include "stdafx.h"

#include <iostream>

#include "FunctionNode.h"
#include "FuncAuto.h"

#include "EventRouterBase.h"
#include "EventContainer.h"
#include "EventCtrlAutoSwitch.h"
#include "EventCtrlAutoControl.h"

// コンストラクタ
FuncAuto::FuncAuto()
{
}

// デストラクタ
FuncAuto::~FuncAuto()
{
}

// イベントルータークラス登録
void FuncAuto::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncAuto::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncAuto::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;

//	printf("CollAuto::eventHandler\n");
//	pEc->printEventName(pEc->getEventType());
}
