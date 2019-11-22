#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
//20191122######################################################################
//查找输入整数中二进制1的个数

int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		for (int i = 0; i<32; i++)
		{
			if (n >> i & 1)
			{
				count++;
			}
		}
		cout << count << endl;
	}
}
//手套
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int sum=0;
		int left_sum=0;
		int right_sum=0;
		int left_min=INT_MAX;
		int right_min=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(left[i]*right[i]==0)
			{
				sum+=left[i];
				sum+=right[i];
			}
			else
			{
				left_sum+=left[i];
				right_sum+=right[i];
				left_min=min(left[i],left_min);
				right_min=min(right[i],right_min);
			}
		}
		return sum+min(left_sum-left_min+1,right_sum-right_min+1)+1;
	}
};

#if 0
//20191121#################################################################################
//幸运的袋子
int n;
int findall(vector<int> nums, int index, int sum, int mul)
{
	int count = 0;
	for (int i = index; i < n; i++)
	{
		sum += nums[i];
		mul *= nums[i];
		if (sum > mul)
		{
			count++;
			count += findall(nums, i + 1, sum, mul);
		}
		else if (nums[i] == 1)
		{
			count += findall(nums, i + 1, sum, mul);
		}
		else
		{
			break;
		}
		sum -= nums[i];
		mul /= nums[i];
		while (i < n - 1 && nums[i] == nums[i + 1])
		{
			i++;
		}
	}
	return count;
}

int main()
{
	while(cin>>n)
	{
		vector<int> x;
		x.resize(n,0);
		int mul=1;
		int sum=0;
	    int count=0;
		for(int i=0;i<x.size();i++)
		{
			cin>>x[i];
		}
		sort(x.begin(),x.end());
		cout<<findall(x,0,0,1)<<endl;
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		vector<int> x;
		x.resize(n,0);
		int mul=1;
		int sum=0;
		int count=0;
		for(int i=0;i<x.size();i++)
		{
			cin>>x[i];
		}
		sort(x.begin(),x.end());
		for(int i=0;i<x.size();i++)
		{
			mul*=x[i];
			sum+=x[i];
		}
		while(mul>sum)
		{
			x.pop_back();
			sum = 0;
			mul = 1;
			for(int i=0;i<x.size();i++)
			{
				mul*=x[i];
				sum+=x[i];
			}
		}
		if(x.empty())
		{
			cout<<count<<endl;
			return 0;
		}
		else
		{
			while (sum >= mul)
			{
				count++;
				x.pop_back();
				sum = 0;
				mul = 1;
				for (int i = 0; i<x.size()&&x.size()>1; i++)
				{
					mul *= x[i];
					sum += x[i];
				}
			}
		}
		cout<<count<<endl;
	}
}

//参数解析***********************
int main()
{
	string str;
	while (getline(cin, str))
	{
		int n = 0;
		int count = 0;
		int num = 0;
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i-1] == ' '&&str[i]!=' ')
			{
				num++;
			}
		}
		cout << num + 1 << endl;
		for (int i = 0; i < str.size()+1; i++)
		{
			count++;
			if (str[i] == ' ')
			{
					string str1 = str.substr(n, count);
					cout << str1 << endl;
					n = i + 1;
					count = 0;
			}
			if (i == str.size())
			{
				string str1 = str.substr(n, count-1);
				cout << str1 << endl;
			}
		}
	}
}

int main()
{
	string str;
	while(cin>>str)
	{
		int num = 0;
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i-1] == ' '&&str[i]!=' ')
			{
				num++;
			}
		}
		cout << num + 1 << endl;
		char * cstr = new char [str.length()+1];
		strcpy (cstr, str.c_str());
		char* ptr=strtok(cstr," ");
		while(ptr!=NULL)
		{
			printf("%s\n",ptr);
			ptr=strtok(NULL," ");
		}
	}
}
//20191118#########################################################
//二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n + m;
	}
};
//查找组成一个偶数最接近的两个素数
bool IsPrime(int x)
{
	for (int i = 2; i < x / 2; i++)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n % 2 != 0)
		{
			return 0;
		}
		int x = 0;
		int y = 0;
		//int dest = 0;
		//int min = 0;
		for (int i = 2; i <= n / 2; i++)
		{
			//dest = n - i - i;
			if (IsPrime(i) && IsPrime(n - i))
			{
				//if (min == 0 || dest>min)
				//{
				x = i;
				y = n - i;
				//}
			}
		}
		cout << x << endl;
		cout << y << endl;
	}
}


//20191117##########################################################################
//求最大连续bit数
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int count = 0;
		int newcount = 0;
		for (int i = 0; i<32;)
		{
			count = 0;
			while (n >> i & 1)
			{
				count++;
				i++;
			}
			i++;
			if (count>newcount)
			{
				newcount = count;
			}
		}
		cout << newcount << endl;
	}
}
#endif