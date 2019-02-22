// 13_RomanToInteger.cpp : Defines the entry point for the console application.
//
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {

public:
	Solution()
	{
		map.insert(std::pair<std::string, int>("I", 1));
		map.insert(std::pair<std::string, int>("V", 5));
		map.insert(std::pair<std::string, int>("IV", 4));
		map.insert(std::pair<std::string, int>("X", 10));
		map.insert(std::pair<std::string, int>("IX", 9));
		map.insert(std::pair<std::string, int>("L", 50));
		map.insert(std::pair<std::string, int>("C", 100));
		map.insert(std::pair<std::string, int>("XL", 90));
		map.insert(std::pair<std::string, int>("XC", 90));
		map.insert(std::pair<std::string, int>("D", 500));
		map.insert(std::pair<std::string, int>("M", 1000));
		map.insert(std::pair<std::string, int>("CD", 400));
		map.insert(std::pair<std::string, int>("CM", 900));
	}
	// 我的解法思路正确，但是有点笨
	int romanToInt(string s) {
		int ret = 0, i = 0;
		while (true)
		{
			if (map.find(s.substr(i, 2)) != map.end())
			{
				ret += map[s.substr(i, 2)];
				i += 2;
			}
			else
			{
				ret += map[s.substr(i, 1)];
				i++;
			}
			if (i >= s.size())
			{
				break;
			}
		}
		return ret;
	}


	// 下面是在Discussion中看到的一个解法. 
	// 这个解法非常酷，发现了IV,IX这样的规律
	int romanToInt(string s)
	{
		unordered_map<char, int> T = {  { 'I' , 1 },
										{ 'V' , 5 },
										{ 'X' , 10 },
										{ 'L' , 50 },
										{ 'C' , 100 },
										{ 'D' , 500 },
										{ 'M' , 1000 } };

		int sum = T[s.back()];
		for (int i = s.length() - 2; i >= 0; --i)
		{
			if (T[s[i]] < T[s[i + 1]])
			{
				sum -= T[s[i]];
			}
			else
			{
				sum += T[s[i]];
			}
		}
	}

private:
	std::map<std::string, int> map;
};

int main()
{
	std::vector<string> strs = {"MMMXLV", "III", "IV", "IX", "LVIII", "MCMXCIV"};
	Solution sln;

	for each (auto str in strs)
	{
		int ret = sln.romanToInt(str);
		cout << str << " is " << ret << endl;
	}
    return 0;
}

