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
	void reverse()
	{
		do
		{
			swap(head->next, head->pre);
			if (head->pre != NULL)
				head = head->pre;
		} while (head->pre != NULL);
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
	cout << "\n\nyour list is : ";
	l.display();
	l.reverse();
	cout << "\nreversed list is : ";
	l.display();
}