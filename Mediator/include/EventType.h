#pragma once
#ifndef _EVENT_TYPE_H
#define _EVENT_TYPE_H

/**
* @file EventType.h
* @brief イベントタイプ定義
* @details イベントタイプ定義
*/

// イベントタイプ
enum EVENT_TYPE {
	EVENT_SENSOR_VALUE,
	EVENT_MOTER_SWITCH,
	EVENT_MOTER_CONTROL,
	EVENT_LED_CONTROL,
	EVENT_SOUND_CONTROL,
	EVENT_REMOTE_CONTROL,
	EVENT_AUTO_CONTROL,
};

#endif	// _EVENT_TYPE_H
