#pragma once

typedef int HDataType;

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
}Heap;

void HeapInit(Heap* hp);
void HeapCreate(Heap* hp, int* array, int size);
void HeapPush(Heap* hp, HDataType data);
void HeapPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);



void testHeap();