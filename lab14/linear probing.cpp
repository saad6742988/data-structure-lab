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
	int capacity,size;
	node* dummy;

public:
	hashmap(int s = 5)
	{
		capacity = s;
		size = 0;
		array = new node * [capacity];
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
		if (size < capacity)
		{
			node* temp = new node(value);
			int hashIndex = hashing(value);
			while (array[hashIndex] != NULL && array[hashIndex]->value != INT_MIN)
			{
				hashIndex++;
				hashIndex %= capacity;
			}
			size++;
			array[hashIndex] = temp;
		}
		else
			cout << "bucket is full\n";
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
				size--;
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
			if (array[hashIndex]->value == value)
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
	do
	{
		cout << "press 1 to enter add value \npress 2 to search value\npress 3 to delete value\npress 4 to exit\n";
		cin >> size;
		cin.ignore();
		switch (size)
		{
		case 1:
			cout << "enter value = ";
			cin >> value;
			h.insert(value);
			system("pause");
			break;
		case 2:
			cout << "enter value = ";
			cin >> value;
			if (h.search(value) == INT_MIN)
			{
				cout << "value not found\n";
			}
			else
				cout << h.search(value) << " is found\n";
			system("pause");
			break;
		case 3:
			cout << "enter value = ";
			cin >> value;
			value = h.delete_(value);
			if ( value== INT_MIN)
			{
				cout << "value not found\n";
			}
			else
				cout << value << " is deleted\n";
			system("pause");
			break;
		case 4:
			break;
		default:
			cout << "invalid input!!!\ntry again = ";

		}
	} while (size != 4);

	
}
