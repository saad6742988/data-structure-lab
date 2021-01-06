#include<iostream> 
using namespace std;
class node
{
public:
	int value;
	node(int v)
	{
		value = v;
	}
};
class hashmap
{ 
	node** array;
	int capacity;
	node* dummy;

public:
	hashmap(int s=5)
	{ 
		capacity = s;
		array = new node*[capacity]; 
		for (int i = 0; i < capacity; i++)
			array[i] = NULL;
		dummy = new node(INT_MIN);
	}
	int hashing(int key)
	{
		return key % capacity;
	}
	void insert(int value)
	{
		node* temp = new node(value);
		int hashIndex = hashing(value);
		while (array[hashIndex] != NULL && array[hashIndex]->value != INT_MIN)
		{
			hashIndex++;
			hashIndex %= capacity;
		}
		array[hashIndex] = temp;
	}
	int delete_(int value)
	{
		int hashIndex = hashing(value);
		while (array[hashIndex] != NULL)
		{
			//if node found 
			if (array[hashIndex]->value == value)
			{
				node* temp = array[hashIndex]; 
				array[hashIndex] = dummy;
				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}
		//If not found 
		return INT_MIN;
	}
	//Function to search the value
	int search(int value)
	{
		int hashIndex = hashing(value);
		int counter = 0;
		while (array[hashIndex] != NULL)
		{
			int counter = 0;
			if (counter++ > capacity) 
				return NULL;
			if (array[hashIndex]->value ==value)
				return array[hashIndex]->value;
			hashIndex++;
			hashIndex %= capacity;
		}
		//if not found
		return INT_MIN;
	}
};
int main()
{
	int size, value;
	cout << "size of hash map = ";
	cin >> size;
	hashmap h(size);
	cout << "\nvalues you want to enter = ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "enter value no." << i + 1 << " = ";
		cin >> value;
		h.insert(value);
	}
	cout << "enter value to search = ";
	cin >> value;
	value = h.search(value);
	if (value == INT_MIN)
	{
		cout << "\nvalue not found in map\n";
	}
	else
		cout << endl << value << " is found\n";
	cout << "enter value to delete = ";
	cin >> value;
	value = h.delete_(value);
	if (value == INT_MIN)
	{
		cout << "\nvalue not found in map\n";
	}
	else
		cout << endl << value << " is deleted\n";
	cout << "enter value to search = ";
	cin >> value;
	value = h.search(value);
	if (value == INT_MIN)
	{
		cout << "\nvalue not found in map\n";
	}
	else
		cout << endl << value << " is found\n";

}
