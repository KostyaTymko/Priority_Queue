#include "List.h"
using namespace std;

List::List()
{
	Head = Tail = nullptr;
	length = 0;
}

void List::AddHead(int n,int p)
{
	Elem * temp = new Elem();
	temp->prev = nullptr;
	temp->data = n;
	temp->priority = p;
	temp->next = Head;

	// если в списке уже есть элементы
	if (Head != nullptr) Head->prev = temp;

	// если элементов не было
	if (length == 0) Head = Tail = temp;
	else Head = temp;

	length++;
}

void List::AddTail(int n,int p)
{
	Elem * temp = new Elem();
	temp->next = nullptr;
	temp->data = n;
	temp->priority = p;
	temp->prev = Tail;

	// если в списке уже есть элементы
	if (Tail != nullptr) Tail->next = temp;

	// если элементов не было
	if (length == 0) Head = Tail = temp;
	else Tail = temp;

	length++;
}

List::List(const List & L)
{
	Head = Tail = nullptr;
	length = 0;
	// голова списка, который копируется
	Elem* temp2 = L.Head;

	while (temp2 != nullptr)
	{
		AddTail(temp2->data, temp2->priority);
		temp2 = temp2->next;
	}
}

List List::operator = (const List & L)
{
	// проверка на присвоение элемента самому себе
	if (this == &L) return *this;

	// удаление старого списка
	this->~List(); // DelAll();

	Elem* temp = L.Head;

	while (temp != nullptr)
	{
		AddHead(temp->data, temp->priority);
		temp = temp->next;
	}

	return *this;
}

void List::Del(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

	int i = 1;
	Elem * Del = Head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}

	Elem * PrevDel = Del->prev;
	Elem * AfterDel = Del->next;

	// если удаляется не голова
	if (PrevDel != nullptr && length != 1)
		PrevDel->next = AfterDel;
	// если удаляется не хвост
	if (AfterDel != nullptr && length != 1)
		AfterDel->prev = PrevDel;

	// удаление крайних элементов
	if (pos == 1) Head = AfterDel;
	if (pos == length) Tail = PrevDel;

	delete Del;

	length--;
}

int List::MaxPriorityElement()
{
	//if (Head != nullptr)
	int max_pr = 0;
	int max_pr_position = 0;

	Elem * temp = new Elem();
	temp = Head;

	for (int i = 1; i <= length; i++)
	{
		if (max_pr < temp->priority)
		{
			max_pr = temp->priority;
			max_pr_position = i;
		}
		temp = temp->next;
	}
	delete temp;
	return max_pr_position;
}

void List::DelAll()
{
	while (length != 0) Del(1);
}

List::~List()
{
	DelAll();
}

int List::GetLength()
{
	return length;
}

List::Elem* List::GetElem(int pos)
{
	if (pos < 1 || pos > length)
		throw "Incorrect position";

	Elem *temp = Head;

	int i = 1;
	while (i < pos && temp != nullptr)
	{
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) return nullptr; // ничего не найдено :(
	return temp;
}
List::Elem* List::MaxPriorityElem()
{
	Elem *temp = Head;

	int i = 1;
	while (i < MaxPriorityElement() && temp != nullptr)
	{
		temp = temp->next;
		i++;
	}

	if (temp == nullptr) return nullptr; // ничего не найдено :(
	return temp;
}

void List::Sort()
{
	int*arrayPriority = new int[length];
	int*arrayData = new int[length];
	Elem* temp = Head;
	for (int i = 0; i < length; i++)
	{
		arrayData[i] = temp->data;
		arrayPriority[i] = temp->priority;
		temp = temp->next;
	}

	for (int j = length - 1; j>0; j--)
		for (int i = 0; i < j; i++)
			if (arrayPriority[i] >= arrayPriority[i + 1])
			{
				swap(arrayPriority[i], arrayPriority[i + 1]);
				swap(arrayData[i], arrayData[i + 1]);
			}

	List Result;
	for (int i = 0; i < length; i++)
	{
		Result.AddTail(arrayData[i], arrayPriority[i]);
	}
	this->~List();
	*this = Result;
	delete[]arrayData;
	delete[]arrayPriority;
}