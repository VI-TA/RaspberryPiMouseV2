#pragma once
#ifndef _MEDIEVENTROUTER_H
#define _MEDIEVENTROUTER_H

/**
* @file MediEventRouter.h
* @brief 機能制御オブジェクト間イベント中継制御
* @details 機能制御オブジェクト間イベント中継制御
*/

#include "EventType.h"

class Mediator;
class Colleague;

class MediEventRouter : public Mediator
{
public:
	// コンストラクタ
	MediEventRouter();
private:
};

#endif	// _MEDIEVENTROUTER_H
