#include<iostream>
using namespace std;
//#include<stdio.h>
#include<Windows.h>
//#include<time.h>

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
	//Date()//无参构造函数
	//{

	//}
	//Date(int _year, int _month, int _day)//带参构造函数
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

class Solution {
public:
	// 统计CSum类总共创建了多少个对象
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


