// StableHeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StableHeapSort.h"
#include <iostream>
using namespace std;

int main()
{
	std::vector<int> ary = {10, 1, 9, 1, 8, 1, 4, 1, 5, 1};
	StableHeapSort stHelpSort;
	stHelpSort.Sort(ary);
	for (int index = 0; index < ary.size(); index++)
	{
		cout << ary[index] << " ";
	}
	cout << endl;
	for (int index = 0; index < ary.size(); index++)
	{
		cout << (*stHelpSort.m_timestampAry)[index+1] << " ";
	}

	char exit;
	cin >> exit;
    return 0;
}

