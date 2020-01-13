#include <iostream>
#include <string>

/*
  if there is a pointer, 1)copy constructor should be overwrited;
  2)and the assignment constructor should be overwrited;
  3)and the deconstructor should be overwrited.
*/

using namespace std;

class NoName
{
public:
	NoName() :pstring(new std::string), i(0), d(0) 
	{
		cout << "it is the constructor!" << endl;
		//oper file
		//connect database
		//allocate memory dynamically
	}
	~NoName();

	NoName(const NoName& othr);
	NoName& operator=(const NoName& othr);

private:
	std::string* pstring;
	int i;
	double d;
};

NoName::~NoName()
{
	cout << "it is deconstructor!" << endl;
	delete pstring;
	//close file
	//connect database
	//release memory
	//recycle memory dynamically
}

NoName::NoName(const NoName& othr)
{
	pstring = new std::string(*(othr.pstring));
	this->i = othr.i;
	this->d = othr.d;
}

NoName& NoName::operator=(const NoName& othr)
{
	pstring = new std::string;
	*pstring = *(othr.pstring);

	this->i = othr.i;
	this->d = othr.d;

	return *this;
}


int main()
{
	NoName nn;
	NoName* ptr = new NoName;
	delete ptr;

	return 0;
}