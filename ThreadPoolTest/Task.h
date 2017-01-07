#pragma  once
#include "stdafx.h"
#include<iostream>
#include <thread>
using namespace std;

namespace
{
	enum PRIORITY
	{
		MIN = 1,
		NORMAL = 25,
		MAX = 25
	};
}


/*ÈÎÎñÀà*/
class Task
{
public:
	Task()
	{

	}
	void SetPriority(int priority)
	{
		if (priority > (PRIORITY::MAX))
		{
			priority_ = (PRIORITY::MAX);
		}
		else if (priority > (PRIORITY::MIN))
		{
			priority_ = (PRIORITY::NORMAL);
		}
		else
		{
			priority_ = (PRIORITY::MIN);
		}
	}
	virtual void Run() = 0;
protected:
	int priority_;
};



