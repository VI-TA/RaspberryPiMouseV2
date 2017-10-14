#ifndef _COLLLED_H
#define _COLLLED_H

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
