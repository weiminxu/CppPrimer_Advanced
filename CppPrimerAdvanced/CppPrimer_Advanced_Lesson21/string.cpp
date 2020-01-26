#include "string.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

String::String(char const* chars)
{
	chars = chars ? chars : "";
	ptrChars = new char[std::strlen(chars) + 1];
	strcpy_s(ptrChars, strlen(chars) + 1, chars);
}

String::String(String const& str)
{
	ptrChars = new char[strlen(str.ptrChars) + 1];
	strcpy_s(ptrChars, strlen(str.ptrChars)+1,str.ptrChars);
}

String::~String()
{
	delete[] ptrChars;
}

void String::display() const
{
	cout << ptrChars << endl;
}