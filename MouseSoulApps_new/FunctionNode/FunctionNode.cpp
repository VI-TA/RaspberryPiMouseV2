/**
* @file FunctionNode.cpp
* @brief 機能ベースクラス
* @details 機能ベースクラス
*/

#include "stdafx.h"

#include "EventRouterBase.h"
#include "FunctionNode.h"

// コンストラクタ
FunctionNode::FunctionNode()
{
}

// デストラクタ
FunctionNode::~FunctionNode()
{
}

// イベントルータークラス登録
void FunctionNode::setEventRouter(EventRouterBase *pEventRouter)
{
	// Mediatorのポインタを保存
	m_pEventRouter = pEventRouter;
}

//! イベント送信
void FunctionNode::eventThrow(EventContainer *ev)
{
	m_pEventRouter->eventThrow(ev);
}

// イベントハンドラ
void FunctionNode::eventHandler(const EventContainer *pEc)
{
	// 処理は継続先のクラスで定義する。
}
