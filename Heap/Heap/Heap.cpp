#include"Heap.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>


//��ʼ��һ���ն�
void HeapInit(Heap* hp,int initCap)
{
	assert(hp);
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType) * initCap);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = initCap;
	hp->size = 0;
}
void Swap(HDataType* left, HDataType* right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}
void AdjustDown(HDataType* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child + 1] < array[child])
			child += 1;
		//parent��С�ĺ����Ѿ��ҵ�
		//���parent�Ƿ�����ѵ�����
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
//�������е�Ԫ�ش�����
void HeapCreate(Heap* hp, int* array, int size)
{
	//1���Ƚ������е�Ԫ�طŵ��ѽṹ��
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;
	//2,���е���
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);
	}
}
void AdjustUp(HDataType* array, int size, int child)
{
	int parent = ((child - 1) / 2);
	while (child)
	{
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}
void CheckCapcity(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//1,�����¿ռ�
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType)*newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//2,����Ԫ��
		memcpy(temp, hp->array, hp->size*sizeof(HDataType));
		//3,�ͷžͿռ�
		free(hp->array);
		//4,ʹ���¿ռ�
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
void HeapPush(Heap* hp, HDataType data)
{
	//����Ƿ���Ҫ����
	CheckCapcity(hp);
	//1,����Ԫ�ز��뵽�����ĩβ��������Ԫ�ز��뵽��ȫ��������ĩβ
	hp->array[hp->size++] = data;
	//2,��Ԫ�صĲ��룬���ܻ��ƻ��ѵ�����
	AdjustUp(hp->array, hp->size, hp->size - 1);
}
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);
}
HDataType HeapTop(Heap* hp)//��ȡ�Ѷ�Ԫ��
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

int HeapEmpty(Heap* hp)//��Ϊ�շ��ط�0ֵ
{
	assert(hp);
	return 0 == hp->size;
}

int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}

void testHeap()
{
	int array[] = { 3, 6, 9, 1, 5, 2, 0, 7, 8,4 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("heap size =%d\n", HeapSize(&hp));
	printf("heap top =%d\n", HeapTop(&hp));
	HeapPop(&hp);
	printf("heap size =%d\n", HeapSize(&hp));
	printf("heap top =%d\n", HeapTop(&hp));
	HeapPush(&hp, 0);
	printf("heap size =%d\n", HeapSize(&hp));
	printf("heap top =%d\n", HeapTop(&hp));
	HeapDestroy(&hp);
}