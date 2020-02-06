//#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

using namespace std;

template<class T>
class Queue
{
private:
	int capacity;
	T* queue;
	int front;
	int rear;
public:
	Queue(int queueCapacity);
	bool IsEmpty() const;
	T& Front() const;
	T& Rear() const;
	void Push(const T& item);
	void Pop();
};


template <class T>
Queue<T>::Queue(int quequeCapacity) :capacity(quequeCapacity)
{
	if (capacity < 1)
	{
		throw "Queue capacity must be  > 0";
	}
	queue = new T[capacity];
	front = rear = 0;
}

template <class T>
inline bool Queue<T>::IsEmpty() const
{
	return front == rear;
}

template <class T>
void Queue<T>::Push(const T& item)
{
	if ((rear + 1) % capacity == front)
	{
		//expand capacity;
		T* newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)
		{
			copy(queue + start, queue + + start + capacity -1, newQueue);
		}
		else
		{
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue + capacity - start);
		}
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		delete[] queue;
		queue = newQueue;
	}

	if (rear == capacity - 1)
	{
		rear = 0;
	}
	else
	{
		rear++;
	}
	//rear = (rear + 1) % capacity;
	queue[rear] = item;
	
}

template<class T>
inline T& Queue<T>::Front() const
{
	if (IsEmpty())
	{
		throw "Queue is empty, No front element";
	}
	return queue[(front + 1) % capacity];
}

template<class T>
inline T& Queue<T>::Rear() const
{
	if (IsEmpty())
	{
		throw "Queue is empty. No rear element";
	}
	return queue[rear];
}

template<class T>
void Queue<T>::Pop()
{
	if (IsEmpty())
	{
		throw "Queue is empty. No rear element";
	}
	front = (front + 1) % capacity;
	queue[front].~T();
}
#endif // !_QUEUE_H

