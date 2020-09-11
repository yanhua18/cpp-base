#if 0
#include<iostream>
using namespace std;
#include<vector>

int main()
{
	int W, L;
	while (cin >> W >> L)
	{
		vector<int> v(L, 0);
		for (int i = 0; i<L; i++)
		{
			cin >> v[i];
		}
		int max = v[0], index = 0;;
		for (int i = 1; i<L; i++)
		{
			if (v[i]>max)
			{
				max = v[i];
				index = i;
			}
		}
		int sum = max*W*L;
		int cap = 0;
		for (int i = 0; i<L; i++)
		{
			cap += v[i] * W;
		}

		int res = sum - cap;
		cout << res << endl;
	}
}
#include <stdio.h>
#include<Windows.h>


//编写函数不允许创建临时变量，求字符串的长度
int Strlen(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str + 1);
}
int main()
{
	char* str = "abcdef";
	int len = Strlen(str);
	printf("%d", len);
	system("pause");
}
//接受一个整型值（无符号），按照顺序打印它的每一位。 例如： 输入：1234，输出 1 2 3 4
void print(int n)
{
	if (n > 9)
		print(n / 10);
	printf("%d\n", n%10);
}
int main()
{
	int n = 1234;
	print(n);
	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
	vector<int> person;
	vector<int> risk;

	int val;
	while (1)
	{
		cin >> val;
		if (getchar() != '\n')
		{
			person.push_back(val);
		}
		else
		{
			break;
		}
	}
	person.push_back(val);

	while (cin >> val)
	{
		//cin >> val;
		if (getchar() != '\n')
		{
			risk.push_back(val);
		}
		else
		{
			break;
		}
	}
	risk.push_back(val);



	sort(person.begin(), person.end());
	sort(risk.begin(), risk.end());
	int num = person.size();
	for (int i = 0; i<person.size(); i++)
	{
		if (person[i]>risk[risk.size() - 1])
		{
			num--;
		}
	}
	cout << num << endl;
	return 0;
}
#endif
