#include<iostream>
using namespace std;
int input(int* &array, int size);
void display(int*, int);
void swap_array(int*&, int*&, int);
int main()
{
	int size = 5,counter_array1, counter_array2;
	int* array1= new int[size], * array2 = new int[size];
	cout << "enter values for first array(enter -1 to exit) : ";
	counter_array1 = input(array1, size);
	cout << "enter values for second array(enter -1 to exit) : ";
	counter_array2 = input(array2, size);
	system("cls");
	cout << "\n\nfirst array : ";
	display(array1, counter_array1);
	cout << "\n\nsecond array : ";
	display(array2, counter_array2);
	swap_array(array1, array2, max(counter_array1, counter_array2));
	swap(counter_array1, counter_array2);
	cout << "\n\n\nboth arrays after swaping : ";
	cout << "\n\nfirst array : ";
	display(array1, counter_array1);
	cout << "\n\nsecond array : ";
	display(array2, counter_array2);
}
int input(int* &array, int size)
{
	int temp, counter = 0;
	while (true)
	{
		cin >> temp;
		if (temp == -1)
		{
			break;
		}
		else
		{
			array[counter++] = temp;
			if (counter == size)
			{
				size *= 2;
				int* temp_array = new int[size];
				for (int i = 0; i < counter; i++)
				{
					temp_array[i] = array[i];
				}
				delete[]array;
				array = temp_array;
			}
		}
	}
	return counter;
	//returning number of elements entered
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
void swap_array(int*& array, int*& array1, int size)
{
	for (int i = 0; i < size; i++)
	{
		swap(array[i], array1[i]);
	}
}