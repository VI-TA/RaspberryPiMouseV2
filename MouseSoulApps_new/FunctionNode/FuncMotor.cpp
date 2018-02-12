/**
* @file FuncMotor.cpp
* @brief モーター制御
* @details モーター制御
*/

#include "stdafx.h"

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <thread>
#include <mutex>
#include <condition_variable>

#include <iostream>
#include <cstring>

#include "FunctionNode.h"
#include "FuncMotor.h"

#include "EventContainer.h"
#include "EventCtrlMotorSwitch.h"
#include "EventCtrlMotorControl.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// コンストラクタ
FuncMotor::FuncMotor()
{
	// イベント待ちフラグ
	is_receiveEvent = false;

	// モータースイッチ初期化
	is_MotorSwitch = false;

	// モーター制御スレッド起動
	m_thread = std::thread(&FuncMotor::motorControlThread, this);
}

// デストラクタ
FuncMotor::~FuncMotor()
{
}

// イベントルータークラス登録
void FuncMotor::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

// イベントハンドラ
void FuncMotor::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncMotor::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;

	if (EventContainer::EVENT_CTRL_MOTOR_SWITCH == pEc->getEventType()) {
		// モータースイッチ
		if(pEc->toBool()) {
			m_motorCommand = EventCtrlMotorControl::CTRL_SW_ON;
		}else{
			m_motorCommand = EventCtrlMotorControl::CTRL_SW_OFF;
		}

		is_receiveEvent = true;
		std::lock_guard<std::mutex> uniq_lk(mtx);
		cv.notify_all();
		std::cout << "FuncMotor::eventHandler() : Motor SW" << "[" << m_motorCommand << "]" << std::endl;
	}else
	if (EventContainer::EVENT_CTRL_MOTOR_CONTROL == pEc->getEventType()) {
		// モーターコマンド値取得
		m_motorCommand = pEc->toInt();

		is_receiveEvent = true;
		std::lock_guard<std::mutex> uniq_lk(mtx);
		cv.notify_all();
		std::cout << "FuncMotor::eventHandler() : Motor Control" << "[" << m_motorCommand << "]" << std::endl;
	}else
	if (EventContainer::EVENT_CTRL_MOTOR_SPEED == pEc->getEventType()) {
		// モータースピード取得
		m_motorSpeed = pEc->toInt();
		std::cout << "FuncMotor::eventHandler() : Speed" << "[" << m_motorSpeed << "]" << std::endl;
	}
}

// モーター制御スレッド
void FuncMotor::motorControlThread()
{
	int motorCommand;
        char buf[50], bufL[50], bufR[50];
        int motor, motorL, motorR, motorSpeed;

	std::cout << "FuncMotor::motorControlThread()" << std::endl;

	while(1) {

	// ----- イベントトリガあるまで停止 -----
	std::unique_lock<std::mutex> uniq_lk(mtx);
	cv.wait(uniq_lk, [this] { return is_receiveEvent; });
	is_receiveEvent = false;
	std::cout << "FuncMotor::motorControlThread() Thread torigger" << std::endl;
	// -----

	// ローカル変数にモーターコマンドをコピー（上書き対策）
	motorCommand = m_motorCommand;
	motorSpeed = m_motorSpeed;

	// モーター制御コマンド
	std::memset(buf, 0, sizeof(buf));
	std::memset(bufR, 0, sizeof(bufR));
	std::memset(bufL, 0, sizeof(bufL));

	// モータースイッチOFF
	if(EventCtrlMotorControl::CTRL_SW_OFF == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motor = open("/dev/rtmotoren0", O_WRONLY);
		buf[0] = '0';
		write(motor, buf, std::strlen(buf));
		close(motor);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_SW_OFF" << std::endl;
	} else
	// モータースイッチON
	if(EventCtrlMotorControl::CTRL_SW_ON == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motor = open("/dev/rtmotoren0", O_WRONLY);
		buf[0] = '1';
		write(motor, buf, std::strlen(buf));
		close(motor);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_SW_ON" << std::endl;
	} else
	// モーターストップ
	if(EventCtrlMotorControl::CTRL_STOP == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motorL = open("/dev/rtmotor_raw_l0", O_WRONLY);
		motorR = open("/dev/rtmotor_raw_r0", O_WRONLY);
		bufL[0] = '0';
		bufR[0] = '0';
		write(motorL, bufL, std::strlen(bufL));
		write(motorR, bufR, std::strlen(bufR));
		close(motorL);
		close(motorR);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_STOP" << std::endl;
	} else
	// 前進
	if(EventCtrlMotorControl::CTRL_FORWARD == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motorL = open("/dev/rtmotor_raw_l0", O_WRONLY);
		motorR = open("/dev/rtmotor_raw_r0", O_WRONLY);
		snprintf(buf, sizeof(buf), "%d", motorSpeed);
		write(motorL, buf, std::strlen(buf));
		write(motorR, buf, std::strlen(buf));
		close(motorL);
		close(motorR);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_FORWARD speed[" << buf << "]" << std::endl;
	} else
	// 左回り
	if(EventCtrlMotorControl::CTRL_LEFT_TRUN == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motorL = open("/dev/rtmotor_raw_l0", O_WRONLY);
		motorR = open("/dev/rtmotor_raw_r0", O_WRONLY);
		snprintf(bufL, sizeof(bufL), "%d", motorSpeed*-1);
		snprintf(bufR, sizeof(bufR), "%d", motorSpeed);
		write(motorL, bufL, std::strlen(bufL));
		write(motorR, bufR, std::strlen(bufR));
		close(motorL);
		close(motorR);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_LEFT_TRUN" << std::endl;
	} else
	// 右回り
	if(EventCtrlMotorControl::CTRL_RIGHT_TRUN == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motorL = open("/dev/rtmotor_raw_l0", O_WRONLY);
		motorR = open("/dev/rtmotor_raw_r0", O_WRONLY);
		snprintf(bufL, sizeof(bufL), "%d", motorSpeed);
		snprintf(bufR, sizeof(bufR), "%d", motorSpeed*-1);
		write(motorL, bufL, std::strlen(bufL));
		write(motorR, bufR, std::strlen(bufR));
		close(motorL);
		close(motorR);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_RIGHT_TRUN" << std::endl;
	} else
	// 後退
	if(EventCtrlMotorControl::CTRL_BACK == motorCommand) {
#ifdef _FOR_LINUX_DRIVER
		motorL = open("/dev/rtmotor_raw_l0", O_WRONLY);
		motorR = open("/dev/rtmotor_raw_r0", O_WRONLY);
		snprintf(bufL, sizeof(bufL), "%d", motorSpeed*-1);
		snprintf(bufR, sizeof(bufR), "%d", motorSpeed*-1);
		write(motorL, bufL, std::strlen(bufL));
		write(motorR, bufR, std::strlen(bufR));
		close(motorL);
		close(motorR);
#endif
		std::cout << "FuncMotor::motorControlThread() CTRL_BACK" << std::endl;
	}

	}
}

