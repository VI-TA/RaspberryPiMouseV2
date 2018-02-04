/**
* @file EventFactory.cpp
* @brief 
* @details 
*/

#include "stdafx.h"

#include <cstring>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlExcomControl.h"
#include "EventCtrlAutoControl.h"
#include "EventCtrlAutoSwitch.h"
#include "EventCtrlLedControl.h"
#include "EventCtrlMotorControl.h"
#include "EventCtrlMotorSwitch.h"
#include "EventCtrlMotorSpeed.h"
#include "EventCtrlSensorSwitch.h"
#include "EventInfoSensorValue.h"
#include "EventCtrlSensorInterval.h"
#include "EventCtrlSoundControl.h"
#include "EventFactory.h"

//! コンストラクタ
EventFactory::EventFactory()
{


}

//! デストラクタ
EventFactory::~EventFactory()
{
}

// char版
EventContainer* EventFactory::createEvent(char *serializeString)
{
	std::string tmpString = serializeString;
	return createEvent(tmpString);
}

// std::string版
EventContainer* EventFactory::createEvent(std::string serializeString)
{
	EventContainer *pEventContainer = NULL;

	std::cout << "EventFactory::createEvent() : IN" << std::endl;

	//!< [情報] センサー値配信イベント
	if(std::strncmp("EVENT_INFO_SENSOR_VALUE", serializeString.c_str(), strlen("EVENT_INFO_SENSOR_VALUE")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_INFO_SENSOR_VALUE" << std::endl;

		EventInfoSensorValue *event = new EventInfoSensorValue();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] センサースイッチ制御イベント
	if(std::strncmp("EVENT_CTRL_SENSOR_SWITCH", serializeString.c_str(), strlen("EVENT_CTRL_SENSOR_SWITCH")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_SENSOR_SWITCH" << std::endl;

		EventCtrlSensorSwitch *event = new EventCtrlSensorSwitch();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] センサー読み取り間隔設定イベント
	if(std::strncmp("EVENT_CTRL_SENSOR_INTERVAL", serializeString.c_str(), strlen("EVENT_CTRL_SENSOR_INTERVAL")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_SENSOR_INTERVAL" << std::endl;

		EventCtrlSensorInterval *event = new EventCtrlSensorInterval();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [情報] モーター制御イベント
	if(std::strncmp("EVENT_CTRL_MOTOR_CONTROL", serializeString.c_str(), strlen("EVENT_CTRL_MOTOR_CONTROL")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_MOTOR_CONTROL" << std::endl;

		EventCtrlMotorControl *event = new EventCtrlMotorControl();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] モータースイッチ制御イベント
	if(std::strncmp("EVENT_CTRL_MOTOR_SWITCH", serializeString.c_str(), strlen("EVENT_CTRL_MOTOR_SWITCH")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_MOTOR_SWITCH" << std::endl;

		EventCtrlMotorSwitch *event = new EventCtrlMotorSwitch();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] モータースピード
	if(std::strncmp("EVENT_CTRL_MOTOR_SPEED", serializeString.c_str(), strlen("EVENT_CTRL_MOTOR_SPEED")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_MOTOR_SPEED" << std::endl;

		EventCtrlMotorSpeed *event = new EventCtrlMotorSpeed();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] LED制御イベント
	if(std::strncmp("EVENT_CTRL_LED_CONTROL", serializeString.c_str(), strlen("EVENT_CTRL_LED_CONTROL")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_LED_CONTROL" << std::endl;

		EventCtrlLedControl *event = new EventCtrlLedControl();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] 音源制御イベント
	if(std::strncmp("EVENT_CTRL_SOUND_CONTROL", serializeString.c_str(), strlen("EVENT_CTRL_SOUND_CONTROL")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_SOUND_CONTROL" << std::endl;

		EventCtrlSoundControl *event = new EventCtrlSoundControl();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] 外部通信制御イベント
	if(std::strncmp("EVENT_CTRL_EXCOM_CONTROL", serializeString.c_str(), strlen("EVENT_CTRL_EXCOM_CONTROL")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_EXCOM_CONTROL" << std::endl;

		EventCtrlExcomControl *event = new EventCtrlExcomControl();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] 自走スイッチイベント
	if(std::strncmp("EVENT_CTRL_AUTO_SWITCH", serializeString.c_str(), strlen("EVENT_CTRL_AUTO_SWITCH")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_AUTO_SWITCH" << std::endl;

		EventCtrlAutoSwitch *event = new EventCtrlAutoSwitch();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	}else
	//!< [制御] 自走制御イベント
	if(std::strncmp("EVENT_CTRL_AUTO_CONTROL", serializeString.c_str(), strlen("EVENT_CTRL_AUTO_CONTROL")) == 0) {
		std::cout << "EventFactory::createEvent() : EVENT_CTRL_AUTO_CONTROL" << std::endl;

		EventCtrlAutoControl *event = new EventCtrlAutoControl();
		event->setSerializeString(serializeString);
		pEventContainer = (EventContainer *)event;
	} else {
		// 該当イベント無し
		std::cout << "EventFactory::createEvent() no hit event." << std::endl;
		return pEventContainer;
	}

	std::cout << "EventFactory::createEvent() : OUT" << std::endl;

	return pEventContainer;
}

