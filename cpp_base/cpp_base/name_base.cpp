#include<iostream>
using namespace std;
#include<Windows.h>
//#include<stdlib.h>
//#pragma warning(disable:4996) 

//#include<stdio.h>


#if 0

/*一个命名空间就定义了一个新的定义域，命名空间中所有的内容都局限于该定义域中*/


//普通的命名空间（命名空间中既可以定义变量也可以定义函数）
namespace N1//N1为命名空间的名称
{
	int a=10;
	int ADD(int a, int b)
	{
		return a + b;
	}
}

//命名空间可以嵌套
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

//同一个工程中允许存在多个相同名称的命名空间（编译器最后会合并到同一个命名空间中去）
namespace N1
{
	int Mul(int a, int b)
	{
		return a*b;
	}
}


/*命名空间的使用方式有三种:
加命名空间名称及作用域限定符
使用using将命名空间引入
使用using namespace命名空间名称引入

//using N2::a;
using namespace N1;
int main()
{
	//加命名空间名称及作用域限定符
	//printf("%d\n", N2::a);
	//使用using将命名空间引入
	//printf("%d\n", a);
	//使用using namespace命名空间名称引入
	//printf("%d\n", ADD(3, 4));

	cout << "hello world" << endl;//使用cout标准输出和cin标准输入时，必须包含<iostream>头文件和std标准命名库


	system("pause");
	return 0;
}
*/


//缺省参数
//缺省参数就是在声明或定义函数时为函数的参数指定一个默认值，在调用该函数时，如果没有指定实参则采用该默认值，否则使用实参
//全缺省参数
void TestFun(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << "a" << endl;
	cout << "b=" << "b" << endl;
	cout << "c=" << "c" << endl;
}
//半缺省参数（半缺省参数必须从右往左依次给值，不能间隔着给）
void TestFunc(int a, int b=10, int c=20)
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}

//函数重载
int Add(int left, int right)
{
	return left + right;
}
double Add(double left, double right)
{
	return left + right;
}


//缺省参数不要与函数重载同时使用
void TestFunc(int a ,int b=10)
{
	cout << "void TestFunc(int)" << endl;
}
void TestFunc(int a,int b)
{
	cout << "void TestFunc(int)" << endl;
}



//如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，因此不能用栈上的空间作为引用类型返回。如果以引用类型返回，返回值的生命周期必须不受函数的限制(即比函数生命周期长)。

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

//传值，传引用，传指针效率比较
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
	//传值
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();
	//传引用
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2(a);
	}
	size_t end2 = clock();
	//传指针
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc3(&a);
	}
	size_t end3 = clock();

	// 分别计算两个函数运行结束后的时间
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
//做返回值类型
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
	//返回值
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc1();
	}
	size_t end1 = clock();
	//返回引用
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc2();
	}
	size_t end2 = clock();
	//返回指针
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; ++i)
	{
		TestFunc3();
	}
	size_t end3 = clock();

	// 分别计算两个函数运行结束后的时间
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
	return 0；
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
	//printf("%d", a);//直接以10打印，没有从a空间中取值
	//printf("%d", *pa);

	TestAuto();
	system("pause");
	return 0;
}


//有范围的for
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
//类和对象*******************************************************************************
//类的两种定义方式
//1,声明和定义全放在类中
//2，声明放在头文件，定义放在执行文件中
struct Person//struct定义的类中成员默认权限是公有的，二class定义的类的成员的默认权限是私有的
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
//类的大小
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
	d.gender = "女";
	d.name = "李猛";
	d.showInfomation();*/
	system("pause");
	return 0;
}



class A
{
public:
	void PrintA()
	{
		cout << _a << endl;//空指针不能访问成员变量
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
	Date()//无参构造函数
	{

	}
	Date(int _year, int _month, int _day)//带参构造函数
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
	//自定义类型
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



//析构函数

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


//运算符==重载*************************************************************************************************
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
bool operator==(const Date &d1, const Date &d2)//需要全局变量是共有的
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



//保证封闭性，将重载函数声明成成员函数
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	// 赋值运算符重载：如果用户没有显式提供，编译器将会生成一份默认的赋值运算符重载
	// 如果一个类中涉及到资源管理，用户必须提供赋值运算符重载

	Date& operator =(const Date& d)//引用是为了提高效率，const保证安全性
	{
		if (&d != this)//看两个对象的地址是不是一样，一样就不需要赋值
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	Date& operator++()//前置++
	{
		_day += 1;
		return *this;
	}

	Date operator++(int)//后置++
	{
		Date tmp(*this);//栈上对象，不能以引用返回
		_day += 1;
		return tmp;
	}

	bool operator==(const Date &d2)//this指向的调用函数的对象
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
	//d1 = 2019;//d1是一个类类型的对象，而2019是一个整形变量
	system("pause");//会先为2019构造一个对象，再用这个临时对象来为d1赋值
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

//友元函数
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


//友元类
class Date;
class Time
{
	friend class Date;
public:
	Time(int hour, int minute, int second)
		:_hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	   {}
	
	void SetTimeOfDate(int hour, int minute, int second)
	{
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};




void Test()
{
	int *p1 = (int *)malloc(sizeof(int));
	free(p1);
	int *p2 = (int *)calloc(4, sizeof(int));
	int *p3 = (int *)realloc(p2, sizeof(int) * 10);
	free(p3);
}
int main()
{
	Test();
	system("pause");
	return 0;
}


void Test()
{
	int *ptr4 = new int;
	int *ptr5 = new int(10);
	int *ptr6 = new int[3];
	delete ptr4;
	delete ptr5;
	delete[] ptr6;
}

int main()
{
	Test();
	system("pause");
	return 0;
}



//函数模板的转化
template <class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	Add(a1, (int)d2);
	// 对函数模板进行隐式实例化
	// 同名函数与函数模板同时存在时，优先使用模板生成的同名函数
	Add<>(1, 2);


	Add<int>(a1, d2);
	system("pause");
	return 0;
}


//用类模板写一个动态类型顺序表

#include<assert.h>

template<class T>
class SeqList
{
public:
	SeqList(size_t capacity = 10)
		:_array(new T[capacity])
		, _size(0)
		, _capacity(capacity)
	{}
	~SeqList()
	{
		delete[] _array;
		_array = nullptr;
		_capacity = 0;
		_size = 0;
	}
	void PopBack()
	{
		--_size;
	}
	size_t size() const
	{
		return _size;
	}
	size_t capacity() const
	{
		return _capacity;
	}
	bool Empty() const
	{
		return 0 == _size;
	}
	T& operator[](size_t index)
	{
		assert(index < _size);
			return _array[index];
	}
	const T& operator[](size_t index)const
	{
		assert(index < _size);
			return _array[index];
	}
	void PushBack(const T& data);

private:
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			// 开辟新空间
			T* array = new T[2 * _capacity];

			// 拷贝元素
			// memcpy(array, _array, _size*sizeof(T));
			for (size_t i = 0; i < _size; ++i)
			{
				array[i] = _array[i];
			}

			// 释放旧空间
			delete[] _array;
			_array = array;
			_capacity *= 2;
		}
	}
	
private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

template<class T>
void SeqList<T>::PushBack(const T&data)
{
	_CheckCapacity();
	_array[_size++] = data;
}
void TestSeqList()
{
	SeqList<int>  s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	cout << s1[2] << endl;
	s1[2] = 10;

	SeqList<double>  s2;
	s2.PushBack(1.0);
	s2.PushBack(2.0);
	s2.PushBack(3.0);
	s2.PushBack(4.0);
	s2.PushBack(5.0);
	cout << s2.size() << endl;
	cout << s2.capacity() << endl;
}

int main()
{
	TestSeqList();
	system("pause");
	return 0;
}

class B
{
public:
	int _b;
};
class C :virtual public B
{
public:
	int _c;
};
class D : virtual public B
{
public:
	int _d;
};
class A :public C, public D
{
public:
	int _a;
};
int main()
{
	cout << sizeof(A) << endl;
	system("pause");
	return 0;
}


template<class T>
class smartptr
{
public:
	smartptr(T* ptr = nullptr)
		:_ptr(ptr)
	{
		cout << "smartptr(T* )" << endl;
	}
	~smartptr()
	{
		cout << "~smartptr(T* )" << endl;
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}
	T& operator*()
	{
		return *_ptr;
	}
	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};
void testsmartptr()
{
	int a = 10;
	int *pa = &a;
	int *pb(pa);
	smartptr<int> sp1(new int);
	smartptr<int> sp2(sp1);
}
int main()
{
	testsmartptr();
	return 0;
}

namespace heqing
{
	//auto_ptr解决的原理就是资源的转移
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//指针特性
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//解决浅拷贝（资源的转移）
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		auto_ptr<T>& operator=(auto_ptr<T> ap)
		{
			if (this != &ap)
			{
				if (_ptr)//如果当前对象管理资源了，先释放原有的资源
				{
					delete _ptr;
				}

				_ptr = ap._ptr;//资源转移
				ap._ptr = nullptr;//ap与资源断开练习
			}
			return *this;
		}
	private:
		T* _ptr;

	};
}
void testautoptr()
{
	int a = 10;
	int* pa = &a;
	int* pb = pa;
	*pa = 100;
	*pb = 200;//两个对象能同时操作同一份资源
	heqing::auto_ptr<int> ap1(new int);
	heqing::auto_ptr<int> ap2(ap1);
	//资源转移带来的缺陷。两个对象不能同时操作同一份资源
	*ap2 = 200;
	*ap1 = 100;
	heqing::auto_ptr<int> ap3;
	ap3 = ap2;
}
int main()
{
	testautoptr();
	return 0;
}
#endif
namespace heqing
{
	//auto_ptr解决的原理就是资源的转移
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			, _owner(false)
		{
			if (_ptr)
			{
				_owner = true;
			}
		}
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//指针特性
		T& operator*()
		{
			return *_ptr;
		}
		T* operator->()
		{
			return _ptr;
		}
		//解决浅拷贝（资源的转移）
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}
		auto_ptr<T>& operator=(auto_ptr<T> ap)
		{
			if (this != &ap)
			{
				if (_ptr)//如果当前对象管理资源了，先释放原有的资源
				{
					delete _ptr;
				}

				_ptr = ap._ptr;//资源转移
				ap._ptr = nullptr;//ap与资源断开练习
			}
			return *this;
		}
	private:
		T* _ptr;
		bool _owner;

	};
}
void testautoptr()
{
	int a = 10;
	int* pa = &a;
	int* pb = pa;
	*pa = 100;
	*pb = 200;//两个对象能同时操作同一份资源
	heqing::auto_ptr<int> ap1(new int);
	heqing::auto_ptr<int> ap2(ap1);
	//资源转移带来的缺陷。两个对象不能同时操作同一份资源
	*ap2 = 200;
	*ap1 = 100;
	heqing::auto_ptr<int> ap3;
	ap3 = ap2;
}
int main()
{
	testautoptr();
	return 0;
}