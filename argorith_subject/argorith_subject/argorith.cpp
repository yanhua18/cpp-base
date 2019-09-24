#include<iostream>
using namespace std;
//日期类*******************************************************************************
class Date
{
public:
	//构造函数******************************
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		if (!(year > 0) &&
			(month > 0 && month < 13) &&
			(day>0 && day <= GetDaysOfMonth(year, month)))
		{
			_year = 1900;
			_month = 1;
			_day = 1;
		}
	}
	//拷贝构造函数***************************
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	//赋值重载********************************
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//求增加多少天后的日期************************
	Date operator+(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day += days;
		while (temp._day > temp.GetDaysOfMonth(temp._year, temp._month))
		{
			temp._day -= temp.GetDaysOfMonth(temp._year, temp._month);
			temp._month += 1;
			if (temp._month > 12)
			{
				temp._month = 1;
				temp._year += 1;
			}
		}
		return temp;
	}
	//求减少多少天后的日期*********************************************
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day -= days;
		while (temp._day <= 0)
		{
			temp._month--;
			if (temp._month < 0)
			{
				temp._month = 12;
				temp._year--;
			}
			temp._day += temp.GetDaysOfMonth(temp._year, temp._month);
		}
		return temp;
	}
	//输出重载***************************************************
	friend ostream& operator<<(ostream& _cout, const Date&d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
	//两个日期对象相减*****************************************
	int operator-(const Date &d)
	{
		Date max(*this);
		Date min(d);
		if (*this < d)
		{
			swap(max, min);
		}
		int count = 0;
		while (min != max)
		{
			count++;
			min++;
		}
		return count;
	}
	//重载== *****************************************************
	bool operator==(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//重载!= *****************************************************
	bool operator!=(const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		return true;
	}

	//重载<  ******************************************
	bool operator<(const Date &d)
	{
		if ((*this)._year < d._year ||
			((*this)._year == d._year) && ((*this)._month < d._month) ||
			((*this)._year == d._year) && ((*this)._month == d._month) && (*this)._day < d._day)
		{
			return true;
		}
		return false;
	}
	//重载>  **************************************************
	bool operator>(const Date& d)const
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}

		return false;
	}
	//前置++     ************************************************
	Date & operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//后置++******************************************************
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}
	//前置--************************************
	Date & operator--()
	{
		*this = *this - 1;
		return *this;
	}
	//后置--**********************************************
	Date operator--(int)
	{
		Date temp(*this);
		*this = *this - 1;
		return temp;
	}

	
private:
	int GetDaysOfMonth(int year, int month)
	{
		int arr[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		arr[2] = 28;
		if ((0 == year % 4 && 0 != year % 100) || 0 == year % 400)
		{
			if (month == 2)
			{
				arr[2] += 1;
			}
		}
		return arr[month];
	}
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 18);
	Date d2(2020, 1, 1);
	cout << d2 - d1 << endl;

	d1 = d1 - 999;
	cout << d1 << endl;
	system("pause");
	return 0;
}