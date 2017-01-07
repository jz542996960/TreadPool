#include "IdleThreadContainer.h"


IdleThreadContainer::IdleThreadContainer()
{

}


IdleThreadContainer::~IdleThreadContainer()
{
	for (int i = 0; i < size(); i++)
	{
		delete idle_thread_container_[i];
		idle_thread_container_[i] = nullptr; 
	}
	idle_thread_container_.clear();
}

void IdleThreadContainer::assign(int n, MyThreadPool* m)
{
	idle_thread_container_.clear();
	if (m == nullptr) return;
	for (int i = 0; i < n; i++)
	{
		MyThread *trd = new MyThread(i,m);
		push(trd);
	}
}

void IdleThreadContainer::push(MyThread *m)
{
	if (m == nullptr) return;
	idle_thread_container_.push_back(m);
}


MyThread* IdleThreadContainer::top()
{
	if (size() <= 0) return  nullptr;
	if (idle_thread_container_[0] != nullptr)
	{
		return idle_thread_container_[0];
	}
	return nullptr;
}

std::vector<MyThread*>::size_type IdleThreadContainer::size()
{
	return idle_thread_container_.size();
}

void IdleThreadContainer::pop()
{
	if (size() > 0)
		idle_thread_container_.erase(idle_thread_container_.begin());
}


bool IdleThreadContainer::erase(MyThread *m)
{
	if (size() > 0)
	{
		idle_thread_container_.erase(remove(idle_thread_container_.begin(), idle_thread_container_.end(), m), idle_thread_container_.end());
		delete m;
		m = nullptr;
		return true;
	}
	return false;
		
}