#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<Windows.h>
#include<stack>
#if 0
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