#include<iostream>
using namespace std;
//#include<stdio.h>
#include<Windows.h>
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
void TestFun(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << "a" << endl;
	cout << "b=" << "b" << endl;
	cout << "c=" << "c" << endl;

}