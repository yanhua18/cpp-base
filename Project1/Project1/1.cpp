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
#endif
