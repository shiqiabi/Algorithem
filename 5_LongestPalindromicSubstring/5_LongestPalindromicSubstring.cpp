// 5_LongestPalindromicSubstring.cpp : Defines the entry point for the console application.
//

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

/*
这是寻找回文串的问题。
1.网上发现的中心扩展法。时间复杂度是O(n*n)
2.经典的马拉车算法。
*/

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int len = (int)s.size();
		if (len < 1) return s;
		int start, maxLen = 0;
		for (int i = 1; i < len; i++)
		{
			// 寻找以i-1,i为中点的偶数长度的回文
			int low = i - 1, high = i;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxLen)
			{
				maxLen = high - low - 1;
				start = low + 1;
			}
			// 寻找以i为中心的奇数长度的回文
			low = i - 1; high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxLen)
			{
				maxLen = high - low - 1;
				start = low + 1;
			}
		}
		return s.substr(start, maxLen);
	}
};

int main()
{
    return 0;
}

