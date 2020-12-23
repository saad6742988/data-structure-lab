#include<iostream>
using namespace std;
void bubbleSort(int*& arr, int n);
void display(int* array, int size);
int main()
{
	int size;
	cout << "enter the size of array = ";
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "enter value no." << i + 1 << " = ";
		cin >> array[i];
	}
	cout << endl << endl;
	cout << "array before sorting = ";
	display(array, size);
	bubbleSort(array, size);
	cout << endl << endl;
	cout << "array after sorting = ";
	display(array, size);
	cout << endl << endl;
}
void bubbleSort(int*& array, int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
}
void display(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != 0)
			cout << " , " << array[i];
		else
			cout << array[i];
	}
}