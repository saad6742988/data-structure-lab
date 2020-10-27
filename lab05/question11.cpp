#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node* pre;
	node(int d = 0)
	{
		data = d;
		next = NULL;
		pre = NULL;
	}
};
class linkedList
{
	node* head;
	bool isEmpty()
	{
		if (head == NULL)
			return true;
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
				head->next = head;
				head->pre = head;
			}
			else
			{
				node* temp = head;
				while (temp->next != head)
				{
					temp = temp->next;
				}
				n->next = temp->next;
				n->pre = temp;
				temp->next = n;
				n->next->pre = n;
			}
		}
	}
	void insertAtStart(int value)
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
				head->next = head;
				head->pre = head;
			}
			else
			{
				n->next = head;
				n->pre = head->pre;
				head->pre = n;
				n->pre->next = n;
				head = n;
			}
		}
	}
	void insertAfter_ByValue(int value, int after)
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
				cout << "\nlist is empty\n";
			}
			else
			{
				node* temp = head;
				bool exist = true;
				while (temp->data != after)
				{
					temp = temp->next;
					if (temp == head)
					{
						exist = false;
						break;
					}

				}
				if (exist == true)
				{
					n->next = temp->next;
					n->pre = temp;
					temp->next = n;
					n->next->pre = n;
				}
				else
					cout << "\nvalue not exist\n";
			}
		}
	}
	void insertAfter_Byindex(int value, int index)
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
				cout << "\nlist is empty\n";
			}
			else
			{
				node* temp = head;
				for (int i = 1; i < index; i++)
				{
					temp = temp->next;
				}
				n->next = temp->next;
				n->pre = temp;
				temp->next = n;
				n->next->pre = n;
			}
		}
	}
	void display()
	{
		node* temp = head;
		do
		{
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
		cout << endl << endl;
	}
	int count()
	{
		node* temp = head;
		int c = 0;
		do
		{
			c++;
			temp = temp->next;
		} while (temp != head);
		return c;
	}
	void deleteByValue(int value)
	{
		if (isEmpty())
		{
			cout << "\nlist is empty\n";
		}
		else
		{
			node* temp = head;
			bool exist = true;
			while (temp->data != value)
			{
				temp = temp->next;
				if (temp == head)
				{
					exist = false;
					break;
				}

			}
			if (exist == true)
			{
				temp->pre->next = temp->next;
				temp->next->pre = temp->pre;
				if (temp == head)
				{
					head = head->next;
				}
			}
			else
				cout << "\nvalue not exist\n";
		}
	}
	void deleteByIndex(int index)
	{
		if (isEmpty())
		{
			cout << "\nlist is empty\n";
		}
		else
		{
			node* temp = head;
			for (int i = 1; i < index; i++)
			{
				temp = temp->next;
			}
			temp->pre->next = temp->next;
			temp->next->pre = temp->pre;
			if (temp == head)
			{
				head = head->next;
			}
		}
	}
};
int main()
{
	linkedList l;
	int value, opt, index;
	do
	{
		cout << "press 1 to insert at end\npress 2 to insertr at head\npress 3 to insert after index\npress 4 to insert after value\n"
			"press 5 to delete by value\npress 6 to delete by index\npress 7 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "enter value to be inserted = ";
			cin >> value;
			l.insert(value);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 2:
			cout << "enter value to be inserted at head = ";
			cin >> value;
			l.insertAtStart(value);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "enter index after which you want to insert = ";
			cin >> index;
			cout << "enter value to be inserted = ";
			cin >> value;
			l.insertAfter_Byindex(value,index);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 4:
			cout << "enter value after which you want to insert = ";
			cin >> index;
			cout << "enter value to be inserted = ";
			cin >> value;
			l.insertAfter_ByValue(value, index);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "enter value which you want to delete = ";
			cin >> value;
			l.deleteByValue(value);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 6:
			cout << "enter index which you want to delete = ";
			cin >> value;
			l.deleteByIndex(value);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 7:
			break;
		default:
			cout << "invalid input!!!!\n";
		}

	} while (opt != 7);
}