#if 0
//1,�����������
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

//2,���üӼ��˳����ӷ�
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

//3���������ľ���
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

//4,��̬��̨��
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
#endif



//1,�������������������Ӵ�����
//��̬�滮���
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	vector<int>v;
	int n;
	while (cin >> n)
	{
		v.push_back(n);
	}
	int sum = v[0];
	int max = v[0];
	n = v.size();
	for (int i = 1; i<n; i++)
	{
		sum = (sum>0) ? sum + v[i] : v[i];
		if (sum>max)
		{
			max = sum;
		}
	}
	cout << max << endl;
}

