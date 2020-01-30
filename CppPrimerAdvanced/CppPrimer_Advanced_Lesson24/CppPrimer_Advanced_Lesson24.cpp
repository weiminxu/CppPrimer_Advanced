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
	operator double() const
	{
		return weight;
	}
	operator string() const
	{
		return name;
	}
private:
	int age;
	double weight;
	string name;
};


int main()
{
	int i;
	double di;
	string str;

	Dog d("Bill", 3, 15.09);
	i = d;
	di = d;
	str = d;
	cout << i << " "<< di << " " << str << endl;

	return 0;
}