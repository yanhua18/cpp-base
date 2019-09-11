//#include<iostream>
//using namespace std;
#include<stdio.h>
#include<Windows.h>
#include<time.h>
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

#if 0

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
	return 0;
}

#endif

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


#if 0
// 类
struct Student
{
	// 成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 29);
	s.PrintStudent();

	return 0;
}
#endif

// 面相对象程序：封装  继承  多态
// 封装：将一个事物的内部实现细节隐藏起来，提供一个公有接口让对象之间进行交互

// C++实现封装：类(通过类将对象的属性和行为包装在一起)
//   访问权限：private  protected  public
// public: 被public修饰的成员，可以直接在类外被访问
// protected/private: 不能直接在类外进行访问

//int _age = 10;

// void SetStudentInfo(char* name)
// {}

#if 0
class Student
{
public:
	// 成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int g_a = 10;
int main()
{
	Student s;
	s.SetStudentInfo("Peter", "男", 29);
	s.PrintStudent();

	// s._age = 30;
	cout << g_a << endl;
	return 0;
}
#endif

#if 0
struct Student
{
public:
	// 成员方法 || 行为
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	void PrintStudent()
	{
		cout << _name << ":" << _gender << ":" << _age << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};

int main()
{
	Student s1, s2, s3;
	cout << sizeof(s1) << endl;

	s1.SetStudentInfo("Peter", "男", 29);
	s2.SetStudentInfo("静静", "女", 30);
	s3.SetStudentInfo("summer", "公", 4);


	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif

#if 0
class A
{
public:
	void TestFun()
	{}
};


// 空类的大小？主流编译器中空类的大小是1
class B
{};


// 
int main()
{
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	B b1, b2, b3;


	return 0;
}
#endif

#if 0
struct Student
{
	char _name[20];
	char _gender[3];
	int _age;
};

void SetStudentInfo(Student* ps, char* name, char* gender, int age)
{
	strcpy(ps->_name, name);
	strcpy(ps->_gender, gender);
	ps->_age = age;
}

void PrintStudent(Student* ps)
{
	printf("%s %s %d", ps->_name, ps->_gender, ps->_age);
}
#endif




#if 0
class Student
{
public:
	void SetStudentInfo(char* name, char* gender, int age)
	{
		// Student* const
		//this = nullptr;
		cout << this << endl;
		strcpy(this->_name, name);
		strcpy(this->_gender, gender);
		this->_age = age;
	}

	void PrintStudent()
	{
		cout << this->_name << ":" << this->_gender << ":" << this->_age << endl;
	}

	// 不定参数
	void TestFunc(...)
	{
		cout << this << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};
#endif

/*
女朋友
未来女朋友的一些基本信息
做饭 &


1. 先识别类名
2. 识别类中的成员变量
3. 识别类中的成员函数并且对类中的成员函数进行改写
*/
#if 0
class Student
{
public:
	/*
	void SetStudentInfo(Student* const this, char* name, char* gender, int age)
	{
	strcpy(this->_name, name);
	strcpy(this->_gender, gender);
	this->_age = age;
	}
	*/
	void SetStudentInfo(char* name, char* gender, int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}

	/*
	void PrintStudent(Student* const this)
	{
	cout << this->_name << ":" << this->_age << endl;
	}
	*/
	void PrintStudent()
	{
		cout << _name << ":" << _age << endl;
	}

private:
	// 成员变量 || 属性
	char _name[20];
	char _gender[3];
	int _age;
};


int main()
{
	//cout << this << endl;
	Student s1, s2, s3;
	s1.TestFunc(10);

	cout << &s1 << endl;
	s1.SetStudentInfo("Peter", "男", 29);

	cout << &s2 << endl;
	s2.SetStudentInfo("静静", "女", 30);

	cout << &s3 << endl;
	s3.SetStudentInfo("summer", "公", 4);

	s1.PrintStudent();
	s2.PrintStudent();
	s3.PrintStudent();
	return 0;
}
#endif

class A
{
public:
	void PrintA()
	{
		cout << this << endl;
		cout << this->_a << endl;
	}

	void Show()
	{
		cout << this << endl;
		cout << "Show()" << endl;
	}
private:
	int _a;
};

int main()
{
	A* p = NULL;
	p->Show();
	p->PrintA();


	return 0;
}
