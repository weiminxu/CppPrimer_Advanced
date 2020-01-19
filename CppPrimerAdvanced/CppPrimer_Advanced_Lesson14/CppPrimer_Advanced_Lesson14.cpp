#include <iostream>

using namespace std;

class Person
{
public:
	//overload operator: add
	void operator+(const Person& rhs)
	{
		cout << "+ is overloaded! " << endl;
	}

private:
	int a;
};

int main()
{

	//simple case
	int a, b;
	a = 12;
	b = 9;
	int c = a + b;
	cout << c;

	//overload operator: add
	Person p1, p2, p;
	p1 + p2;

	cout << "hello ";
	system("pause");

	return 0;
}