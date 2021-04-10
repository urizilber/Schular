
#include "schular.h"
#include <thread>
#include <unistd.h>
#include <chrono>
#include <atomic>

using namespace std;

Schuelar::Schuelar(){
	 go_on = true;

	
	 t1 = new thread( &Schuelar::PerformSchelaing,this);
	 t1->join();
}

bool Schuelar::setTasker(Tasker* ts){
	Pqueue.push(ts);

};
bool Schuelar::cancelTask(){};
bool Schuelar::PerformSchelaing(){
	while(go_on){
		auto timt_now = std::chrono::system_clock::now();
        
		std::unique_lock<std::mutex> sch(m);
		
		if(!Pqueue.empty() && Pqueue.top()->getTime()  > timt_now){
			cv.wait_until(sch,Pqueue.top()->getTime() -std::chrono::system_clock::now());
		}
		else if(Pqueue.empty()){
			cv.wait(sch);
		}

		while (!Pqueue.empty() && Pqueue.top()->getTime() <=timt_now ){
			Tasker *temp = Pqueue.top();
			Pqueue.pop();
		}

		sch.unlock();
	}
};