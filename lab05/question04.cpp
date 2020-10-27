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
	//i tried a lot but logic is not working properly
	void sort()
	{
		node* temp = NULL,*temp1=NULL;
		bool sorting = true;
		while (sorting)
		{
			temp = head;
			sorting = false;
			while (temp->next != NULL)
			{
				temp1 = temp->next;
				if (temp->data > temp1->data)
				{
					swap(temp,temp1);
					swap(temp->next, temp1->next);
					swap(temp->pre, temp1->pre);
					swap(temp->next, temp1->pre);
					if(temp1->next!=NULL&&temp->pre!=NULL)
					swap(temp1->next->pre, temp->pre->next);
					else if (temp1->next == NULL)
					{
						temp->pre->next = temp;
					}
					else if (temp->pre == NULL)
					{
						temp1->next->pre = temp1;
					}
					sorting = true;
				}
				temp = temp->next;
			}
		}
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
	cout << endl << endl<<"your list before sorting : ";
	l.display();
	cout << endl << endl << "your list after sorting : ";
	l.sort();
	l.display();
	cout << endl << endl;

}