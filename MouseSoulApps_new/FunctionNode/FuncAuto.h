#pragma once
#ifndef _FUNC_AUTO_H
#define _FUNC_AUTO_H

/**
* @file FuncAuto.h
* @brief 自走制御
* @details 自走制御
*/

#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class FunctionNode;
class EventContainer;

class FuncAuto : public FunctionNode
{
public:
	//! コンストラクタ
	FuncAuto();

	//! デストラクタ
	~FuncAuto();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:
	void autoThread();

        std::mutex mtx;
        std::condition_variable cv;

	//! スレッドインスタンス
	std::thread m_thread;

	//! 自走スレッドイベントトリガー
	bool m_eventTrigger;

	//! 自動モードスイッチ
	bool m_autoMode;

	//! センサー値
	std::vector<int> m_sensorValue;

};

#endif	// _FUNC_AUTO_H
