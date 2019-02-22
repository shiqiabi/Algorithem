// HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HeapSort.h"

int main()
{
	int ary[] = { 2, 10, 6, 8, 4, 12, 67, 1, 5, 9 };
	int length = sizeof(ary) / sizeof(int) - 1;       // the length is the number of elements in the heap.
	sort(ary, length);

	for (int index = 1; index <= length; index++)
	{
		printf("%d ", ary[index]);
	}

	printf("\n");

	char exit;
	scanf_s("%c", &exit);

    return 0;
}

