#pragma once
#ifndef _MEDIEVENTROUTER_H
#define _MEDIEVENTROUTER_H

/**
* @file MediEventRouter.h
* @brief 簡単な説明
* @details 詳細な説明
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
