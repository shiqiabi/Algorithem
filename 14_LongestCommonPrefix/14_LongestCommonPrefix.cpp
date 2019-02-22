// 14_LongestCommonPrefix.cpp : Defines the entry point for the console application.
//

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string result;
		int minLen = strs.size() == 0 ? 0 : (int)strs[0].size() ; size_t index;
		// index是字符串数组的索引
		for ( index = 1; index < strs.size(); index++)
		{
			if (strs[index].length() < minLen) minLen = strs[index].length();
		}
		// i 公共字符的索引
		for (int i = 0; i < minLen; i++)
		{
			for (index = 0; index < strs.size() - 1; index++)
			{
				if (strs[index][i] != strs[index+1][i])
				{
					return result;
				}
			}
			result.push_back(strs[0][i]);
		}
		return result;
	}
};

int main()
{
	std::vector<std::vector<std::string>> strsAry;
	strsAry.push_back({ "flower", "flow", "flight" });
	strsAry.push_back({ "dog","racecar","car" });
	strsAry.push_back({});
	Solution sln;
	for each (auto strs in strsAry)
	{
		string ret = sln.longestCommonPrefix(strs);
		cout << ret << endl;
	}
    return 0;
}

