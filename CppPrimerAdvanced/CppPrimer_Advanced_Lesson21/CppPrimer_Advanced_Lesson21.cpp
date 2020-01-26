#include <iostream>
#include "string.h"
#include "pointer.h"

using namespace std;

int main()
{
	String s("hello");
	s.display();

	String* ptr = &s;
	ptr->display();

	try 
	{
		Pointer p1("smart pointer!");
		p1->display();

		Pointer p2;
		p2->display();
	}
	catch(String const& error)
	{
		error.display();
	}
	

	system("pause");
	return 0;
}