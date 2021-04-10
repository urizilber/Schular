#ifndef SHUELAR_H
#define SHUELAR_H

#include <queue>
#include <thread>
#include <memory>
#include <functional>
#include <future>
#include "tasker.h"
#include <thread>
#include <condition_variable>
#include <mutex>

class Schuelar
{

public:
	Schuelar();
	std::thread *t1;
	bool setTasker(Tasker* ts);
	bool cancelTask();
	bool PerformSchelaing();


private:
	std::priority_queue<Tasker*> Pqueue;
	bool go_on;
	std::mutex m;
	std::condition_variable cv;
	std::chrono::system_clock::time_point timt;

};

#endif
