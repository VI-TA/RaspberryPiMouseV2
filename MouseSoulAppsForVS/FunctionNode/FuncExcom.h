#pragma once
#ifndef _FUNC_EXCOM_H
#define _FUNC_EXCOM_H

/**
* @file FuncExcom.h
* @brief リモート制御
* @details リモート制御
*/

#include <thread>

class FunctionNode;
class EventContainer;

class FuncExcom : public FunctionNode
{
public:
	//! コンストラクタ
	FuncExcom();

	//! デストラクタ
	~FuncExcom();


	//! [TEST] センサー計測開始
	void startMeasureSensor();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:


	//! [TEST] スレッドインスタンス
	//! センサー値取得
	void measureSensor();
	std::thread m_thread;
	bool m_threadState;

};

#endif	// _FUNC_EXCOM_H
