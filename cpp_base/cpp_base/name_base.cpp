#include<iostream>
using namespace std;
//#include<stdio.h>
#include<Windows.h>
//#include<time.h>

#if 0

/*һ�������ռ�Ͷ�����һ���µĶ����������ռ������е����ݶ������ڸö�������*/


//��ͨ�������ռ䣨�����ռ��мȿ��Զ������Ҳ���Զ��庯����
namespace N1//N1Ϊ�����ռ������
{
	int a=10;
	int ADD(int a, int b)
	{
		return a + b;
	}
}

//�����ռ����Ƕ��
namespace N2
{
	int a=20;
	int ADD(int a, int b)
	{
		return a + b;
	}
	namespace N3
	{
		int x=40;
		int y=50;
		int sub(int c, int d)
		{
			return c - d;
		}
	}
}

//ͬһ��������������ڶ����ͬ���Ƶ������ռ䣨����������ϲ���ͬһ�������ռ���ȥ��
namespace N1
{
	int Mul(int a, int b)
	{
		return a*b;
	}
}


/*�����ռ��ʹ�÷�ʽ������:
�������ռ����Ƽ��������޶���
ʹ��using�������ռ�����
ʹ��using namespace�����ռ���������

//using N2::a;
using namespace N1;
int main()
{
	//�������ռ����Ƽ��������޶���
	//printf("%d\n", N2::a);
	//ʹ��using�������ռ�����
	//printf("%d\n", a);
	//ʹ��using namespace�����ռ���������
	//printf("%d\n", ADD(3, 4));

	cout << "hello world" << endl;//ʹ��cout��׼�����cin��׼����ʱ���������<iostream>ͷ�ļ���std��׼������


	system("pause");
	return 0;
}
*/


//ȱʡ����
//ȱʡ�����������������庯��ʱΪ�����Ĳ���ָ��һ��Ĭ��ֵ���ڵ��øú���ʱ�����û��ָ��ʵ������ø�Ĭ��ֵ������ʹ��ʵ��
//ȫȱʡ����
void TestFun(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << "a" << endl;
	cout << "b=" << "b" << endl;
	cout << "c=" << "c" << endl;
}
//��ȱʡ��������ȱʡ������������������θ�ֵ�����ܼ���Ÿ���
void TestFunc(int a, int b=10, int c=20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}

//��������
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}


//ȱʡ������Ҫ�뺯������ͬʱʹ��
void TestFunc(int a ,int b=10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a,int b)
{
	cout << "void TestFunc(int)" << endl;
}



//�����������ʱ���뿪�������������ջ�Ͽռ��Ѿ�����ϵͳ����˲�����ջ�ϵĿռ���Ϊ�������ͷ��ء�������������ͷ��أ�����ֵ���������ڱ��벻�ܺ���������(���Ⱥ����������ڳ�)��

int& Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :" << ret << endl;
	system("pause");
	return 0;
}

//��ֵ�������ã���ָ��Ч�ʱȽ�
struct A
{
	int a[10000];
};
void TestFunc1(A a)
{}
void TestFunc2(A &a)
{}
void TestFunc3(A *a)
{}
void TestRefAndValue()
{
	A a;
	//��ֵ
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();
	//������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();
	//��ָ��
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc3(&a);
	}
	size_t end3 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(int)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
	cout << "TestFunc2(int*)-time:" << end2 - begin2 << endl;

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		TestRefAndValue();
	}
	system("pause");
	return 0;
}



struct A
{
	int a[10000];
};
//������ֵ����
A a;
A TestFunc1()
{
	return a;
}
A& TestFunc2()
{
	return a;
}
A* TestFunc3()
{
	return &a;
}
void TestRefAndValue()
{
	//����ֵ
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1();
	}
	size_t end1 = clock();
	//��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2();
	}
	size_t end2 = clock();
	//����ָ��
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc3();
	}
	size_t end3 = clock();

	// �ֱ���������������н������ʱ��
	cout << "TestFunc1(int)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int&)-time:" << end2 - begin2 << endl;
	cout << "TestFunc2(int*)-time:" << end2 - begin2 << endl;

}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		TestRefAndValue();
	}
	system("pause");
	return 0��
}

void TestAuto()
{
	int a[] = { 1, 2, 3 };
	auto b[3] = { 4,6 ,7};
}

int main()
{
	//const int a = 10;
	//int *pa = (int *)&a;
	//*pa = 20;
	//printf("%d", a);//ֱ����10��ӡ��û�д�a�ռ���ȡֵ
	//printf("%d", *pa);

	TestAuto();
	system("pause");
	return 0;
}


//�з�Χ��for
void TestFor()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		array[i] *= 2;
	for (int *p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)
		cout << *p << endl;
}

void TestFor1()
{
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto &e : array)
		e *= 2;
	for (auto e : array)
		cout << e << endl;
}
int main()
{
	TestFor1();
	system("pause");
	return 0;
}


#include "person.h"
//��Ͷ���*******************************************************************************
//������ֶ��巽ʽ
//1,�����Ͷ���ȫ��������
//2����������ͷ�ļ����������ִ���ļ���
struct Person//struct��������г�ԱĬ��Ȩ���ǹ��еģ���class�������ĳ�Ա��Ĭ��Ȩ����˽�е�
{

	void showInfomation();

	char *name;
	char *gender;
	int age;
};
void Person::showInfomation()
{
	cout << name <<" "<<age<<" "<<gender<<endl;
}
//��Ĵ�С
class A1
{
public:
	void getinfo();
	void outinfo();
private:
	char * name;
	char * gender;
	
};

class A2
{
public:
	void get();
};
class A3
{
	int array[10];
};
class A4
{

};
int main()
{

	A1 a1;
	A2 a2;
	A3 a3;
	A4 a4;
	cout << sizeof(a1) << endl;
	cout << sizeof(a2) << endl;
	cout << sizeof(a3) << endl;
	cout << sizeof(a4) << endl;
	/*Person d;
	d.age = 12;
	d.gender = "Ů";
	d.name = "����";
	d.showInfomation();*/
	system("pause");
	return 0;
}



class A
{
public:
	void PrintA()
	{
		cout << _a << endl;//��ָ�벻�ܷ��ʳ�Ա����
	}
	void Show()
	{
		cout << "show" << endl;
	}
private:
	int _a;
};


class Date
{
public:
	void Display()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
	void SetDate(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}
private:
	int year;
	int month;
	int day;
};



int main()
{
	A *p = NULL;
	p->PrintA();
	p->Show();
	/*Date d1, d2;
	d1.SetDate(2018, 5, 1);
	d2.SetDate(2018, 7, 1);
	d1.Display();
	d2.Display();*/
	system("pause");
	return 0;
}
#endif


class Time
{
public :
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	//Date()//�޲ι��캯��
	//{

	//}
	//Date(int _year, int _month, int _day)//���ι��캯��
	//{
	//	year = _year;
	//	month = _month;
	//	day = _day;
	//}
	/*void Display()
	{
		cout << year << "-" << month << "-" << day << endl;
	}
	void SetDate(int _year, int _month, int _day)
	{
		year = _year;
		month = _month;
		day = _day;
	}*/
private:
	int year;
	int month;
	int day;
	//�Զ�������
	Time t1;
};
void TestDate()
{
	Date d1;
	//Date d2(2015, 1, 1);
	//Date d3();
}
int main()
{
	TestDate();
	system("pause");
	return 0;
}

class Solution {
public:
	// ͳ��CSum���ܹ������˶��ٸ�����
	class CSum
	{
	public:
		CSum()
		{
			_count++;
			_sum += _count;
		}

		static void ReSet()
		{
			_count = 0;
			_sum = 0;
		}

		static size_t GetSum()
		{
			return _sum;
		}
	private:
		static size_t _count;
		static size_t _sum;
	};

	int Sum_Solution(int n) {
		CSum::ReSet();
		CSum total[n];
		return CSum::GetSum();
	}
};

size_t Solution::CSum::_count = 0;
size_t Solution::CSum::_sum = 0;


