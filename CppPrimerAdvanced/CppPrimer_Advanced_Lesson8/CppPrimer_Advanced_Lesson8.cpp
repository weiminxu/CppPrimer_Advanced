#include <iostream>

//friend class is meaning that a class can call a private variable in others classes

using namespace std;

class Screen;

class Dog
{
public:
	int foo(Screen& screen);

	int koo(Screen& screen);
};

class Screen
{
	friend int calcArea(Screen&);
	friend class Window_Mgr;
	friend int Dog::foo(Screen&);

public:
	typedef std::string::size_type index;
	explicit Screen():cursor(0), height(0), width(0) {}
	explicit Screen(int ht, int wd) :contents(ht* wd, ' '), height(ht), width(wd), cursor(0) {}
	int area() const;
	int getHeight()
	{
		return  height;
	}
	int getWidth()
	{
		return width;
	}
	void setHeight(int ht)
	{
		height = ht;
	}
	void setWidth(int wd)
	{
		width = wd;
	}

private:
	std::string contents;
	index cursor;
	int height, width;

};

inline int Screen::area() const
{
	return height * width;
}

int calcArea(Screen& screen)
{
	return screen.height * screen.width;
}

class Window_Mgr// the class is to manage the class of Screen
{
public:
	void relocate(int r, int c, Screen& s)
	{
		s.height += r;
		s.width += c;
	}
};

int Dog::foo(Screen& screen)
{
	return screen.height * screen.width;
}
int Dog::koo(Screen& screen)
{
	return screen.area();
}

int main()
{
	Screen a(60, 100);
	Screen a1;
	a1.setHeight(60);
	a1.setWidth(100);
	cout << a1.area() << endl;
	cout << calcArea(a1) << endl;

	Window_Mgr wm;
	wm.relocate(10, 30, a);
	cout << a.area();

	Dog dog;
	dog.foo(a);

	return 0;
}
