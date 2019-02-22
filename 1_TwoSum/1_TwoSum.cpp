// 1_TwoSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return[0, 1].
*/

/*
1. 数组并非是排序数组。
2. 肯定会有且只有一个解。

第一种方法：排序数组，双指针，但是会破坏数组中元素的位置。时间复杂度较高，且需要O(n)的空间复杂度
第二种方法：Map法
*/

#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public: 
	vector<int> twoSum(vector<int>& nums, int target)
	{
		std::vector<int> rets;
		std::map<int, int> numMap;
		size_t index;
		for (index = 0; index < nums.size(); index++)
		{
			if (numMap.find(target - nums[index]) != numMap.end())
			{				
				rets.push_back(numMap[target - nums[index]]);
				rets.push_back((int)index);
				return rets;
			}
			else
			{
				if (numMap.find(nums[index]) == numMap.end())
				{
					numMap[nums[index]] = (int)index;
				}
			}			
		}
		return rets;
	}
};


int main()
{
	std::vector<int> nums = { 2, 7, 11, 15 };
	Solution sln;
	std::vector<int> rets = sln.twoSum(nums, 9);
	for each (auto var in rets)
	{
		cout << var << " ";
	}
	cout << std::endl;
    return 0;
}

