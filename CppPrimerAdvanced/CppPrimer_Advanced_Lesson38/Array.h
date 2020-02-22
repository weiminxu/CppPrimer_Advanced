//#pragma once
#ifndef _Array_H_
#define _Array_H_

using namespace std;

const int DefaultSize = 10;

class Array
{
private:
	int* pType;
	int itsSize;

public:
	Array(int itsSize = DefaultSize);

	~Array()
	{
		delete []pType;
	}

	int* getPointer();
	int getSize();

	int& operator[](int offSet);
	const int& operator[] (int offSet) const;

	class xBoundary{};
	class xZero {};
	class xNegative {};
	class xTooSmall {};
	class xTooBig {};
	
};


#endif // !_Array_H_
