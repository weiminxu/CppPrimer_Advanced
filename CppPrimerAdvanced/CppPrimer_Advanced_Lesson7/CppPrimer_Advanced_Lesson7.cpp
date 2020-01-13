#include <iostream>

using namespace std;

/*
class Person
{
private:
	std::string name;
	int age;

public:
	Person(std::string& nm) :name(nm) {}
	Person(const std::string& nm) :name(nm),age(0) {}
	const std::string get() const
	{
		return name;
	}
};
*/

class Sales_item
{
private:
	std::string isbn;
	unsigned units_sold;
	double revenue;

public:
	explicit Sales_item(const std::string& book, int units, double amount)
		:isbn(book), units_sold(units), revenue(amount)
	{

	}
	//explicit is to reduce site effect
	explicit Sales_item(const std::string& book=""):isbn(book),units_sold(0),revenue(0.0) {}//Equal Sales_item()
	/*explicit Sales_item() : units_sold(0), revenue(0.0),isbn("") {}
	Sales_item() : units_sold(0), revenue(0.0) {}
	Sales_item() : units_sold(0), revenue(0.0), isbn(10,'A') {}*/
	Sales_item(std::istream& is):units_sold(0), revenue(0.0) { is >> *this; }
	Sales_item(int units, double price)
	{
		this->units_sold = units;
		this->revenue = units * price;
	}

	friend std::istream& operator>>(std::istream&, Sales_item&);
};

inline istream& operator>>(istream& in, Sales_item& s)
{
	double price;
	in >> s.units_sold >> price;
	if (in)
	{
		s.revenue = s.units_sold * price;
	}
	else
	{
		s = Sales_item();
	}

	return in;
}




int main()
{
	/*
	std::string str = "zhangfei";
	Person a(str);
	Person b("guanyu");
	cout << b.get() << endl;
	cout << a.get() << endl;
	*/
	Sales_item item1;
	Sales_item item2("0-201-82470-1");
	Sales_item* p1 = new Sales_item();
	Sales_item* p2 = new Sales_item("0-201-82470-1");
	const Sales_item item3;

	delete p1;
	delete p2;

	return 0;
}