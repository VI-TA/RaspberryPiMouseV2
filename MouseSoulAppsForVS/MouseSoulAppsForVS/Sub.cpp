/**
* @file Sub.cpp
* @brief
* @details
*/

#include "stdafx.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "sub.h"

Sub::Sub()
{
	is_wait = false;

	std::thread main_exec([&] { Sub::SubWait(); });
	main_exec.join();
}

Sub::~Sub()
{

}

void Sub::SubWait()
{
	std::cout << "Sub::SubWait" << std::endl;
	std::unique_lock<std::mutex> uniq_lk(mtx);
	cv.wait(uniq_lk, [this] { return is_wait; });
}
