#include<iostream>
using namespace std;




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

#if 0
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