// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int size(0), flag = 0;
	cout << "Bubble Sort " << endl;
	cout << "Enter the size " << endl;
	cin >> size;
	int *arr = new int[size];

	cout << "The elements before sorting the array are " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		flag = 0;
		for (int j = 0; j < size - 2; j++)
		{
			if (arr[j] < arr[j + 1])  // For ascending >
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}	
	}
	cout << "The elements after sorting the array are " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
    return 0;
}

