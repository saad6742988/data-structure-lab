#include<iostream>
using namespace std;
int main()
{
	int size,largest = INT_MIN,smallest=INT_MAX;
	cout << "enter the size of array = ";
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "enter value no." << i + 1 << " = ";
		cin >> array[i];
	}
	for (int i = 0; i < size; i++)
	{
		largest = max(largest, array[i]);
	}
	for (int i = 0; i < size; i++)
	{
		smallest = min(smallest, array[i]);
	}
	cout << endl;
	cout << "largest element = " << largest << endl;
	cout << "smallest element = " << smallest << endl;
}