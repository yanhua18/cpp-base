#if 0

#include <stdio.h>
#include<Windows.h>


//编写函数不允许创建临时变量，求字符串的长度
int Strlen(char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str + 1);
}
int main()
{
	char* str = "abcdef";
	int len = Strlen(str);
	printf("%d", len);
	system("pause");
}
//接受一个整型值（无符号），按照顺序打印它的每一位。 例如： 输入：1234，输出 1 2 3 4
void print(int n)
{
	if (n > 9)
		print(n / 10);
	printf("%d\n", n%10);
}
int main()
{
	int n = 1234;
	print(n);
	system("pause");
	return 0;
}
#endif