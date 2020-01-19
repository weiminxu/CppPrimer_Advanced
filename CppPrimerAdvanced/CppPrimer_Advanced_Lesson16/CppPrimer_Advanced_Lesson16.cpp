#include <iostream>
#include <string>

using namespace std;

class Sales_item 
{
	friend ostream& operator<<(ostream& out, const Sales_item& rhv);
public:
	Sales_item(const std::string& book, const unsigned units, const double amount)
		:isbn(book), units_sold(units), revenue(amount) {}
	Sales_item& operator+=(const Sales_item&);
	Sales_item& operator-=(const Sales_item&);

private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret += rhs;

	return ret;
}

Sales_item operator-(const Sales_item& lhs, const Sales_item& rhs)
{
	Sales_item ret(lhs);
	ret -= rhs;

	return ret;
}


Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return *this;

}

ostream& operator<<(ostream& out, const Sales_item& rhv)
{

	out << rhv.isbn << endl << rhv.units_sold << endl << rhv.revenue << endl;

	return out;
}

Sales_item& Sales_item::operator-=(const Sales_item& rhs)
{
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;

	return *this;

}

int main()
{
	string str = "0-201-78345-X";

	Sales_item item3(str, 10, 120);
	Sales_item item4(str, 20, 240);
	Sales_item item5 = item3 + item4;
	Sales_item item6 = item4 - item3;
	cout << item5 << endl;
	cout << item6 << endl;

	cout << "hello" << endl;
	system("pause");

	return 0;
}