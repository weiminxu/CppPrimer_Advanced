#include <iostream>

using namespace std;

class CDemo
{
public:
	CDemo(int pa, const char* cstr)
	{
		this->a = pa;
		this->str = new char[1024];
		strcpy_s(str, 1024, cstr);
	}

	CDemo(CDemo& cdemo)
	{
		this->a = cdemo.a;
		this->str = new char[1024];
		if (str != 0)
		{
			strcpy_s(str, 1024, cdemo.str);
		}
		
	}

	~CDemo()
	{
		delete str;
	}

	int getA() const
	{
		return a;
	}

	char* getSTR() const
	{
		return str;
	}

public:
	int a;
	char* str;

};
int main()
{
	CDemo c(10, "fefw");
	cout << c.getA() << endl;
	cout << c.getSTR() << endl;

	cout << "**************************" << endl;

	CDemo d = c;
	d.a = 9;
	d.str[0] = 'F';
	cout << d.getA() << endl;
	cout << d.getSTR() << endl;
	
	return 0;
}