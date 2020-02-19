#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"common.h"
//��ɢ��



//����̽������ϣ��ͻ���ŵ㣺��   ȱ�㣺1���ռ������ʲ��� 2������������ݶѻ�
enum STATE{EMPTY,EXIST,DELETE};


//�����ϣ����ֻ�ܴ����������⣬��ϣ�����п��Դ����������
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

//T�����ε�
template<class T>
class DFDef
{
public:
	T operator()(const T& data)
	{
		return data;
	}
};
//T��string���͵Ķ���
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
			hash = hash * 131 + ch;   // Ҳ���Գ���31��131��1313��13131��131313..  
			// ����˵���˷��ֽ�Ϊλ���㼰�Ӽ����������Ч�ʣ��罫��ʽ���Ϊ��hash = hash << 7 + hash << 1 + hash + ch;  
			// ����ʵ��Intelƽ̨�ϣ�CPU�ڲ��Զ��ߵĴ���Ч�ʶ��ǲ��ģ�  
			// �ҷֱ������100�ڴε������������㣬���ֶ���ʱ�������Ϊ0�������Debug�棬�ֽ��λ�����ĺ�ʱ��Ҫ��1/3����  
			// ��ARM����RISCϵͳ��û�в��Թ�������ARM�ڲ�ʹ��Booth's Algorithm��ģ��32λ�����˷����㣬����Ч��������йأ�  
			// ������8-31λ��Ϊ1��0ʱ����Ҫ1��ʱ������  
			// ������16-31λ��Ϊ1��0ʱ����Ҫ2��ʱ������  
			// ������24-31λ��Ϊ1��0ʱ����Ҫ3��ʱ������  
			// ������Ҫ4��ʱ������  
			// ��ˣ���Ȼ��û��ʵ�ʲ��ԣ���������Ȼ��Ϊ����Ч���ϲ�𲻴�          
		}
		return hash;
	}
};


//T--��ʾԪ�ص�����   
//DF--��ʾ��T���͵Ķ���ת��Ϊ�������ݵķ���  
//isLine--��ʾ��ѡ������̽����������Ƕ���̽���������ϣ��ͻ
template<class T, class DF=DFDef<T>, bool isLine=true>
class HashTable
{
public:
	HashTable(size_t capacity = 10)
		:_size(0)
		, _total(0)
	{
		_table.resize(GetNextPrime(10));//vector����10��Ԫ�أ�ÿһ��Ԫ�ص�״̬���ǿ�
	}
	
	bool Insert(const T& data)
	{
		//1,ͨ��hash��������hash��ַ
		size_t hashAddr = HashFun(data);

		size_t i = 0;
		//2,�ҵ����ʵ�λ��
		while (_table[hashAddr]._state != EMPTY)
		{
			if (_table[hashAddr]._state == EXIST&&_table[hashAddr]._data == data)
				return false;
			//λ����delete
			//λ��״̬��exist��������ϣ��ͻ

			
			if (isLine)//����̽��
			{
				hashAddr++;
				if (hashAddr == _table.capacity())
				{
					hashAddr = 0;
				}
			}
			else//����̽��
			{
				i++;
				hashAddr = hashAddr + 2 * i + 1;
				hashAddr %= _table.capacity();
			}
			

		}
		//�ҵ���һ����λ�ã����Բ���Ԫ��
		_table[hashAddr]._data = data;
		_table[hashAddr]._state = EXIST;
		++_size;
		++_total;
		return true;

	}

	int Find(const T& data)
	{
		//1,ͨ����ϣ��������Ԫ���ڱ���е�λ��
		size_t hashAddr = HashFun(data);
		size_t i = 0;
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

	void Swap(HashTable<T, DF, isLine> & ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}
private:
	void CheckCapacity()//�ж��Ƿ���Ҫ����
	{
		//if (_size*10 / _table.capacity() >= 7) ---- ɾ��λ�ÿ��Բ���Ԫ�ص����
		if (_total*10 / _table.capacity() >= 7)
		{
			//�������ݣ����´���һ����ϣ����״̬Ϊ���ڵ�Ԫ�����¹�ϣ����в���
			//1,����һ���µĹ�ϣ��
			HashTable<T, DF, isLine> newH(GetNextPrime(_table.capacity()));
			//2,���͹�ϣ����״̬Ϊ���ڵ�Ԫ�����¹�ϣ���в���
			for (auto e : _table)
			{
				if (e._state == EXIST)
					newH.Insert(e);
			}
			Swap(newH);//��thisָ��Ĺ�ϣ�����Ϊ�´����Ĺ�ϣ��
		}
	}

	size_t HashFun(const T& data)//��ϣ����
	{
		return DF()(data) % _table.capacity();
	}
private:
	vector<Elem<T>> _table;//hash���
	size_t _size;//��ʾhash���д洢��Ԫ�ظ���
	size_t _total;//��ʾ��ϣ������Ѿ��洢Ԫ�صĸ�������������ЧԪ�غ�ɾ��Ԫ��֮�ͣ�
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