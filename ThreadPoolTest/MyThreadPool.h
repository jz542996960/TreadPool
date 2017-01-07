#pragma once
#include "Task.h"

#include "BuyThreadContainer.h"
#include "IdleThreadContainer.h"
#include "TaskContainer.h"
#include <mutex>

class MyThreadPool
{
public:
	MyThreadPool();
	MyThreadPool(int number);
	~MyThreadPool();
	void AddTask(Task* task,int priority);
	void AddIdleThread(int m);
	void RemoveThreadFromBusy(MyThread *myThread);
	void Start();
	void EndMyThreadPool();
private:
	BuyThreadContainer busy_thread_container_;
	IdleThreadContainer idle_thread_container_;
	TaskContainer task_container_;
	bool issurvive_;
	std::thread thread_this_;
	std::mutex busy_mutex_;
	std::mutex idle_mutex_;
	std::mutex task_mutex_;
	int number_of_thread;


};

