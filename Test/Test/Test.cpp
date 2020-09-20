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













