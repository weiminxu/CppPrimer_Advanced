#include <iostream>
#include <string>

using namespace std;

class Item_base
{
public:
	Item_base(const std::string& book = " ", double sales_price = 0) : isbn(book), price(sales_price) {}
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

void print_total(ostream& os, Item_base* item, size_t n)
{
	os << "ISBN: " << item->book() << ", " << "number sold: " << n << ", " << "total price: " << item->net_price(n) << endl;
}

int main()
{
	Item_base* a = new Item_base("1-234-567-1", 11.0);
	Item_base* b = new Bulk_item("1-234-567-02", 22.0, 2, 0.05);

	print_total(cout, a, 2);
	print_total(cout, b, 3);

	Item_base* books[5];
	books[0] = new Item_base("0-123-456-01", 10.0);
	books[1] = new Bulk_item("0-123-456-02", 20.0, 6, 0.05);
	books[2] = new Item_base("0-123-456-01", 30.0);
	books[3] = new Bulk_item("0-123-456-02", 40.0, 4, 0.15);
	books[4] = new Bulk_item("0-123-456-02", 50.0, 2, 0.18);
	
	int num[5];
	num[0] = 2;
	num[1] = 10;
	num[2] = 1;
	num[3] = 5;
	num[4] = 3;

	for (int i = 0; i < 5; i++)
	{
		print_total(cout, books[i], num[i]);
	}

	return 0;
}