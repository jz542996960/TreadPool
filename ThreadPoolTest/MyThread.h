#ifndef MYTHREAD_HEAD_
#define MYTHREAD_HEAD_
#include "task.h"
#include<memory>
#include<thread>


class MyThreadPool;
/*œﬂ≥Ã¿‡*/
class MyThread
{
	friend bool operator==(MyThread my1, MyThread my2);
	friend bool operator!=(MyThread my1,MyThread my2);
public:
	MyThread();
	MyThread(int id,MyThreadPool* pool);
	~MyThread();
public:
	void Assign(Task* task);
	void Run();
	void StartThread();
	int GetThreadId();
	void SetIsDetach(bool isdetch);
private:
	static int s_threadNumber;
	bool isdetch;
	Task* task;
	int  threadid_;
	std::thread thread_;
	MyThreadPool *threadPool;
};
#endif
