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
	//const int& operator[] (int offSet) const;

	class xBoundary{};
	class xZero {};
	class xNegative {};
	class xTooSmall {};
	class xTooBig {};
	/*class xSize 
	{
	private:
		int itsSize;

	public:
		
		xSize(int size) :itsSize(size) {}
		~xSize() {}
	};

	class xZero:public xSize 
	{
		
		xZero(int size) :xSize(size) {}
	};
	class xNegative:public xSize 
	{
		xNegative(int size) :xSize(size) {}
	};
	class xTooSmall:public xSize 
	{
		xTooSmall(int size) :xSize(size) {}
	};
	class xTooBig:public xSize 
	{
		xTooBig(int size) :xSize(size) {}
	};*/
	
};


#endif // !_Array_H_
