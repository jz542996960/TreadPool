#include "MyThread.h"
#include "MyThreadPool.h"

MyThread::MyThread()
{
	task = nullptr;
	isdetch = false; 
}

MyThread::MyThread(int id, MyThreadPool* pool)
{
	MyThread();
	this->threadid_ = id;
	this->threadPool = pool;
}

MyThread::~MyThread()
{
}

void MyThread::Assign(Task* task)
{
	this->task = task;
}

void MyThread::StartThread()
{
	thread_ = std::thread(&MyThread::Run,this);
	if (isdetch)
	{
		thread_.detach();
	}
	else
	{
		thread_.join();
	}

}

void MyThread::Run()
{
	cout << "Thread: " << threadid_ << "running " << endl;
	if (task != nullptr)
	{
		task->Run();
	}
	if (threadPool != nullptr)
	{
		threadPool->RemoveThreadFromBusy(this);//线程结束后把线程移动到空闲队列
	}
}


int MyThread::GetThreadId()
{
	return threadid_;
}


void MyThread::SetIsDetach(bool isdetch)
{
	this->isdetch = isdetch;
}


bool operator==(MyThread my1, MyThread my2)
{
	return (my1.threadid_ == my2.threadid_);
}


bool operator!=(MyThread my1, MyThread my2)
{
	if (my1.threadid_ != my2.threadid_)
	{
		return true;
	}
	return false;
}