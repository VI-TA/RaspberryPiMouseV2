#pragma once
#ifndef _COLLMOTER_H
#define _COLLMOTER_H

/**
* @file CollMoter.h
* @brief 簡単な説明
* @details 詳細な説明
*/

class Mediator;
class Colleague;
class EventContainer;

class CollMoter : public Colleague
{
public:
	// コンストラクタ
	CollMoter();

	// イベント処理
	void eventHandler(EventContainer *pEc);
private:
};

#endif	// _COLLMOTER_H
