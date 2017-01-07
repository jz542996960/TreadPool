#include "MyTask.h"


MyTask::MyTask()
{

}

MyTask::~MyTask()
{

}

void MyTask::setData(int d)
{
	data_ = d;
}

void MyTask::Run()
{
	std::cout << "Hello I am" << data_ << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
}
