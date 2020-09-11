#include<iostream>
using namespace std;
#include<string>
#include<stdio.h>
#include<Windows.h>


struct st{
	int i[3];
	int a;
	char b;
};
int main()
{
	struct st a;
	for (int i = 0; i < 5; i++)
	{
		a.i[i] = i;
	}
	printf("%d", a.a);
}
