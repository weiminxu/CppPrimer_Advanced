//#pragma once
#ifndef _Stack_H_
#define _Stack_H_

#include <exception>
#include <deque>

template<class T>
class Stack
{
protected:
	std::deque<T> d;

public:
	class ReadEmptyStack :public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "read empty stack, heap and stack are empty...";
		}
	};

	void push(const T& elem)
	{
		d.push_back(elem);
	}

	bool empty() const
	{
		return d.empty();
	}

	T pop()
	{
		if (d.empty())
		{
			throw ReadEmptyStack();
		}
		T elem(d.back());
		d.pop_back();

		return elem;
	}

	T& top()
	{
		if (d.empty())
		{
			throw ReadEmptyStack();
		}
		return d.back();
	}
	

	
};



#endif // !_Stack_H_
