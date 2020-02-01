#include <iostream>

using namespace std;

class Base1
{
private:
	int b1;

public:
	Base1(int i)
	{
		b1 = i;
		cout << "Base1's constructor was called." << endl;
	}
	~Base1()
	{
		cout << "Base1's destructor was called." << endl;
	}
	void print() const
	{
		cout << b1 << endl;
	}
};

class Base2
{
public:
	Base2(int i)
	{
		b2 = i;
		cout << "Base2's constructor was called." << endl;
	}
	~Base2()
	{
		cout << "Base2's destructor was called." << endl;
	}
	void print()
	{
		cout << b2 << endl;
	}
private:
	int b2;
};

class Base3
{
public:
	Base3()
	{
		b3 = 0;
		cout << "Base3's constructor without parameter was called." << endl;
	}
	~Base3()
	{
		cout << "Base3's destructor was called." << endl;
	}
	void print()
	{
		cout << b3 << endl;
	}
private:
	int b3;
};

class Member
{
public:
	Member(int i)
	{
		m = i;
		cout << "Member's constructor was called." << endl;
	}
	~Member()
	{
		cout << "Member's destructor was called." << endl;
	}
	int getM()
	{
		return m;
	}
private:
	int m;
};

class Derived :public Base2, public Base1, public Base3
{
public:
	Derived(int i, int j, int k, int l);
	~Derived();
	void print();
private:
	int d;
	Member mem;
};

Derived::Derived(int i, int j, int k, int l):Base1(i), Base2(j), mem(k)
{
	d = l;
	cout << "Derived's contructor was called. " << endl;
}

Derived::~Derived()
{
	cout << "Derived's destructor was called. " << endl;
}

void Derived::print()
{
	Base1::print();
	Base2::print();
	Base3::print();
	cout << mem.getM() << endl;
	cout << d << endl;
}

int main()
{
	Derived object(1, 2, 3, 4);
	object.print();

	system("pause");
	return 0;
}