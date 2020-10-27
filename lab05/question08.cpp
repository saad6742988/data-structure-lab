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
	void insertAt(int value, int index)
	{
		if (isFull())
		{
			cout << "\nmemory is full\n";
		}
		else {
			node* n = new node(value);
			if (isEmpty())
			{
				// if empty then insert at satrt by default
				head = n;
			}
			else {
				if (index == 1)
				{
					head->pre = n;
					n->next = head;
					head = n;
				}
				else if (index <= count())
				{
					node* temp = head;
					for (int i = 1; i < index - 1; i++)
					{
						temp = temp->next;
					}
					n->pre = temp;
					n->next = temp->next;
					temp->next->pre = n;
					temp->next = n;
				}
				else
				{
					//if index is greater than the length of list then value will
					//be inserted at end;
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
	}
	void insertAfterValue(int value, int pre_value)
	{
		if (isFull())
		{
			cout << "\nmemory is full\n";
		}
		else {
			node* n = new node(value);
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
				else
				{
					cout<<endl<<pre_value << " not found in list\n";
				}
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
};
int main()
{
	linkedList l;
	int value, opt,temp;
	do
	{
		cout << "press 1 to insert at index\npress 2 to insert after value\npress 3 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "enter index at which value will inserted = ";
			cin >> temp;
			cout << "enter value to be inserted = ";
			cin >> value;
			l.insertAt(value, temp);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 2:
			cout << "enter value after which value will inserted = ";
			cin >> temp;
			cout << "enter value to be inserted = ";
			cin >> value;
			l.insertAfterValue(value, temp);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "invalid input!!!!\n";
		}

	} while (opt != 3);
}