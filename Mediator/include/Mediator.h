// インクルード二重定義抑止の手法
//#pragma once

#ifndef _MEDIATOR_H
#define _MEDIATOR_H

#include <map>
#include "EventType.h"

// std:: を省けるが学習のため明示する。
//using namespace std;

class Colleague;
class EventContainer;

class Mediator
{
public:
	// コンストラクタ
	Mediator();

	// イベントリスナ登録
	void addEventListener(EVENT_TYPE type, Colleague *pColl);

	// イベントリスナ抹消
	void removeEventListener(EVENT_TYPE type, Colleague *pColl);

	// イベント配信
	void eventThrow(EventContainer *);
private:
	// イベントリスナリスト
	std::multimap<EVENT_TYPE, Colleague*> eventListener;
protected:

};

#endif	// _MEDIATOR_H
