// 20_ValidParentheses.cpp : Defines the entry point for the console application.
//

// 这道题目是一道栈数据结构的应用题目。

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0) return true;
		stack<char> charStack;
		for (size_t i = 0; i < s.length(); i++)
		{			
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				charStack.push(s[i]);
			}
			else
			{
				if (!charStack.empty() > 0)
				{
					if ((s[i] == ')' && charStack.top() == '(') || (s[i] == ']' &&  charStack.top() == '[') || (s[i] == '}' &&  charStack.top() == '{'))
					{
						charStack.pop();
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
		}
		return charStack.empty();
	}
};

int main()
{
	Solution sln;
	std::vector<string> strAry = {"[])", "]", "()", "()[]{}", "(]", "([)]", "{[]}"};
	for each (string var in strAry)
	{
		if (sln.isValid(var))
		{
			cout << var << ": true" << endl;
		}
		else
		{
			cout << var << ": false" << endl;
		}
	}
    return 0;
}

