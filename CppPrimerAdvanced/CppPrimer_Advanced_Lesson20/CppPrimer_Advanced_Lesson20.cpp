#include <iostream>
#include <ostream>
#include <string>
#pragma warning( disable : 4290 )

using namespace std;

class String
{
private:
	char* ptrChars;
	static String errorMessage;

public:
	String(char const* chars="");
	~String();
	char& operator[](std::size_t index);
	char operator[](std::size_t index) const;
};

String String::errorMessage("Subscript out of range!");

String::String(char const* chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[strlen(chars) + 1];
	
	strcpy_s(ptrChars, strlen(chars) + 1, chars);
} 

String::~String()
{
	delete ptrChars;
}

char& String::operator[](std::size_t index) 
{
	if (index >= strlen(ptrChars))
	{
		cout<< "Subscript out of range!" << endl;
		
	}
	
	return ptrChars[index];

	//return index >= strlen(ptrChars) ? throw errorMessage : ptrChars[index];
}

char String::operator[](std::size_t index) const
{
	if (index >= strlen(ptrChars))
	{
		cout << "Subscript out of range!" << endl;

	}

	return ptrChars[index];

}


int main()
{
	String s("hello");
	cout << s[0] << endl;
	
	s[0] = 'A';
	cout << s[0] << endl;

	system("pause");
	return 0;
}