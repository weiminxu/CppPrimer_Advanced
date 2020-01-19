
#ifndef SALES_ITEM_H
#define SALES_ITEM_H
#include <string>
#include <iostream>

using namespace std;

class Sales_item
{
private:
	std::string bookname;
	int booknumber;
	double bookprice;
	double amount;

public:
	Sales_item() :bookname(), booknumber(0), bookprice(0), amount(0) {}
	Sales_item(const std::string& book) :bookname(book), booknumber(0), bookprice(0), amount(0) {}
	Sales_item(string bookname1, int booknumber1, double bookprice1) :bookname(bookname1), booknumber(booknumber1), bookprice(bookprice1), amount(0) {}
	//Sales_item(std::istream& is) { is >> *this; }
	Sales_item(const Sales_item& si) :bookname(si.bookname), booknumber(si.booknumber), bookprice(si.bookprice), amount(si.amount) {}
	~Sales_item() {}
	friend istream& operator >> (istream& is, Sales_item& t);
	friend std::ostream& operator << (std::ostream& os, Sales_item& t1);
	friend bool operator == (const Sales_item&, const Sales_item&);
	Sales_item& operator+=(const Sales_item& si);

	double avg_price() const;
	bool same_isbn(const Sales_item& rhs) const
	{
		return bookname == rhs.bookname;
	}
};

Sales_item operator + (const Sales_item&, const Sales_item&);

Sales_item& Sales_item::operator+=(const Sales_item& si)
{
	this->booknumber += si.booknumber;
	this->bookprice += si.bookprice;

	return *this;
}

istream& operator >> (istream& is, Sales_item& t)
{
	is >> t.bookname;
	is >> t.booknumber;
	is >> t.bookprice;

	return is;
}

ostream& operator << (ostream& out, Sales_item& t)
{
	out << t.bookname << endl;
	out << t.booknumber << endl;
	cout << t.bookprice << endl;

	return out;
}

inline bool operator == (const Sales_item& lhs, const Sales_item& rhs)
{
	return lhs.bookprice == rhs.bookprice && lhs.bookname == rhs.bookname
		&& lhs.booknumber == rhs.booknumber;
}

bool operator != (const Sales_item& lhs, const Sales_item& rhs)
{
	return !(lhs == rhs);
}

Sales_item operator + (const Sales_item& si1, const Sales_item& si2)
{
	Sales_item ret(si1);
	ret += si2;

	return ret;
}

inline double Sales_item::avg_price() const
{
	if (bookprice)
	{
		return amount / booknumber;
	}
	else
	{
		return 0;
	}
}
#endif // !1


