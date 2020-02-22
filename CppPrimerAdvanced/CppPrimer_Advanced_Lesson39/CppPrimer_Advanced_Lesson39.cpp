#include <iostream>

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

int main()
{

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
	}

	system("pause");
	return 0;
}