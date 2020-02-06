//#pragma once
#ifndef GeneralQueue_H_
#define GeneralQueue_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template<class Element>
class GeneralQueue
{
	struct Node
	{
		int num;
		Element element;
		Node* next;
	};

public:
	GeneralQueue();
	~GeneralQueue();
	void push(Element b);
	void pop();
	int getlength();
	virtual void print();

private:
	Node* head;
	Node* rear;
};

template<class Element>
void GeneralQueue<Element>::push(Element b)
{
	Node* p1 = new Node;
	p1->element = b;
	p1->next = NULL;
	rear->next = p1;
	rear = p1;
	head->num++;
	cout << setw(2) << b << setw(2) << " was pushed into Queue..." << endl;
}

template<class Element>
void GeneralQueue<Element>::pop()
{
	Node* p;
	p = head->next;
	cout << " " << setw(2) << p->a << setw(2) << "pop out of Queue..." << endl;
	head->next = p->next;
	delete p;
	head->num--;
}

template<class Element>
int GeneralQueue<Element>::getlength()
{
	return head->a;
}

template<class Element>
void GeneralQueue<Element>:: print()
{
	Node* p;
	p = head->next;
	cout << "the element in Queue is: " << endl;
	while (p)
	{
		cout << p->element << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

template<class Element>
GeneralQueue<Element>::GeneralQueue()
{
	rear = head = new Node();
}

template<class Element>
GeneralQueue<Element>::~GeneralQueue()
{
}
#endif // !1