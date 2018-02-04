#pragma once
#ifndef _FUNC_EXCOM_H
#define _FUNC_EXCOM_H

/**
* @file FuncExcom.h
* @brief リモート制御
* @details リモート制御
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#include <thread>
#include <mutex>
#include <condition_variable>

class FunctionNode;
class EventContainer;

class FuncExcom : public FunctionNode
{
public:
	//! コンストラクタ
	FuncExcom();

	//! デストラクタ
	~FuncExcom();

	//! ソケット初期化
	bool startExCom();

	//! イベントルータークラス登録
	virtual void setEventRouter(EventRouterBase *pEventRouter);

	//! イベント処理
	void eventHandler(const EventContainer *pEc);
private:

	//!
        std::mutex mtx;

	//!
        std::condition_variable cv;

	//! 受信スレッド
	void recvThread();

	//! 送信スレッド
	void sendThread();

	//! 受信スレッドインスタンス
	std::thread m_recvThread;

	//! 送信スレッドインスタンス
	std::thread m_sendThread;

	// サーバー情報
	int m_socket;
	struct sockaddr_in m_serverInfo;

	// クライアント情報
	int m_clientSocket;
	struct sockaddr_in m_clientInfo;

	// 受信バッファ
	char m_recBuff[1024];

	bool m_threadState;

	bool m_sendState;

	std::string	m_serializeStr;
};

#endif	// _FUNC_EXCOM_H
