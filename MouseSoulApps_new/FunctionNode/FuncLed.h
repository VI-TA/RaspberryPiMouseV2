#pragma once
#ifndef _FUNC_LED_H
#define _FUNC_LED_H

/**
* @file FuncLed.h
* @brief LED制御 
* @details LED制御 
*/

class FunctionNode;
class EventContainer;

class FuncLed : public FunctionNode
{
public:
	//! コンストラクタ
	FuncLed();

	//! デストラクタ
	~FuncLed();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:
};

#endif	// _FUNC_LED_H
