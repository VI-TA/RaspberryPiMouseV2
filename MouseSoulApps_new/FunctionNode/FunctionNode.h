#pragma once
#ifndef _FUNC_NODE_H
#define _FUNC_NODE_H

/**
* @file FunctionNode.h
* @brief 機能ベースクラス
* @details 機能ベースクラス
*/

class EventRouterBase;
class EventContainer;

class FunctionNode
{
public:
	//! コンストラクタ
	FunctionNode();

	//! デストラクタ
	virtual ~FunctionNode();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント送信
	virtual void eventThrow(EventContainer *ev);

	//! イベントハンドラ 
	virtual void eventHandler(const EventContainer *pEc);
protected:
	EventRouterBase *m_pEventRouter;
};

#endif	// _FUNC_NODE_H
