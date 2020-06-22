//1,给定整数序列求连续子串最大和
//动态规划求解
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	vector<int>v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
	}
	int sum = v[0];
	int max = v[0];
	n = v.size();
	for (int i = 1; i<n; i++)
	{
		sum = (sum>0) ? sum + v[i] : v[i];
		if (sum>max)
		{
			max = sum;
		}
	}
	cout << max << endl;
}