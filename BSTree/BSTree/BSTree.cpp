#include<iostream>
using namespace std;
//平衡二叉树的插入与删除
template<class T>
struct BSTNode
{
	BSTNode(const T& data = T())
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	BSTree<T>* _pLeft;
	BSTree<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTNode<T> Node;
public:
	BSTree()
		:_pRoot(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		//找到待插入的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
			{
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data)
			{
				pCur = pCur->_pRight;
			}
			else
			{
				return false;
			}
		}

		//插入新的节点
		pCur = new Node(data);
		if (data > pCur->_data)
		{
			pParent->_pRight = pCur;
		}
		else
		{
			pParent->_pLeft = pCur;
		}

		return true;
	}

	bool Delete(const T& data)
	{
		if (nullptr == _pRoot)
		{
			return false;
		}
		//找到待删除节点的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (data == pCur->_data)
			{
				break;
			}
			else if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
		}
		if (nullptr == pCur)
		{
			return false;
		}

		//对节点进行删除
		Node* pDelNode = pCur;
		//所有的叶子节点和只有右孩子的节点
		if (nullptr == pCur->_pLeft)
		{
			if (nullptr == pParent)
			{
				_pRoot = pCur->_pRight;
			}
			else
			{
				if (pCur == pParent->_pLeft)
				{
					pParent->_pLeft = pCur->_pRight;
				}
				else
				{
					pParent->_pRight = pCur->_pRight;
				}
			}
		}//只有左孩子
		else if (nullptr == pCur->_pRight)
		{
			if (nullptr == pParent)
			{
				_pRoot = pParent->_pLeft;
			}
			else
			{
				if (pCur == pParent->_pLeft)
				{
					pParent->_pLeft = pCur->_pLeft;
				}
				else
				{
					pParent->_pRight = pCur->_pLeft;
				}
			}
		}
		else//左右孩子都存在
		{
			Node* pDel = pCur->_pRight;
			pParent = pCur;
			while (pDel->_pLeft)
			{
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			pCur->_data = pDel->_data;
			if (pParent->_pLeft == pDel)
			{
				pParent->_pLeft = pDel->_pRight;
			}
			else
			{
				pParent->_pRight = pDel->_pRight;
			}
		}
		delete pDelNode;
		return true;
	}
private:
	BSTNode* _pRoot;
};