#include <iostream>
#include <bitset>
#include <string>
#include <stdexcept>
#include "Stack.h"

using namespace std;

class Dog
{
private:
	int* parr;
public:
	Dog()
	{
		parr = new int[1000000];
	}
};

class Student
{
public:
	Student(int age):m_age(age)
	{
		if (age < 0 || age > 150)
		{
			throw out_of_range("age can not be less than 0 or age can not be more than 150!");
			this->m_age = age;
		}
	}
private:
	int m_age;
};

int main()
{
	/*
		standard exception
		*eception
		*rentime_error
		*rang_error
		*overflow_error
		*underflow_error
		*logic_error
		*invalid_argument
		*length_error
		*out_of_range
		*bad_alloc
	*/

	/*
	Dog* pDog;
	try
	{
		for (int i = 0; i < 10000; i++)
		{
			pDog = new Dog();
			cout << i << ": new Dog successful..." << endl;
		}
	}
	catch (bad_alloc err)
	{
		cout << "new Dog fail..." << endl;
	}*/

	/*try
	{
		string s("10ab110010");
		bitset<10> b(s);
		cout << "bitset ok" << endl;

	}
	catch (invalid_argument err)
	{
		cout << "bitset error: " << err.what() << endl;
	}*/

	/*try
	{
		Student student(1000);
		cout << "student age is correct" << endl;
	}
	catch (out_of_range err)
	{
		cout << "student age is error: " << err.what() << endl;
	}*/

	try
	{
		Stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		cout << st.pop() << endl;
		cout << st.pop() << endl;
		cout << st.pop() << endl;
		cout << st.pop() << endl;
	}
	catch (const exception & e)
	{
		cout << "error happened: " << e.what() << endl;
	}



	system("pause");
	return 0;
}