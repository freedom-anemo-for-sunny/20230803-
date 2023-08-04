#define  _CRT_SECURE_NO_WARNINGS  1
#pragma  warning(disable:6031)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void insert(void* arr, int length, int size, int(*compare)(void*, void*))
{
	int i = 0, j = 0;
	int left = -1, right = length;
	int middle;
	int cmp;
	
	char* px;
	px = (char*)malloc(size);
	while (left < right - 1)
	{
		middle = (left + right) / 2;
		cmp = compare((void*)((char*)arr + middle * size), (void*)((char*)arr + length * size));
		if (cmp < 0)
			right = middle;
		else if (cmp > 0)
			left = middle;
		else
		{
			left = middle;
			right = middle;
			break;
		}
	}
	for (j = 0; j < size; j++)
		px[j] = *((char*)arr + length * size + j);
	for (i = length; i >= 0; i--)
	{
		if (i > left + 1)
			for (j = 0; j < size; j++)
				*((char*)arr + i * size + j) = *((char*)arr + (i - 1) * size + j);
		else if (i == left + 1)
			for (j = 0; j < size; j++)
				*((char*)arr + i * size + j) = px[j];
	}
	free(px);
	px = NULL;
}

void insert_sort(void* arr, int length, int size, int(*compare)(void*, void*))
{
	int i = 0;
	for (i = 0; i < length - 1; i++)
		insert(arr, i + 1, size, compare);
}

int compare(void* e1, void* e2)
{
	return *((short*)e2) - *((short*)e1);
}

int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	short arr[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		arr[i] = rand();
		printf("%d ", arr[i]);
	}
	printf("\n");
	insert_sort(arr, 10, sizeof(arr[0]), compare);
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}