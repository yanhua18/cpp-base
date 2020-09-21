#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<Windows.h>
#include<algorithm>
#include<vector>
#if 0

#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v;
		string str;
		for (int i = 0; i<n; ++i)
		{
			cin >> str;
			v.push_back(str);
		}
		for (int i = 0; i<n; ++i)
		{
			if (v[i].size()<3)
				cout << "NO" << endl;
			else
			{
				string str1 = v[i].substr(0, 3);
				int flag = 1;
				for (int j = 3; j<v[i].size();)
				{
					int num = 3;
					int a = 0;
					int count = 0;
					while (num && j<v[i].size())
					{
						if (v[i][j] == str1[a])
							count++, a++;
						num--,j++;
					}
					if (count < 2)
					{
						flag = 0;
						break;
					}

				}
				if (flag)
					cout << "Yes" << endl;
				else
					cout << "No" << endl;
			}
		}
	}
}

int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		char arr[256] = { 0 };
		int count = 0;
		for (int i = 0; i<str2.size(); ++i)
		{
			arr[str2[i]]++;
			count++;
		}
		int sum = count;
		for (int i = 0; i<str1.size(); ++i)
		{
			if (arr[str1[i]]>0)
			{
				arr[str1[i]]--;
				count--;
			}
		}
		cout << sum - count << endl;
	}
}
//Ìæ»»¿Õ¸ñ
void replaceSpace(char *str, int length) {
	int count=0;
	for(int i=0;i<length;++i)
	{
		if(str[i]==' ')
			count++;
	}
	int newLen=length+2*count;
	char* oldl = str + length;
	char* newl = str + newLen;
	while (oldl>=str&&newl >= str)
	{
		if (*oldl == ' ')
		{
			*newl-- = '%';
			*newl-- = '0';
			*newl-- = '2';
			oldl--;
		}
		else
		{
			*newl-- = *oldl--;
		}
	}
}
int main()
{
	char* str = { "We Are Happy." };
	int length = 13;
	replaceSpace(str, length);
}



//Ðý×ª×Ö·ûÓÎÏ·
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> vv(m);
		for (int i = 0; i<vv.size(); ++i)
		{
			vv[i].resize(n, 0);
		}
		int count = 0;
		char temp = 'A';
		int i = 0, j = 0;
		int flag = 0;
		while (count != m*n)
		{
			vv[i][j] = temp;
			count++;
			temp = count % 26 +'A';
			if (flag == 0)
			{
				if (j + 1<n && vv[i][j + 1] == 0)
					j++;
				else
					flag = 1, i++;
			}
			else if (flag == 1)
			{
				if (i + 1<m && vv[i + 1][j] == 0)
					i++;
				else
					flag = 2, j--;
			}
			else if (flag == 2)
			{
				if (j - 1 >= 0 && vv[i][j - 1] == 0)
					j--;
				else
					flag = 3, i--;
			}
			else if (flag == 3)
			{
				if (i - 1 >= 0 && vv[i - 1][j] == 0)
					i--;
				else
					flag = 0, j++;
			}
		}
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				cout << " " << vv[i][j];
			}
			cout << endl;
		}
	}
}
#endif
#if 0

#include<iostream>
using namespace std;
#include<string>
#include<vector>
int main()
{
	string str;

	while (1)
	{
		getline(cin, str);
		vector<string> vv;

		for (int i = 0; i<str.size(); i++)
		{
			string s;
			int flag = 0;
			while (str[i] >= '0'&&str[i] <= '9')
			{
				s += str[i];
				i++;
				flag = 1;
			}
			if (flag&&(str[i]!='%'))
				vv.push_back(s);
		}
		for (int i = 0; i<vv.size(); ++i)
		{
			for (int j = 0; i<vv[i].size(); j++)
			{
				if (vv[i][j] == '0')
					vv[i].erase(j);
			}
			int temp = stoi(vv[i]);
			if (temp >= 1000 && temp <= 3999)
			{
				cout << vv[i] << ' ';
			}
		}
		cout << endl;
		//getchar();

	}
}



#include<iostream>
using namespace std;
#include<vector>
vector<vector<int>>  Func(vector<int> v, int n)
{
	vector<vector<int>> vv;
	vector<int> p;
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			p.push_back(v[j]);
		}
		for (int a = 0; a < p.size(); a++)
		{
			sum += p[a];
		}
		if (sum == n)
		{
			vv.push_back(p);
		}
	}
	return vv;

}
int main()
{
	vector<int> v;
	v.resize(5);
	for (int i = 0; i < v.size(); i++)
	{
		cin >> v[i];
	}
	Func(v, 4);

}





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
