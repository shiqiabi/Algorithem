// 215_KthLargestElementInAry.cpp : Defines the entry point for the console application.
//

/*
寻找第K大的问题，这是一个典型的问题，同时也有典型的解法。
1. 分治法。类似于快速排序。该解法的时间复杂度是O(n)，空间复杂度为O(n)
2. 堆排序法。它的时间复杂度可以按照下面进行分析： 
   a. 创建一个大小为k的小顶堆。O(klogk)
   b. 将剩余元素依次插入到小顶堆中，如果小于堆顶元素，则丢弃该元素。如果大于堆顶元素则将该元素替换堆顶元素，整理堆 (nlogk)
   c. 在b步骤结束后，堆顶元素就是第k大元素 
   该算法的时间复杂度是(O(klogk + nlogk)=O((k+n)logk) - O(nlogk)。所以当n较大k较小的时候，时间复杂度较好。
   该算法空间复杂度为O(k)
3. 桶排序法：当数组中的最大元素，在一定的范围时，可以采用该方法。时间复杂度为O(n), 但是该方法的空间复杂度比较大 O(MAXElement)。
*/

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		// 留出第一个元素，以方便堆中元素的访问
		mHeap.push_back(INT32_MAX);
		// 构建小顶堆
		int i;
		for (i = 0; i < k; i++)
		{
			mHeap.push_back(nums[i]);
		}
		createHeap();

		for (i = k; i < (int)nums.size(); i++)
		{
			if (nums[i] > mHeap[1])
			{
				mHeap[1] = nums[i];
				sink(mHeap, 1);
			}
		}
		return mHeap[1];
	}

private:
	void createHeap();
	void sink(std::vector<int> &ary, int index);

private:
	std::vector<int> mHeap;
};

// 将一个无序数组变成小顶堆：从1/2元素处进行下沉操作
void Solution::createHeap()
{
	//
	int length = (int)mHeap.size();
	for (int i = length / 2; i >= 1; i--)
	{
		sink(mHeap, i);
	}
}

void Solution::sink(std::vector<int> &ary, int index)
{
	if (ary.size() < 1) return;
	int heapsize = (int)ary.size() - 1;
	// 如果元素有子元素，左子元素的tag是index*2，右子元素的tag是index*2 + 1
	while (index * 2 <= heapsize)
	{
		// 找到子元素中的最小元素
		int j = index * 2;
		if (j < heapsize && ary[j] > ary[j + 1])
		{
			j = j + 1;      
		}

		// 如果父元素大于最小的子元素，则进行交换.
		if (ary[index] > ary[j])
		{
			std::swap(ary[index], ary[j]);
			index = j;
		}
		else
		{
			// 退出循环
			break;
		}
	}
}

int main()
{
	Solution sln;
	std::vector<std::vector<int>> intArys = { { 3,2,1,5,6,4 }, { 3,2,3,1,2,4,5,5,6 } };
	std::vector<int> ks = { 2, 4 };

	for (size_t index = 0; index < intArys.size(); index++)
	{
		int kthValue = sln.findKthLargest(intArys[index], ks[index]);
		cout << "The " << ks[index] << "th max value is " << kthValue << endl;
	}
    return 0;
}

