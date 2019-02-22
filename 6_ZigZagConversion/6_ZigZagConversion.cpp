// 6_ZigZagConversion.cpp : Defines the entry point for the console application.
//

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/


#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/*
	这种方法有点生硬。
	*/
	string convert(string s, int numRows) {
		std::vector<string> strs(numRows);
		int length = (int)s.length();
		int m, n, index = 0;
		while (index < length)
		{
			for (m = 0; m < numRows && index < length; m++, index++)
			{
				strs[m].push_back(s[index]);
			}
			for (n = numRows - 2; n > 0 && index < length; n--, index++)
			{
				strs[n].push_back(s[index]);
			}
		}
		string ret;
		for (m = 0; m < numRows; m++)
		{
			ret += strs[m];
		}
		return ret;
	}

	/*
	这种方法更好一点，相较于第一种方法，省略了较多的判断。
	*/
	string convert2(string s, int numRows)
	{
		if (numRows == 1) return s;
		string result;
		vector<string> strAry = vector<string>(numRows);
		int size = s.size();
		int row = 0, step = 1;
		for (int index = 0; index < size; index++)
		{
			strAry[row] = strAry[row] + s[index];
			if (row == numRows - 1)
			{
				step = -1;
			}
			else if (row == 0)
			{
				step = 1;
			}
			row += step;
		}
		for (string str : strAry)
		{
			result.append(str);
		}
		return result;
	}
};

int main()
{
	std::vector<string> strs = { "PAYPALISHIRING", "PAYPALISHIRING" };
	std::vector<int> rows = { 4, 3 };
	Solution sln;
	for (int i = 0; i < strs.size(); i++)
	{
		string ret = sln.convert(strs[i], rows[i]);
		cout << ret << endl;
	}
    return 0;
}

