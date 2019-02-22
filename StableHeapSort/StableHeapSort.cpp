#include "stdafx.h"
#include "StableHeapSort.h"

StableHeapSort::StableHeapSort()
{
	m_timestampAry = nullptr;
	m_backup = nullptr;
	m_size = 0;
}


StableHeapSort::~StableHeapSort()
{
}


void StableHeapSort::Sort(vector<int>& ary)
{
	m_size = (int)ary.size();
	m_backup = std::make_unique<vector<int>>(m_size + 1);
	m_timestampAry = std::make_unique<vector<int>>(m_size + 1);
	int index = 1, timestamp = 1;
	for each (int ele in ary)
	{
		(*m_backup)[index] = ele;
		(*m_timestampAry)[index] = timestamp++;
		index++;
	}
	// initialise max heap
	for (int index = m_size / 2; index >= 1; index--)
	{
		sink(index);
	}

	// sort the heap
	while (m_size > 1)
	{
		int temp = (*m_backup)[1];
		int timestamp = (*m_timestampAry)[1];
		(*m_backup)[1] = (*m_backup)[m_size];
		(*m_timestampAry)[1] = (*m_timestampAry)[m_size];
		(*m_backup)[m_size] = temp;
		(*m_timestampAry)[m_size] = timestamp;
		m_size--;
		sink(1);
	}

	for (int index = 1; index <= ary.size(); index++)
	{
		ary[index - 1] = (*m_backup)[index];
	}
}

// helper function: swim
void StableHeapSort::swim(int k)
{
	while (k / 2 && less(k / 2, k))
	{		
		int temp = (*m_backup)[k / 2];
		int timestamp = (*m_timestampAry)[k / 2];
		(*m_backup)[k / 2] = (*m_backup)[k];
		(*m_timestampAry)[k / 2] = (*m_timestampAry)[k];
		(*m_backup)[k] = temp;
		(*m_timestampAry)[k] = timestamp;

		k = k / 2;
	}
}

// helper function: sink
void StableHeapSort::sink(int k)
{
	while (2 * k <= m_size)
	{
		int j = 2 * k;
		if (j < m_size && less(j, j+1)) j = j + 1;
		if (less(k, j))
		{
			int temp = (*m_backup)[k];
			int timestamp = (*m_timestampAry)[k];
			(*m_backup)[k] = (*m_backup)[j];
			(*m_timestampAry)[k] = (*m_timestampAry)[j];
			(*m_backup)[j] = temp;
			(*m_timestampAry)[j] = timestamp;
			k = j;
		}
		else
		{
			break;
		}
	}
}

bool StableHeapSort::less(int i, int j)
{
	if ((*m_backup)[i] < (*m_backup)[j]) return true;
	else if ((*m_backup)[i] > (*m_backup)[j]) return false;
	else  return (*m_timestampAry)[i] < (*m_timestampAry)[j];
}