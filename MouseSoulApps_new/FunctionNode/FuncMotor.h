#pragma once
#ifndef _FUNC_MOTOR_H
#define _FUNC_MOTOR_H

/**
* @file FuncMotor.h
* @brief モーター制御
* @details モーター制御
*/

#include <thread>
#include <mutex>
#include <condition_variable>

class FunctionNode;
class EventContainer;

class FuncMotor : public FunctionNode
{
public:
	//! コンストラクタ
	FuncMotor();

	//! デストラクタ
	~FuncMotor();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:
	void motorControlThread();

        std::mutex mtx;
        std::condition_variable cv;

	//! スレッドインスタンス
	std::thread m_thread;

	bool	is_receiveEvent;
	bool	is_MotorSwitch;
	int	m_motorSpeed;
	int	m_motorCommand;

};

#endif	// _FUNC_MOTOR_H
