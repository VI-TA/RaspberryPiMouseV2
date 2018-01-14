#pragma once
#ifndef _FUNC_SENSOR_H
#define _FUNC_SENSOR_H

/**
* @file FuncSensor.h
* @brief 距離センサー計測制御ヘッダ
* @details 距離センサー計測制御ヘッダ
*/

#include <thread>

class FunctionNode;
class EventContainer;

class FuncSensor : public FunctionNode
{
public:
	//! コンストラクタ
	FuncSensor();

	//! デストラクタ
	~FuncSensor();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! センサー計測開始
	void startMeasureSensor();

	//! センサー計測停止
	void stopMeasureSensor();

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
	
	///// テスト ////
	void sendEvent();
private:
	//! センサー値取得
	void measureSensor();

private:
	//! スレッドインスタンス
	std::thread m_thread;

	//! センサー計測スレッド状態
	bool m_threadState;

	//! センサー計測開始／停止
	bool m_sensorState;

};

#endif	// _FUNC_SENSOR_H
