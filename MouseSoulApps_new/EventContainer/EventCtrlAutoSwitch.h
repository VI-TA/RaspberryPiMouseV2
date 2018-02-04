#pragma once
#ifndef _EVENT_CTRL_AUTO_SWITCH_H
#define _EVENT_CTRL_AUTO_SWITCH_H

/**
* @file EventCtrlAutoSwitch.h
* @brief 自走機能 開始／停止イベント
* @details 自走機能 開始／停止イベント
*/

class EventContainer;

class EventCtrlAutoSwitch : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlAutoSwitch();

	// デストラクタ
	~EventCtrlAutoSwitch();

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:


};

#endif	// _EVENT_CTRL_AUTO_SWITCH_H
