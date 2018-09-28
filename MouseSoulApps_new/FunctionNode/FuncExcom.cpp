/**
* @file FuncExcom.cpp
* @brief 外部通信制御
* @details 外部通信制御
*/

#include "stdafx.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "FunctionNode.h"
#include "FuncExcom.h"
#include "FuncExcom.h"

#include "EventContainer.h"
#include "EventFactory.h"
//#include "EventCtrlSensorSwitch.h"
////#include "EventInfoSensorValue.h"
////#include "EventCtrlLedControl.h"



// コンストラクタ
FuncExcom::FuncExcom()
{
	m_threadState = false;	// スレッド停止
	m_sendState = false;
}

// デストラクタ
FuncExcom::~FuncExcom()
{
}

/**
* @fn void FuncExcom::setEventRouter(EventRouterBase *pEventRouter)
* @brief 通信設定
* @param[in]
* @param[out]
* @return bool true:通信設定成功、false:通信設定失敗 
* @sa
* @details
*/
bool FuncExcom::startExCom()
{
	std::cout << "FuncExcom::startExCom() IN" << std::endl;

	// 通信設定
	signal(SIGPIPE, SIG_IGN);       // SIGPIPEシグナルを無視する

	std::cout << "FuncExcom::startExCom() create socket" << std::endl;

	// ソケットの作成
	m_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if(m_socket < 0) {
		perror("socket");
		std::cout << "FuncExcom::startExCom() socket error" << "[" << errno << "]" << std::endl;
		return false;
	}

	/* ソケットの設定 */
	m_serverInfo.sin_family = AF_INET;
	m_serverInfo.sin_port = htons(49152);
	m_serverInfo.sin_addr.s_addr = INADDR_ANY;

	// バインドする
	if(bind(m_socket, (struct sockaddr *)&m_serverInfo, sizeof(m_serverInfo)) < 0) {
		perror("bind");
		std::cout << "FuncExcom::startExCom() bind error" << "[" << errno << "]" << std::endl;
		return false;
	}

	std::cout << "FuncExcom::startExCom() bind ok!!" << std::endl;

	std::cout << "FuncExcom::startExCom() create socket complite!!" << std::endl;

	// スレッド起動
	m_threadState = true;	// スレッド開始
	m_recvThread = std::thread(&FuncExcom::recvThread, this);
	m_sendThread = std::thread(&FuncExcom::sendThread, this);

	return true;
}

/**
* @fn void FuncExcom::setEventRouter(EventRouterBase *pEventRouter)
* @brief イベントルータークラス登録
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
void FuncExcom::setEventRouter(EventRouterBase *pEventRouter)
{
	// 独自処理定義

	// 基底クラスへ通知
	FunctionNode::setEventRouter(pEventRouter);
}

/**
* @fn void FuncExcom::sendThread()
* @brief イベントハンドラ
* @param[in] EventContainer* イベントコンテナ
* @param[out]
* @return
* @sa
* @details
*/
void FuncExcom::eventHandler(const EventContainer *pEc)
{
	std::cout << "FuncExcom::eventHandler" << "[" << pEc->getEventType() << "]" << std::endl;

	// センサー読み取り値
	if (EventContainer::EVENT_INFO_SENSOR_VALUE == pEc->getEventType()) {

		std::lock_guard<std::mutex> uniq_lk(mtx);
		m_serializeStr = pEc->toSerializeString();
		m_sendState = true;
		cv.notify_all();

		std::cout << "FuncExcom::eventHandler()" << std::endl;
	}
}

/**
* @fn void FuncExcom::recvThread()
* @brief Ethernetデータ受信スレッド
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
void FuncExcom::recvThread()
{
	std::cout << "FuncExcom::recvThread() IN" << std::endl;

	while(1) {
		memset(m_recBuff, 0, sizeof(m_recBuff));

		// パケット受信、パケットが到着するまでブロック
		unsigned int len = sizeof(m_clientInfo);
		if(recvfrom(m_socket, m_recBuff, sizeof(m_recBuff), 0, (struct sockaddr *)&m_clientInfo, &len) < 0) {
			perror("recv");
			std::cout << "FuncExcom::recvThread() read error" << "[" << errno << "]" << std::endl;
			return;
//			pthread_exit(0);
		}

		std::cout << "FuncExcom::recvThread()" << m_recBuff << std::endl;	

		// シリアライズデータをイベントコンテナ型に変換する。
		EventFactory	ef;
		EventContainer	*ec;
		ec = ef.createEvent(m_recBuff);
		if(NULL != ec) {
			// イベントコンテナ型への変換に成功後に配信する。
			std::cout << "FuncExcom::recvThread() eventThrow" << std::endl;
			eventThrow(ec);
			delete ec;
		}
	}

	std::cout << "FuncExcom::recvThread() OUT" << std::endl;
}

/**
* @fn void FuncExcom::sendThread()
* @brief Ethernetデータ送信スレッド
* @param[in]
* @param[out]
* @return
* @sa
* @details
*/
void FuncExcom::sendThread()
{
	std::cout << "FuncExcom::sendThread() thread start !!" << std::endl;

	while(1) {
		const char	*pChar;

		// wait
		std::unique_lock<std::mutex> uniq_lk(mtx);
		cv.wait(uniq_lk, [this] { return m_sendState; });
		m_sendState = false;
		// wait

		struct sockaddr_in info;
		info.sin_family = AF_INET;
		info.sin_port = htons(49152);
		info.sin_addr.s_addr = inet_addr("192.168.12.18");

		pChar = m_serializeStr.c_str();

		if(sendto(m_socket, pChar, strlen(pChar), 0, (struct sockaddr *)&info, sizeof(info)) < 0) {
			perror("recv");
			std::cout << "FuncExcom::sendThread() sendto error" << "[" << errno << "]" << std::endl;
		}

		std::cout << "FuncExcom::sendThread() thread sended !!" << std::endl;

	}
}

