#include"Heap.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>


//初始化一个空堆
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
		//parent较小的孩子已经找到
		//检测parent是否满足堆的性质
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
//用数组中的元素创建堆
void HeapCreate(Heap* hp, int* array, int size)
{
	//1，先将数组中的元素放到堆结构中
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;
	//2,进行调整
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
		//1,开辟新空间
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType)*newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		//2,拷贝元素
		memcpy(temp, hp->array, hp->size*sizeof(HDataType));
		//3,释放就空间
		free(hp->array);
		//4,使用新空间
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
void HeapPush(Heap* hp, HDataType data)
{
	//检测是否需要扩容
	CheckCapcity(hp);
	//1,将新元素插入到数组的末尾，即将新元素插入到完全二叉树的末尾
	hp->array[hp->size++] = data;
	//2,新元素的插入，可能会破坏堆的性质
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
HDataType HeapTop(Heap* hp)//获取堆顶元素
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

int HeapEmpty(Heap* hp)//堆为空返回非0值
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