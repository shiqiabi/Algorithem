#pragma once

#include <vector>
#include <memory>
using namespace std;

class MergeSort
{
public:
	MergeSort();
	~MergeSort();
	void Sort(vector<int>& ary);

private:
	std::unique_ptr<vector<int>> m_backup = nullptr;

private:
	void mergesort(vector<int>& ary, int start, int end);
	void merge(vector<int>& ary, int start, int mid, int end);
};