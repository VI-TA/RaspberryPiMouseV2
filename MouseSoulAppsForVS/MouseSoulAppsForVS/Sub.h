#pragma once
#ifndef _SUB_H
#define _SUB_H

/**
* @file Sub.h
* @brief 
* @details 
*/

#include <thread>
#include <mutex>
#include <condition_variable>

class Sub
{
public:
	Sub();
	~Sub();
private:
	std::mutex mtx;
	std::condition_variable cv;
	bool is_wait;

	void SubWait();
};

#endif	// _SUB_H