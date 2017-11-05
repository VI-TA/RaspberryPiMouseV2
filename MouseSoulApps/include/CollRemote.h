#pragma once
#ifndef _COLLREMOTE_H
#define _COLLREMOTE_H

/**
* @file CollRemote.h
* @brief リモート制御
* @details リモート制御
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
