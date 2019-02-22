#pragma once

#include <vector>
#include <memory>
using namespace std;

class StableHeapSort
{
public:
	StableHeapSort();
	~StableHeapSort();
	void Sort(vector<int>& ary);

public:
	std::unique_ptr<vector<int>> m_timestampAry = nullptr;

private:
	std::unique_ptr<vector<int>> m_backup = nullptr;
	int m_size = 0;

private:
	void swim(int k);
	void sink(int k);
	bool less(int i, int j);
};