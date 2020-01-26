#include <iostream>

using namespace std;

class String
{
private:
	char* ptrChar;

public:
	String(char const* chars = "");
	String(String const& str);
	~String();

	void display() const;
	String& operator++();//fornt ++
	String const operator++(int); //tail ++
};

String::String(char const* chars)
{
	chars = chars ? chars : "";
	ptrChar = new char[strlen(chars)+1];
	strcpy_s(ptrChar, strlen(chars) + 1, chars);
}

String::String(String const& str)
{
	ptrChar = new char[strlen(str.ptrChar) + 1];
	strcpy_s(ptrChar, strlen(str.ptrChar)+1, str.ptrChar);

}

String::~String()
{
	delete[] ptrChar;
}

String& String::operator++() //fornt ++
{
	for (size_t i = 0; i < strlen(ptrChar); i++)
	{
		++ptrChar[i];
	}

	return *this;
}

String const String::operator++(int) //tail ++
{
	String copy(*this);
	++(*this);

	return copy;
}

void String::display() const
{
	cout << ptrChar << endl;
}


int main()
{
	String s("abcdefghijklmn");
	s.display();
	++s;
	s.display();
	s++;
	s.display();

	system("pause");
	return 0;
}