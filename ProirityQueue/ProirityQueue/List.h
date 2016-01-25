#pragma once
#include <iostream>

class List
{
public:
	struct Elem
	{
		int data;
		int priority;
		Elem* next;
		Elem* prev;
	};

private:
	Elem *Head, *Tail;
	int length;

public:
	List();
	~List();
	int GetLength();
	void AddTail(int n,int p);
	void AddHead(int n,int p);
	List(const List & L);
	List operator = (const List & L);
	void Del(int pos);
	void Sort();
	int MaxPriorityElement();
	void DelAll();
	Elem* GetElem(int);
	Elem* MaxPriorityElem();
};

