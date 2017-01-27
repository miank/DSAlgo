// BinarySrch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int ele)
{
	int low = 0, high = n - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (ele == arr[mid])
			return mid;
		else if (ele < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
	cout << "Enter a number " << endl;
	int num(0);
	cin >> num;
	int index = BinarySearch(arr, 10, num);
	if (index == -1)
		cout << "Element not found" << endl;
	else
		cout << "Element found " << num << " at position " << index << endl;
    return 0;
}

