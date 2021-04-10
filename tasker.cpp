
#include "tasker.h"

using namespace std;
Tasker::Tasker(std::chrono::system_clock::time_point &timt_a,Callable f)
{
	timt_t = timt_a;
	func = f;   
}


std::chrono::system_clock::time_point Tasker::getTime(){
		return timt_t;
	}

Callable Tasker::returnFunc(){
		return func;
	}	
