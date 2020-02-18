#pragma once
#include<iostream>
using namespace std;
#include<vector>

//线性探测解决哈希冲突的优点：简单   缺点：1，空间利用率不高 2，容易造成数据堆积
enum STATE{EMPTY,EXIST,DELETE};

template<class T>
struct Elem
{
	Elem(const T& data=T())
		:_data(data)
		, _state(EMPTY)
	{}
	T _data;//保存的元素
	STATE _state;//保存的状态
};

template<class T>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_size(0)
	{
		_table.resize(10);//vector中有10个元素，每一个元素的状态都是空
	}
	
	bool Insert(const T& data)
	{
		//1,通过hash函数计算hash地址
		size_t hashAddr = HashFun(data);
		//2,找到合适的位置
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST&&_table[hashAddr]._data == data)
				return false;
			//位置是delete
			//位置状态是exist，发生哈希冲突

			//线性探测
			hashAddr++;
			if (hashAddr == _table.capacity())
			{
				hashAddr = 0;
			}

		}
		//找到了一个空位置，可以插入元素
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;
		return true;

	}

	int Find(const T& data)
	{
		//1,通过哈希函数计算元素在表格中的位置
		size_t hashAddr = HashFun(data);
		//2,查找
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST&&_table[hashAddr]._data == data)
				return hashAddr;
			//3,需要继续往后探测：线性探测
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
	vector<Elem<T>> _table;//hash表格
	size_t _size;//表示hash表中存储的元素个数

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