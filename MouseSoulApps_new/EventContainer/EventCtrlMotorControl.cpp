/**
* @file EventCtrlMotorControl.cpp
* @brief モーター制御イベント
* @details モーター制御イベント
*/

#include "stdafx.h"

#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>

#include "EventContainer.h"
#include "EventCtrlMotorControl.h"

// コンストラクタ
EventCtrlMotorControl::EventCtrlMotorControl()
{
	setEventType(EVENT_CTRL_MOTOR_CONTROL);
}

// デストラクタ
EventCtrlMotorControl::~EventCtrlMotorControl()
{
}

void EventCtrlMotorControl::setMotorCommand(int command)
{
	// 入力値チェック
	if(EventCtrlMotorControl::BEGIN <= command &&
	   EventCtrlMotorControl::END >= command) {
		// モーター制御コマンド設定
		m_command = command;
	} else {
		// コマンド値外
		// 暴走抑止のためモーターを止める。
		m_command = CTRL_STOP;
	}

	setData(m_command);
}

int EventCtrlMotorControl::getMotorCommand(void)
{
	return m_command;
}

// シリアライズデータ設定
bool EventCtrlMotorControl::setSerializeString(std::string serializeString)
{
    std::cout << "EventCtrlMotorControl::setSerializeString() IN." << std::endl;

    // ヘッダチェック
    if(std::strcmp("EVENT_CTRL_MOTOR_CONTROL", serializeString.c_str()) > 0) {
        std::cout << "EventCtrlMotorControl::setSerializeString() header error.." << std::endl;
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
        std::cout << "EventCtrlMotorControl::setSerializeString() size error.." << std::endl;
        return false;
    }

    // スイッチを取得
    std::string tmpStr = v.at(1);
    if(std::strcmp("STOP", tmpStr.c_str()) == 0) {
		m_command = CTRL_STOP;
		setData(m_command);
    }else
    if(std::strcmp("FORWARD", tmpStr.c_str()) == 0) {
		m_command = CTRL_FORWARD;
		setData(m_command);
    }else
    if(std::strcmp("BACK", tmpStr.c_str()) == 0) {
		m_command = CTRL_BACK;
		setData(m_command);
    }else
    if(std::strcmp("RIGHT", tmpStr.c_str()) == 0) {
		m_command = CTRL_RIGHT_TRUN;
		setData(m_command);
    }else
    if(std::strcmp("LEFT", tmpStr.c_str()) == 0) {
		m_command = CTRL_LEFT_TRUN;
		setData(m_command);
    }else{
        std::cout << "EventCtrlMotorControl::setSerializeString() switch set error.." << std::endl;
    }

    std::cout << "EventCtrlMotorControl::setSerializeString() OUT." << std::endl;

	return true;
}

// シリアライズ文字列取得
std::string EventCtrlMotorControl::toSerializeString() const
{
	std::string	tmpStr;

	tmpStr = "EVENT_CTRL_MOTOR_CONTROL,";
	switch(m_command)
	{
		case CTRL_STOP:
			tmpStr += "STOP";
			break;
        case CTRL_FORWARD:
			tmpStr += "FORWARD";
			break;
        case CTRL_BACK: 
			tmpStr += "BACK";
			break;
        case CTRL_RIGHT_TRUN:
			tmpStr += "RIGHT";
			break;
        case CTRL_LEFT_TRUN:
			tmpStr += "LEFT";
			break;
		default:
			break;
	}

	return tmpStr;
}
