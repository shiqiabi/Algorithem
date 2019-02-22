// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MergeSort.h"
#include <iostream>
using namespace std;

int main()
{
	vector<int> ary = {19, 57, 0, 46, 90, 23, 18, 89, 78, 34, 119, 66};
	MergeSort mergeSort;
	mergeSort.Sort(ary);

	for each (int var in ary)
	{
		cout << var << " ";
	}
	cout << endl;

	char exit;
	cin >> exit;
    return 0;
}

