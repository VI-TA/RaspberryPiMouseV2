#pragma once
#ifndef _EVENT_CTRL_SOUND_CONTROL_H
#define _EVENT_CTRL_SOUND_CONTROL_H

/**
* @file EventCtrlSoundControl.h
* @brief 音源制御イベント
* @details 音源制御イベント
*/

#include <vector>
#include "EventType.h"

class EventContainer;

class EventCtrlSoundControl : public EventContainer
{
public:
	// コンストラクタ
	EventCtrlSoundControl();

	// デストラクタ
	~EventCtrlSoundControl();

	// 楽譜登録
	void setSoundScore(std::vector<int> score);

	// 楽譜取得
	std::vector<int> getSoundScore(void);

        //! シリアライズデータ設定
        virtual bool setSerializeString(std::string serializeString);

	// シリアライズ文字列
	virtual std::string	toSerializeString(void) const;
private:
	// 楽譜
	std::vector<int> m_score;
};

#endif	// _EVENT_CTRL_SOUND_CONTROL_H
