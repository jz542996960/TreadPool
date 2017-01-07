#include "MyThreadPool.h"


MyThreadPool::MyThreadPool()
{
	
}

MyThreadPool::MyThreadPool(int number)
{
	issurvive_ = true;
	number_of_thread = number;
	idle_thread_container_.assign(number, this);
	thread_this_ = std::thread(&MyThreadPool::Start,this);
	thread_this_.detach();
}


MyThreadPool::~MyThreadPool()
{
}

void MyThreadPool::AddTask(Task* task, int priority)
{
	task_mutex_.lock();
	task->SetPriority(priority);
	task_container_.push(task);
	task_mutex_.unlock();
}

void MyThreadPool::AddIdleThread(int m)
{
	int index = idle_thread_container_.size();
	idle_mutex_.lock();
	for (int i = 0; i < m; i++)
	{
		MyThread *myTrd = new MyThread(index,this);
		idle_thread_container_.push(myTrd);
	}
	idle_mutex_.unlock();
}

void MyThreadPool::RemoveThreadFromBusy(MyThread *myThread)
{
	busy_mutex_.lock();
	cout << "Thread: " << myThread->GetThreadId() << "remove from buylist" << endl;
	busy_thread_container_.erase(myThread);


	idle_mutex_.lock();
	cout << "Thread: " << myThread->GetThreadId() << "push to idlelist" << endl;
	idle_thread_container_.push(myThread);
	idle_mutex_.unlock();

	busy_mutex_.unlock();
}

void MyThreadPool::Start()
{
	while (true)
	{
		if (issurvive_ == false)
		{
			busy_mutex_.lock();
			if (busy_thread_container_.size() != 0)
			{
				busy_mutex_.unlock();
				continue;;
			}
			busy_mutex_.unlock();
			break;
		}

		idle_mutex_.lock();
		if (idle_thread_container_.size() == 0)
		{
			idle_mutex_.unlock();
			continue;;
		}
		idle_mutex_.unlock();
	
		task_mutex_.lock();
		if (task_container_.size() == 0)
		{ 
			task_mutex_.unlock();
			continue;
		}

		Task *b = task_container_.top();
		task_container_.pop();
		task_mutex_.unlock();

		idle_mutex_.lock();
		MyThread *mythread = idle_thread_container_.top();
		idle_thread_container_.pop();
		mythread->Assign(b);
		idle_mutex_.unlock();

		busy_mutex_.lock();
		busy_thread_container_.push(mythread);
		busy_mutex_.unlock();
		mythread->StartThread();
	}
}

void MyThreadPool::EndMyThreadPool()
{
	issurvive_ = false;
}