#pragma once
#include "MyThread.h"
#include <list>
class BuyThreadContainer
{
public:
	BuyThreadContainer();
	~BuyThreadContainer();
	void push(MyThread* m);
	std::list<MyThread*>::size_type size();
	void erase(MyThread *m);
private:
	std::list<MyThread*> busy_thread_container;
	typedef std::list<MyThread*> Container;
	typedef Container::iterator Iterator;
};

