/**
* @file FuncSound.cpp
* @brief ブザー制御
* @details ブザー制御
*/

#include "stdafx.h"

#include <iostream>

#include "FunctionNode.h"
#include "FuncSound.h"

#include "EventContainer.h"
#include "EventCtrlSoundControl.h"

// コンストラクタ
FuncSound::FuncSound()
{
}

// デストラクタ
FuncSound::~FuncSound()
{
}

// イベントルータークラス登録
void FuncSound::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncSound::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncSound::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;
	pEc->printEventName(pEc->getEventType());
}
