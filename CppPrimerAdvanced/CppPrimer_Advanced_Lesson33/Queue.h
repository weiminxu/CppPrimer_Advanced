
#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include <iomanip>

using namespace std;

class Queue
{
	struct Node
	{
		int a;
		Node* next;
	};

public:
	Queue();
	void push(int b);
	void pop();
	int getlength();
	virtual void print();

private:
	Node* head;
	Node* rear;
};

void Queue::push(int b)
{
	Node* p1 = new Node;
	p1->a = b;
	p1->next = NULL;
	rear->next = p1;
	rear = p1;
	head->a++;
	cout << setw(2) << b << setw(2) << " was pushed into Queue..." << endl;
}

void Queue::pop()
{
	Node* p;
	p = head->next;
	cout << " " << setw(2) << p->a << setw(2) << "pop out of Queue..." << endl;
	head->next = p->next;
	delete p;
	head->a--;
}

int Queue::getlength()
{
	return head->a;
}

void Queue::print()
{
	Node* p;
	p = head->next;
	cout << "the element in Queue is: " << endl;
	while (p)
	{
		cout << p->a << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

Queue::Queue()
{
	rear = head = new Node();
}

#endif // !QUEUE_H_
