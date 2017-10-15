#pragma once
#ifndef _COLLREMOTE_H
#define _COLLREMOTE_H

/**
* @file CollRemote.h
* @brief 簡単な説明
* @details 詳細な説明
*/

class Mediator;
class Colleague;
class EventContainer;

class CollRemote : public Colleague
{
public:
	// コンストラクタ
	CollRemote();

	// イベント処理
	void eventHandler(EventContainer *pEc);
private:
};

#endif	// _COLLREMOTE_H
