/**
* @file MouseSoulAppsForVS.cpp
* @brief マウスの魂
* @details マウスの魂
* 2018
*/

#include "stdafx.h"

#include <iostream>
#include <thread>

#include "Sub.h"

int main()
{
	std::cout << "main start" << std::endl;

	// イベントルーター(Mediator)
	EventRouter		eventRouter;

	// ファンクション(Colleague)
	FuncSensor	funcSensor;
	FuncMoter	funcMoter;
	FuncLed		funcLed;
	FuncSound	funcSound;
	FuncExcom	funcExcom;
	FuncAuto	funcAuto;

	// イベント(EventContainer)
	EventInfoSensorValue	eventSensorValue;
	EventCtrlSensorSwitch	eventSensorSwitch;
	EventCtrlMoterSwitch	eventMoterSwitch;
	EventCtrlLedControl		eventLedControl;
	EventCtrlSoundControl	eventSoundControl;
	EventCtrlExcomControl	eventExcomControl;
	EventCtrlAutoControl	eventAutoControl;

	// イベントリスナー登録
//	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcSensor);
	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcMoter);
	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcLed);
	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcSound);
	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcExcom);
	eventRouter.addEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcAuto);

	eventRouter.addEventListener(EventContainer::EVENT_CTRL_LED_CONTROL, &funcSensor);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_LED_CONTROL, &funcMoter);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_LED_CONTROL, &funcLed);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_LED_CONTROL, &funcSound);
//	eventRouter.addEventListener(EventContainer::EVENT_CTRL_LED_CONTROL, &funcExcom);
	eventRouter.addEventListener(EventContainer::EVENT_CTRL_LED_CONTROL, &funcAuto);

	// イベント配信先を登録
	funcSensor.setEventRouter(&eventRouter);
	funcExcom.setEventRouter(&eventRouter);

	// センサー機能スレッドを開始
	funcSensor.startMeasureSensor();
	funcExcom.startMeasureSensor();

	//	削除チェック
	// eventRouter.removeEventListener(EventContainer::EVENT_INFO_SENSOR_VALUE, &funcLed);

	// ループ
	Sub sub;
//	std::thread main_exec([&] { sub(); });
//	main_exec.join();
	
    return 0;
}

