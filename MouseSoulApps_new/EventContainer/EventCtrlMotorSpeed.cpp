/**
* @file EventCtrlMotorSpeed.cpp
* @brief モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
* @details モーターソフトウェアスイッチ ＯＮ／ＯＦＦイベント
*/

#include "stdafx.h"

#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlMotorSpeed.h"

// コンストラクタ
EventCtrlMotorSpeed::EventCtrlMotorSpeed()
{
	setEventType(EVENT_CTRL_MOTOR_SPEED);
}

// デストラクタ
EventCtrlMotorSpeed::~EventCtrlMotorSpeed()
{
}

// シリアライズデータ設定
bool EventCtrlMotorSpeed::setSerializeString(std::string serializeString)
{
	std::cout << "EventCtrlMotorSpeed::setSerializeString() IN." << std::endl;

	// ヘッダチェック
	if(std::strcmp("EVENT_CTRL_MOTOR_SPEED", serializeString.c_str()) > 0) {
		std::cout << "EventCtrlMotorSpeed::setSerializeString() header error.." << std::endl;
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
		std::cout << "EventCtrlMotorSpeed::setSerializeString() size error.." << std::endl;
		return false;
	}

	// モータースピード取得
	std::string tmpStr = v.at(1);
	int speed = std::atoi(tmpStr.c_str());
	setData(speed);

	std::cout << "EventCtrlMotorSpeed::setSerializeString() OUT." << std::endl;

	return true;
}

// シリアライズ文字列取得
std::string EventCtrlMotorSpeed::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
