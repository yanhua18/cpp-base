
#include<iostream>
using namespace std;
#include<string>

class Solution {
public:
	void reverse(int m, int n, string &s)
	{
		while(m<n)
		{
			swap(s[m],s[n]);
			m++;
			n--;
		}
	}
	string reverseStr(string s, int k) {
		int pos=2*k-1;
		int tmp=s.size();
		while(pos<tmp)
		{
			reverse(pos-2*k+1,pos-k,s);
			pos+=2*k;
		}
		if(pos-k<tmp)
		{
			reverse(pos-2*k+1,pos-k,s);
		}
		else if(pos-k>tmp&&pos-2*k-1<tmp)
		{
			reverse(pos-2*k+1,tmp-1,s);
		}
		else if(pos-2*k==tmp)
		{
			return s;
		}
		return s;
	}
};
int main()
{
	Solution d;
	cout<<d.reverseStr("abcdefg", 8)<<endl;

	system("pause");
	return 0;

}


#if 0
//2019_09_26#######################################################################################################################
//求两个字符串数字相乘得到的结果以字符串输出************************************************
class Solution {
public:
	string multiply(string num1, string num2) {
		string s;
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int count = 1;
		long long cur = 0;    
		int temp = 0;
		int getnum = 1;
		int mul = 0;
		for (end1; end1 >= 0; end1--)
		{
			cur = 0;
			temp = 0;
			count = 1;
			for (end2 = num2.size() - 1; end2 >= 0; end2--)
			{
				cur += ((num1[end1] - '0')*(num2[end2] - '0') + temp)*count;
				if (end2 > 0)
				{
					temp = cur / (10 * count);
					cur = cur % (10 * count);
					count *= 10;
				}
			}
			mul += cur*getnum;
			getnum *= 10;
		}
		s = to_string(mul);
		return s;
	}
};
int main()
{
	Solution d;
	cout << d.multiply("12345","45678") << endl;

	system("pause");
	return 0;
}


//找字符串中第一个只出现一次的字母*************************************************************
int main()
{
	int count[255]={0};
	string s;
	int i = 0;
	while(getline(cin,s))
	{
		for(int i=0;i<s.size();i++)
		{
			count[s[i]]++;
		}
		for(i=0;i<s.size();i++)
		{
			if(count[s[i]]==1)
			{
				cout<<s[i]<<endl;
				break;
			}
		}
		if (i == s.size())
		{
			cout << "-1" << endl;
		}
	}
}

//将字符串中的每一个单词进行逆转***************************************************
class Solution {
public:
	void reverse(int m,int n,string &s )
	{
		while(m<n)
		{
			swap(s[m],s[n]);
			m++;
			n--;
		}
	}
	string reverseWords(string s) {
		int pos=0;
		int temp=0;
		while (s.find(' ', pos)!=string::npos)
		{
			temp=s.find(' ',pos);
			reverse(pos,temp-1,s);
			pos=temp+1;
		}
		temp = pos;
		for (int i = 0; s[pos] != '\0'; i++)
		{
			pos++;
		}
		reverse(temp, pos-1,s);
		return s;
	}
};
int main()
{
	Solution d;
	cout << d.reverseWords("Let's take LeetCode contest") << endl;

	system("pause");
	return 0;
}


//判断两个字符串是否为变形词*******************************************************888
#include<iostream>
using namespace std;
#include<string>
int Ischangeword(string s1, string s2)
{
	int pos = 0;
	for (size_t i = 0; i<s1.size(); i++)
	{
		pos = s2.find(s1[i]);
		if (pos >= 0 && pos <= s1.size())
		{
			s2[pos] = '0';
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	size_t m, n;
	cin >> m >> n;
	string s1, s2;
	cin >> s1 >> s2;
	if (m == n)
	{
		if (Ischangeword(s1, s2))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	else
	{
		cout << "false" << endl;
	}
}

//2019_09_25#################################################################################################################33
//判断两个字符串是否互为旋转词***********************
int IsRevolve(string s1, string s2)
{
	char ch1 = s1[0];
	size_t pos = s2.find(ch1);
	for (int i = 0; i<s1.size(); i++)
	{
		if (s2[pos] == s1[i])
		{
			pos++;
		}
		else
		{
			return 0;
		}
		if (pos == s1.size())
		{
			pos = 0;
		}
	}
	return 1;
}
int main()
{
	size_t m, n;
	cin>>m>>n;
	string s1,s2;
	cin >> s1 >> s2;
	if(m==n)
	{
		if(IsRevolve(s1,s2))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}
	system("pause");
	return 0;
}

//验证是否是回文字符串（不分大小写）
class Solution {
public:
	bool isletterornumber(char c)
	{
		return c >= 'a'&&c <= 'z' || c >= '0'&&c <= '9';
	}
	bool isPalindrome(string s) {
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
			{
				s[i] += 32;
			}
		}
		int start = 0;
		int end = s.size() - 1;
		while (start <= end)
		{
			if (isletterornumber(s[start]))
			{
				if (isletterornumber(s[end]))
				{
					if (s[start] == s[end])
					{
						start++;
						end--;
					}
					else
					{
						return false;
					}
				}
				else
				{
					end--;
				}
			}
			else
			{
				start++;
			}

		}
		return true;
	}
};
//字符串中最后一个单词的长度
int main()
{
	string s;
	while(getline(cin,s))
	{
		size_t pos=s.rfind(' ');
		cout<<s.size()-pos-1<<endl;
	}
}

//找字符串中第一个只出现一次的字符的下标
class Solution {
public:
	int firstUniqChar(string s) {
		int count[128]={0};
		int i=0;
		for(i=0;i<s.size();i++)
		{
			count[s[i]]++;
		}
		for(i=0;i<s.size();i++)
		{
			if(count[s[i]]==1)
			{
				return i;
			}
		}
		return -1;
	}
};

//反转一个字符串****************************************************************
class Solution {
public:
	string reverseString(string s) {
		if (s.empty())
		{
			return s;
		}
		int start = 0;
		int end = s.size() - 1;
		while (start < end)
		{
			swap(s[start], s[end]);
			start++;
			end--;
		}
		return s;
	}
};

int main()
{
	Solution s;
	string s1("abcdefghigk");
	s.reverseString(s1);
	system("pause");
	return 0;
}


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

#endif

