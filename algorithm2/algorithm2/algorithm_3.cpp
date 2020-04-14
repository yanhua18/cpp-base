#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<stack>
#include<assert.h>
#include<time.h>

#if 0
//20200314##############################################################################################
//ţ����---�Ǽ�����
int  Func(int x)
{
	vector<int> v;
	v.resize(x+3);
	v[0]=1;
	v[1]=1;
	v[2]=2;
	for(int i=3;i<=x;i++)
	{
		v[i]=v[i-1]+v[i-2];
		if(v[i]>=10000)
			v[i]%=10000;
	}
	return v[x];
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n,0);
		string s;
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		for(int i=0;i<n;i++)
		{
			string temp = to_string(Func(v[i]));
			int size = temp.size();
			while (size < 4)
			{
				s += '0';
				size++;
			}
			s += temp;
		}
		cout<<s<<endl;
	}
}

//ʧ�ܰ汾
#include<iostream>
using namespace std;
#include<string>
#include<vector>
int Get_Mode(int x)
{
	int a = 1;
	int b = 2;
	int c;
	if (x == 1)
	{
		return a;
	}
	else if (x == 2)
	{
		return b;
	}
	else
	{
		while (x >= 3)
		{
			c = a + b;
			a = b;
			b = c;
			x--;
		}
		return c;
	}
}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> v;
		v.resize(n,0);
		string s;
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		for (int i = 0; i<n; i++)
		{

			int num = Get_Mode(v[i]);
			string temp = to_string(num);
			int size = temp.size();
			if (size > 4)
			{
				temp.erase(0, size-4);
				s += temp;
			}
			else if (size < 4)
			{
				while (size < 4)
				{
					s += '0';
					size++;
				}
				s += temp;
			}
			else
			{
				s += temp;
			}
		}
		cout << s << endl;
	}
}

//ţ����--����
int FindNumber(long long x)
{

	while (x / 10 != 0)
	{
		long long sum=0;
		while(x)
		{
			sum+=x%10;
			x=x/10;
		}
		x=sum;
	}
	return x;
}
int main()
{
	string s;
	while(cin>>s)
	{
		int x=0;
		for(auto e:s)
		{
			x+=(e-'0');
		}
		cout<<FindNumber(x)<<endl;
	}
}


//2020-3-26######################################################################################
//���ֲ���
class BinarySearch {
public:
	int getPos(vector<int> A, int n, int val) {
		int i = 0;
		int j = n - 1;
		while (i <= j)
		{
			int mid=(i+j)/2;
			if(A[mid]==val)
			{aaa
			while(A[mid]==val)
				mid--;
			return mid+1;
			}
			else if(i<j&&A[mid]>val)
			{
				j=mid-1;
			}
			else
			{
				i=mid+1;
			}
		}
		return -1;
	}
};

int main() {
	srand(time(0));
	vector<int> intList(4, 0);
	intList.reserve(4);
    vector<int>::iterator ivBegin = intList.begin();
	vector<int>::iterator ivEnd = intList.end();
	for (vector<int>::iterator iter = ivBegin;
		iter != ivEnd; iter++) {
		*iter = 100 + (rand() % 10);
	}
	for (vector<int>::iterator iter = ivBegin;
		iter != ivEnd; iter++) {
		if (*iter == 102) {
			intList.insert(iter, 121);//���в�������󣬵�����ʧЧ
		}
		else if (*iter == 100) {
			intList.erase(iter);
		}
	}
	for (int i = 0; i < intList.size(); i++) {
		cout << "value\t" << i << "\t= " << intList[i] << endl;
	}
	return 0;
}

struct Point3D {
	int x;
	int y;
	int z;
};
int main(int argc, char* argv[]) {
	Point3D* pPoint = NULL;
	int offset = (int)(&(pPoint)->z);
	printf("%d", offset);
	return 0;
}

int SizeOf(char pString[]) {
	return sizeof(pString);
}
int main(int argc, char** argv) {
	char* pString1 = "BONC_TEST";
	int size1 = sizeof(pString1);
	int size2 = sizeof(*pString1);
	char pString2[100] = "BONC_TEST";
	int size3 = sizeof(pString2);
	int size4 = SizeOf(pString2);
	printf("%d, %d, %d, %d", size1, size2, size3, size4);
	return 0;
}

class A {
private:
	int n1;
	int n2;
public:
	A(): n2(0), n1(n2 + 2) {}
	void Print() {
		std::cout << "n1: " << n1 << ", n2: " << n2 << std::endl;
	}
};
int main(int argc, char** argv) {
	A	a;
	a.Print(); //��Ϊ���캯���ǰ���Ա����������˳�������г�ʼ���ģ�����n1Ϊ���ֵ��n2Ϊ0
	return 0;
}


class A {
private:
	int m_value;
public:
	A(int value) {
		m_value = value;
	}
	void Print1() {
		printf("hello world, print1");
	}
	virtual void Print2() {
		printf("hello world, print2");
	}
	void Print3() {
		printf("%d", m_value);
	}
};
int main(int argc, char** argv) {
	A* pA = NULL;
	pA->Print1();
	pA->Print2();//ͨ���麯����ָ����������Ӧ���麯����û�ж����û���麯����
	pA->Print3();
	return 0;
}


class A {
public:
	A() {
		std::cout << "A is created." << std::endl;
		Print();
	}
	~A() {
		std::cout << "A is deleted." << std::endl;
	}
	virtual void Print() {

		std::cout << "A::Print called." << std::endl;
	}
};

class B : public A {
public:
	B() {
		std::cout << "B is created." << std::endl;
		Print();
	}
	~B() {
		std::cout << "B is deleted." << std::endl;
	}
	virtual void Print() {
		std::cout << "B::Print called." << std::endl;
	}
};

int main(int argc, char** argv) {
	A* pA = new B();
	delete pA;//��deletepAʱ����Ҫ��������������������������û�б�����Ϊ�麯�������Ի���ָ��ֻ�ܵ��û�����������Ӷ�����ڴ�й©����
	return 0;
}


#define MAX(a,b) ((a)>(b))?(a):(b)
int main()
{
	char str1[100] = "abc";
	char str2[sizeof(str1)];
	str2[0] = 'a';
	system("pause");
	return 0;
}


//����ʵ��memmove����
void* my_memmove(void* dst, const void* source, size_t num)
{
	char* dst_ = (char*)dst;
	char* src_ = (char*)source;
	if (dst_ > src_&&dst < src_ + num)
	{
		dst_ += num - 1;
		src_ += num - 1;
		while (num--)
		{
			*dst_ = *src_;
			dst_--, src_--;
		}
	}
	else
	{

		while (num--)
		{
			*dst_ = *src_;
			dst_--, src_--;
		}
	}

	return dst;

}

//����ʵ��my_memcpy
void* my_memcpy(void* dst, void* src, int num)
{
	assert(dst);
	assert(src);
	void* ret = dst;
	while (num--)
	{
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//����ʵ��my_strcpy
void* my_strcpy(char* dst, char* src)
{
	assert(dst);
	assert(src);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;
}
//����ʵ��my_strcmp
int my_strcmp(const char* src, const char* dst)
{
	assert(src);
	assert(dst);
	int ret = 0;
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) && dst)
	{
		++src, ++dst;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;

	return ret;
}

int main()
{
	char arr1[16] = "abcdzfg";
	char arr2[16];
	my_memcpy(arr2, arr1,strlen(arr1)+1);
	system("pause");
	return 0;
}
//2020-3-14#################################################################################################
/**������ǰ�����
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> v;
		TreeNode* cur = root;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur->right);
				v.push_back(cur->val);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
		}
		return v;
	}
};

/**�������������
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> v;
		TreeNode* cur = root;
		while (cur || !s.empty())
		{
			for (; cur; cur = cur->left)
			{
				s.push(cur);
			}
			if (!s.empty())
			{
				cur = s.top();
				v.push_back(cur->val);
				s.pop();
				cur = cur->right;
			}
		}
		return v;
	}
};
//#########################################################################################################
//����ģʽ
template<typename T>
class Singleton
{
	volatile static T* inst;
	static std::next_permutation lock;
public:
	static T* GetInstance()
	{
		if (inst == NULL)
		{
			lock.lock();
			if (inst == NULL)
			{
				inst = new T();
			}
			lock.unlock();
		}
		return inst;
		}
	}

//����ģʽ
template<typename T>
class singleton
{
	static T data;
public:
	static T* GetInstance()
	{
		return &data;
	}
};


//2019-2-14#####################################################################################
//2---67,���������
class Solution {
public:
	string addBinary(string a, string b) {
		int longA = a.size() - 1;
		int longB = b.size() - 1;
		string c;
		int flag = 0;
		while (longA >= 0 && longB >= 0)
		{
			int temp = a[longA] - '0' + b[longB] - '0' + flag;
			if (temp >= 2)
			{
				flag = 1;
				c += (temp % 2 + '0');
				longA--;
				longB--;
			}
			else
			{
				c += (temp % 2 + '0');
				flag = 0;
				longA--;
				longB--;
			}

		}
		while (longA >= 0)
		{
			c += (a[longA] - '0' + flag) % 2 + '0';
			if (a[longA] - '0' + flag >= 2)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			longA--;
		}
		while (longB >= 0)
		{
			c += (b[longB] - '0' + flag) % 2 + '0';
			if (b[longB] - '0' + flag >= 2)
			{
				flag = 1;
			}
			else
			{
				flag = 0;
			}
			longB--;
		}
		if (flag == 1)
		{
			c += '1';
		}
		reverse(c.begin(), c.end());
		return c;                
	}
};

//1---1,����֮��
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
		int i = 0, j = nums.size();
		for (; i<nums.size() - 1; i++)
		{
			for (j = nums.size() - 1; j>i; j--)
			{
				if (nums[i] + nums[j] == target)
				{
					v.push_back(i);
					v.push_back(j);
				}
			}
		}
		return v;
	}
};

//2020-2-13################################################################################
//2---414�����������
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(nums.rbegin(), nums.rend());
		int i = 0;
		int temp = nums[i];
		int count = 0;
		while (i<nums.size() && count<2)
		{
			if (temp>nums[i])
			{
				temp = nums[i];
				count++;
				i++;
			}
			else
			{
				i++;
			}
		}
		if (count == 2)
		{
			return temp;
		}
		else
		{
			return nums[0];
		}
	}
};
//1---66,��һ
class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int size=digits.size();
		int flag=1;
		if(digits[size-1]<9)
		{
			digits[size-1]+=1;
		}
		else
		{
			int i=0;
			for(i=size-1;i>=0;i--)
			{
				if(digits[i]+flag==10)
				{
					digits[i]=(digits[i]+flag)%10;
					flag=1;
				}
				else
				{
					if(flag==1)
					{
						digits[i]+=1;
					}
					flag=0;
				}
			}
			if(i==-1&&flag==1)
			{
				digits.insert(digits.begin(),1);
			}
		}
		return digits;
	}
};

//2020-2-12################################################################################
//4�������������
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		int sum = 0;
		int max = v[0];
		for (int i = 0; i<n; i++)
		{
			sum += v[i];
			if (sum>max)
			{
				max = sum;
			}
			if(sum<0)
			{
				sum=0;
			}
		}
		cout<<max<<endl;
	}
}

//3��ɾ��str1�а���str2����ĸ
int main()
{
	string str1;
	string str2;
	while (getline(cin,str1))
	{
		getline(cin,str2);
		string str3;
		for(int i=0;i<str1.size();i++)
		{
			for(int j=0;j<str2.size();)
			{
				if(str1[i]==str2[j])
				{
					break;
				}
				else
				{
					j++;
				}
				if (j == str2.size())
				{
					str3 += str1[i];
				}
			}
		}
		cout<<str3<<endl;
	}
}

//2---724��Ѱ���������������
class Solution {
public:
	int ToSum(int a, int b, vector<int>& nums)
	{
		int sum = 0;
		for (int i = a; i<b; i++)
		{
			sum += nums[i];
		}
		return sum;
	}
	int pivotIndex(vector<int>& nums) {
		int sum = nums.size();
		int i = 0;
		while (i<sum)
		{
			int sum1 = ToSum(0, i, nums);
			int sum2 = ToSum(i + 1, sum, nums);
			if (sum1 == sum2)
			{
				return i;
			}
			else
			{
				i++;
			}
		}
		return -1;

	}
};
//1---905������ż��������
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int i = 0;
		int j = A.size() - 1;
		while (i<j)
		{
			while(A[i]%2==0&&i<j)
			{
				i++;
			}
			while(A[j]%2!=0&&i<j)
			{
				j--;
			}
			if(i<j)
			{
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
				i++;
				j--;
			}
		}
		return A;
	}
};
//2020-2-11##########################################################################################################
//2---917,������ת��ĸ
class Solution {
public:
	string reverseOnlyLetters(string S) {
		int i = 0;
		int j = S.size() - 1;
		while (i<j)
		{
			if (S[i] >= 'a'&&S[i] <= 'z' || S[i] >= 'A'&&S[i] <= 'Z')
			{
				if (S[j] >= 'a'&&S[j] <= 'z' || S[j] >= 'A'&&S[j] <= 'Z')
				{
					char temp = S[i];
					S[i] = S[j];
					S[j] = temp;
					i++;
					j--;
				}
				else
				{
					j--;
				}
			}
			else
			{
				i++;
			}
		}
		return S;
	}
};
//1---977�����������ƽ��
class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		for(int i=0;i<A.size();i++)
		{
			A[i]*=A[i];
		}
		sort(A.begin(),A.end());
		return A;
	}
};

//2020-2-10##################################################################################
//2---925,��������
class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int longA = name.size();
		int longB = typed.size();
		if (longA>longB)
			return false;
		int i = 0, j = 0;
		if (name[0] != typed[0])
			return false;
		while (i<longA&&j<longB)
		{
			if (name[i] == typed[j])
			{
				i++;
				j++;
			}
			else
			{
				if (typed[j] == name[i - 1])
				{
					j++;
				}
				else
				{
					return false;
				}
			}
		}
		if (i < longA)
		{
			return false;
		}
		while (j<longB)
		{
			if (typed[j] == name[i - 1])
			{
				j++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
//1---217,�����ظ�Ԫ��
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		int i=nums.size()-1;
		int j=0;
		while(j<i)
		{
			if(nums[j]==nums[j+1])
			{
				return true;
			}
			j++;
		}
		return false;
	}
};

//2019-2-9###########################################################################################
//2, 88,�ϲ�������������
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int sumlong = m + n - 1;
		for (m--, n--; m >= 0 && n >= 0;)
		{
			if (nums1[m]<nums2[n])
			{
				nums1[sumlong] = nums2[n];
				sumlong--;
				n--;
			}
			else
			{
				nums1[sumlong] = nums1[m];
				sumlong--;
				m--;
			}
		}
		while (n >= 0)
		{
			nums1[sumlong] = nums2[n];
			sumlong--;
			n--;
		}
	}
};
//1, 58���һ�����ʵĳ���
class Solution {
public:
	int lengthOfLastWord(string s) {
		int end=s.size()-1;
		if(end<0)
		{
			return 0;
		}
		while(s[end]==' ')
		{
			end--;
		}
		int start=end;
		for(;start>=0;start--)
		{
			if(s[start]==' ')
			{
				return end-start;
			}
		}
		return end-start;
	}
};

2019-2-8##########################################################################################################
//2,�ж�һ�������Ƿ��ǻ���������������ָ���򣨴������ң��͵��򣨴������󣩶�����һ����������
class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0)
		{
			return false;
		}
		string str;
		while (x)
		{
			int temp = x % 10;
			temp += 48;
			str += temp;
			x /= 10;
		}
		string str1 = str;
		reverse(str.begin(), str.end());
		if (str1 == str)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//1,����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		char ch[256] = { 0 };
		for (int i = 0; i<ransomNote.size(); i++)
		{
			ch[ransomNote[i]]++;
		}
		for (int i = 0; i<magazine.size(); i++)
		{
			if (ch[magazine[i]] != 0)
			{
				ch[magazine[i]]--;
			}
		}
		for (int i = 0; i<256; i++)
		{
			if (ch[i] != 0)
			{
				return false;
			}
		}
		return true;
	}
};

//2019-2-7####################################################################################################################
//2,����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
int searchInsert(vector<int>& nums, int target) {
	int i = 0;
	int j = nums.size() - 1;
	int mid = 0;
	while (i<j)
	{
		mid = (i + j) / 2;
		if (nums[mid]>target)
		{

			j = mid - 1;
		}
		else if (nums[mid]<target)
		{
			i = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	if (nums[j] >= target)
	{
		return j;
	}
	else
	{
		return j + 1;
	}

}
int main()
{
	int num[] = { 1,3};
	vector<int> nums(num, num + sizeof(num) / sizeof(int));
	int target = 0;
	int result = searchInsert(nums, target);
	
}

//1,����һ������ nums ��һ��ֵ val������Ҫԭ���Ƴ�������ֵ���� val ��Ԫ�أ������Ƴ���������³��ȡ�
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int start = 0;
		int end = nums.size() - 1;
		while (start <= end)
		{
			while (nums[start] != val&&start <= end)
			{
				start++;
				if (start > end)
					break;
			}
			while (nums[end] == val&&start <= end)
			{
				end--;
				if (end < 0)
					break;
			}
			if (start <= end)
			{
				nums[start] = nums[end];
				start++;
				end--;
			}
		}
		return start;
	}
};


//2020-2-1################################################################################################
//2,����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
class Solution {
public:
	void reverse(vector<int>& nums, int a, int b)
	{
		while (a<b)
		{
			int tmp = nums[a];
			nums[a] = nums[b];
			nums[b] = tmp;
			a++;
			b--;
		}
	}
	vector<int> rotate(vector<int>& nums, int k) {
		int num = nums.size() - 1;
		if (num == 0)
		{
			return nums;
		}
		if (num + 1 <= k)
		{
			k = k - num - 1;
		}
		reverse(nums, 0, num);
		reverse(nums, 0, k - 1);
		reverse(nums, k, num);
		return nums;
	}
};
//1,ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str���������ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ�����
class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i<str.size(); i++)
		{
			if (str[i] >= 'A'&&str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		return str;
	}
};
//2019-1-4###############################################################################
//У����----����--��Ϸ����
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str;
	while (cin >> str)
	{
		int len = str.size();
		cout << 26 * (len + 1) - len << endl;
	}
}
//2019-12-24###############################################################################
//��ΪS��������������
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> v;
		if (sum == 1)
		{
			return v;
		}
		int start = 1;
		int end = 2;
		int Tosum = start + end;
		int mid = (sum + 1) / 2;
		int x = 0;
		while (start<mid)
		{
			if (Tosum == sum)
			{
				v.resize(x + 1);
				for (int i = start; i <= end; i++)
					v[x].push_back(i);
				x++;
			}
			while (Tosum>sum&&start<mid)
			{
				Tosum -= start;
				start++;
				if (Tosum == sum)
				{
					v.resize(x + 1);
					for (int i = start; i <= end; i++)
						v[x].push_back(i);
					x++;
				}
			}
			end++;
			Tosum += end;
		}
		return v;
	}
};

//����************************************************************************
int Min(int a, int b, int c)
{
	int _min = a;
	if (a>b)
	{
		_min = b;
	}
	if (_min>c)
	{
		_min=c;
	}
	return _min;
}
int GetUglyNumber_Solution(int index) {
	if (index == 0)
	{
		return 0;
	}
	int *Uglynumber = new int[index];
	Uglynumber[0] = 1;
	int nextindex = 1;
	int *pnumber2 = Uglynumber;
	int *pnumber3 = Uglynumber;
	int *pnumber5 = Uglynumber;

	while (nextindex<index)
	{
		int temp = Min(*pnumber2 * 2, *pnumber3 * 3, *pnumber5 * 5);
		Uglynumber[nextindex] = temp;
		while (*pnumber2 * 2 <= Uglynumber[nextindex])
		{
			pnumber2++;
		}
		while (*pnumber3 * 3 <= Uglynumber[nextindex])
		{
			pnumber3++;
		}
		while (*pnumber5 * 5 <= Uglynumber[nextindex])
		{
			pnumber5++;
		}
		nextindex++;
	}
	int number = Uglynumber[nextindex - 1];
	delete[] Uglynumber;
	return number;
}

int main()
{
	int x=GetUglyNumber_Solution(5);
	cout << x << endl;
	system("pause");
	return 0;
}

//2019-12-22#############################################################################
/*������������˫������
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void Change(TreeNode* pRootOfTree,TreeNode* &pNode)
	{
		if(pRootOfTree==nullptr)
		{
			return ;
		}
		Change(pRootOfTree->left,pNode);

		pRootOfTree->left=pNode;
		if(pNode)
		{
			pNode->right=pRootOfTree;
		}
		pNode=pRootOfTree;

		Change(pRootOfTree->right,pNode);
	}
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if(pRootOfTree==nullptr)
		{
			return nullptr;
		}
		TreeNode* pNode=nullptr;
		Change(pRootOfTree,pNode);
		TreeNode* res = pRootOfTree;
		while(res ->left)
			res = res ->left;
		return res;
	}
};
//2019-12-18#############################################################################
/*�Ѷ�������ӡ�ɶ���
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> vv;
		if(pRoot==nullptr)
		{
			return vv;
		}
		queue<TreeNode*> queArray;
		vector<int> v;
		queArray.push(pRoot);
		int len=0;
		int toPrint=1;
		while(!queArray.empty())
		{
			TreeNode* pTemp=queArray.front();
			queArray.pop();
			v.push_back(pTemp->val);
			if(pTemp->left)
			{
				queArray.push(pTemp->left);
				++len;
			}
			if(pTemp->right)
			{
				queArray.push(pTemp->right);
				++len;
			}
			--toPrint;
			if(toPrint==0)
			{
				vv.push_back(v);
				toPrint=len;
				len=0;
				v.clear();
			}
		}
		return vv;
	}

};
//2019-12-17##############################################################################
/*�����������
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if(pRoot==nullptr)
		{
			return 0;
		}
		int leftL=TreeDepth(pRoot->left);
		int rightL=TreeDepth(pRoot->right);
		if(leftL>rightL)
		{
			return leftL+1;
		}
		else
		{
			return rightL+1;
		}
	}
};
/*�������к�Ϊĳһֵ��·��
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};*/
class Solution {
public:
	void FindPath(TreeNode* root, int expectNumber, vector<vector<int>>& res, vector<int> path, int curNumber)
	{
		curNumber += root->val;
		path.push_back(root->val);
		if (curNumber == expectNumber&&root->left == nullptr&&root->right == nullptr)
		{
			res.push_back(path);
		}
		if (root->left)
		{
			FindPath(root->left, expectNumber, res, path, curNumber);
		}
		if (root->right)
		{
			FindPath(root->right, expectNumber, res, path, curNumber);
		}
		path.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> res;
		if (root == nullptr)
		{
			return res;
		}
		int curNumber = 0;
		vector<int> path;
		FindPath(root, expectNumber, res, path, curNumber);
		return res;
	}
};

//2019-12-16##########################################################################################
//�����������ĺ������
class Solution {
public:
	bool back_seach(vector<int> sequence, int start, int length)
	{
		int root = sequence[length - 1];
		int i = 0;
		while (sequence[i]<root&&i<length - 1)
		{
			i++;
		}
		int j = i;
		while (j<length - 1)
		{
			if (sequence[j]>root)
			{
				j++;
			}
			else
			{
				return false;
			}
		}
		bool left = true;
		if (i>0)
		{
			left = back_seach(sequence, 0, i);
		}
		bool right = true;
		if (i<length - 1)
		{
			right = back_seach(sequence, i, length - i - 1);
		}
		return (left&&right);
	}
	bool VerifySquenceOfBST(vector<int> sequence) {
		int length = sequence.size();
		if (length == 0)
		{
			return false;
		}
		bool result = back_seach(sequence, 0, length);
		return result;
	}
};
//ջ��ѹ�룬��������
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		int length = pushV.size();
		if (length<0)
		{
			return false;
		}
		int pushIndex = 0;
		int popIndex = 0;
		stack<int> stackV;
		while (popIndex<length)
		{
			while (stackV.empty() || stackV.top() != popV[popIndex])
			{
				if (pushIndex >= length)
				{
					break;
				}
				stackV.push(pushV[pushIndex]);
				pushIndex++;
			}
			if (stackV.top() != popV[popIndex])
			{
				break;
			}
			popIndex++;
			stackV.pop();
			if (stackV.empty() && popIndex == length)
			{
				return true;
			}
		}
		return false;
	}
};
#endif