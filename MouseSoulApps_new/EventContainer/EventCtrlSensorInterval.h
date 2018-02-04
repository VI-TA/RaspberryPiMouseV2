#pragma once
#ifndef _EVENT_CTRL_SENSOR_INTERVAL_H
#define _EVENT_CTRL_SENSOR_INTERVAL_H

/**
* @file EventCrltSensorInterval.h
* @brief 距離センサー読み取り間隔設定ヘッダファイル
* @details 距離センサー読み取り間隔を設定する。
*/

#include "EventType.h"

class EventContainer;

class EventCtrlSensorInterval : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlSensorInterval();
	EventCtrlSensorInterval(bool sw);

	// デストラクタ
	~EventCtrlSensorInterval();

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:
};

#endif	// _EVENT_CTRL_SENSOR_INTERVAL_H
