#include <iostream>
#include <time.h>
#include "List.h"
#include "ProirityQueue.h"
using namespace std;

void Queue::Show()
{
	cout << "-----------------------------------------------------\n";
	for (int i = 0; i < count; i++)
		cout <<l.GetElem(i + 1)->data << " pr: " << l.GetElem(i + 1)->priority<<"  /";
	cout << "\n";
	cout << "-----------------------------------------------------\n";
}

void main()
{
	system("title Пользовательский адаптер Queue (двусвязный список)");
	srand(time(0));
	rand();

	Queue q(25);

	for (int i = 0; i < 5; i++)
		q.Enqueue(rand() % 90 + 10, rand() % 10);
	
	q.Enqueue(99,8);

	q.Show();

	q.Dequeue();

	q.Show();

	for (int i = 0; i < 2; i++)
		q.Enqueue(rand() % 90 + 10, rand() % 10);

    q.Show();

	for (int i = 0; i < 3; i++)
		q.Dequeue();

	q.Show();
}
