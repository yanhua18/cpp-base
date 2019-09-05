#include<iostream>
using namespace std;
//#include<stdio.h>
#include<Windows.h>
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
void TestFun(int a = 10, int b = 20, int c = 30)
{
	cout << "a=" << "a" << endl;
	cout << "b=" << "b" << endl;
	cout << "c=" << "c" << endl;

}