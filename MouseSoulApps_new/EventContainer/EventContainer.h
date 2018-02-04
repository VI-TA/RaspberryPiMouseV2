/**
* @file EventContainer.h
* @brief イベントコンテナ基底クラスヘッダ
* @details イベントコンテナ基底クラスヘッダ
*/

#pragma once
#ifndef _EVENT_CONTAINER_H
#define _EVENT_CONTAINER_H

#include <string>
#include <vector>

/**
* @brief イベントコンテナ基底クラス
* @details 1) データ設定メソッドは隠ぺいし、外部からの直接なデータ変更は不可とする。
* @details 2) データ設定はコンストラクタで行う。
* @details 3) コンストラクタは継承クラスで必要な型のみ定義する。
* @details 4) データ取得メソッドは継承クラスで任意に再定義する。
* @details 
*/
class EventContainer
{
public:
	//! イベントタイプ
	enum EVENT_TYPE {
		EVENT_INFO_SENSOR_VALUE,			//!< [情報] センサー値配信イベント
		EVENT_CTRL_SENSOR_SWITCH,			//!< [制御] センサースイッチ制御イベント
		EVENT_CTRL_SENSOR_INTERVAL,			//!< [制御] センサー値インターバルイベント
		EVENT_CTRL_MOTOR_CONTROL,			//!< [情報] モーター制御イベント
		EVENT_CTRL_MOTOR_SWITCH,			//!< [制御] モータースイッチ制御イベント
		EVENT_CTRL_MOTOR_SPEED,				//!< [制御] モータースピード制御イベント
		EVENT_CTRL_LED_CONTROL,				//!< [制御] LED制御イベント
		EVENT_CTRL_SOUND_CONTROL,			//!< [制御] 音源制御イベント
		EVENT_CTRL_EXCOM_CONTROL,			//!< [制御] 外部通信制御イベント
		EVENT_CTRL_AUTO_SWITCH,				//!< [制御] 自走スイッチイベント
		EVENT_CTRL_AUTO_CONTROL,			//!< [制御] 自走制御イベント
	};
	
	//! コンストラクタ
	EventContainer();						//!< 空データイベント
	EventContainer(bool data);
	EventContainer(int data);
	EventContainer(unsigned long data);
	EventContainer(float data);
	EventContainer(std::vector<int> data);
	EventContainer(std::vector<unsigned long> data);
	EventContainer(std::vector<float> data);
	EventContainer(std::string data);

	//! デストラクタ
	virtual ~EventContainer();

	//! イベントタイプ取得
	EVENT_TYPE	getEventType() const;

	//! シリアライズデータ設定
	virtual bool setSerializeString(std::string serializeString)=0;

	//! データ取得メソッド
	virtual bool						toBool(void) const;
	virtual int							toInt(void) const;
	virtual unsigned long				toULong(void) const;
	virtual float						toFloat(void) const;
	virtual std::vector<int>			toIntArray(void) const;
	virtual std::vector<unsigned long>	toULongArray(void) const;
	virtual std::vector<float>			toFloatArray(void) const;
	virtual std::string					toString(void) const;
	virtual std::string					toSerializeString(void) const;
	
	//! [DEBUG] イベント名表示
	void	printEventName(EVENT_TYPE) const;

	//! データ設定メソッド
	void setData(bool data);
	void setData(int data);
	void setData(unsigned long data);
	void setData(float data);
	void setData(std::vector<int> data);
	void setData(std::vector<unsigned long> data);
	void setData(std::vector<float> data);
	void setData(std::string data);
private:

	//! イベントタイプ
	EVENT_TYPE	m_type;

	//! 保存データ型
	bool						m_bool;				//!< BOOLEAN
	int							m_int;				//!< INTEGER
	unsigned long				m_uLong;			//!< UNSIGNED LONG
	float						m_float;			//!< FLOAT
	std::vector<int>			m_intArray;			//!< INTEGER ARRAY
	std::vector<unsigned long>	m_uLontArray;		//!< UNSIGNED LONG ARRAY
	std::vector<float>			m_floatArray;		//!< FLOAT ARRAY
	std::string					m_string;			//!< STRING

	std::string					m_serializeStr;		//!< SERIALIZE STRING
protected:

	void setEventType(EVENT_TYPE type);

};

#endif	// _EVENT_CONTAINER_H
