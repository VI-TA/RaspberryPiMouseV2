#pragma once
#ifndef _FUNC_SOUND_H
#define _FUNC_SOUND_H

/**
* @file FuncSound.h
* @brief ブザー制御
* @details ブザー制御
*/

class FunctionNode;
class EventContainer;

class FuncSound : public FunctionNode
{
public:
	//! コンストラクタ
	FuncSound();

	//! デストラクタ
	~FuncSound();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:
};

#endif	// _FUNC_SOUND_H
