// BubbleSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Bubble Sort " << endl;

	int arr[] = { 10, 50, 21, 2, 6, 66, 802, 75, 24, 170 };
	int size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size -i - 1; j++)
		{
			if (arr[j] > arr[j + 1])  // For ascending >
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
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

