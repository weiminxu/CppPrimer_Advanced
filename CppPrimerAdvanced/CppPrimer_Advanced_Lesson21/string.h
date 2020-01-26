//#pragma once
#ifndef STRING_H
#define STRING_H

class String
{
private:
	char* ptrChars;
public:
	String(char const* chars = "");
	String(String const& str);
	~String();

	void display() const;
};



#endif // !STRING_H

