#pragma once
#ifndef _EVENTCONTAINER_H
#define _EVENTCONTAINER_H

/**
* @file EventContainer.h
* @brief イベント基底クラス
* @details イベント基底クラス
*/

#include "EventType.h"

class EventContainer
{
public:
	// コンストラクタ
	EventContainer();

	// デストラクタ(Polymorphicの為、virtualにする）
	virtual ~EventContainer();

	// イベントタイプ設定
	void		setEventType(EVENT_TYPE);

	// イベントタイプ取得
	EVENT_TYPE	getEventType();

	// [DEBUG] イベント名表示
	void 		printEventName(EVENT_TYPE);
private:
	// イベントタイプ
	EVENT_TYPE	m_type;
};

#endif	// _EVENTCONTAINER_H
