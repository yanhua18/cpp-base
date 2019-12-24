#include<iostream>
using namespace std;
//ƽ��������Ĳ�����ɾ��
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

		//�ҵ��������λ��
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

		//�����µĽڵ�
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
		//�ҵ���ɾ���ڵ��λ��
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

		//�Խڵ����ɾ��
		Node* pDelNode = pCur;
		//���е�Ҷ�ӽڵ��ֻ���Һ��ӵĽڵ�
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
		}//ֻ������
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
		else//���Һ��Ӷ�����
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