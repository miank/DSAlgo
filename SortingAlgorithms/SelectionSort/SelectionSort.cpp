// SelectionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort(int arr[], int n)
{
	int i, j, min(0);
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		swap(&arr[min], &arr[i]);
	}
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int arr[] = { 65, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(int);
	SelectionSort(arr, n);
	cout << "Sorted Array is " << endl;
	printArray(arr, n);
    return 0;
}

