#pragma once
#ifndef _COLLLED_H
#define _COLLLED_H

/**
* @file CollLed.h
* @brief 簡単な説明
* @details 詳細な説明
*/

class Mediator;
class Colleague;
class EventContainer;

class CollLed : public Colleague
{
public:
	// コンストラクタ
	CollLed();

	// イベント処理
	void eventHandler(EventContainer *pEc);
private:
};

#endif	// _COLLLED_H
