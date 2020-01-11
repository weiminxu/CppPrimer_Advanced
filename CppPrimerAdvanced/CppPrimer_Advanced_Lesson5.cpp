#include <iostream>
#include <string>

using namespace std;

/*
class Person
{
private:
	string name;
	string address;

public:
	Person(const std::string& nm, const std::string& adr) :name(nm), address(adr) {}

	std::string getName() const { return this->name; }
	std::string getAddress() const { return this->address; }

};
*/

class Screen
{
private:
	std::string contents;
	std::string::size_type cursor;
	std::string::size_type height, width;
	void do_display(std::ostream& os) const
	{
		os << contents;
	}
	
public:
	Screen(std::string::size_type ht = 0, std::string::size_type wd = 0) :contents(ht* wd, 'A'), cursor(0), height(ht), width(wd) {}
	char get() const { return contents[cursor]; }
	char get(std::string::size_type r, std::string::size_type c) const
	{
		std::string::size_type row = r * width;
		return contents[row + c];
	}

	Screen& move(std::string::size_type r, std::string::size_type c);
	//Screen& move(std::string::size_type r, std::string::size_type c);
	void set(std::string::size_type, std::string::size_type, char);
	Screen& set(char);
	
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	

	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}
};

Screen& Screen::move(std::string::size_type r, std::string::size_type c)
{
	std::string::size_type row = r * width;
	cursor = row + c;
	return *this;
}

void Screen::set(std::string::size_type r, std::string::size_type c, char ch)
{
	std::string::size_type row = r * width;
	contents[row + c] = ch;
}

Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

int main()
{
	/*
	Person person("zhangfei", "82 Walkfield, NewYork City, America");
	cout << person.getAddress() << endl;
	cout << person.getName() << endl;
	*/
	Screen myScreen(5, 3);
	//cout << myScreen.get() << endl;
	//cout << myScreen.get(3, 2) << endl;
	//myScreen.set(3, 2, 'B');
	//cout << myScreen.get(3, 2) << endl;
	//this is important
	//myScreen.move(2,3);
	//myScreen.set('C');
	//cout << myScreen.get() << endl;

	//this is the simplest waty to implement
	myScreen.move(2,3).set('l').display(cout).set('K').display(cout);
	//myScreen.move(4,0).set('X').move(4, 1).set('Y').move(4, 2).set('Z').display(cout);
	//cout << myScreen.get() << endl;
	//myScreen.display(cout);

	return 0;
}