#include <iostream>
#include <string>

using namespace std;

class Item_base
{
public:
	Item_base(const std::string& book=" ", double sales_price = 0) : isbn(book), price(sales_price) {}
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

class Bulk_item : public Item_base
{
public:
	Bulk_item(const std::string& book = " ", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0)
		:Item_base(book, sales_price), min_qty(qty), discount(disc_rate) {}

	void test()
	{
		//cout << x << endl;
		cout << price << endl;
	}
	void test2(const Bulk_item& d, const Item_base& b)
	{
		//cout << d.x << endl;
		cout << d.price << endl;
		//cout << b.x << endl;
	}
	double net_price(size_t cnt) const
	{
		if (cnt >= min_qty)
		{
			return ((_int64)cnt * (1 - discount) * price);
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


int main()
{
	Item_base item1("0-12-3456-789", 9.9);
	cout << item1.net_price(10) << endl;
	Bulk_item item2("0-12-3456-789", 9.9, 10, 0.12);
	cout << item2.net_price(11) << endl;

	item2.test();
	item2.test2(item2, item1);

	return 0;
}