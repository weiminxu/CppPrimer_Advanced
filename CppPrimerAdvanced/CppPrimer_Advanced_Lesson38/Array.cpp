#include <iostream>
#include "Array.h"

Array::Array(int size) : itsSize(size)
{
	if (size == 0)
	{
		throw xZero();
	}
	else if (size < 5 && size > 0)
	{
		throw xTooSmall();
	}
	else if (size > 100)
	{
		throw xTooBig();
	}
	else if(size < 0)
	{
		throw xNegative();
	}


	pType = new int[size];

	for (int i = 0; i < size; i++)
	{
		pType[i] = 0;
	}

}

int* Array::getPointer()
{
	return pType;
}

int Array::getSize()
{
	return itsSize;
}

int& Array::operator[] (int offset)
{
	int size = this->getSize();
	if (offset >= 0 && offset < size)
	{
		return pType[offset];
	}
	else
	{
		throw xBoundary();
	}
}

//const int& Array::operator[] (int offset) const
//{
//	
//	if (offset >= 0 && offset < getSize())
//	{
//		return pType[offset];
//	}
//	else
//	{
//		throw xBoundary();
//	}
//}