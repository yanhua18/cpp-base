//list����ͷ����˫��ѭ������
//ģ��ʵ��

#include<iostream>
using namespace std;
#include<windows.h>

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
			:_pCur(pCur)
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
		Self operator++(int)//����++
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
		Self operator--(int)//����--
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
	

	public:
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
		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		//��������
		list(const list<T>& L)
		{
			CreateHead();
			Node* _pCur = L._pHead->_pNext;
			while (_pCur != L._pHead)
			{
				push_back(_pCur->_data);
				_pCur = _pCur->_pNext;
			}
		}

		//��ֵ��������� L1=L2
		list<T>& operator= (const list<T>& L)
		{
			if (this != &L)
			{
				clear();
				Node* _pCur = l._pHead->_pNext;
				while (_pCur != l._pHead)
				{
					push_back(_pCur->_data);
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
		iterator insert(iterator pos, const T& data)
		{
			Node* pNewNode = new Node(data);
			Node* pCur = pos._pCur;
			pNewNode->_pPre = pCur->_pPre;
			pNewNode->_pNext = pCur;
			pNewNode->_pPre->_pNext = pNewNode;
			pCur->_pPre = pNewNode;

			return iterator(pNewNode);
		}
		iterator erase(iterator pos)
		{
			Node* pDelNode = pos._pCur;
			if (pDelNode == _pHead)
				return end();
			Node* pRet = pDelNode->_pNext;
			pDelNode->_pNext->_pPre = pDelNode->_pPre;
			pDelNode->_pPre->_pNext = pDelNode->_pNext;
			return iterator(pRet);
		}
		void clear()
		{
			Node* pCur = _pHead->_pNext;
			while (pCur != _pHead)
			{
				_pHead->_pNext = pCur->_pNext;
				delete pCur;
				pCur = _pHead->_pNext;
			}
			_pHead->_pPre = _pHead;
			_pHead->_pNext = _pHead;
		}
		void swap(list<T>& L)
		{
			swap(_phead, L._pHead);
		}
		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (oldsize < newsize)
			{
				for (size_t i = oldsize; i < newsize; i++)
				{
					push_back(data);
				}
			}
			else
			{
				for (size_t i = newsize; i < oldsize; i++)
				{
					pop_back();
				}
			}
		}
	protected:
		Node* _pHead;
	private:
		void CreateHead()
		{
			_pHead = new Node;
			_pHead->_pNext = _pHead;
			_pHead->_pPre = _pHead;
		}
	};
}
#include<vector>
void Testlist1()
{
	bite::list<int> L1;
	bite::list<int> L2(10, 5);
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::list<int> L3(v.begin(), v.end());
	bite::list<int> L4(L3);

	auto it = L2.begin();
	while (it != L2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : L3)
		cout << e << " ";
	cout << endl;

}

void Testlist2()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.push_back(4);

	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.push_front(0);
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_front();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.pop_back();
	cout << L.size() << endl;
	cout << L.front() << endl;
	cout << L.back() << endl;

	L.clear();
	if (L.empty())
		cout << "clear over" << endl;
}
void Testlist3()
{
	bite::list<int> L;
	L.push_back(1);
	L.push_back(2);
	L.push_back(3);
	L.resize(10, 5);
	for (auto e : L)
		cout << e << " ";
	cout << endl;

	L.resize(2);
	for (auto e : L)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//Testlist1();
	//Testlist2();
	Testlist3();
	system("pause");

	return 0;
}