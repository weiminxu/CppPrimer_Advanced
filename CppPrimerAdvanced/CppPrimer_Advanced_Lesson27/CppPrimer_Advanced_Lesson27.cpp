#include <iostream>

using namespace std;

class A
{
public:
	int a;
	int a1;
	int a2;

	A():a(0), a1(0), a2(0), b(0), c(0) {}

protected:
	int b;
private:
	int c;
};

class B1 : public A
{
public:
	B1() {}

	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

class B2 : private A //private inherit is that a, b and c are private
{
public:
	using A::a2; // a2 is changed to public
	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

class B3 : protected A //protected inherit is that a, b are protected; c is private
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

class B4 : A //it is private
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

struct B5 : A // it is public
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

class C : public B1// 
{
public:
	void test()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

int main()
{
	B1 b1;
	cout << b1.a << endl;

	//a in class B2 is private.
	//B2 b2;
	//cout << b2.a << endl;

	system("pause");
	return 0;
}