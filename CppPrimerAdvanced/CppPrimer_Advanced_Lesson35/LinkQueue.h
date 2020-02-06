#ifndef QUEUE_H_
#define QUEUE_H_

template<class Object>
class Queue
{
private:
	struct LinkNote
	{
		int num;
		Object element;
		LinkNote* next;

		//LinkNote(const Object& theElement) :element(theElement) {}
		LinkNote(const Object& theElement, LinkNote* n = 0) :element(theElement), next(n) {}
	};
	LinkNote* front;
	LinkNote* back;
public:
	Queue();
	~Queue();

	bool isEmpty() const;
	const Object& getFront() const;
	void enqueue(const Object& x);
	Object dequeue();
	void makeEmpty();
};

template<class Object>
Queue<Object>::Queue()
{
	front = back = 0;
}

template<class Object>
Queue<Object>::~Queue()
{
	makeEmpty();
}

template<class Object>
bool Queue<Object>::isEmpty() const
{
	return front == 0;
}

template<class Object>
const Object& Queue<Object>::getFront() const
{
	if (isEmpty())
	{
		throw "Queue is empty.";
	}
	return front->element;
}

template<class Object>
void Queue<Object>::enqueue(const Object& x)
{
	if (isEmpty())
	{
		back = front = new LinkNote(x);
	}
	else
	{
		back = back->next = new LinkNote(x);
	}
}

template<class Object>
Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();

	LinkNote* old = front;
	front = front->next;
	delete old;

	return frontItem;
}

template<class Object>
void Queue<Object>::makeEmpty()
{
	while (isEmpty())
	{
		dequeue();
	}
}

#endif // !QUEUE_H_