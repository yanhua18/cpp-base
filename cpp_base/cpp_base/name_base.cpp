#include<iostream>
//#include<String>
using namespace std;
//#include<stdio.h>
#include<Windows.h>
//#include<time.h>
#pragma warning(disable:4996) 

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
	Date()//�޲ι��캯��
	{

	}
	Date(int _year, int _month, int _day)//���ι��캯��
	{
		year = _year;
		month = _month;
		day = _day;
	}
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



//��������

#include<malloc.h>
#include<string.h>
#include<assert.h>
typedef int DateType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		cout << "SeqList(size_t)" << endl;
		_array = (DateType *)malloc(sizeof(DateType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
			return;
		}
		_capacity = 0;
		_size = 0;
	}
	~SeqList()
	{
		cout << "~SeqList()" << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DateType *_array;
	size_t _size;
	size_t _capacity;
};

void TestSeqList()
{
	SeqList s;
}


class String
{
public:
	String(const char *str = "")
	{
		cout << "String()" << endl;
		if (nullptr == str)
			str = "";
		_str = (char *)malloc(strlen(str) + 1);
			strcpy(_str, str);
	}
	~String()
	{
		cout << "~String() "<< endl;
		if (_str)
		{
			free(_str);
		}
	}
private:
	char *_str;
};
class Person
{
private:
	String _name;
	String _gender;
	int age;
};
void TestPerson()
{
	Person p;
}



class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	/*void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/
	Date(const Date&d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "Date(const Date &)" << endl;
	}
	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
void showDate()
{
	Date d1;
	Date d2(d1);
	d1.PrintDate();
	d2.PrintDate();
}

class String
{
public:
	String(const char *str = "")
	{
		cout << "String()" << endl;
		if (nullptr == str)
			str = "";
		_str = (char *)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		cout << "~String() " << endl;
			free(_str);
	}
private:
	char *_str;
};

int main()
{
	String s1("hello");
	String s2(s1);
	system("pause");
	return 0;
}


//�����==����*************************************************************************************************
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
bool operator==(const Date &d1, const Date &d2)//��Ҫȫ�ֱ����ǹ��е�
{
	return (d1._year == d2._year)
		&&(d1._month == d2._month)
		&&(d1._day == d2._day);
}
void Test()
{
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	cout << (d1 == d2) << endl;
}



//��֤����ԣ������غ��������ɳ�Ա����
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// ��ֵ��������أ�����û�û����ʽ�ṩ����������������һ��Ĭ�ϵĸ�ֵ���������
	// ���һ�������漰����Դ�����û������ṩ��ֵ���������

	Date& operator =(const Date& d)//������Ϊ�����Ч�ʣ�const��֤��ȫ��
	{
		if (&d != this)//����������ĵ�ַ�ǲ���һ����һ���Ͳ���Ҫ��ֵ
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date& operator++()//ǰ��++
	{
		_day += 1;
		return *this;
	}

	Date operator++(int)//����++
	{
		Date tmp(*this);//ջ�϶��󣬲��������÷���
		_day += 1;
		return tmp;
	}

	bool operator==(const Date &d2)//thisָ��ĵ��ú����Ķ���
	{
		return (_year == d2._year)
			&& (_month == d2._month)
			&& (_day == d2._day);
	}
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year ||
			_year == d._year && _month > d._month ||
			_year == d._year && _month == d._month && _day > d._day)
		{
			return true;
		}
		return false;
	}
private:
	int _year;
	int _month;
	int _day;
};
void Test()
{
	
	Date d1(2018, 9, 26);
	Date d2(2018, 9, 27);
	Date d3(2018, 9, 28);
	d2=d3++;
	d1=++d3;
}
int main()
{
	Test();
	system("pause");
	return 0;
}



class Date
{
public:
	Date(int year, int month, int day)
		:_year(year), _month(month), _day(day)
	{
		_count++;
	}
private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

int main()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	//d1 = 2019;//d1��һ�������͵Ķ��󣬶�2019��һ�����α���
	system("pause");//����Ϊ2019����һ���������������ʱ������Ϊd1��ֵ
	return 0;
}


class A
{
public:
	A()
	{
		++_count;
	}
	A(const A& t)
	{
		++_count;
	}
	static int GetACount()
	{
		return _count;
	}
private:
	static int _count;
};

int A::_count = 0;

void TestA()
{
	cout<<A::GetACount()<<endl;
	A a1, a2;
	A a3(a1);
	cout<<A::GetACount()<<endl;
}
int main()
{
	TestA();
	system("pause");
	return 0;
}
#endif
//��Ԫ����
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year), _month(month), _day(day)
	{}
	ostream & operator<<(ostream &_cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
		return _cout;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d(1,2,30);
	d << cout;
	//cout << d;
	system("pause");
	return 0;
}




