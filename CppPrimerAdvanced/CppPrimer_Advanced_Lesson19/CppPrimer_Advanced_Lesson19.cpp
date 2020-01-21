#include <iostream>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class String
{
	
private:
	char* ptrChars;

public:
	String(char const *chars = " ");
	String& operator=(String const&);

	void print();
};

String::String(char const* chars)
{
	chars = chars ? chars : " ";
	ptrChars = new char[std::strlen(chars) + 1];
	strcpy_s(ptrChars, strlen(chars)+1, chars);

}


String& String::operator=(String const& str)
{
	if (strlen(ptrChars) != strlen(str.ptrChars))
	{
		char* ptrHold = new char[strlen(str.ptrChars) + 1];
		delete[] ptrChars;
		ptrChars = ptrHold;
	}
	strcpy_s(ptrChars, strlen(str.ptrChars)+1, str.ptrChars);

	return *this;
}

void String::print()
{
	cout << ptrChars << endl;
}

int main()
{
	String s1("hello");
	s1.print();

	String s2("Dog");
	s2.print();

	s1 = s2;
	s1.print();

	system("pause");
	return 0;
}