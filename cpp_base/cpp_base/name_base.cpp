//#include<iostream>
//using namespace std;
#include<stdio.h>
#include<Windows.h>
#include<time.h>
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

#if 0

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
	//printf("%d", a);//ֱ����10��ӡ��û�д�a�ռ���ȡֵ
	//printf("%d", *pa);

	TestAuto();
	system("pause");
	return 0;
}
