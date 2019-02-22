// BigNumSubstract.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
大整数减法.下面的算法考虑的是两个任意大小的正整数相减的情况。
该算法的一个核心点就是始终让大数去减小数。
该算法的另外一个核心点就是逐位相减。
*/

class Solution
{
public:
	string bigNumberSubstract(string numberA, string numberB)
	{
		int compareResult = compare(numberA, numberB);
		if (compareResult == 0)
			return "0";
		bool isNegative = false;
		if (compareResult == -1)
		{
			string  temp = numberA;
			numberA = numberB;
			numberB = temp;
			isNegative = true;
		}
		// 把两个大数用数组逆序存储，数组长度等于较大整数位数+1
		int maxLength = int(numberA.length() > numberB.length() ? numberA.length() : numberB.length());
		int *aryA = new int[maxLength + 1]{0};
		for (int i = 0; i < numberA.length(); i++)
		{
			aryA[i] = numberA[numberA.length() - i - 1] - 0x30;
		}
		int *aryB = new int[maxLength + 1]{0};
		for (int i = 0; i < numberB.length(); i++)
		{
			aryB[i] = numberB[numberB.length() - i - 1] - 0x30;
		}
		// 构建result数组
		int *result = new int[maxLength + 1]{0};
		// 遍历数组，按位相加
		for (int i = 0; i < maxLength + 1; i++)
		{
			int temp = result[i];
			temp += aryA[i];
			temp -= aryB[i];
			if (temp < 0)
			{
				temp += 10;
				result[i + 1] = -1;
			}
			result[i] = temp;
		}
		// 把result数组再次逆序
		string ret;
		bool findfirst = false;
		for (int i = maxLength; i >= 0; i--)
		{
			if (!findfirst) {
				if (result[i] == 0)
				{
					continue;
				}
				findfirst = true;
			}
			ret.push_back(result[i] + 0x30);
		}
		//
		delete[] aryA;
		delete[] aryB;
		delete[] result;

		if (isNegative)
			return "-" + ret;
		else
			return ret;
	}

private:
	int compare(string x, string y)
	{
		if (x.size() > y.size())
		{
			return 1;
		}
		else if (x.length() < y.length())
		{
			return -1;
		}
		else {
			for (int i = 0; i < x.length(); i++)
			{
				if (x[i] > y[i])
				{
					return 1;
				}
				else if (x[i] < y[i])
				{
					return -1;
				}
			}
			return 0;
		}
	}
};
int main()
{
	std::vector<string>strs = { "99", "100", "10", "100", "39", "23"};
	Solution sln;
	for (int index = 0; index < (int)strs.size(); index += 2)
	{
		string ret = sln.bigNumberSubstract(strs[index], strs[index + 1]);
		cout << ret.c_str() << endl;
	}
    return 0;
}

