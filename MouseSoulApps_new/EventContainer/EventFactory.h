/**
* @file EventFactroy.h
* @brief イベント生成クラスヘッダ
* @details イベント生成クラスヘッダ
*/

#pragma once
#ifndef _EVENT_FACTORY_H
#define _EVENT_FACTORY_H

#include <string>
#include <vector>

class EventContainer;

/**
* @brief イベント生成クラス
* @details 
*/
class EventFactory
{
public:
	//! コンストラクタ
	EventFactory();

	//! デストラクタ
	~EventFactory();

	//! イベント生成
	EventContainer* createEvent(char *serializeString);
	EventContainer* createEvent(std::string serializeString);

private:
	//! 保存データ型
	std::string	m_serializeStr;

};

#endif	// _EVENT_FACTORY_H
