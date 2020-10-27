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
	void deleteAt(int index)
	{
		if (index <= count())
		{
			node* temp = head;
			for (int i = 1; i < index; i++)
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
		else {
			cout << "\nindex exceeded the list length\n";
		}
	}
	//this function will the node after the passed value
	//as the funtion name in question is deleteAfter
	//so i am not deleting the exact passed value
	void deleteAfterValue(int value)
	{
		node* temp = head;
		while (temp->data != value)
		{
			temp = temp->next;
		}
		temp = temp->next; //to delete the next next value
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
};
int main()
{
	linkedList l;
	int value, opt, temp;
	do
	{
		cout << "press 1 to insert\npress 2 to delete at index\npress 3 to delete after value\npress 4 to exit\n";
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
			cout << "enter index to be deleted = ";
			cin >> value;
			l.deleteAt(value);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "enter value after which you want to delete = ";
			cin >> value;
			l.deleteAfterValue(value);
			cout << endl << endl << "your list is:";
			l.display();
			cout << endl;
			system("pause");
			break;
		case 4:
			break;
		default:
			cout << "invalid input!!!!\n";
		}

	} while (opt != 4);
}