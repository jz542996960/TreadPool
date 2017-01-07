#include "stdafx.h"
#include <iostream>
#include "MyTask.h"
#include "MyThreadPool.h"

int main()
{
	MyThreadPool mythreadpool(10);

	MyTask j[50];
	for (int i = 0; i < 50; i++)
	{
		j[i].setData(i);
	}
	for (int i = 0; i < 50; i++)
	{ 
		mythreadpool.AddTask(&j[i], i);
	}
	int i;
	while (true)
	{
		cin >> i;
		if (i == 100)
		{
			MyTask j;
			j.setData(i);
			mythreadpool.AddTask(&j, i);
		}
		if (i == -1)
		{
			mythreadpool.EndMyThreadPool();
			break;
		}
	}

}