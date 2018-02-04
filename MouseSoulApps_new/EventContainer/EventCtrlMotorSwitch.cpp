/**
* @file EventCtrlMotorSwitch.cpp
* @brief モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
* @details モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
*/

#include "stdafx.h"

#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlMotorSwitch.h"

// コンストラクタ
EventCtrlMotorSwitch::EventCtrlMotorSwitch()
{
	setEventType(EVENT_CTRL_MOTOR_SWITCH);
}

// デストラクタ
EventCtrlMotorSwitch::~EventCtrlMotorSwitch()
{
}

// シリアライズデータ設定
bool EventCtrlMotorSwitch::setSerializeString(std::string serializeString)
{
	std::cout << "EventCtrlMotorSwitch::setSerializeString() IN." << std::endl;

	// ヘッダチェック
	if(std::strcmp("EVENT_CTRL_MOTOR_SWITCH", serializeString.c_str()) > 0) {
		std::cout << "EventCtrlMotorSwitch::setSerializeString() header error.." << std::endl;
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
		std::cout << "EventCtrlMotorSwitch::setSerializeString() size error.." << std::endl;
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
		std::cout << "EventCtrlMotorSwitch::setSerializeString() switch set error.." << std::endl;
	}

	std::cout << "EventCtrlMotorSwitch::setSerializeString() OUT." << std::endl;

	return true;
}

// シリアライズ文字列取得
std::string EventCtrlMotorSwitch::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
