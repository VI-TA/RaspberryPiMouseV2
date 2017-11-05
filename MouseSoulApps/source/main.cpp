/**
* @file main.cpp
* @brief マイクロマウス制御メイン
* @details マイクロマウス制御メイン
*/

#include <stdio.h>
#include "Mediator.h"
#include "MediEventRouter.h"
#include "Colleague.h"
#include "CollSensor.h"
#include "CollMoter.h"
#include "CollLed.h"
#include "CollSound.h"
#include "CollRemote.h"
#include "CollAuto.h"
#include "EventContainer.h"
#include "EventSensor.h"
#include "EventMoter.h"
#include "EventLed.h"
#include "EventSound.h"
#include "EventRemote.h"
#include "EventAuto.h"
#include "EventType.h"

int main()
{
	// イベントルーター(Mediator)
	MediEventRouter	medi;

	// ファンクション(Colleague)
	CollSensor	collSensor;
	CollMoter	collMoter;
	CollLed		collLed;
	CollSound	collSound;
	CollRemote	collRemote;
	CollAuto	collAuto;

	// イベント(EventContainer)
	EventSensor	eventSensor;	
	EventMoter	eventMoter;
	EventLed	eventLed;
	EventSound	eventSound;
	EventRemote	eventRemote;
	EventAuto	eventAuto;

	eventSensor.setEventType(EVENT_SENSOR_VALUE);
	eventMoter.setEventType(EVENT_MOTER_CONTROL);
	eventLed.setEventType(EVENT_LED_CONTROL);
	eventSound.setEventType(EVENT_SOUND_CONTROL);
	eventRemote.setEventType(EVENT_REMOTE_CONTROL);
	eventAuto.setEventType(EVENT_AUTO_CONTROL);
	eventSensor.setSensorValue(10,20,30,40);

#if 1
	// センサーファンクションにルータのポインタを設定
	collSensor.setMediator(&medi);
	// センサーファンクションからルータにイベントリスナー登録
	collSensor.test1();
	// モーターイベントを配信してみる。
	medi.eventThrow(&eventMoter);
	// ★ センサーファンクションのイベントハンドラに届けばOK


	// センサーイベントがモータファンクションに届くよう設定
	medi.addEventListener(EVENT_SENSOR_VALUE, &collMoter);
	collSensor.test2();
	// ★ モータファンクションのイベントハンドラにセンサーイベントが届けばOK
#else
	// ファンクションをルータのイベントリスナーに登録
	//   ファンクション自身のポインタと、
	//   配信して欲しいイベントタイプを登録する。
	//   本来は、ファンクションにルータのポインタを登録して
	//   ファンクション内からリスナー登録すべし。
	medi.addEventListener(EVENT_SENSOR_VALUE, &collSensor);
	medi.addEventListener(EVENT_MOTER_CONTROL, &collSensor);
	medi.addEventListener(EVENT_MOTER_CONTROL, &collMoter);
	medi.addEventListener(EVENT_LED_CONTROL, &collLed);
	medi.addEventListener(EVENT_SOUND_CONTROL, &collSound);
	medi.addEventListener(EVENT_REMOTE_CONTROL, &collRemote);
	medi.addEventListener(EVENT_LED_CONTROL, &collRemote);
	medi.addEventListener(EVENT_AUTO_CONTROL, &collAuto);

	printf("-- SENSOR EVENT--\n");
	medi.eventThrow(&eventSensor);

	printf("-- MOTER EVENT--\n");
	medi.eventThrow(&eventMoter);

	printf("-- LED EVENT--\n");
	medi.eventThrow(&eventLed);

	printf("-- SOUND EVENT--\n");
	medi.eventThrow(&eventSound);

	printf("-- REMOTE EVENT--\n");
	medi.eventThrow(&eventRemote);

	printf("-- AUTO EVENT--\n");
	medi.eventThrow(&eventAuto);

	printf("----\n");
	printf("Hello world!!\n");
#endif
	return 0;
}

