#include <iostream>
#include <string>

using namespace std;

class Dog
{
public:
	Dog(string n, int a, double w) :age(a), weight(w), name(n) {}
	operator int() const
	{
		return age;
	}
private:
	int age;
	double weight;
	string name;
};


int main()
{
	int b;

	Dog d("Bill", 3, 15.09);
	b = d;
	cout << b << endl;

	return 0;
}