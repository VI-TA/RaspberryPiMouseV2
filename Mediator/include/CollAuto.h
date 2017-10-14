#ifndef _COLLAUTO_H
#define _COLLAUTO_H

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
