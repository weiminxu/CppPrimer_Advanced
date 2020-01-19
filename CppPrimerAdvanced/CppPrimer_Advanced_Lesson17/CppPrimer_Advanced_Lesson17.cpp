#include <iostream>
#include <string>
#include "Sales_item.h"

using namespace std;

int main()
{
	string str = "2-123-4567-X";
	Sales_item a(str, 10, 120);
	Sales_item b(str, 10, 120);

	if (a == b)
	{
		cout << "the two items are the same!";

	}
	else
	{
		cout << "the two items are different!";
	}
	return 0;
}