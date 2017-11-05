#include <iostream>

#include <thread>
#include <stdio.h>
#include <unistd.h>

class Worker {
public:
	Worker();

	void run();

	void stop();

private:
	bool	abortFlg;

	void subThread();

	std::thread m_thread;
};

Worker::Worker()   //  : m_thread(&Worker::subThread, this)
{
	std::cout << "create worker" << std::endl;
}

void Worker::run()
{
	abortFlg = false;

	// スレッド起動
	std::cout << "run thread" << std::endl;
	m_thread = std::thread(&Worker::subThread, this);
}

void Worker::stop()
{
	if(!abortFlg) {
		// スレッド停止フラグON
		abortFlg = true;;
		std::cout << "abort thread start" << std::endl;
		// スレッド停止待ち
		m_thread.join();
		std::cout << "abort thread finish" << std::endl;
	}
}

void Worker::subThread()
{
	while(1) {
		if(abortFlg) {
			std::cout << "break" << std::endl;
//			printf("break!!!¥n");
//			sleep(5);
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			break;
		}
		std::cout << "therad" << std::endl;
//		printf("thread");
		sleep(1);
	}
}


int main()
{
	Worker wk;

	wk.run();

	sleep(10);

	wk.stop();

}
