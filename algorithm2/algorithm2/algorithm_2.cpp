#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<Windows.h>
//20191128#########################################################################
//公共字串计算
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		for (int i = 0; i<str1.size(); i++)
		{
			if (str1[i]<'a' || str1[i]>'z')
			{
				str1[i] -= 'a';
			}
		}
		for (int i = 0; i<str2.size(); i++)
		{
			if (str2[i]<'a' || str2[i]>'z')
			{
				str2[i] +=32;
			}
		}
		int begin = 0;
		int len = 0;
		for (int i = 0; i < str1.size(); ++i)
		{
			int start = 0;
			int cur = -1;
			int max = 0;
			int length = 0;
			for (int j = 0, z = i; j < str2.size() && z < str1.size(); ++j)
			{
				if (max < length)
				{
					max = length;
					start = cur;
				}
				if (str1[z] == str2[j])
				{
					if (cur == -1)
					{
						cur = j;
					}
					++length;
					++z;
				}
				else
				{
					length = 0;
					cur = -1;
					z = i;
				}
			}
			if (max > len)
			{
				len = max;
				begin = start;
			}
		}
		str2 = str2.substr(begin, len+1);
		cout << str2.size()+1 << endl;
	}
}

#if 0
//字符串反转
void swap(char& a, char& b)
{
	char tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main()
{
	string str;
	while(cin>>str)
	{
		int i=0;
		int j=str.size()-1;
		while(i<=j)
		{
			swap(str[i],str[j]);
			i++;
			j--;
		}
		cout << str << endl;
	}
}

//20191127###############################################################################
//跳石板
//计算约数，求除了1和本身的约数
void divisorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			//非平方数时还有另一个数也要加入
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
}
int Jump(int N, int M)
{
	//储存的到达此stepNum点的步数，初始N为1步，从N到N为1步
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;
	for (int i = N; i < M; i++)
	{
		//N的所有约数，即为从本身这个点开始能走的数量
		vector<int> divNum;
		//0代表这个点不能到
		if (stepNum[i] == 0)
			continue;
		//求出所有能走的步数储存在divNum的容器中
		divisorNum(i, divNum);
		for (int j = 0; j < divNum.size(); j++)
		{
			//由位置i出发能到达的点为 stepNum[divNum[j]+i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i], stepNum[i] +
				1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	}
	if (stepNum[M] == 0)
		return -1;
	else
		//初始化时多给了一步，故需要减1
		return stepNum[M] - 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}


//20191126################################################################################################
//查找两个字符串a,b中的最长公共字串
int main()
{
	string str1;
	string str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() > str2.size())
		{
			swap(str1, str2);
		}
		int begin = 0;
		int len = 0;
		for (int i = 0; i < str1.size(); ++i)
		{
			int start = 0;
			int cur = -1;
			int max = 0;
			int length = 0;
			for (int j = 0, z = i; j < str2.size() && z < str1.size(); ++j)
			{
				if (max < length)
				{
					max = length;
					start = cur;
				}
				if(str1[z]==str2[j])
				{
					if(cur==-1)
					{
						cur=j;
					}
					++length;
					++z;
				}
				else
				{
					length=0;
					cur=-1;
					z=i;
				}
			}
			if (max > len)
			{
				len = max;
				begin = start;
			}
		}
		cout << str2.substr(begin, len) << endl;
	}
}

string Fun(string str1, string str2)
{
	if (str1 < str2)
	{
		swap(str1, str2);
	}
	for (int i = str2.size(); i > 0; i--)
	{
		for (int j = 0; j <= str1.size() - i; j++)
		{
			if (str1.find(str2.substr(j, i)) != string::npos)
			{
				return str2.substr(j, i);
			}
		}
	}
	return "";
}

int main()
{
	string str1;
	string str2;
	while(cin>>str1)
	{
		cin>>str2;
		string str = Fun(str1, str2);
		cout << str << endl;
	}
}


//汽水瓶
int main()
{
	vector<int> v, w;
	v.resize(10);
	int count = 0;
	int i = 0;
	while (cin >> v[i])
	{
		if (v[i] == 0)
		{
			break;
		}
		count++;
		i++;
	}
	w.resize(count);
	for(int i=0,j=0;i<count;i++,j++)
	{
		int drink=0;
		int bottle=v[i];
		int sum=0;
		while(bottle>=3)
		{
			drink=bottle/3;
			sum+=drink;
			bottle=bottle%3+drink;
			if (bottle == 2)
			{
				sum += 1;
			}
		}
		w[j]=sum;
	}
	for(int j=0;j<count;j++)
	{
		cout<<w[j]<<endl;
	}
}

//20191125####################################################################################
//统计每个月兔子的总数
int main()
{
	int n = 0;
	while (cin >> n)
	{
		int sum = 0;
		vector<int> v;
		v.resize(n + 1, 0);
		v[1] = 1;
		v[2] = 1;
		v[3] = 2;
		int i = 0;
		for (i = 4; i <= n; i++)
		{
			v[i] = v[i - 1] + v[i - 2];
		}
		cout << v[n] << endl;
	}
}
//字符串通配符
bool Match(string str1,string str2)
{
	if (str1 == ""&&str2 == "")
	{
		return true;
	}
	for(int i=0,j=0;i<str1.size()&&j<str2.size();)
	{
		if(str1[i]==str2[j])
		{
			i++,j++;
		}
		else if(str1[i]=='?')
		{
			i++,j++;
		}
		else if(str1[i]=='*')
		{
			++i, ++j;
		}
		else
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string str1;
	string str2;
	while(cin>>str1)
	{
		cin>>str2;
		if(Match(str1,str2))
		{
			cout<<"true"<<endl;
		}
		else
		{
			cout<<"false"<<endl;
		}
	}
}

//20191124#######################################################################################################
//INOC产品部--杨辉三角的变形
int Find_yanhui(int n)
{
	if (n <= 2)
	{
		return -1;
	}
	vector<vector<int>> v;
	v.resize(n);
	for (int i = 1; i <= n; i++)
	{
		v[i - 1].resize(2 * n - 1, 0);
	}
	v[0][n - 1] = v[n - 1][0] = v[n - 1][2 * n - 2] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < 2 * n - 2; j++)
		{
			v[i][j] = v[i - 1][j - 1] + v[i - 1][j] + v[i - 1][j + 1];
		}
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		if (v[n - 1][i] % 2 == 0 && v[n-1][i] != 0)
		{
			return i+1;
		}
	}
	return -1;
}
int main()
{
	int n=0;
	while(cin>>n)
	{
		int x=Find_yanhui(n);
		cout << x << endl;
	}
}

//字符串相加、超长整数相加
string addStrings(string num1, string num2) {
	int end1 = num1.size() - 1;
	int end2 = num2.size() - 1;
	int cur = 0;
	string s;
	while (end1 >= 0 || end2 >= 0 || cur != 0)
	{
		if (end1 >= 0)
		{
			cur += num1[end1--] - '0';
		}
		if (end2 >= 0)
		{
			cur += num2[end2--] - '0';
		}
		s += to_string(cur % 10);
		cur /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int main()
{
	string str1;
	string str2;
	while(cin>>str1)
	{
		cin>>str2;
		string str3;
		int count1=str1.size();
		int count2=str2.size();
		if(count1<count2)
		{
			swap(count1,count2);
			swap(str1, str2);
		}
		str3.resize(count1 + 1,0);
		int num = 0;
		int i = count1 - 1, j = count2 - 1;
		for(;i>=0&&j>=0;i--,j--)
		{
			if (((str1[i] - '0') + (str2[j] - '0'))+num >= 10)
			{
				str3[i + 1] = (str1[i] - '0') + (str2[j] - '0') - 10 + num + '0';
				num=1;
			}
			else
			{
				str3[i + 1] = (str1[i] - '0') + (str2[j] - '0') + num + '0';
				num = 0;
			}
		}
		while (i >= 0)
		{
			if ((str1[i] - '0') + num >= 10)
			{
				str3[i + 1] = (str1[i] - '0') + num - 10 + '0';
				num = 1;
				i--;
			}
			else
			{
				str3[i + 1] = (str1[i] - '0') + num + '0';
				num = 0;
				i--;
			}
		}
		if (num == 1)
		{
			str3[0] = '1';
		}
		else
		{
			str3[0] = '0';
		}
		if (str3[0] == '0')
		{
			str3.erase(0, 1);
		}
		cout << str3 << endl;
	}
}

//20191123###########################################################################################################
//扑克牌大小
int main()
{
	string str;
	while (getline(cin, str))
	{
		if (str.find("joker JOKER") != string::npos)//只要有大小王，那就一定是大小王最大
		{
			cout<<"joker JOKER"<<endl;
		}
		else
		{
			string a="345678910JQKA2jokerJOKER";
			int pos=str.find('-');
			string str1=str.substr(0,pos);
			string str2=str.substr(pos+1);
			int count1=count(str1.begin(),str1.end(),' ');//通过计算出空格的数量来进行判断是否是同类型间的比较
			int count2=count(str2.begin(),str2.end(),' ');
			string first1=str1.substr(0,str1.find(' '));
			string first2=str2.substr(0,str2.find(' '));
			if(count1==count2)//如果两手牌的长度一样，就说明应该是同类型间的比较
			{
				if(a.find(first1)>a.find(first2))//同类型间的比较主要是比较第一个字符，但由于扑克牌有着自己的大小顺序，因此需要进行一个转换
				{
					cout<<str1<<endl;
				}
				else
				{
					cout<<str2<<endl;
				}
			}
			else//长度不一样就说明不是同类型间的比较，如果有炸弹，就说明炸弹是最大的，如果没有炸弹就是非法比较输出error
			{
				if(count1==3)
				{
					cout<<str1<<endl;
				}
				else if(count2==3)
				{
					cout<<str2<<endl;
				}
				else
				{
					cout<<"ERROR"<<endl;
				}
			}
		}

	}
}

//INOC产品部-完全数计算
bool Isperfect(int n)
{
	if (n == 1)
	{
		return false;
	}
	vector<int> v;
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			v.push_back(i);
		}
	}
	v.push_back(1);
	int sum = 0;
	for (int i = 0; i<v.size(); i++)
	{
		sum += v[i];
	}
	if (sum == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int count(int n)
{
	int num = 0;
	for (int i = 0; i <= n; i++)
	{
		if (Isperfect(i))
		{
			num++;
		}
	}
	return num;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int num = 0;
		num = count(n);
		cout << num << endl;
	}
}


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
		int count = 0;
		//首先计算参数数量
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;
			//如果是双引号，向后遍历，直到下一个双引号结束
			if (str[i] == '"')
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
		}
		//以空格计算个数，空格数量比参数个数少1
		cout << count + 1 << endl;
		//用flag表示是否包含双引号，0表示有双引号
		//双引号中的空格要打印出来
		//用异或改变flag的值，两个双引号可以使flag复原
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			//有双引号，flag通过异或变为0，下一次再遇到双引号，flag置为1
			if (str[i] == '"')
				flag ^= 1;
			//双引号和普通空格不打印
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//双引号中的空格要打印
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//遇到双引号之外的空格就换行
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	}
	return 0;
}
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