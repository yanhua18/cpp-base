#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<Windows.h>
#include<algorithm>
#include<vector>

#if 0
void Reverse(int m, int n, string& str)
{
	int i = m, j = n;
	for (; m < n; m++, n--)
	{
		swap(str[m], str[n]);
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		string str;
		getchar();
		getline(cin,str);
		for (int i = 0; i<str.size(); i += n)
		{
			if (n-1+i >=str.size())
			{
				Reverse(i, str.size() - 1, str);
			}
			else
			{
				Reverse(i, n - 1 + i, str);
			}
			
		}
		cout << str << endl;
	}
}
#endif
