#include <iostream>

using namespace std;

class MyFather
{
	friend class YourFather;
public:
	MyFather():MyFatherAge(56) {}
	~MyFather() {}

	void setAge()
	{
		MyFatherAge = 20;
	}
	int getAge()
	{
		return MyFatherAge;
	}
private:
	string MyFatherName;
	size_t MyFatherAge;
};

class Myself:public MyFather
{
public:
	Myself():MyselfAge(0) {}
	~Myself() {}
private:
	string MyselfName;
	size_t MyselfAge;
};

class YourFather
{
public:
	YourFather() :YourFatherAge(50) {}
	~YourFather() {}
	int getYourFatherAge(MyFather& mf)
	{
		return mf.MyFatherAge;
	}
private:
	string YourFatherName;
	size_t YourFatherAge;
};

class Youself: public YourFather
{
public:
	Youself() :YouselfAge(30) {}
	~Youself() {}
private:
	string YouselfName;
	size_t YouselfAge;
};

int main()
{
	MyFather mf;
	cout << mf.getAge() << endl;
	YourFather yf;
	cout << yf.getYourFatherAge(mf) << endl;

	system("pause");
	return 0;
}