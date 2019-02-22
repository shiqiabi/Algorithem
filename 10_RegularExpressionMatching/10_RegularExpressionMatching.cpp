// 10_RegularExpressionMatching.cpp : Defines the entry point for the console application.
//
/*
Given an input string(s) and a pattern(p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string(not partial).

Note:

s could be empty and contains only lowercase letters a - z.
p could be empty and contains only lowercase letters a - z, and characters like . or *.
Example 1 :

	Input :
	s = "aa"
	p = "a"
	Output : false
	Explanation : "a" does not match the entire string "aa".
	Example 2 :

	Input :
	s = "aa"
	p = "a*"
	Output : true
	Explanation : '*' means zero or more of the precedeng element, 'a'.Therefore, by repeating 'a' once, it becomes "aa".
	Example 3 :

	Input :
	s = "ab"
	p = ".*"
	Output : true
	Explanation : ".*" means "zero or more (*) of any character (.)".
	Example 4 :

	Input :
	s = "aab"
	p = "c*a*b"
	Output : true
	Explanation : c can be repeated 0 times, a can be repeated 1 time.Therefore it matches "aab".
	Example 5 :

	Input :
	s = "mississippi"
	p = "mis*is*p*."
	Output : false
*/
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	// 这是自己的代码实在是太low了。关键是没有思路。
	bool isMatch_my(string s, string p) {
		if (p == ".*") return true;

		size_t si, pi;
		for (si = 0, pi = 0; si < s.size() && pi < p.size(); si++, pi++)
		{
			if (p[pi] == '.' && p[pi + 1] == '*')
			{
				return true;
			}
			else
			{
				if (s[si] == p[pi] || p[pi] == '.')
				{
					continue;
				}
				else if (s[si] == p[pi] && p[pi + 1] == '*')
				{
					while (true)
					{
						if (s[si + 1] != p[pi])
							break;
						else
							si = si + 1;
					}
					continue;
				}
				else
				{
					return false;
				}
			}
		}

		if (si == s.size())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	
public:
	// 递归方法isMatch()的条件判别如下：
	/*
	p.length() == 0, s is empty : s is not empty, true, false                                                                                        (1)
	p.length() == 1, s is empty,                      false                                                                                              (2)                                              
	                 (p[0] == s[0] or p[0] == '.') => true : false,                                  isMatch(s.subString(1), p.subString(1)) : false (3)
	p.length() >= 2, 
	                 p[1] != '*' && s is not empty && (p[0] == s[0] or p[0] == '.') => true : false, isMatch(s.subsring(1), p.substring(1)) : false (4)
	                 // if s[0] is repeated only once or s[0] is repeated many times
					 p[1] == ‘*’ && s is not empty && (p[0] == s[0] or p[0] == '.') => true : false, if (isMatch(s, p.substring(2)))                (5)
																										true
																									 else 
																									    s = s.substring(1)                  
					 // p[0] != s[0] or s is empty p[0] != '.'
	                 p[1] == '*'                                                                     isMatch(s, p.substring(2))                     (6)

					 对于第5个条件：当p的第二个字符是星号时，如果S不空且(p.charAt(0) == s.charAt(0) 或者 p.charAt(0)==‘ . ’)，有两种分支需要分别判断：
					 1. 某字符+星号不要匹配s的首字符：（因为星号之前的字符可出现可不出现，该情况不配是考虑到后面有必须匹配的。假设当前匹配并截去s的首字符，会导致后续匹配错误。）
					 截去p的前两个元素（某字符+星号）并进入下一层递归，假如返回true，则当前递归返回true；假如返回false，进入分支2。

					 2.某字符+星号要匹配s的首字符：截去s首字符并继续条件5的判断。
					 
					 对于第6个条件：当p的第二个字符是星号时，非【S不空且(p.charAt(0) == s.charAt(0) 或者 p.charAt(0)==‘ . ’)】，截去p的前两个元素（某字符+星号）并进入下一层递归。

					 作者：SiyueLin
					 链接：https://www.jianshu.com/p/85f3e5a9fcda
					 來源：简书
					 简书著作权归作者所有，任何形式的转载都请联系作者获得授权并注明出处。
	*/
	bool isMatch_recursive(string s, string p)
	{
		if (p.size() == 0)
		{
			if (s.size() == 0)
				return true;
			else
				return false;
		}

		if (p.size() == 1)
		{
			if (s.size() == 0) return false;
			if (p[0] == s[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		}

		// p.size() >=2的情形 
		if (p[1] != '*')
		{
			if (s.size() == 0) return false;
			if (p[0] == s[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
			else
				return false;
		}
		else
		{
			// s.size() == 0 && d.size() >= 2时，不一定不匹配
			while (s.size() > 0 && (s[0] == p[0] || p[0] == '.'))
			{
				// * 可以看作重复零次到任意多次.所以每进行一次重复，就需要考虑进行下面的匹配
				if (isMatch(s, p.substr(2)))
					return true;
				// 
				s = s.substr(1);
			}


			// 
			return isMatch(s, p.substr(2));
		}
	}

	// from discussion, see a DP solution
	// 1. dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
	// 2. dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;
	// 3. dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 time.

	bool isMatch(string s, string p)
	{
		int m = s.size(), n = p.size();
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (p[j - 1] == '*') {

					dp[i][j] = dp[i][j - 2]     //  
						       || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));   // 匹配至少一次
				}
				else {
					// 
					dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}
		return dp[m][n];
	}
};


int main()
{
	std::vector<string> strs = {"a", "ab", "aa", "aa", "ab", "aab", "mississippi"};
	std::vector<string> patterns = {"ab*", ".*c", "a", "a*", ".*", "c*a*b", "mis*is*p*."};
	Solution sln;
	for (int i = 0; i < strs.size(); i++)
	{
		if (sln.isMatch(strs[i], patterns[i]))
		{
			cout << strs[i] << " and " << patterns[i] << " are matched" << endl;
		}
		else
		{
			cout << strs[i] << " and " << patterns[i] << " are not matched" << endl;
		}
	}
    return 0;
}

