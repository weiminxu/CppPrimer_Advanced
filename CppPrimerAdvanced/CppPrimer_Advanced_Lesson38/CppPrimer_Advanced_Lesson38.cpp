#include <iostream>
#include "Array.h"

using namespace std;

int main()
{

	/*for (int i = 0; i < 10; i++)
	{
		cout << array.getPointer()[i] << endl;
	}*/

	try
	{
		/*array[15] = 4;
		cout << "Hello World!" << "  " << array[15] << endl;*/
		Array array(-10);
		for (int j = 0; j < 50; j++)
		{
			array[j] = j;
			cout << "intArray[" << j << "] okay..." << endl;
		}
	}
	catch (Array::xBoundary)
	{
		cout << "subscript is not in bounds!" << endl;
	}
	catch (Array::xNegative)
	{
		cout << "subscript is negative!" << endl;
	}
	catch (...)
	{
		cout << "unknown error happened!" << endl;
	}
	

	system("pause");
	return 0;
}