//list：带头结点的双向循环链表
//模拟实现

#include<iostream>
using namespace std;

namespace bite
{

	//节点的类型
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
	//list正向迭代器：将节点类型的指针重新封装
	template<class T>
	struct list_iterator
	{
		typedef ListNode<T> Node;
		typedef list_iterator<T> Self;
	public:
		//迭代器的构造
		list_iterator(Node* pCur)
			:_pCur(pcur)
		{}
		//按照指针方式进行应用
		T& operator*()
		{
			return _pCur->_data;
		}
		T* operator ->()
		{
			return &(_pCur->_data);
		}
		//像指针一样通过++ --进行移动
		Self& operator++()//前置++
		{
			_pCur = _pCur->_pNext;
			return *this;
		}
		Self operator++)(int)//后置++
		{
			Self temp(*this);
			_pCur = _pCur->_pNext;
			return temp;
		}
		Self& operator--()//前置--
		{
			_pCur = _pCur->_pPre;
			return *this;
		}
		Self operator--)(int)//后置--
		{
			Self temp(*this);
			_pCur = _pCur->_pPre;
			return temp;
		}
		//迭代器进行比较
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
		//无参数的构造函数
		list()
		{
			CreateHead();
		}
		//将前n 节点初始化为data
		list(int n, const T& data)
		{
			CreateHead();
			for (int i = 0; i < n; i++)
			{
				push_back(data);
			}
		}

		//通过迭代器的区间构造
		list(Iterator first, Iterator last);

		//拷贝构造
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

		//赋值运算符重载 L1=L2
		list<T>& operator=(const list<T>&　Ｌ)
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
		//析构函数
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