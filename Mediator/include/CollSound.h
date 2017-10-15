#pragma once
#ifndef _COLLSOUND_H
#define _COLLSOUND_H

/**
* @file CollSound.h
* @brief 簡単な説明
* @details 詳細な説明
*/

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
