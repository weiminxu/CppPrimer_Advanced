#include <iostream>
#include <stdlib.h>

using namespace std;

class Date
{
private:
	int month, day, year;

public:
	Date(int m = 0, int d = 0, int y = 0) : month(m), day(d), year(y) {}

	int operator==(Date& dt) const;
	int operator!=(Date& dt) const;
	int operator<(Date& dt) const;
	int operator>(Date& dt) const;
	int operator>=(Date& dt) const;
	int operator<=(Date& dt) const;
};

int Date::operator==(Date& dt) const
{
	return (month == dt.month) && (day == dt.day) && (year == dt.year);
}

int Date::operator!=(Date& dt) const
{
	return !(*this == dt);
}

int Date::operator<(Date& dt) const
{
	if (year == dt.year)
	{
		if (month == dt.month)
		{
			return day < dt.day;
		}
		return month < dt.month;
	}
	return year < dt.year;
}


int main()
{
	Date d1(2, 14, 2005);
	Date d2(6, 19, 2005);
	Date d3(2, 14, 2005);

	if (d1 < d2)
	{
		cout << "d1 is less than d2" << endl;
	}

	if (d1 == d3)
	{
		cout << "d1 equal d3" << endl;
	}

	return 0;
}