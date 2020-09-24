#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str;
	while (cin >> str)
	{
		
		string res;
		for (int i = 0; i<str.size(); ++i)
		{
			int count = 1;
			res += str[i];
			while (str[i] == str[i + 1])
			{
				count++;
				i++;
			}
			res += to_string(count);
		}
		if (res.size()<str.size())
		{
			cout << res << endl;
		}
		else
		{
			cout << str << endl;
		}
	}
}
