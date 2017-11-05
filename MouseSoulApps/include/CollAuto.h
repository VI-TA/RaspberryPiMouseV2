#pragma once
#ifndef _COLLAUTO_H
#define _COLLAUTO_H

/**
* @file CollAuto.h
* @brief 自走制御
* @details 自走制御
*/

class Mediator;
class Colleague;
class EventContainer;

class CollAuto : public Colleague
{
public:
	// コンストラクタ
	CollAuto();

	// イベント処理
	void eventHandler(EventContainer *pEc);
private:
};

#endif	// _COLLAUTO_H
