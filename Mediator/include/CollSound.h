#ifndef _COLLSOUND_H
#define _COLLSOUND_H

class Mediator;
class Colleague;
class EventContainer;

class CollSound : public Colleague
{
public:
	// コンストラクタ
	CollSound();

	// イベント処理
	void eventHandler(EventContainer *pEc);
private:
};

#endif	// _COLLSOUND_H
