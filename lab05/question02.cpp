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
	void _delete(node* n)
	{
		node* temp = head;
		while (temp != n)
		{
			temp = temp->next;
		}
		if (temp == head)
		{
			head = head->next;
			head->pre = NULL;
		}
		else if (temp->next == NULL)
		{
			temp->pre->next = NULL;
		}
		else
		{
			temp->pre->next = temp->next;
			temp->next->pre = temp->pre;
		}
	}
	void deleteDuplicate()
	{
		node* temp = head;
		node* duplicate;
		while (temp != NULL)
		{
			duplicate = temp->next;
			while (duplicate != NULL)
			{
				if (duplicate != NULL && temp->data == duplicate->data)
					_delete(duplicate);
				duplicate = duplicate->next;
			}
			temp = temp->next;
		}
	}
};
int main()
{
	linkedList l;
	int x, value; cout << "values you want to enter = "; cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter value no." << i + 1 << " = ";
		cin >> value;
		l.insert(value);
	}
	system("cls");
	cout << "list you entered : ";
	l.display();
	cout << endl;
	cout << "\nlist after deleting duplicates : ";
	l.deleteDuplicate();
	l.display();
	cout << endl;
}