#include <iostream>

using namespace std;

class Item_base
{
public:
	Item_base(const std::string& book = " ", double sales_price = 0) :isbn(book), price(sales_price) {}
	std::string book() const
	{
		return isbn;
	}
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
private:
	string isbn;
protected:
	double price;
};

class Bulk_item :public Item_base
{
public:
	Bulk_item(const std::string& book = "", double sales_price = 0, size_t qty = 0, double disc_rate = 0) :
		Item_base(book, sales_price), min_qty(qty), discount(disc_rate) {}
	
	void test()
	{
		cout << price << endl;
	}

	void test2(const Bulk_item& d, const Item_base& b)
	{
		cout << d.price << endl;
	}

	double net_price(size_t cnt) const
	{
		if (cnt >= min_qty)
		{
			return cnt * (1 - discount) * price;
		}
		else
		{
			return cnt * price;
		}
	}

private:
	size_t min_qty;
	double discount;
};

void print_total_1(ostream& os, const Item_base item, size_t n)
{
	os << "ISBN: " << item.book() << ", " << "number sold: " << n << ", " << "total price: " << item.net_price(n) << endl;
}

void print_total_2(ostream& os, const Item_base* item, size_t n)
{
	os << "ISBN: " << item->book() << ", " << "number sold: " << n << ", " << "total price: " << item->net_price(n) << endl;
}

void print_total_3(ostream& os, const Item_base& item, size_t n)
{
	os << "ISBN: " << item.book() << ", " << "number sold: " << n << ", " << "total price: " << item.net_price(n) << endl;
}

int main()
{
	
	Item_base item("0-12-3456-789", 9.9);
	Bulk_item item2("0-12-3456-789", 9.9, 10, 0.12);
	
	// transform object from dericed class to base class
	print_total_1(cout, item, 10);
	//print_total_1(cout, item2, 10);//not good, it is object transformation

	print_total_2(cout, &item, 10);
	print_total_2(cout, &item2, 10);//good, it is pointer transformation

	print_total_3(cout, item, 10);
	print_total_3(cout, item2, 10);//good, it is reference trnasformation

	//transform object from base class to dericed class
	Bulk_item* p = static_cast<Bulk_item*> (&item);
	p->net_price(10); //it is ok, but dangerous

	system("pause");
	return 0;
}