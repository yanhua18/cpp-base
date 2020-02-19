#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"common.h"
//闭散列



//线性探测解决哈希冲突的优点：简单   缺点：1，空间利用率不高 2，容易造成数据堆积
enum STATE{EMPTY,EXIST,DELETE};


//解决哈希表中只能存整数的问题，哈希函数中可以存放任意数据
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

//T是整形的
template<class T>
class DFDef
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};
//T是string类型的对象
class DFStr
{
public:
	size_t operator()(const string& s)
	{
		return BKDRHash(s.c_str());
	}
private:
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
			// 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;  
			// 但其实在Intel平台上，CPU内部对二者的处理效率都是差不多的，  
			// 我分别进行了100亿次的上述两种运算，发现二者时间差距基本为0（如果是Debug版，分解成位运算后的耗时还要高1/3）；  
			// 在ARM这类RISC系统上没有测试过，由于ARM内部使用Booth's Algorithm来模拟32位整数乘法运算，它的效率与乘数有关：  
			// 当乘数8-31位都为1或0时，需要1个时钟周期  
			// 当乘数16-31位都为1或0时，需要2个时钟周期  
			// 当乘数24-31位都为1或0时，需要3个时钟周期  
			// 否则，需要4个时钟周期  
			// 因此，虽然我没有实际测试，但是我依然认为二者效率上差别不大          
		}
		return hash;
	}
};


//T--表示元素的类型   
//DF--表示将T类型的对象转化为整数数据的方法  
//isLine--表示是选择线性探测来解决还是二次探测来解决哈希冲突
template<class T, class DF=DFDef<T>, bool isLine=true>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_size(0)
		, _total(0)
	{
		_table.resize(GetNextPrime(10));//vector中有10个元素，每一个元素的状态都是空
	}
	
	bool Insert(const T& data)
	{
		//1,通过hash函数计算hash地址
		size_t hashAddr = HashFun(data);

		size_t i = 0;
		//2,找到合适的位置
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST&&_table[hashAddr]._data == data)
				return false;
			//位置是delete
			//位置状态是exist，发生哈希冲突

			
			if (isLine)//线性探测
			{
				hashAddr++;
				if (hashAddr == _table.capacity())
				{
					hashAddr = 0;
				}
			}
			else//二次探测
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _table.capacity();
			}
			

		}
		//找到了一个空位置，可以插入元素
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;
		++_total;
		return true;

	}

	int Find(const T& data)
	{
		//1,通过哈希函数计算元素在表格中的位置
		size_t hashAddr = HashFun(data);
		size_t i = 0;
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

	void Swap(HashTable<T, DF, isLine> & ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
private:
	void CheckCapacity()//判断是否需要扩容
	{
		//if (_size*10 / _table.capacity() >= 7) ---- 删除位置可以插入元素的情况
		if (_total*10 / _table.capacity() >= 7)
		{
			//进行扩容，重新创建一个哈希表，将状态为存在的元素向新哈希表格中插入
			//1,创建一个新的哈希表
			HashTable<T, DF, isLine> newH(GetNextPrime(_table.capacity()));
			//2,将就哈希表中状态为存在的元素向新哈希表中插入
			for (auto e : _table)
			{
				if (e._state == EXIST)
					newH.Insert(e);
			}
			Swap(newH);//将this指向的哈希表更新为新创建的哈希表
		}
	}

	size_t HashFun(const T& data)//哈希函数
	{
		return DF()(data) % _table.capacity();
	}
private:
	vector<Elem<T>> _table;//hash表格
	size_t _size;//表示hash表中存储的元素个数
	size_t _total;//表示哈希表格中已经存储元素的个数（包含了有效元素和删除元素之和）
};

//######################################################################################################################

void testHashTable()
{
	int array[] = { 21, 67, 112, 69, 5, 13, 44 };
	HashTable<int, DFDef<int>,true > ht;
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


void testHashTable2()
{
	HashTable<string, DFStr, false> ht;
	ht.Insert("1111");
	ht.Insert("2222");
	ht.Insert("3333");
	ht.Insert("4444");

}