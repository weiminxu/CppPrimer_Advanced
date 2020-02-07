#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

template <typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2)
	{
		return -1;
	}
	if (v1 > v2)
	{
		return 1;
	}
	return 0;
}

template <class T>
T abs(T v1)
{
	return v1 > 0 ? v1 : -v1;
}

template <typename T1, typename T2>
T1& print(T1& s, T2 val)
{
	s << val;
	return s;
}

template <class T>
const T& bigger(const T& v1, const T& v2)
{
	return v1 > v2 ? v1 : v2;
}


int main()
{
	double d1 = 1.23;
	double d2 = 9.56;
	cout << compare(d1, d2) << endl;

	double dval = -0.88;
	cout << abs(dval) << endl;
	float fval = -12.3;
	string oristr = "this is a test";
	string desstr;
	ostringstream oss(desstr);
	ofstream outFile("result.dat");

	print(cout, -3) << endl;
	print(cout, dval) << endl;
	print(cout, fval) << endl;
	print(cout, oristr) << endl;

	print(outFile, -3) << endl;
	print(outFile, dval) << endl;
	print(outFile, fval) << endl;
	print(outFile, oristr) << endl;
	outFile.close();

	print(oss, -3);
	print(oss, dval);
	print(oss, fval);
	print(oss, oristr);

	cout << bigger(d1, d2) << endl;

	system("pause");
	return 0;
}