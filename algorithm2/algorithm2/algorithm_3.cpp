#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<stack>

//懒汉模式
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

//饿汉模式
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



#if 0
//2019-2-14#####################################################################################
//2---67,二进制求和
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

//1---1,两数之和
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
//2---414，第三大的数
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
//1---66,加一
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
//4，求最大子序列
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

//3，删除str1中包含str2的字母
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

//2---724，寻找数组的中心索引
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
//1---905，按奇偶排序数组
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
//2---917,仅仅反转字母
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
//1---977，有序数组的平方
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
//2---925,长按键入
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
//1---217,存在重复元素
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
//2, 88,合并两个有序数组
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
//1, 58最后一个单词的长度
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
//2,判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
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

//1,给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
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
//2,给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
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

//1,给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
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
//2,给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
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
//1,实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
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
//校招题----快手--游戏海报
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
//和为S的连续正数序列
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

//丑数************************************************************************
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
/*二叉搜索树与双向链表
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
/*把二叉树打印成多行
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
/*二叉树的深度
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
/*二叉树中和为某一值的路径
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
//二叉搜索树的后序遍历
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
//栈的压入，弹出序列
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