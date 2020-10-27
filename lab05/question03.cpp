#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* pre;
	node* next;
	node(int d = 0)
	{
		data = d;
		pre = NULL;
		next = NULL;
	}
};
class linkedList
{
	node* head;
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		try
		{
			node* temp = new node();
			delete temp;
			return false;
		}
		catch (bad_alloc memory)
		{
			return true;
		}
	}
	bool checkPrime(int value)
	{
		int count = 0, div = 1;
		while (div <= value / 2)
		{
			if (value % div == 0)
			{
				count++;
			}
			div++;
		}
		if (count == 1)
			return true;
		return false;
	}
public:
	linkedList()
	{
		head = NULL;
	}
	//the are is no specifications for insert function in question
	//so i am inserting at end;
	void insert(int value)
	{
		if (isFull())
		{
			cout << "\nmemory is full\n";
		}
		else
		{
			node* n = new node(value);
			if (isEmpty())
			{
				head = n;
			}
			else
			{
				node* temp = head;
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = n;
				n->pre = temp;
			}
		}
	}
	void display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	int productOfPrimeNodes()
	{
		int product = 1;
		node* temp = head;
		while (temp != NULL)
		{
			if (checkPrime(temp->data))
			{
				product *= temp->data;
			}
			temp = temp->next;
		}
		return product;
	}
};
int main()
{
	linkedList l;
	cout << "numbers you want to input = ";
	int x, value;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter number no." << i + 1 << " = ";
		cin >> value;
		l.insert(value);
	}
	cout << "your list : ";
	l.display();
	cout << "\nproduct of prime nodes = " << l.productOfPrimeNodes() << endl;
}
