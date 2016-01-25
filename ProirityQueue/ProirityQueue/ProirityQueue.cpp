#include "ProirityQueue.h"	

Queue::Queue(int m)
	{
		max_count = m;
	}

Queue::~Queue()
	{
		l.DelAll();
	}

void Queue::Clear()
	{
		l.DelAll();
		count = 0;
	}

bool Queue::IsEmpty()
	{
		return count == 0;
	}

bool Queue::IsFull()
	{
		return count == max_count;
	}

int Queue::GetCount()
	{
		return count;
	}

void Queue::Enqueue(int number,int priority)
	{
		l.AddTail(number,priority);
		count++;
		l.Sort();
	}

void Queue::Dequeue()
{
	if (!IsEmpty())
	{
		l.Del(1);
		count--;
	}
	else throw "Queue is empty!";
}

//int Queue::Dequeue()
//	{
//		if (!IsEmpty())
//		{
//			int first = l.MaxPriorityElem()->data;
//			l.Del(l.MaxPriorityElement());
//			count--;
//			return first;
//		}
//		else throw "Queue is empty!";
//	}

//void Queue::Dequeue()
//{
//	if (!IsEmpty())
//	{
//		//int first = l.MaxPriorityElem()->data;
//		l.Del(l.MaxPriorityElement());
//		count--;
//		//return first;
//	}
//	else throw "Queue is empty!";
//}





