#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<stack>



#if 0
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