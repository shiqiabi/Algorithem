// BigNumMultiply.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution
{
public:
	string bigNumberMultiply(string numberA, string numberB)
	{
		bool isNegative = false;
		if (numberA[0] == '-' && numberB[0] == '-')
		{
			numberA = numberA.substr(1);
			numberB = numberB.substr(1);
		}
		else if ((numberA[0] == '-' && numberB[0] != '-') ||
			     (numberA[0] != '-' && numberB[0] == '-'))
		{
			isNegative = true;
			if (numberA[0] == '-') numberA = numberA.substr(1);
			if (numberB[0] == '-') numberB = numberB.substr(1);
		}
		// 如果两数之和长度小于10，则直接相乘。
		if (numberA.length() + numberB.length() < 10)
		{
			int numA = std::atoi(numberA.c_str());
			int numB = std::atoi(numberB.c_str());
			int ret = numA * numB;
			stringstream ss;
			if (isNegative) ss << "-";
			ss << ret;
			return ss.str();
		}

		// 公式AC*10^n + ((A-B)(D-C)+AC+BD)*10^(n/2)+BD
		string a, b, c, d;
		if (numberA.length() == 1)
		{
			a = "0";
			b = numberA;
		}
		else
		{
			if (numberA.length() % 2 != 0)
			{
				numberA = "0" + numberA;
			}
			a = numberA.substr(0, numberA.length() / 2);
			b = numberA.substr(numberA.length() / 2);
		}

		if (numberB.length() == 1)
		{
			c = "0";
			d = numberB;
		}
		else
		{
			if (numberB.length() % 2 != 0)
			{
				numberB = "0" + numberB;
			}
			c = numberB.substr(0, numberB.length() / 2);
			d = numberB.substr(numberB.length() / 2);
		}

		// 按最大位数取值，已确定补零
		int n = numberA.length() > numberB.length() ? numberA.length() : numberB.length();
		string t1, t2, t3;
		string ac = bigNumberMultiply(a, c);
		string bd = bigNumberMultiply(b, d);

		t1 = bigNumberMultiply(bigNumberSubstract(a, c), bigNumberSubstract(b, d));
		t2 = bigNumberSum(bigNumberSum(t1, ac), bd);
		t3 = bigNumberSum(bigNumberSum(pow10(ac, n), pow10(t2, n / 2)), bd);
		stringstream ss;
		if (isNegative) ss << "-";
		ss << t3;
		return ss.str();
	}
};
int main()
{
    return 0;
}

