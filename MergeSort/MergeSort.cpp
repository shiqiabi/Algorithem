#include "stdafx.h"
#include "MergeSort.h"

MergeSort::MergeSort()
{
	m_backup = nullptr;
}

MergeSort::~MergeSort()
{
}

void MergeSort::Sort(vector<int>& ary)
{
	int size = ary.size();
	if (size <= 1) return;
	m_backup = make_unique<vector<int>>(size);
	mergesort(ary, 0, size-1);
}

void MergeSort::mergesort(vector<int>& ary, int start, int end)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		mergesort(ary, start, mid);
		mergesort(ary, mid + 1, end);
		merge(ary, start, mid, end);
	}
}

// 在进行merge的时候，start到mid 和 mid+1到end已经是有序的了 
void MergeSort::merge(vector<int>& ary, int start, int mid, int end)
{
	// copy original ary elements to backuo ary
	for (int index = start; index <= end; index++)
	{
		(*m_backup)[index] = ary[index];
	}

	int i = start, j = mid + 1, k = start;

	while (i <= mid && j <= end)
	{
		if ((*m_backup)[i] < (*m_backup)[j]) ary[k++] = (*m_backup)[i++];
		else ary[k++] = (*m_backup)[j++];
	}
	while (i <= mid ) ary[k++] = (*m_backup)[i++];
	while (j <= end) ary[k++] = (*m_backup)[j++];
}

