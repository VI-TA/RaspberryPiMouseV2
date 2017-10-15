/**
* @file Colleague.cpp
* @brief 簡単な説明
* @details 詳細な説明
*/

#include "Colleague.h"

// コンストラクタ
Colleague::Colleague()
{
}

void Colleague::setMediator(Mediator *pMedi)
{
	// Mediatorのポインタを保存
	pMediator = pMedi;
}

void Colleague::eventHandler(EventContainer *pEc)
{
	// 処理は継承先のクラスで定義する。
}
