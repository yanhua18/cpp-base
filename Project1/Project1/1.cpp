#include<iostream>
using namespace std;
#include<vector>
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

#endif
