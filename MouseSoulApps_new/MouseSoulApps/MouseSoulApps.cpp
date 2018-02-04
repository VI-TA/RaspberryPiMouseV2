/**
* @file MouseSoulAppsForVS.cpp
* @brief マウスの魂
* @details マウスの魂
*/

#include "stdafx.h"

#include <iostream>
#include <thread>

#include "Sub.h"

int main()
{
	std::cout << "main start" << std::endl;

	// --------------------------------------------------------------------------------
	// イベントルーター(Mediator)
	// --------------------------------------------------------------------------------

	EventRouter		eventRouter;

	// --------------------------------------------------------------------------------
	// ファンクション(Colleague)
	// --------------------------------------------------------------------------------

	FuncSensor	funcSensor;
	FuncMotor	funcMotor;
	FuncLed		funcLed;
	FuncSound	funcSound;
	FuncExcom	funcExcom;
	FuncAuto	funcAuto;

	// --------------------------------------------------------------------------------
	// イベントリスナー登録
	// --------------------------------------------------------------------------------
	// センサースイッチ
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_SENSOR_SWITCH,   &funcSensor);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_SENSOR_INTERVAL, &funcSensor);
	// センサー読み取り値
	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE,    &funcExcom);
	// モーター制御
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_MOTOR_CONTROL,   &funcMotor);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_MOTOR_SWITCH,    &funcMotor);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_MOTOR_SPEED ,    &funcMotor);
	// 自動モード切り替え
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_AUTO_SWITCH ,    &funcAuto);

	// --------------------------------------------------------------------------------
	// イベント配信先を登録
	// --------------------------------------------------------------------------------

	funcSensor.setEventRouter(&eventRouter);
	funcExcom.setEventRouter(&eventRouter);


	funcExcom.startExCom();

	//	削除チェック
	// eventRouter.removeEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcLed);

	// ループ
	Sub sub;

    return 0;
}

