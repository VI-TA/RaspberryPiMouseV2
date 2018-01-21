/**
* @file FuncExcom.cpp
* @brief 外部通信制御
* @details 外部通信制御
*/

#include "stdafx.h"

#include <iostream>
#include <thread>

#include "FunctionNode.h"
#include "FuncExcom.h"
#include "FuncExcom.h"

#include "EventContainer.h"
#include "EventInfoSensorValue.h"
#include "EventCtrlLedControl.h"

// コンストラクタ
FuncExcom::FuncExcom()
{
	m_threadState = false;	// スレッド停止
}

// デストラクタ
FuncExcom::~FuncExcom()
{
}

void FuncExcom::startMeasureSensor()
{
	m_threadState = true;	// スレッド開始
	m_thread = std::thread(&FuncExcom::measureSensor, this);
}

// イベントルータークラス登録
void FuncExcom::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

void FuncExcom::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncExcom::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;
	pEc->printEventName(pEc->getEventType());
}

void FuncExcom::measureSensor()
{
	char buf[50];
	int sensor;
	int data[4];

	while (1)
	{
		EventCtrlLedControl ev;
		std::cout << "FuncExcom event throw!!" << std::endl;
		eventThrow(&ev);

		std::this_thread::sleep_for(std::chrono::seconds(1));
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}