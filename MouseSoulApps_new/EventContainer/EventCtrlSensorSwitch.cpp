/**
* @file EventCrltSensorSwitch.cpp
* @brief 距離センサー読み取り 開始／停止イベント
* @details 距離センサー読み取り 開始／停止イベント
*/

#include "stdafx.h"

#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlSensorSwitch.h"

// コンストラクタ
EventCtrlSensorSwitch::EventCtrlSensorSwitch()
{
	setEventType(EVENT_CTRL_SENSOR_SWITCH);
}

EventCtrlSensorSwitch::EventCtrlSensorSwitch(bool sw):EventContainer(sw)
{
	EventCtrlSensorSwitch();
}

// デストラクタ
EventCtrlSensorSwitch::~EventCtrlSensorSwitch()
{
}

// シリアライズデータ設定
bool EventCtrlSensorSwitch::setSerializeString(std::string serializeString)
{
	std::cout << "EventCtrlSensorSwitch::setSerializeString() IN." << std::endl;

	// ヘッダチェック
	if(std::strcmp("EVENT_CTRL_SENSOR_SWITCH", serializeString.c_str()) > 0) {
		std::cout << "EventCtrlSensorSwitch::setSerializeString() header error.." << std::endl;
		return false;
	}

	// ","による分割
	std::vector<std::string> v;
	std::stringstream ss(serializeString);
	std::string buffer;
	while(std::getline(ss, buffer, ',')) {
		v.push_back(buffer);
	}

	//
	if(2 < v.size()) {
		// 件数が多い
		std::cout << "EventCtrlSensorSwitch::setSerializeString() size error.." << std::endl;
		return false;
	}

	// スイッチを取得
	std::string tmpStr = v.at(1);
	if(std::strcmp("ON", tmpStr.c_str()) == 0) {
		setData(true);
	}else
	if(std::strcmp("OFF", tmpStr.c_str()) == 0) {
		setData(false);
	}else{
		std::cout << "EventCtrlSensorSwitch::setSerializeString() switch set error.." << std::endl;
	}

	std::cout << "EventCtrlSensorSwitch::setSerializeString() OUT." << std::endl;

	return true;
}

// シリアライズ文字列取得
std::string EventCtrlSensorSwitch::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
