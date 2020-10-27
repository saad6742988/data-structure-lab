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
	int count()
	{
		node* temp = head;
		int c = 0;
		while (temp != NULL)
		{
			temp = temp->next;
			c++;
		}
		return c;
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
	void insertAfterValue(node *n, int pre_value)
	{
		if (isFull())
		{
			cout << "\nmemory is full\n";
		}
		else {
			if (isEmpty())
			{
				// if empty then insert at satrt by default
				head = n;
			}
			else {
				node* temp = head;
				bool found = false;
				if (head->data == pre_value)
				{
					found = true;
				}
				while ((temp != NULL))
				{
					if (temp != NULL) {
						if (temp->data == pre_value)
						{
							found = true;
							break;
						}
						temp = temp->next;
					}
				}
				if (found)
				{
					if (temp->next == NULL)
					{
						temp->next = n;
						n->pre = temp;
					}
					else {
						n->pre = temp;
						n->next = temp->next;
						temp->next->pre = n;
						temp->next = n;
					}
				}
			}
		}
	}
	void insertbeforeValue(node* n, int pre_value)
	{
		if (isFull())
		{
			cout << "\nmemory is full\n";
		}
		else {
			if (isEmpty())
			{
				// if empty then insert at satrt by default
				head = n;
			}
			else {
				node* temp = head;
				bool found = false;
				if (head->data == pre_value)
				{
					found = true;
				}
				while ((temp != NULL))
				{
					if (temp != NULL) {
						if (temp->data == pre_value)
						{
							found = true;
							break;
						}
						temp = temp->next;
					}
				}
				temp = temp->pre;
				if (found)
				{
					if (temp->next == NULL)
					{
						temp->next = n;
						n->pre = temp;
					}
					else {
						n->pre = temp;
						n->next = temp->next;
						temp->next->pre = n;
						temp->next = n;
					}
				}
			}
		}
	}
	void sortConsective()
	{
		node* temp = head;
		node* consective = NULL;
		while (temp != NULL)
		{
			consective = temp->next;
			while (consective != NULL)
			{
				if (consective != NULL && temp->data == consective->data - 1)
				{
					_delete(consective);
					insertAfterValue(consective, temp->data);
				}
				consective = consective->next;
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
	cout << "\n\nlist you entered : ";
	l.display();
	cout << endl;
	cout << "\nlist after sorting consectives : ";
	l.sortConsective();
	l.display();
	cout << endl;
}