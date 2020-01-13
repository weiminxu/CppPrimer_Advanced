#include <iostream>
#include <string>

using namespace std;

double interestRate;

class Account
{
public:
	Account(std::string name, double money) :owner(name), amount(money) {}

	void applyint()
	{
		amount += amount * interestRate;
	}

	double getAmount() const
	{
		return this->amount;
	}

	void deposit(double money)
	{
		this->amount += money;
	}

	double getRate()
	{
		return interestRate;	
	}

	void setRate(double newRate)
	{
		interestRate = newRate;
	}


private:
	std::string owner;
	double amount;
	static double interestRate; //static is meaning that the variable is only one
	//static const int period = 0;// static integral can be initized
};

double Account::interestRate = 0.015;

int main()
{
	Account a("zhangsan", 1000);
	Account b("lisi", 30000);

	a.deposit(400);
	b.deposit(3000);

	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	cout << a.getRate() << endl;
	b.setRate(0.017);
	cout << a.getRate() << endl;
	cout << b.getRate() << endl;

	a.applyint();
	b.applyint();
	cout << a.getAmount() << endl;
	cout << b.getAmount() << endl;

	return 0;
}