#pragma once
#ifndef _FUNC_MOTER_H
#define _FUNC_MOTER_H

/**
* @file FuncMoter.h
* @brief モーター制御
* @details モーター制御
*/

class FunctionNode;
class EventContainer;

class FuncMoter : public FunctionNode
{
public:
	//! コンストラクタ
	FuncMoter();

	//! デストラクタ
	~FuncMoter();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:
};

#endif	// _FUNC_MOTER_H
