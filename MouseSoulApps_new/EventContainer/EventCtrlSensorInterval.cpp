/**
* @file EventCrltSensorInterval.cpp
* @brief 距離センサー読み取り間隔 設定イベント
* @details 距離センサー読み取り間隔 設定イベント
*/

#include "stdafx.h"

#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlSensorInterval.h"

// コンストラクタ
EventCtrlSensorInterval::EventCtrlSensorInterval()
{
	setEventType(EVENT_CTRL_SENSOR_INTERVAL);
}

EventCtrlSensorInterval::EventCtrlSensorInterval(bool sw):EventContainer(sw)
{
	EventCtrlSensorInterval();
}

// デストラクタ
EventCtrlSensorInterval::~EventCtrlSensorInterval()
{
}

// シリアライズデータ設定
bool EventCtrlSensorInterval::setSerializeString(std::string serializeString)
{
	std::cout << "EventCtrlSensorInterval::setSerializeString() IN." << std::endl;

	// ヘッダチェック
	if(std::strcmp("EVENT_CTRL_SENSOR_INTERVAL", serializeString.c_str()) > 0) {
		std::cout << "EventCtrlSensorInterval::setSerializeString() header error.." << std::endl;
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
		std::cout << "EventCtrlSensorInterval::setSerializeString() size error.." << std::endl;
		return false;
	}

	// インターバル値を取得
	std::string tmpStr = v.at(1);
	int interval = std::atoi(tmpStr.c_str());
	setData(interval);

	std::cout << "EventCtrlSensorInterval::setSerializeString() OUT." << std::endl;
}

// シリアライズ文字列取得
std::string EventCtrlSensorInterval::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}
