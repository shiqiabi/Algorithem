// 4_MedianOfTwoSortedArrays.cpp : Defines the entry point for the console application.
//

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

/*
求两个排序数组的中值。
1. 如果采用归并排序的方法的化，空间复杂度是O(m+n),时间复杂度也是O(m+n). 不符合题目要求。
2. 这里的时间复杂度要求log(m+n). 分治法的策略。
   a. 如果m+n是偶数，只需要能够找到前(m+n)/2+1个数，并完成排序即可。
   b. 如果m+n是奇数，自需要找到前(m+n)/2个数，并完成排序。
   c. 这道题目演变成了从两个有序数组中找第k大数的问题。
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = (int)nums1.size(), size2 = (int)nums2.size();
		if ((size1 + size2) % 2 != 0)
		{
			return getKth(nums1, 0, nums2, 0, (size1 + size2 + 1) / 2);
		}
		else
		{
			return (getKth(nums1, 0, nums2, 0, (size1 + size2) / 2) + getKth(nums1, 0, nums2, 0, (size1 + size2 + 2) / 2)) / 2.0;
		}
	}

private:
	double getKth(vector<int> &nums1, int start1, vector<int> &nums2, int start2, int k)
	{
		// 函数旨在在nums1+nums中找到第k个元
		
		// 如果nums1耗尽，则返回nums2中的kth元素
		if (start1 == (int)nums1.size()) return nums2[start2 + k - 1];

		// 如果nums2耗尽，则返回nums1中的kth元素
		if (start2 == (int)nums2.size()) return nums1[start1 + k - 1];

		// 如果 k == 1, 返回第一个数字
		if (k == 1) return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];

		// 理解了这个思路
		int mid1 = INT32_MAX;
		int mid2 = INT32_MAX;
		
		if (start1 + k / 2 - 1 < nums1.size()) mid1 = nums1[start1 + k / 2 - 1];
		if (start2 + k / 2 - 1 < nums2.size()) mid2 = nums2[start2 + k / 2 - 1];

		if (mid1 < mid2)
			return getKth(nums1, start1 + k / 2, nums2, start2, k - k / 2);
		else
			return getKth(nums1, start1, nums2, start2 + k / 2, k - k / 2);
	}
};

int main()
{
	Solution sln;
	std::vector<std::vector<int>> numArys = {
		{1, 2}, {-1, 3},
		{1, 2}, {1, 1},
		{3, 5, 9, 10}, {1, 4, 13, 24, 34, 45, 76},
		{1, 3}, {2},
		{1,2}, {3,4},
		{2}, {1, 3},
		{2}, {5},
	};
	for (size_t index = 0; index < numArys.size(); index+=2)
	{
		double median = sln.findMedianSortedArrays(numArys[index], numArys[index+1]);
		cout << "The median value is " << median << endl;
	}
    return 0;
}

