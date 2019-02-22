// 15_3Sum.cpp : Defines the entry point for the console application.
//

/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
*/


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		std::vector<vector<int>> ret;
		sort(nums.begin(), nums.end());
		if (nums.size() == 0 || nums[0] > 0 || nums[nums.size() - 1] < 0) return ret;
		size_t num = nums.size() - 1;
		while (num >= 0)
		{
			if (nums[num] >= 0)
			{
				int i = 0; int j = num - 1;
				while (i < j)
				{
					if (nums[i] + nums[j] < (-1)*nums[num])
					{
						i++;
					}
					else if (nums[i] + nums[j] > (-1)*nums[num])
					{
						j--;
					}
					else
					{
						ret.push_back({ nums[i], nums[j], nums[num] });
						break;
					}
				}
			}
			else
			{
				break;
			}
			num--;
		}
		return ret;
	}
};

int main()
{
	std::vector<int> intary = { -1, 0, 1, 2, -1, -4 };
	Solution sln;

	std::vector<std::vector<int>> ret = sln.threeSum(intary);
	for each (std::vector<int> var in ret)
	{
		for each (int num in var)
		{
			cout << num << " ";
		}
		cout << endl;
	}
    return 0;
}

