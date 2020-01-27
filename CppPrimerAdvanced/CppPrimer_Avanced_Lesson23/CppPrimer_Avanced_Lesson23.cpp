#include <iostream>

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
struct DisplayElement
{
	void operator() (const elementType& element) const
	{
		cout << element << '';
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
	

	system("pause");
	return 0;
}