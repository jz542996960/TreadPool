#include "TaskContainer.h"


TaskContainer::TaskContainer()
{
}


TaskContainer::~TaskContainer()
{
}

void TaskContainer::push(Task* task)
{
	if (task != nullptr)
	{
		task_container_.push(task);
	}
}

Task* TaskContainer::top()
{
	return task_container_.top();
}

void TaskContainer::pop()
{
	task_container_.pop();
}

int TaskContainer::size()
{
	return task_container_.size();
}
