// LinearSrch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

bool LinearSearch(int arr[], int n, int ele)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == ele)
			return true;
	}
	return false;
}

int main()
{
	int n(0), data(0);
	bool result;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "Enter the element to search in the array " << endl;
	cin >> data;
	result = LinearSearch(arr, n, data);
	if (result == true)
		cout << "Element found " << endl;
	else
		cout << "Element not found " << endl;
    return 0;
}

