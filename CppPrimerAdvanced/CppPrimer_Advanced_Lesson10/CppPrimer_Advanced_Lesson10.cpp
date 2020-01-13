/*
	when in a class, there is pointer variable which need to allocate memory, 
	we should rewrite the copy constructor and assignment constructor.
	Other situations, we do not need to do that.
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sales_item
{
public:
	//plain constructor
	Sales_item() : isbn(" "), units_sold(0), revenue(0.0) { cout << "the default constructor without parameter!"; }
	Sales_item(const std::string& book) :isbn(book), units_sold(0), revenue(0) { cout << "the constructor with parameter!"; }

	//copy constructor
	Sales_item(const Sales_item& orig) :isbn(orig.isbn), units_sold(orig.units_sold), revenue(orig.revenue) { cout << "the copy constructor is called!"<<endl; }

	//assignment constructor
	Sales_item& operator=(const Sales_item& rhs)
	{
		isbn = rhs.isbn;
		units_sold = rhs.units_sold;
		revenue = rhs.revenue;
		cout << "the assignment constructor is invocated!";

		return *this;
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revenue;
};

Sales_item foo(Sales_item itm)
{
	Sales_item epm;
	epm = itm;

	return epm;
}

Sales_item& koo(Sales_item& itm)
{
	Sales_item epm;
	epm = itm;

	return epm;
}

class NoName
{
public:
	NoName() :pstring(new std::string), i(0), d(0) {}
	NoName(const NoName& other) :pstring(new std::string(*(other.pstring))), i(other.i), d(other.d) 
	{
		cout << "NoName Copy Constructor" << endl;
	}

	NoName& operator=(const NoName& rhs)
	{
		pstring = new std::string(*(rhs.pstring));
		//*pstring = *(rhs.pstring);

		i = rhs.i;
		d = rhs.d;

		return *this;
	}

private:
	std::string* pstring;
	int i;
	double d;
};



int main()
{


	Sales_item a;
	Sales_item b("0-201-78345-X");
	Sales_item c(b);
	a = b;

	Sales_item item = string("0-201-78345-Y");

	cout << endl << "have a try foo: " << endl;
	Sales_item fret;
	fret = foo(item);

	/*cout << endl << "have a try koo: " << endl;
	Sales_item kret;
	kret = koo(item);*/

	cout << endl << "have a try vector:" << endl;
	vector<Sales_item> svec(5);

	cout << endl << "have a try array:" << endl;
	Sales_item primer_eds[] = {
		string("0-201-16487-6"),
		string("0-201-54848-8"),
		string("0-201-82470-1"),
		Sales_item()
	};

	return 0;
}