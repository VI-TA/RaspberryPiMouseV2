#pragma once
#ifndef _EVENT_CTRL_SENSOR_SWITCH_H
#define _EVENT_CTRL_SENSOR_SWITCH_H

/**
* @file EventCrltSensorSwitch.h
* @brief 距離センサー制御ヘッダファイル
* @details 距離センサー計測開始／停止を制御する。
*/

#include "EventType.h"

class EventContainer;

class EventCtrlSensorSwitch : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlSensorSwitch();
	EventCtrlSensorSwitch(bool sw);

	// デストラクタ
	~EventCtrlSensorSwitch();

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:
	// センサー測定値(左センサー）
	int m_left;

	// センサー測定値(中央左センサー）
	int m_leftCenter;

	// センサー測定値(中央右センサー）
	int m_rightCenter;

	// センサー測定値(右センサー）
	int m_right;
};

#endif	// _EVENT_CTRL_SENSOR_SWITCH_H
