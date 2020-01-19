#include <iostream>
#include <string>

using namespace std;

class Sales_item
{
	friend ostream& operator<<(ostream&, const Sales_item&);
	friend istream& operator>>(istream&, Sales_item&);
private:
	string isbn;
	unsigned units_sold;
	double revenue;

public:
	Sales_item(string& book, unsigned units, double price)
		:isbn(book), units_sold(units), revenue(units*price) {}
	Sales_item() :units_sold(0), revenue(0.0) {}

	
};

ostream& operator<<(ostream& out, const Sales_item& rhv)
{
	
	out << rhv.isbn << endl << rhv.units_sold << endl << rhv.revenue << endl;

	return out;
}

istream& operator>>(istream& in, Sales_item& lhv)
{
	double price;

	in >> lhv.isbn;
	cout << endl;
	in >> lhv.units_sold;
	cout << endl;
	in >> price;
	cout << endl;

	if (in)
	{
		lhv.revenue = lhv.units_sold * price;
	}
	else
	{
		lhv = Sales_item();
	}
	
	return in;
}

int main()
{
	string str = "0-201-78345-X";
	Sales_item item1(str, 2, 25.00);
	cout << item1 << endl;
	Sales_item item2;
	cin >> item2;
	cout << item2;

	cout << "hello " << endl;
	system("pause");

	return 0;
}