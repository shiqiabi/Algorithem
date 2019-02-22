// 17_LetterCombinationsOfPhonNumber.cpp : Defines the entry point for the console application.
//

/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	// 这是一道组合排列的问题
	vector<string> letterCombinations(string digits) {
		std::map<int, std::string> d2s_map = {
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};

		m_results.clear();

		string result(digits.size(), 'x');
		std::vector<string> strary;
		for (size_t i = 0; i < digits.size(); i++)
		{
			strary.push_back(d2s_map[digits[i]]);
		}

		stringCombination(strary, 0, result);

		return m_results;
	}

private: 
	void stringCombination(vector<string> &sources, int start, string &result)
	{
		for (size_t index = 0; index < sources[start].size(); index++)
		{
			result[start] = (sources[start][index]);
			if (start == sources.size() - 1)
			{
				m_results.push_back(result);
			}
			else
			{
				stringCombination(sources, start + 1, result);
			}
		}
	}

private:
	std::vector<std::string> m_results;
};

int main()
{
	Solution sln;

	std::vector<std::string> combinations = sln.letterCombinations("23");
	for each (string var in combinations)
	{
		cout << var.c_str() << " ";
	}
	cout << endl;

	combinations = sln.letterCombinations("3");
	for each (string var in combinations)
	{
		cout << var.c_str() << " ";
	}
	cout << endl;
    return 0;
}

