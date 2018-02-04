#pragma once
#ifndef _EVENT_CTRL_AUTO_CONTROL_H
#define _EVENT_CTRL_AUTO_CONTROL_H

/**
* @file EventCtrlAutoControl.h
* @brief 自走機能制御イベント
* @details 自走機能制御イベント
*/

class EventContainer;

class EventCtrlAutoControl : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlAutoControl();

	// デストラクタ
	~EventCtrlAutoControl();

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:


};

#endif	// _EVENT_CTRL_AUTO_CONTROL_H
