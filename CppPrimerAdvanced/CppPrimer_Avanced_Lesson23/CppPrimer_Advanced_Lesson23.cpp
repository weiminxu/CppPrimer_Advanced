#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

struct absInt
{
public:
	//overload operator:function call operator
	int operator()(int val)
	{
		return val < 0 ? -val : val;
	}

};

template<typename elementType>
struct DisplayElement//functionality object which is a class
{
public:
	int m_nCount;

	DisplayElement() :m_nCount(0) {}

	void operator() (const elementType& element) 
	{
		++m_nCount;
		cout << element << ' ';
	}
};

template<typename elementType>
void FuncDisplayElement(const elementType& element)//plaint functionality
{
	cout << element << ' ';
}

template<typename numberType>
struct IsMultiple
{
	numberType m_Divisor;

	IsMultiple(const numberType& divisor)
	{
		m_Divisor = divisor;
	}

	bool operator() (const numberType& element) const
	{
		return ((element % m_Divisor) == 0);
	}
};

template<typename elementType>
class CMultipy
{
public:
	elementType operator()(const elementType& elem1, const elementType& elem2)
	{
		return elem1 * elem2;
	}
};

class CCompareStringNoCase
{
public:
	bool operator()(const string& str1, const string& str2) const
	{
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		transform(str1.begin(), str1.end(), str1LowerCase.begin(), tolower);

		string str2LowerCase;
		str2LowerCase.resize(str2.size());
		transform(str2.begin(), str2.end(), str2LowerCase.begin(), tolower);

		return (str1LowerCase < str2LowerCase);
	}
};


int main()
{
	{
		int i = -42;
		absInt absObj;
		unsigned int ui = absObj(i);
		cout << ui << endl;
	}
	
	{
		vector<int> a;
		for (auto i = 0; i < 10; i++)
		{
			a.push_back(i);
		}
		
		list<char> b;
		for (char c = 'a'; c < 'k'; c++)
		{
			b.push_back(c);
		}

		//for_each(a.begin(), a.end(), DisplayElement<int>());
		//cout << endl;
		DisplayElement<int> mResult;
		mResult = for_each(a.begin(), a.end(), mResult);
		cout << endl << "*** "<<mResult.m_nCount <<" ***"<< endl;

		for_each(b.begin(), b.end(), DisplayElement<char>());
		cout << endl;
	}
	
	{
		vector<int> vecIntegers;
		for (int i = 25; i < 99; ++i)
		{
			vecIntegers.push_back(i);
		}
		vector<int>::iterator iElement;
		iElement = find_if(vecIntegers.begin(), vecIntegers.end(), IsMultiple<int>(4));
		if (iElement != vecIntegers.end())
		{
			cout << "the first number: " << *iElement << " is divised by 4" << endl;
		}
	}

	{
		vector<int> a, b;
		for (int i = 0; i < 10; ++i)
		{
			a.push_back(i);
		}

		for (int j = 100; j < 110; ++j)
		{
			b.push_back(j);
		}

		vector<int> mResult;
		mResult.resize(10);

		transform(a.begin(), a.end(), b.begin(), mResult.begin(), CMultipy<int>());

		for (size_t nIndex = 0; nIndex < mResult.size(); ++nIndex)
		{
			cout << mResult[nIndex] << endl;
		}
	}

	{
		set<string, CCompareStringNoCase> names;
		names.insert("Tina");
		names.insert("jim");
		names.insert("Jack");
		names.insert("Same");
		names.insert("hello");

		set<string, CCompareStringNoCase>::iterator iNameFound = names.find("jack");
		if (iNameFound != names.end())
		{
			cout << "it was found: " << *iNameFound << endl;
		}
		else
		{
			cout << "it was not found: " << *iNameFound << endl;
		}
	}

	system("pause");
	return 0;
}