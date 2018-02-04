/**
* @file EventCtrlAutoSwitch.cpp
* @brief 自走機能 開始／停止イベント
* @details 自走機能 開始／停止イベント
*/

#include "stdafx.h"

#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlAutoSwitch.h"

// コンストラクタ
EventCtrlAutoSwitch::EventCtrlAutoSwitch()
{
	setEventType(EVENT_CTRL_AUTO_SWITCH);
}

// デストラクタ
EventCtrlAutoSwitch::~EventCtrlAutoSwitch()
{
}

// シリアライズデータ設定
bool EventCtrlAutoSwitch::setSerializeString(std::string serializeString)
{
	std::cout << "EventCtrlAutoSwitch::setSerializeString() IN." << std::endl;

	// ヘッダチェック
	if(std::strcmp("EVENT_CTRL_AUTO_SWITCH", serializeString.c_str()) > 0) {
		std::cout << "EventCtrlAutoSwitch::setSerializeString() header error.." << std::endl;
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
		std::cout << "EventCtrlAutoSwitch::setSerializeString() size error.." << std::endl;
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
		std::cout << "EventCtrlAutoSwitch::setSerializeString() switch set error.." << std::endl;
	}

	std::cout << "EventCtrlAutoSwitch::setSerializeString() OUT." << std::endl;

	return true;
}

// シリアライズ文字列取得
std::string EventCtrlAutoSwitch::toSerializeString() const
{
	std::string	tmpStr;
	return tmpStr;
}

