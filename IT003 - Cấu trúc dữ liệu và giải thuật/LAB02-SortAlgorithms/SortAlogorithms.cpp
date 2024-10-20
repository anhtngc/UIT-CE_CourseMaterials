#include <iostream>
#include <algorithm>

using namespace std;

void GetArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> arr[i];
	}
}

void PrintArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "  ";
	}
}

void SelectionSort(int arr[], int n)
{
	int min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
				swap(arr[min], arr[i]);
			}
		}
	}
}

void InsertSort(int arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = arr[i];
		int position = i - 1;
		while ((position >= 0) && (arr[position] > x))
		{
			arr[position + 1] = arr[position];
			position--;
		}
		arr[position + 1] = x;
	}
}

void QuickSort(int arr[], int left, int right)
{
	int x = arr[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while (arr[i] < x)
			i++;
		while (arr[j] > x)
			j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j)
		QuickSort(arr, left, j);
	if (i < right)
		QuickSort(arr, i, right);
}

void MergeSort(int arr[], int n)
{

}

void CountingSort(int input[], int n)
{
	int output[n];
	int max = input[0];
	int min = input[0];
	for (int i = 1; i < n; i++)
	{
		if (input[i] > max)
			max = input[i];
		else if (input[i] < min)
			min = input[i];
	}
	int k = max - min + 1;
	int countArray[k];
	for (int i = 0; i < k; i++)
		countArray[i] = 0;
	for (int i = 0; i < n; i++)
		countArray[input[i] - min]++;
	for (int i = 1; i < k; i++)
		countArray[i] += countArray[i - 1];
	for (int i = 0; i < n; i++)
	{
		output[countArray[input[i] - min] - 1] = input[i];
		countArray[input[i] - min]--;
	}
	for (int i = 0; i < n; i++)
		input[i] = output[i];
}

//Similar to Counting Sort algorithm
void RadixSort(int input[], int n)
{
	int output[n];
	int max = input[0];
	for (int i = 1; i < n; i++)
	{
		if (input[i] > max)
			max = input[i];
	}
	int exp = 1;
	while (max / exp > 0)
	{
		int countArray[10] = { 0 };
		for (int i = 0; i < n; i++)
			countArray[(input[i] / exp) % 10]++;
		for (int i = 1; i < 10; i++)
			countArray[i] += countArray[i - 1];
		for (int i = n - 1; i >= 0; i--)
		{
			output[countArray[(input[i] / exp) % 10] - 1] = input[i];
			countArray[(input[i] / exp) % 10]--;
		}
		for (int i = 0; i < n; i++)
			input[i] = output[i];
		exp *= 10;
	}
}

//Heap Sort algorithm
void Heapify(int* arr[], int k, int n)
{
	int j = 2 * k + 1;
	while (j < n)
	{
		if (j + 1 < n)
		{
			if (arr[j] < arr[j + 1])
				j = j + 1;
		}
		if (arr[k] >= arr[j])
			return;
		swap(arr[k], arr[j]);
		k = j; j = 2 * k + 1;
	}
}

void buildHeap(int *arr[], int n)
{
	int i;
	i = n / 2 - 1;
	while (i >= 0)
	{
		Heapify(arr, i, n);
		i--;
	}
}

void HeapSort(int* arr[], int n)
{
	buildHeap(arr, n);
	while (n > 0)
	{
		n = n - 1;
		swap(arr[0], arr[n]);
		Heapify(arr, 0, n);
	}
}
//End Heap Sort algorithm

void InterchangeSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[i])		//thỏa 1 cặp nghịch thế
				swap(arr[i], arr[j]);
	}
}

void BubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n; j--)
			if (arr[j] < arr[j - 1])	//nếu sai vị trí thì đổi chỗ
				swap(arr[j], arr[j - 1]);
	}
}