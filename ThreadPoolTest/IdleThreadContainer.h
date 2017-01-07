#pragma once
#include<vector>
#include "MyThread.h"

#include <algorithm>
class IdleThreadContainer
{
public:
	IdleThreadContainer();
	~IdleThreadContainer();
	std::vector<MyThread*>::size_type size();
	void push(MyThread *m);
	void assign(int n,MyThreadPool* m);
	MyThread* top();
	void pop();
	bool erase(MyThread *m);
private:
	std::vector<MyThread*> idle_thread_container_;
	typedef std::vector<MyThread*> Container;
	typedef Container::iterator Iterator;
};

