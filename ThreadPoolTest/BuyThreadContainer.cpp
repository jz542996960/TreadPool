#include "BuyThreadContainer.h"


BuyThreadContainer::BuyThreadContainer()
{
}


BuyThreadContainer::~BuyThreadContainer()
{
	Iterator it = busy_thread_container.begin();
	for (it; it != busy_thread_container.end(); ++it)
	{
		MyThread *m = *it;
		delete m;
		m = NULL;
	}
	busy_thread_container.clear();

}

void BuyThreadContainer::push(MyThread* m)
{
	if (!m) return;
	busy_thread_container.push_back(m);
}

std::list<MyThread*>::size_type BuyThreadContainer::size()
{
	return busy_thread_container.size();
}

void BuyThreadContainer::erase(MyThread *m)
{
	busy_thread_container.remove(m);
}
