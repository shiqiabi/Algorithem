// 7_ReverseInteger.cpp : Defines the entry point for the console application.
//

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/


#include "stdafx.h"
#include <math.h>
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	// 这是我的代码，在提交时总是有失败的case.
	// 知道失败的原因了： x = -x   => x = abs(x). 这里的行为不一致，
	int reverse(int x)
	{
		int64_t result = 0;
		bool isNegative = false;
		if (x < 0)
		{
			isNegative = true;
			x = -x;
		}
		while (x != 0)
		{
			result = result * 10 + (x % 10);
			x = x / 10;
			if (!isNegative && result > INT_MAX)
			{
				return 0;
			}
			else if (isNegative && (-1)*result < INT_MIN)
			{
				return 0;
			}
		}
		return isNegative ? -1 * result : result;
	}

	// 下面是我在discussion中看到的被人的代码
	int reverse2(int x)
	{ 
		bool isPos = x > 0;
		int64_t l = abs(x), rl = 0;
		for (; l; l /= 10) rl = rl * 10 + (l % 10);
		return (rl > INT_MAX || rl < INT_MIN)
			? 0
			: rl * (isPos ? 1 : -1);
	}
};

int main()
{
	std::vector<int> intAry = {INT_MIN, -1563847412, 1534236469, 123, -123, 120, 1 , 0 };
	Solution sln;
	for each (auto num in intAry)
	{
		int ret = sln.reverse2(num);
		cout << ret << endl;
	}

    return 0;
}

