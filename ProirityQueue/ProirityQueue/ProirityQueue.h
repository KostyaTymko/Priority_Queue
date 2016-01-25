#pragma once
#include <iostream>
#include "List.h"

class Queue
{
	List l;
	int max_count;
	int count = 0;

public:
	Queue(int m);
	~Queue();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Enqueue(int number,int priority);
	//int Dequeue();
	void Dequeue();
    void Show();
};