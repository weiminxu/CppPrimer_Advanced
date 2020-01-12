#include <iostream>

void A()
{
	int b;
	b = 9;
	std::cout << b << std::endl;
};

void B()
{
	int a;
	a = 10;
	std::cout << a << std::endl;
};

class First
{
private:
	int memi;
	double memd;

public:
	void C()
	{
		memi = 22;
	}
	void D()
	{
		C();
	}
};

int height;
class ScreenA
{
public:
	typedef std::string::size_type index;
	char get(index r, index c) const
	{
		index row = r * width;
		return contents[row + c];
	}
	index get_cursor() const;

	void dummy_fcn(index height)
	{
		cursor = width * height; //height is coming form dummy_fcn(index height)
		cursor = width * this->height; //height is coming form class private height
		cursor = width * ::height;//height is global height, :: is global
	}


private:
	std::string contents;
	index cursor;
	index height, width;
};

ScreenA::index ScreenA::get_cursor() const
{
	return cursor;
}


int main()
{
	A();
	B();

	First first;
	First *ptr = &first;
	first.C();
	ptr->D();

	ScreenA::index ht;

	return 0;
}