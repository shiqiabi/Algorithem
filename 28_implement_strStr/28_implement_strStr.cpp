// 28_implement_strStr.cpp : Defines the entry point for the console application.
//

/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent 

to C's strstr() and Java's indexOf().
*/
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		if (haystack.size() == 0) return -1;
		int j = 0;
		for (int i = 0; i < haystack.size(); i++)
		{
			if (haystack[i] == needle[0])
			{
				for (j = 1; j < needle.size(); j++)
				{
					if (haystack[i + j] != needle[j])
					{
						break;
					}
				}
				if (j == needle.size())
				{
					return i;
				}
			}
		}
		return -1;
	}

	// 更加优化的方法
	// 在leetcode上的discussion中看到有使用api(indexof)的解法。
};

int main()
{
	std::vector<string> strAry = {"hello", "aaaaaaaaa"};
	std::vector<string> needles = { "ll", "bba" };

	Solution sln;
	for (int index = 0; index < strAry.size(); index++)
	{
		int pos = sln.strStr(strAry[index], needles[index]);
		cout << strAry[index] << "," << needles[index] << ": " << pos << endl;
	}
    return 0;
}

