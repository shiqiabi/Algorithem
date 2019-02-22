// 3_longestSubStrWithoutRepeatCharacters.cpp : Defines the entry point for the console application.
//

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
这个问题肯定不是一种方法。
1. 利用map
2. 滑动窗口的思路与利用map的思路非常类似。当时利用map的时间复杂度更优.
*/

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0;
		int start = 0;
		std::map<char, int> charMap;
		size_t i;
		for (i = 0; i < s.length(); i++)
		{
			if (charMap.find(s[i]) == charMap.end())
			{
				charMap.insert(std::pair<char, int>(s[i], (int)i));
				// 更新不重复字符串的长度
				ret = (int)charMap.size() > ret ? (int)charMap.size() : ret;
			}
			else
			{
				int index = charMap.find(s[i])->second;
				// 删除map中重复元素之前的字符
				for (; start <= index; start++)
				{
					charMap.erase(s[start]);
				}
				charMap.insert(std::pair<char, int>(s[i], (int)i));
			}
		}
		return ret;
	}

	// 在网上看到了一种优化后的解法，也是利用map。相对于自己的算法，省略了删除map中多余元素的步骤。使得时间复杂度更优。但是空间复杂度会有所增加。
	int lengthOfLongestSubstring2(string s) {
		int ret = 0;
		int start = 0;
		std::map<char, int> charMap;
		size_t i;
		for (i = 0; i < s.length(); i++)
		{
			if (charMap.find(s[i]) == charMap.end())
			{
				// 直接插入map
				charMap.insert(std::pair<char, int>(s[i], (int)i));
			}
			else
			{
				int index = charMap.find(s[i])->second;
				// 更新start元素
				start = index + 1 > start ? index + 1 : start;
				// 更新重复元素的位置
				charMap[s[i]] = i;
			}
			// 更新最大的长度
			ret = i - start + 1 > ret ? i - start + 1 : ret;
		}
		return ret;
	}
};


int main()
{
	std::vector<std::string> strAry = {"aabaab!bb", "abcabcbb","bbbbb", "pwwkew"};

	Solution sln;
	for each (string str in strAry)
	{
		int ret = sln.lengthOfLongestSubstring2(str);
		cout << "The length of longest sub string is " << ret << endl;
	}
    return 0;
}

