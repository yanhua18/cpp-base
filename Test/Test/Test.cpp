#if 0

#include <stdio.h>
#include<Windows.h>


//��д��������������ʱ���������ַ����ĳ���
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
//����һ������ֵ���޷��ţ�������˳���ӡ����ÿһλ�� ���磺 ���룺1234����� 1 2 3 4
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