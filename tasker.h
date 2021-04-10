#ifndef TASKER_H
#define TASKER_H

#include <iostream>
#include <chrono>

typedef void (*Callable)();
class Tasker
{

public:
	Tasker(std::chrono::system_clock::time_point &timt_a,Callable f);
	std::chrono::system_clock::time_point getTime();

	bool operator< (class Tasker* rhs) {
		return this->timt_t < rhs->getTime();
	} 
	Callable returnFunc();

private:

	std::chrono::system_clock::time_point timt_t;
	Callable func;
	
};

#endif