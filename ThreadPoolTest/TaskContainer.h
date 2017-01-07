#pragma once
#include "Task.h"
#include <queue>
class TaskContainer
{
public:
	TaskContainer();
	~TaskContainer();
	void push(Task*);
	Task* top();
	void pop();
	int size();
private:
	std::priority_queue<Task*> task_container_; //优先队列
};

