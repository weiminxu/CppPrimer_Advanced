//#pragma once
#ifndef POINTER_H
#define POINTER_H

class String;
class Pointer
{
private:
	String* ptr;
	static String errorMessage;
public:
	Pointer();
	Pointer(String const& n);
	~Pointer();

	String& operator*();
	String* operator->() const;
};
#endif 
