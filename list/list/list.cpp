//list����ͷ����˫��ѭ������
//ģ��ʵ��

#include<iostream>
using namespace std;

namespace bite
{

	//�ڵ������
	template<class T>
	struct ListNode
	{
		ListNode(const T& data = T())
			:_pNext(nullptr)
			, _pPre(nullptr)
			, _data(data)
		{}
		ListNode<T>* _pNext;
		ListNode<T>* _pPre;
		T _data;
	};
	//list��������������ڵ����͵�ָ�����·�װ
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	public:
		//�������Ĺ���
		list_iterator(Node* pCur)
			:_pCur(pcur)
		{}
		//����ָ�뷽ʽ����Ӧ��
		T& operator*()
		{
			return _pCur->_data;
		}
		T* operator ->()
		{
			return &(_pCur->_data);
		}
		//��ָ��һ��ͨ��++ --�����ƶ�
		Self& operator++()//ǰ��++
		{
			_pCur = _pCur->_pNext;
			return *this;
		}
		Self operator++)(int)//����++
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}
		Self& operator--()//ǰ��--
		{
			_pCur = _pCur->_pPre;
			return *this;
		}
		Self operator--)(int)//����--
		{
			Self temp(*this);
			_pCur = _pCur->_pPre;
			return temp;
		}
		//���������бȽ�
		bool operator!=(const Self& s)
		{
			return _pCur != s._pCur;
		}
		bool operator==(const Self& s)
		{
			return _pCur == s._pCur;
		}
	private:
		Node* _pCur;
	};



	template <class T>
	class list
	{
	public:
		typedef ListNode<T> Node;
		typedef list_iterator<T> iterator;
	public:
		//�޲����Ĺ��캯��
		list()
		{
			CreateHead();
		}
		//��ǰn �ڵ��ʼ��Ϊdata
		list(int n, const T& data)
		{
			CreateHead();
			for (int i = 0; i < n; i++)
			{
				push_back(data);
			}
		}

		//ͨ�������������乹��
		list(Iterator first, Iterator last);

		//��������
		list(const list<T>& L);
		{
			CreateHead();
			Node* _pCur = L._pHead->next;
			while (_pCur != L._pHead)
			{
				push_back(_pCur->data);
				_pCur = _pCur->_pNext;
			}
		}

		//��ֵ��������� L1=L2
		list<T>& operator=(const list<T>&����)
		{
			if (this != &L)
			{
				clear();
				Node* _pCur = L._pHead->_pNext;
				while (_pCur != L._pHead)
				{
					push_back(_pCur->data);
					_pCur = _pCur->_pNext;
				}
			}
			return *this;
		}
		//��������
		~list()
		{
			clear();
			delete _pHead;
		}
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_phead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	//list iterator****************************************************
		iterator begin()
		{
			return iterator(_pHead->_pNext);
		}
		iterator end()
		{
			return iterator(_pHead);
		}
	//list capacity****************************************************
	public:
		size_t size()const
		{
			size_t count = 0;
			Node* _pCur = _pHead->_pNext;
			while (_pCur != _pHead)
			{
				count++;
				_pCur = _pCur->_pNext;
			}
			return count;
		}
		size_t empty()const
		{
			return _pHead->_pNext == _pHead;
		}
		//list element access*********************************************
		T& front()
		{
			return _pHead->_pNext->_data;
		}
		T& front()const
		{
			return _pHead->_pNext->_data;
		}
		T& back()
		{
			return _pHead->_pPre->_data;
		}
		T& back()const
		{
			return _pHead->_pPre->_data;
		}
		// list modifiers****************************************************
		void push_back(const T& data)
		{
			insert(end(), data);
		}
		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& data)
		{
			insert(begin(), data);
		}
		void pop_front()
		{
			erase(begin());
		}


















	protected:
		Node* _pHead;
	};











}