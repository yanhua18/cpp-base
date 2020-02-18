#pragma once
#include<iostream>
using namespace std;
#include<vector>

//����̽������ϣ��ͻ���ŵ㣺��   ȱ�㣺1���ռ������ʲ��� 2������������ݶѻ�
enum STATE{EMPTY,EXIST,DELETE};

template<class T>
struct Elem
{
	Elem(const T& data=T())
		:_data(data)
		, _state(EMPTY)
	{}
	T _data;//�����Ԫ��
	STATE _state;//�����״̬
};

template<class T>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_size(0)
	{
		_table.resize(10);//vector����10��Ԫ�أ�ÿһ��Ԫ�ص�״̬���ǿ�
	}
	
	bool Insert(const T& data)
	{
		//1,ͨ��hash��������hash��ַ
		size_t hashAddr = HashFun(data);
		//2,�ҵ����ʵ�λ��
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST&&_table[hashAddr]._data == data)
				return false;
			//λ����delete
			//λ��״̬��exist��������ϣ��ͻ

			//����̽��
			hashAddr++;
			if (hashAddr == _table.capacity())
			{
				hashAddr = 0;
			}

		}
		//�ҵ���һ����λ�ã����Բ���Ԫ��
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;
		return true;

	}

	int Find(const T& data)
	{
		//1,ͨ����ϣ��������Ԫ���ڱ���е�λ��
		size_t hashAddr = HashFun(data);
		//2,����
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST&&_table[hashAddr]._data == data)
				return hashAddr;
			//3,��Ҫ��������̽�⣺����̽��
			hashAddr++;
			if (hashAddr == _table.capacity())
			{
				hashAddr = 0;
			}
		}
		return -1;
	}

	bool Erase(const T& data)
	{
		int pos = Find(data);
		if (pos != -1)
		{
			_table[pos]._state = DELETE;
			_size--;
			return true;
		}
		return false;
	}

	size_t Size()const
	{
		return _size;
	}
private:
	size_t HashFun(const T& data)
	{
		return data % 10;
	}
private:
	vector<Elem<T>> _table;//hash���
	size_t _size;//��ʾhash���д洢��Ԫ�ظ���

};

void testHashTable()
{
	int array[] = { 21, 67, 112, 69, 5, 13, 44 };
	HashTable<int> ht;
	for (auto e : array)
	{
		ht.Insert(e);
	}
	cout << ht.Size() << endl;
	ht.Insert(87);
	ht.Insert(77);
	cout << ht.Size() << endl;
	
	if (ht.Find(87) != -1)
	{
		cout << "87 is exist!\n";
	}
	else
	{
		cout << "87 is empty!\n";
	}

	ht.Erase(67);
	if (ht.Find(67) != -1)
	{
		cout << "67 is exist!\n";
	}
	else
	{
		cout << "67 is empty!\n";
	}
	if (ht.Find(87) != -1)
	{
		cout << "87 is exist!\n";
	}
	else
	{
		cout << "87 is empty!\n";
	}
}