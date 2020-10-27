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
public:
	linkedList()
	{
		head = NULL;
	}
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
	void merge(linkedList l)
	{
		node* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = l.head;
		l.head->pre = temp;
	}
};
int main()
{
	linkedList l,l1;
	cout << "numbers you want to input in list 1 = ";
	int x, value;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter number no." << i + 1 << " = ";
		cin >> value;
		l.insert(value);
	}
	cout << "numbers you want to input in list 2= ";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter number no." << i + 1 << " = ";
		cin >> value;
		l1.insert(value);
	}
	cout << "\n\nyour list1 : ";
	l.display();
	cout << "\n\nyour list2 : ";
	l1.display();
	cout << "\n\nafter merging lint 2 in list 1 : ";
	l.merge(l1);
	l.display();
}
