#include <stdio.h>
#include <pthread.h>
#include "Mediator.h"
#include "Colleague.h"
#include "CollSensor.h"
#include "EventContainer.h"
#include "EventSensor.h"

CollSensor::CollSensor()
{
}

void CollSensor::eventHandler(EventContainer *pEc)
{
	int left, leftCenter, rightCenter, right;
	EventSensor *pEs;

	pEc->printEventName(pEc->getEventType());

	// センサー測定値イベントの場合は値を表示
	if(pEc->getEventType() == EVENT_SENSOR_VALUE) {
		pEs = dynamic_cast<EventSensor*>(pEc);
		if(pEs == NULL) {
			printf("ERROR dynamic_cat ¥n");
		}
		pEs->getSensorValue(left, leftCenter, rightCenter, right);
		printf("CollSensor::eventHandler Value[%d][%d][%d][%d]\n",
			left, leftCenter, rightCenter, right
		);
	} else {
		printf("CollSensor::eventHandler\n");
	}
}

void CollSensor::measureSensor()
{
}

void CollSensor::test1()
{
	printf("test1\n");
	// [DEBUG] モータイベントをリスナーに登録する。
	Colleague::pMediator->addEventListener(EVENT_MOTER_CONTROL, this);
}

void CollSensor::test2()
{
        EventSensor     eventSensor;

	printf("test2\n");

        eventSensor.setEventType(EVENT_SENSOR_VALUE);
	// [DEBUG] モータイベントをリスナーに登録する。
	pMediator->eventThrow(&eventSensor);
}
