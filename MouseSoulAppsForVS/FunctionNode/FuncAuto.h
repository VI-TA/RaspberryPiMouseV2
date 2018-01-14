#pragma once
#ifndef _FUNC_AUTO_H
#define _FUNC_AUTO_H

/**
* @file FuncAuto.h
* @brief 自走制御
* @details 自走制御
*/

class FunctionNode;
class EventContainer;

class FuncAuto : public FunctionNode
{
public:
	//! コンストラクタ
	FuncAuto();

	//! デストラクタ
	~FuncAuto();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! 
	void eventHandler(const EventContainer *pEc);
private:
};

#endif	// _FUNC_AUTO_H
