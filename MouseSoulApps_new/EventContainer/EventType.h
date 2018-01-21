#pragma once
#ifndef _EVENT_TYPE_H
#define _EVENT_TYPE_H

/**
* @file EventType.h
* @brief イベントタイプ定義
* @details イベントタイプ定義
*/

#if 0

//! イベントタイプ
enum EVENT_TYPE {
	EVENT_INFO_SENSOR_VALUE,			//!< [情報] センサー値情報
	EVENT_CTRL_MOTER_CONTROL,			//!< [情報] モーター制御
	EVENT_CTRL_MOTER_SWITCH,			//!< [制御] モータースイッチ制御 
	EVENT_CTRL_LED_CONTROL,				//!< [制御] LED制御
	EVENT_CTRL_SOUND_CONTROL,			//!< [制御] 音源制御
	EVENT_CTRL_REMOTE_CONTROL,			//!< [制御] ？？？？
	EVENT_CTRL_AUTO_CONTROL,			//!< [制御] ？？？？
};

#endif

#endif	// _EVENT_TYPE_H
