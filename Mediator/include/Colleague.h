#pragma once
#ifndef _COLLEAGUE_H
#define _COLLEAGUE_H

/**
* @file Colleague.h
* @brief 簡単な説明
* @details 詳細な説明
*/

class Mediator;
class EventContainer;

class Colleague
{
public:
	// コンストラクタ
	Colleague();

	// Mediatorを設定
	void setMediator(Mediator *pMedi);

	// イベント処理
	virtual void eventHandler(EventContainer *pEc);
	//virtual void eventHandler(const EventContainer *pEc);
protected:
	Mediator *pMediator;
};

#endif	// _COLLEAGUE_H
