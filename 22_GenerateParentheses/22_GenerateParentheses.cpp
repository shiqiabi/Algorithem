// 22_GenerateParentheses.cpp : Defines the entry point for the console application.
//

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// 虽然是递归，但有点动态规划的思想 

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n <= 0) return {};
		if (n == 1)
		{
			return{ "()" };
		}
		else
		{
			vector<string> result;
			vector<string> ret = generateParenthesis(n - 1);
			for each (string var in ret)
			{
				if ("()" + var != var + "()")
				{
					result.push_back("()" + var);
					result.push_back(var + "()");
				}
				else
				{
					result.push_back("()" + var);
				}

				result.push_back("(" + var + ")");
			}
			return result;
		}
	}
};

int main()
{
	vector<int> nums = { 3 };
	Solution sln;
	for each (int var in nums)
	{
		cout << var << endl;
		vector<string> results = sln.generateParenthesis(var);
		for each (string var in results)
		{
			cout << var << endl;
		}
	}
	
    return 0;
}

