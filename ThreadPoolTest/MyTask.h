#pragma once
#include "Task.h"
class MyTask :public Task
{
	friend bool operator<(MyTask lv1, MyTask lv2)
	{
		return lv1.priority_ < lv2.priority_;
	}
public:
	MyTask();
	~MyTask();
	virtual void Run();
	void setData(int d);
private:
	int data_;
};

