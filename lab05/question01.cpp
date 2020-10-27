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
public:
	linkedList()
	{
		head = NULL;
	}
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
	//there is no specifications for delete function in question
	//so i am deleting from end;
	void _delete()
	{
		if (!isEmpty())
		{
			node* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			if (temp == head)
			{
				head = NULL;
			}
			else
			{
				temp->pre->next = NULL;
			}
		}
		else
			cout << "\nyour list is already empty\n";

	}
};
int main()
{
	linkedList l;
	int value, opt;
	do
	{
		cout << "press 1 to insert\npress 2 to delete\npress 3 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "enter value to insert = ";
			cin >> value;
			l.insert(value);
			cout << "your list is : ";
			l.display();
			cout << endl;
			system("pause");
			cout << "\n*************************\n\n";
			break;
		case 2:
			l._delete();
			cout << "your list is : ";
			l.display();
			cout << endl;
			system("pause");
			cout << "\n*************************\n\n";
			break;
		case 3:
			break;
		default:
			cout << "\ninvalid input!!!!\n\n";
		}
		
	} while (opt != 3);
}