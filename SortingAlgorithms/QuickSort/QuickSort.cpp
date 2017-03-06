// QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
	int temp, i, j, pivot;
	i = low + 1;
	j = high;

	pivot = arr[low];

	while (i <= j)
	{
		while (arr[i] < pivot && (i < j))
			i++;
		while (arr[j] > pivot)
			j--;

		if (i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
		else
			i++;
	}

	arr[low] = arr[j];
	arr[j] = pivot;
	return j;
}

void QuickSort(int arr[], int low, int high)
{
	int pivot(0);
	if (low >= high)
		return;
	pivot = partition(arr, low, high);
	QuickSort(arr, low, pivot - 1);  // process left list
	QuickSort(arr, pivot + 1, high); // process right list
}

int main()
{
	int n(5);
	int *arr = new int[n];
	cout << "Enter the elements in the array " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	QuickSort(arr, 0, n - 1);

	cout << "The elements of the array are " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

    return 0;
}

