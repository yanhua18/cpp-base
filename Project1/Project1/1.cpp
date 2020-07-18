#include<iostream>
using namespace std;
#include<vector>
#include<string>
#if 0
//1,二叉树的深度
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
		{
			return 0;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left>right) ? (left + 1) : (right + 1);
	}
};

//2,不用加减乘除做加法
class Solution {
public:
	int Add(int num1, int num2)
	{
		int sum, carry;
		do{
			sum = (num1^num2);
			carry = (num1&num2) << 1;
			num1 = sum;
			num2 = carry;
		} while (num2 != 0);
		return num1;
	}
};

//3，二叉树的镜像
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == nullptr)
		{
			return;
		}
		if (pRoot->left == nullptr&&pRoot->right == nullptr)
		{
			return;
		}
		struct TreeNode* tmp;
		tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;
		if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}
	}
};

//4,变态跳台阶
class Solution {
public:
	int jumpFloorII(int number) {
		int sum = 1;
		for (int i = 1; i<number; i++)
		{
			sum *= 2;
		}
		return sum;
	}
};

//5，求1+2+3+....+n
class A
{
public:
	A(){ N++, sum += N; };
	static void Reset()
	{
		N = 0; sum = 0;
	}
	static int Reback()
	{
		return sum;
	}
private:
	static int N;
	static int sum;
};
int A::N = 0;
int A::sum = 0;
class Solution {
public:
	int Sum_Solution(int n) {
		A::Reset();
		A* a = new A[n];
		delete[]a;
		a = nullptr;
		return A::Reback();
	}
};

//6,构建乘积数组
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int n = A.size();
		vector<int> C(n, 1);
		vector<int> D(n, 1);
		for (int i = 1; i<n; i++)
		{
			C[i] = C[i - 1] * A[i - 1];
		}
		for (int i = n - 2; i >= 0; --i)
		{
			D[i] = D[i + 1] * A[i + 1];
		}
		vector<int> B(n, 1);
		for (int i = 0; i<n; i++)
		{
			B[i] = C[i] * D[i];
		}
		return B;
	}
};
//7,连续子序列的最大和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int sum = array[0];
		int max = array[0];
		for (int i = 1; i<array.size(); i++)
		{
			sum = (sum>0) ? sum + array[i] : array[i];
			max = (sum>max) ? sum : max;
		}
		return max;
	}
};
//8,用两个栈实现队列
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		while (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int temp = stack2.top();
		stack2.pop();
		return temp;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
//9,跳台阶
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;

		return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
};
//10,矩阵覆盖
class Solution {
public:
	int rectCover(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;

		return rectCover(number - 1) + rectCover(number - 2);
	}
};
//11,平衡二叉树
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr)
		{
			return true;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		if (left - right>1 || left - right<-1)
		{
			return false;
		}
		else
		{
			return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		}
	}
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
		{
			return 0;
		}
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return (left>right) ? left + 1 : right + 1;
	}
};
//12,求二进制中1的个数
class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		for (int i = 0; i<32; i++)
		{
			if (n >> i & 1 == 1)
			{
				count++;
			}
		}
		return count;
	}
};
//13,整数中1出现的次数
class Solution {
public:
	int numof1(int n)
	{
		int temp;
		int count = 0;
		do
		{
			temp = n % 10;
			if (temp == 1)
			{
				count++;
			}
			n /= 10;
		} while (n);
		return count;
	}
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			count += numof1(i);
		}
		return count;
	}
};
//14,两链表第一个公共节点
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		int len1 = GetLength(cur1);
		int len2 = GetLength(cur2);
		if (len1 >= len2)
		{
			int len = len1 - len2;
			while (len>0)
			{
				cur1 = cur1->next;
				len--;
			}
		}
		else if (len1<len2)
		{
			int len = len2 - len1;
			while (len>0)
			{
				cur2 = cur2->next;
				len--;
			}
		}
		while (cur1 != nullptr&&cur2 != nullptr&&cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	int GetLength(ListNode* pHead1)
	{
		int length = 0;
		ListNode* pHead = pHead1;
		while (pHead != nullptr)
		{
			length++;
			pHead = pHead->next;
		}
		return length;
	}
};
//15,旋转数组的最小数字
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		sort(rotateArray.begin(), rotateArray.end());
		return rotateArray[0];
	}
};
//16,剪绳子
class Solution {
public:
	int cutRope(int number) {
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;
		vector<int> v(number + 1, 0);
		v[1] = 1;
		v[2] = 2;
		v[3] = 3;
		int max = -1;
		for (int i = 4; i <= number; i++)
		{
			for (int j = 0; j <= i / 2; j++)
			{
				int val = v[i - j] * v[j];
				max = (val>max) ? val : max;
			}
			v[i] = max;
		}
		return v[number];
	}
};
//17,链表中环的入口节点
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead)
			return nullptr;
		ListNode* pFast = pHead;
		ListNode* pLast = pHead;
		while (pFast->next->next && pFast->next && pLast->next)
		{
			pFast = pFast->next->next;
			pLast = pLast->next;
			if (pFast == pLast)
			{
				pFast = pHead;
				while (pFast != pLast)
				{
					pFast = pFast->next;
					pLast = pLast->next;
				}
				return pLast;
			}
		}
		return nullptr;
	}
};
//18,数值的整数次方
public:
	double Power(double base, int exponent) {
		double x;
		if (exponent >= 0)
		{
			x = pow(base, exponent);
		}
		else
		{
			x = pow(base, -exponent);
			x = 1 / x;
		}
		return x;
	}
};
//19,包含min函数的栈
class Solution {
public:
	void push(int value) {
		st.push(value);
		if (stmin.empty() || stmin.top()>value)
		{
			stmin.push(value);
		}
		else
		{
			stmin.push(stmin.top());
		}
	}
	void pop() {
		st.pop();
		stmin.pop();
	}
	int top() {
		return st.top();
	}
	int min() {
		return stmin.top();
	}
private:
	stack<int> st;
	stack<int> stmin;
};
//20，左旋转字符串
class Solution {
public:
	string LeftRotateString(string str, int n) {
		reverse(str.begin(), str.end());
		reverse(str.begin(), str.end() - n);
		reverse(str.begin() + str.size() - n, str.end());
		return str;
	}
};
//21,斐波那契数列
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 1;

		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};
//22,字符流中第一个不重复的字符
class Solution
{
public:

	vector<char> v;
	void Insert(char ch)
	{
		v.push_back(ch);
	}
	char FirstAppearingOnce()
	{
		char arr[256] = { 0 };
		for (int i = 0; i<v.size(); ++i)
		{
			arr[v[i]]++;
		}
		for (int i = 0; i<v.size(); ++i)
		{
			if (arr[v[i]] == 1)
			{
				return v[i];
			}
		}
		char ch = '#';
		return ch;
	}
};
//23,把二叉树打印成多行
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> vv;
		if (pRoot == NULL)
			return vv;
		queue<TreeNode*> que;
		que.push(pRoot);
		while (!que.empty())
		{
			vector<int> v;
			int num = que.size();
			while (num--)
			{
				TreeNode* cur = que.front();
				if (cur->left)
					que.push(cur->left);
				if (cur->right)
					que.push(cur->right);
				v.push_back(cur->val);
				que.pop();
			}
			vv.push_back(v);
		}
		return vv;
	}
};
//24,对称二叉树
class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr&&pRoot2 == nullptr)
		{
			return true;
		}
		if (pRoot1 == nullptr || pRoot2 == nullptr)
		{
			return false;
		}
		if (pRoot1->val != pRoot2->val)
		{
			return false;
		}

		return isSymmetrical(pRoot1->left, pRoot2->right) && isSymmetrical(pRoot1->right, pRoot2->left);
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		return isSymmetrical(pRoot, pRoot);
	}

};
//25,数字在排序数组中出现的次数
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int size = data.size();
		int start = 0;
		int end = size - 1;
		int res;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			if (data[mid]<k)
			{
				start = mid + 1;
			}
			else if (data[mid]>k)
			{
				end = mid - 1;
			}
			else
			{
				res = mid;
				break;
			}
		}
		int count = 0;
		int i = 0;
		while ((res - i) >= 0 && data[res - i] == k)
		{
			count++;
			i++;
		}
		i = 1;
		while ((res + i)<size && data[res + i] == k)
		{
			count++;
			i++;
		}
		return count;
	}
};
//26,圆圈中最后剩下的数
class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n<1 || m<1)
			return -1;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
			v[i] = i;
		int index = -1;
		while (v.size()>1)
		{
			int count = 0;
			while (count<m)
			{
				count++;
				index++;
				if (index == v.size())
				{
					index = 0;
				}
			}
			v.erase(v.begin() + index);
			index--;
		}
		return v[0];
	}
};
//27,数组中只出现一次的数字
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		int size = data.size();
		int sum = 0;
		for (int i = 0; i<size; ++i)
		{
			sum ^= data[i];
		}
		int index = 0;
		for (int i = 0; i<32; i++)
		{
			if (sum >> i & 1 == 1)
			{
				index = i;
				break;
			}
		}
		vector<int> num11;
		vector<int> num22;
		for (int i = 0; i<size; i++)
		{
			if (data[i] >> index & 1 == 1)
			{
				num11.push_back(data[i]);
			}
			else
			{
				num22.push_back(data[i]);
			}
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i<num11.size(); ++i)
		{
			sum1 ^= num11[i];
		}
		for (int i = 0; i<num22.size(); ++i)
		{
			sum2 ^= num22[i];
		}
		*num1 = sum1;
		*num2 = sum2;
	}
};
//28，反转链表
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
			return pHead;
		ListNode* pre = pHead;
		ListNode* cur = pHead->next;
		ListNode* next = pHead->next;
		pre->next = nullptr;
		while (next)
		{
			next = next->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		pHead = pre;
		return pHead;
	}
};
//29,二叉树的下一个节点
class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
			return nullptr;
		TreeLinkNode* pNext = nullptr;
		if (pNode->right != nullptr)
		{
			TreeLinkNode* cur = pNode->right;
			while (cur->left != nullptr)
				cur = cur->left;
			pNext = cur;
		}
		else if (pNode->next != nullptr)
		{
			TreeLinkNode* cur = pNode;
			TreeLinkNode* pParent = pNode->next;
			while (pParent != nullptr&&pParent->right == cur)
			{
				cur = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;
		}
		return pNext;
	}
};
//30，栈的压入，弹出序列
class Solution {
public:
	bool IsPopOrder(vector<int> pushV,vector<int> popV) {
		int lengthpush=pushV.size();
		int lengthpop=popV.size();
		if(lengthpush!=lengthpop)
			return false;
		int pushIndex=0,popIndex=0;
		stack<int> st;
		while(pushIndex<lengthpush)
		{
			while(pushIndex<lengthpush&&(st.empty()||st.top()!=popV[popIndex]))
			{
				st.push(pushV[pushIndex]);
				pushIndex++;
			}
			if(st.top()!=popV[popIndex])
			{
				return false;
			}
			popIndex++;
			st.pop();
			if(st.empty()&&popIndex==lengthpop)
				return true;
		}
	}
};
//31,和为S的两个数字
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array,int sum) {
		vector<int> v;
		int start=0;
		int end=array.size()-1;
		while(start<end)
		{
			if(array[start]+array[end]<sum)
			{
				start++;
			}
			else if(array[start]+array[end]>sum)
			{
				end--;
			}
			else
			{
				v.push_back(array[start]);
				v.push_back(array[end]);
				break;
			}
		}
		return v;
	}
};
//32,数组中重复的数字
bool duplicate(int numbers[], int length, int* duplication) {
	for (int i = 0; i<length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			swap(numbers[i], numbers[numbers[i]]);
		}
	}
	return false;
}
};
//33，二叉搜索树和双向链表
class Solution {
public:
	void Change(TreeNode* pRootOfTree,TreeNode* &pNode)
	{
		if(pRootOfTree==nullptr)
		{
			return ;
		}
		Change(pRootOfTree->left,pNode);//遍历左子树

		pRootOfTree->left=pNode;
		if(pNode)
		{
			pNode->right=pRootOfTree;
		}
		pNode=pRootOfTree;

		Change(pRootOfTree->right,pNode);//遍历右子树
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
//34,第一个只出现一次的字符
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
//35,数组中出现次数超过一半的数字
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int mid = (numbers.size()) / 2;
		int num_mid = numbers[mid];
		int count = 0;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (numbers[i] == num_mid)
				count++;
		}
		if (count>mid)
			return num_mid;
		else
			return 0;
	}
};
//36,把数组排成最小数
class Solution {
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.empty())
			return "";
		sort(numbers.begin(), numbers.end(), cmp);
		string sum;
		for (int i = 0; i<numbers.size(); i++)
			sum += to_string(numbers[i]);
		return sum;
	}
	static bool cmp(int a, int b)
	{
		string aa = to_string(a) + to_string(b);
		string bb = to_string(b) + to_string(a);
		return aa<bb;
	}
};
//37，和为S的连续正数序列
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> s;
		if (sum < 3)
			return s;
		int big = 2;
		int small = 1;
		int mid = (1 + sum) / 2;
		int curSum = small + big;

		while (small < mid){
			if (curSum == sum){
				vector<int> tmp;
				for (int i = small; i <= big; i++)
					tmp.push_back(i);
				s.push_back(tmp);
			}
			while (curSum > sum && small < mid){
				curSum -= small;
				small++;
				if (curSum == sum){
					vector<int> tmp;
					for (int i = small; i <= big; i++)
						tmp.push_back(i);
					s.push_back(tmp);
				}
			}
			big++;
			curSum += big;
		}
		return s;
	}
};
//38，表示数值的字符串
class Solution {
public:
	bool isNumeric(char* str)
	{
		if (str == NULL)
		{
			return false;
		}
		if (*str == '+' || *str == '-')
		{
			str++;
		}
		int digit = 0;//表示小数点出现的状态
		int e = 0;//表示e/E出现的状态
		int number = 0;//表示数字出现的状态
		while (*str != '\0')
		{
			if (*str >= '0'&&*str <= '9')
			{
				str++;
				number = 1;
			}
			else if (*str == '.')
			{
				if (e>0 || digit>0)
				{
					return false;
				}
				digit = 1;
				str++;
			}
			else if (*str == 'e' || *str == 'E')
			{
				if (e>0 || number == 0)
				{
					return false;
				}
				e = 1;
				++str;
				if (*str == '+' || *str == '-')
				{
					str++;
				}
				if (*str == '\0')
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return true;
	}
};
//39,合并两个排序的链表
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* newpHead = nullptr;
		if (pHead1->val>pHead2->val)
		{
			newpHead = pHead2;
			newpHead->next = Merge(pHead1, pHead2->next);
		}
		else
		{
			newpHead = pHead1;
			newpHead->next = Merge(pHead1->next, pHead2);
		}
		return newpHead;
	}
};
//40,从上往下打印二叉树
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> v;
		if (root == nullptr)
		{
			return v;
		}
		queue<TreeNode*> TreeQueue;
		TreeQueue.push(root);
		while (TreeQueue.size())
		{
			TreeNode* tmp = TreeQueue.front();
			TreeQueue.pop();
			v.push_back(tmp->val);
			if (tmp->left)
			{
				TreeQueue.push(tmp->left);
			}
			if (tmp->right)
			{
				TreeQueue.push(tmp->right);
			}
		}
		return v;
	}
};
//41,调整数组顺序使奇数位于偶数前面
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int j = 0;
		int tmp = 0;
		for (int i = 0; i<array.size(); i++)
		{
			if (array[i] % 2 == 1)
			{
				tmp = array[i];
				j = i - 1;
				while (j >= 0 && array[j] % 2 == 0)
				{
					array[j + 1] = array[j];
					j--;
				}
				array[j + 1] = tmp;
			}
		}
	}
};
#endif
