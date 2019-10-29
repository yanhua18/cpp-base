
#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<functional>




#if 0
//20191029########################################################################################################################
//������ֻ����һ�ε����֣�һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int sum=0;
		int pos=0;
		for(int i=0;i<data.size();i++)
		{
			sum^=data[i];
		}
		for(int i=0;i<32;i++)
		{
			if(sum>>i&1)
			{
				pos=i;
				break;
			}
		}
		vector<int> d1;
		vector<int> d2;
		for(int i=0;i<data.size();i++)
		{
			if(data[i]>>pos&1)
			{
				d1.push_back(data[i]);
			}
			else
			{
				d2.push_back(data[i]);
			}
		}
		for(int i=0;i<d1.size();i++)
		{
			*num1^=d1[i];
		}
		for(int i=0;i<d2.size();i++)
		{
			*num2^=d2[i];
		}
	}
};
//��ת����˳���У���student. a am I����ȷ�ľ���Ӧ���ǡ�I am a student.��
string ReverseSentence(string str) {
	reverse(str.begin(), str.end());
	size_t fast = 0; size_t last = fast;
	int length = str.size()-1;
	while(last <= str.size())
	{
		while (str[last] != ' '&&str[last] != '\0')
		{
			last++;
		}
		if (str[last] == '\0')
		{
			last = last - 1;
			reverse((str.begin() + fast), (str.end() - length + last));
			break;
		}
		else
		{
			reverse((str.begin() + fast), (str.end() - length + last - 1));
		}
		while (str[last] == ' ')
		{
			last++;
		}
		fast = last;
	}
	return str;
}
int main()
{
	string str = "student. a am I";
	ReverseSentence(str);
	system("pause");
	return 0;
}

//20191028#######################################################################################################
//��ΪS����������*******************************************************************
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> vv;
		int start = 0;
		int end = array.size() - 1;
		while (start < end)
		{
			if (array[start] + array[end] > sum)
			{
				end--;
			}
			else if (array[start] + array[end] < sum)
			{
				start++;
			}
			else
			{
				vv.push_back(array[start]);
				vv.push_back(array[end]);
				break;
			}
		}
		return vv;
	}
};

//��ΪS����������ɵ��������������****
	int main()
	{
		vector<int> array;
		array.push_back(1);
		array.push_back(3);
		array.push_back(5);
		array.push_back(6);
		array.push_back(7);
		array.push_back(8);
		array.push_back(10);
		array.push_back(11);
		int sum = 14;


	int mid = array.size() / 2 - 1;
	int end = mid + 1;
	int start = mid - 1;
	vector<int> vv;
	vector<int> v;
	while (end < array.size())
	{
		if (array[mid] + array[end] < sum)
		{
			end++;
		}
		else if (array[mid] + array[end] == sum)
		{
			vv.push_back(array[mid]);
			vv.push_back(array[end]);
			break;
		}
		else
		{
			break;
		}
	}
	while (start >= 0 && end < array.size())
	{
		if (array[start] + array[end] > sum)
		{
			start--;
		}
		else if (array[start] + array[end] < sum)
		{
			end++;
		}
		else
		{
			vv.push_back(array[start]);
			vv.push_back(array[end]);
			start--;
			end++;
		}
	}
	int min = vv[0];
	int max = vv[0];
	int pos1 = 0;
	int pos2 = 0;
	int i = 0;
	for (; i<vv.size(); i++)
	{
		if (vv[i]<min)
		{
			min = vv[i];
			pos1 = i;
		}
		if (vv[i]>max)
		{
			max = vv[i];
			pos2 = i;
		}
	}
	cout << vv[pos1] << vv[pos2] << endl;

	system("pause");
	return 0;
}
#endif


#if 0
//��С��k����************************************************************************
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		int length = input.size();
		vector<int> vv;
		if(length<=0||k<=0||k>length)
		{
			return vv;
		}
		sort(input.begin(),input.end());
		int i=0;
		while(i<k)
		{
			vv.push_back(input[i]);
			i++;
		}
		return vv;
	}
};
//20191027######################################################################################################################
//쳲������������n��ֵ
int Fibonacci(int n) {
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}
	int n1 = 1;
	int n2 = 1;
	int n3 = 0;
	int i = 3;
	while (i<=n)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		i++;
	}
	return n3;
}
int main()
{
	int temp = Fibonacci(6);
		cout << temp << endl;
	system("pause");
	return 0;
}

//��������1�ĸ���
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for(int i=0;i<32;i++)
		{
			if(n>>i&1)
			{
				count++;
			}
		}
		return count;
	}
};
#endif
#if 0

//20191026###################################################################################################################

//��һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy
void replaceSpace(char *str, int length) {
	int i;
	int count = 0;
	for (i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	int num = 2 * count + length;
	int j = num - 2;
	str[num-1] = '\0';
	for (i = length - 2; i >= 0,j>=0; i--)
	{
		if (str[i] == ' ')
		{
			str[j] = '0';
			j--;
			str[j] = '2';
			j--;
			str[j] = '%';
			j--;
		}
		else
		{
			str[j] = str[i];
			j--;
		}
	}
}
int main()
{
	char arr[] = "ab cdef g";
	int num = sizeof(arr) / sizeof(arr[0]);
	replaceSpace(arr, num);
	system("pause");

	return 0;
}


//��ά�����еĲ��ң���һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
	bool Find(int target, vector<vector<int> > array) {
		int i = 0;
		int j = array[0].size() - 1;
		while (i<array.size() && j >= 0)
		{
			if (array[i][j]>target)
			{
				j--;
			}
			else if (array[i][j]<target)
			{
				i++;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};



//ɾ���ַ��������ظ�����ĸ************************************************************
int  main()
{
	string s1;
	while (cin >> s1)
	{
		for (int i = 0; i<s1.size(); i++)
		{
			for (int j = i+1; j<s1.size();)
			{
				if (s1[i] == s1[j])
				{
					s1.erase(j, 1);
				}
				else
				{
					j++;
				}
			}
		}
		cout << s1 << endl;
	}

}
//
//int  main()
//{
//	string s1;
//	while (cin >> s1)
//	{
//		for (int i = 0; i<s1.size();)
//		{
//			if (s1.find(s1[i]) != string::npos)
//			{
//				s1.erase(s1.find(s1[i]), 1);                                                                                                                                                                               
//			}
//			else
//			{
//				i++;
//			}
//		}
//		cout << s1 << endl;
//	}
//}
#endif
































#if 0

20191021###############################################################################################################
�������Ĳ������*************************************************************************
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ret;
		if (root == nullptr)
		{
			return ret;
		}
		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int levelsize = q.size();
			for (int i = 0; i<levelsize; i++)
			{
				TreeNode* pcur = q.front();
				level.push_back(pcur->val);
				if (pcur->left)
				{
					q.push(pcur->left);
				}
				if (pcur->right)
				{
					q.push(pcur->right);
				}
				q.pop();
			}
			ret.push_back(level);
		}
		return ret;
	}
};
//�����е�k�����Ԫ��**********************************************************
class Solution {//��������
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> p(nums.begin(), nums.end());
		for (int i = 0; i<k - 1; i++)
		{
			p.pop();
		}
		return p.top();
	}
};
class Solution {//�������������
public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		return nums[k - 1];
	}
};
//��һ��ֻ����һ�ε��ַ�***************************************************
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		int arr[256] = { 0 };
		for (int i = 0; i<str.size(); i++)
		{
			arr[str[i]]++;
		}
		for (int i = 0; i<str.size(); i++)
		{
			if (arr[str[i]] == 1)
			{
				return i;
			}
		}
		return -1;
	}
};
//������1���ֵĴ���********************************************************
class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int temp = 0;
		int com = 0;
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			temp = i;
			while (temp)
			{
				com = temp % 10;
				temp = temp / 10;
				if (com == 1)
				{
					count++;
				}
			}
		}
		return count;
	}
};

//20191020###################################################################################################################
//���������������************************************************************************
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = array[0];
		int sum = 0;
		for (int i = 0; i<array.size(); i++)
		{
			sum += array[i];
			if (sum<array[i])
			{
				sum = array[i];
			}
			if (sum>max)
			{
				max = sum;
			}
		}
		return max;
	}
};

//�ҵ������г��ִ�������һ�������************************************************************************88
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int mid = numbers.size() / 2;
		int count = 0;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == numbers[mid])
			{
				count++;
			}
		}
		if (count>mid)
		{
			return numbers[mid];
		}
		else{
			return 0;
		}
	}
};
//����*************************************************
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quickSort(int *arr, int start, int end)
{
	int i = start;
	int j = end;
	int flag = 1;
	if (start >= end)
	{
		return;
	}
	while (i < j)
	{
		if (arr[i] > arr[j])
		{
			Swap(&arr[i], &arr[j]);
			flag = !flag;
		}
		flag ? i++ : j--;
	}
	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);
}

//20191015*******************************************************************************************************************************************
//260��ֻ����һ�ε����֣�����һ���������� nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int sum = 0;
		int pos = 0;
		vector<int> num(2, 0);
		for (int i = 0; i<nums.size(); i++)
		{
			sum ^= nums[i];
		}
		for (int i = 0; i<32; i++)
		{
			if (sum >> i & 1)
			{
				pos = i;
			}
		}
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] >> pos & 1)
			{
				num[0] ^= nums[i];
			}
			else
			{
				num[1] ^= nums[i];
			}
		}
		return num;
	}
};

//ֻ����һ�ε����֣�����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int single=0;
		for(int i=0;i<32;i++)
		{
			int count=0;
			for(int j=0;j<nums.size();j++)
			{
				if(nums[j]>>i&1)
				{
					count++;
				}
			}
			if(count%3!=0)
			{
				single=single|1<<i;
			}
		}
		return single;
	}
};
//ɵ�Ͻⷨ
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int i=0;
		int j=0;
		for(i=0;i<nums.size();i++)
		{
			for(j=0;j<nums.size();j++)
			{
				if(i==j)
				{
					continue;
				}
				if(nums[i]==nums[j])
				{
					break;
				}
			}
			if(j==nums.size())
			{
				break;
			}
		}
		return nums[i];
	}
};



//ɾ�������������ظ�����
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int i = 0;
		int j = 1;
		while (j<nums.size())
		{
			if (nums[i] != nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
			else
			{
				j++;
			}
		};

		class Solution {
		public:
			int removeDuplicates(vector<int>& nums) {
				if(nums.size()==0)
				{
					return 0;
				}
				int i = 0;
				while (i < nums.size()-1)
				{
					if (nums[i] == nums[i + 1])
					{
						nums.erase(nums.begin() + i + 1);
					}
					if (nums[i] != nums[i + 1])
					{
						i++;
					}
				}
				return nums.size();
			}
		};

		int main()
		{
			int arr[10] = { 1, 1, 3, 4, 5, 6, 6, 7, 7, 9 };
			vector<int> vv(arr, arr + sizeof(arr) / sizeof(int));
			int i = 0;
			while (i < vv.size()-1)
			{
				if (vv[i] == vv[i + 1])
				{
					vv.erase(vv.begin() + i + 1);
				}
				if (vv[i] != vv[i + 1])
				{
					i++;
				}
			}

			system("pause");
			return 0;

		}

//������ǣ�����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		for (int i = 1; i <= vv.size(); i++)
		{
			vv[i - 1].resize(i, 0);
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}
		for (int i = 2; i<vv.size(); i++)
		{
			for (int j = 1; j<vv[i].size()-1; j++)
			{
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
			}
		}
		return vv;

	}
};

//ֻ����һ�ε�����
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for(size_t i =0 ; i < nums.size(); ++i){
			value ^= nums[i];
		}
		return value;
	}
};


//20191005############################################################################################################
//�ȽϺ��˸���ַ���
class Solution {
public:
	bool backspaceCompare(string S, string T) {
		int pos;
		while(S.find('#')!=string::npos)
		{
			pos=S.find('#');
			if(pos==0)
			{
				S.erase(pos,1);
			}
			else
			{
				S.erase(pos-1,2); 
			}
		}
		while(T.find('#')!=string::npos)
		{
			pos=T.find('#');
			if(pos==0)
			{
				T.erase(pos,1);
			}
			else
			{
				T.erase(pos-1,2); 
			}
		}
		if(S.compare(T)==0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//ɾ���ַ��������������ظ��������Сд��ĸ��ɵ��ַ��� S���ظ���ɾ��������ѡ��������������ͬ����ĸ����ɾ�����ǡ�
class Solution {
public:
	string removeDuplicates(string S) {
		int i=0;
		for(i=0;i<S.size();)
		{
			if(S[i]==S[i+1])
			{
				S.erase(i,2);
				i=0;
			}
			else
			{
				i++;
			}
		}
		return S;
	}
};

//�����ַ������������
class Solution {
public:
	string gcdOfStrings(string str1, string str2) {
		string str3 = str1;
		int i = 0;
		while (str1.compare(str2) != 0)//�ж������ַ����Ƿ����
		{
			if (str1.size()<str2.size())//�������ַ����бȽϳ����Ǹ�Ϊstr1
			{
				swap(str1, str2);
			}
			for (i = 0; i<str2.size();)//�ж�str1��ǰi���ַ��Ƿ���str2���
			{
				if (str1[i] == str2[i])
				{
					i++;
				}
				else
				{
					return "";//����Ⱦͷ���
				}
			}
			str3 = str1.substr(i);//��Ⱦͽص�ǰi���ַ������Ƚ�
			str1 = str3;
		}
		return str1;//ֱ�������ַ�����Ⱦͷ���
	}
};
int main()
{
	string str1 = "ABABAB";
	string str2 = "ABAB";
	Solution d;
	string str3=d.gcdOfStrings(str1, str2);
	cout << str3 << endl;
	system("pause");
	return 0;
}


//2019_09_26#######################################################################################################################
//�������ַ���������˵õ��Ľ�����ַ������************************************************
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


//���ַ����е�һ��ֻ����һ�ε���ĸ*************************************************************
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

//���ַ����е�ÿһ�����ʽ�����ת***************************************************
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


//�ж������ַ����Ƿ�Ϊ���δ�*******************************************************888
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
//�ж������ַ����Ƿ�Ϊ��ת��***********************
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

//��֤�Ƿ��ǻ����ַ��������ִ�Сд��
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
//�ַ��������һ�����ʵĳ���
int main()
{
	string s;
	while(getline(cin,s))
	{
		size_t pos=s.rfind(' ');
		cout<<s.size()-pos-1<<endl;
	}
}

//���ַ����е�һ��ֻ����һ�ε��ַ����±�
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

//��תһ���ַ���****************************************************************
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


//������*******************************************************************************
class Date
{
public:
	//���캯��******************************
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
	//�������캯��***************************
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	//��ֵ����********************************
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
	//�����Ӷ�����������************************
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
	//����ٶ�����������*********************************************
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
	//�������***************************************************
	friend ostream& operator<<(ostream& _cout, const Date&d)
	{
		_cout << d._year << "-" << d._month << "-" << d._day;
		return _cout;
	}
	//�������ڶ������*****************************************
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
	//����== *****************************************************
	bool operator==(const Date& d)
	{
		if (_year == d._year&&_month == d._month&&_day == d._day)
		{
			return true;
		}
		return false;
	}
	//����!= *****************************************************
	bool operator!=(const Date& d)
	{
		if (*this == d)
		{
			return false;
		}
		return true;
	}

	//����<  ******************************************
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
	//����>  **************************************************
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
	//ǰ��++     ************************************************
	Date & operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//����++******************************************************
	Date operator++(int)
	{
		Date temp(*this);
		*this = *this + 1;
		return temp;
	}
	//ǰ��--************************************
	Date & operator--()
	{
		*this = *this - 1;
		return *this;
	}
	//����--**********************************************
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