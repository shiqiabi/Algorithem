#include "HeapSort.h"
#include <stdio.h>
#include "stdafx.h"

// This is large heap
// the function will be used when remove an element from a help 
void sink(int ary[], int index, int length)
{
	if (index < 1)
	{
		printf("Invalid index in sink \n");
		return;
	}

	if (length <= 1) return;
	while (index * 2 <= length)
	{
		int j = index * 2;
		if (j < length && ary[j] < ary[j + 1])      // j + 1 is right child of index
		{
			j = j + 1;
		}

		if (ary[index] < ary[j])
		{
			int temp = ary[j];
			ary[j] = ary[index];
			ary[index] = temp;
			index = j;
		}
		else
		{
			break;
		}
	}
}

// the function will be used when insert an element to a help
void swim(int ary[], int index)
{
	while (index > 1 && ary[index] > ary[index / 2])
	{
		int temp = ary[index];
		ary[index] = ary[index / 2];
		ary[index / 2] = temp;
		index = index / 2;
	}
}


// the array is sorted by asending, heap sorting
void sort(int ary[], int length)
{
	// first step: construct a heap
	for (int start = length / 2; start >= 1; start--)
	{
		sink(ary, start, length);
	}

	// second step: sort
	int n = length;
	while (n > 1)
	{
		int temp = ary[1];
		ary[1] = ary[n];
		ary[n] = temp;
		sink(ary, 1, --n);
	}
}