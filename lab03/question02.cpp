#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d = 0)
	{
		data = d;
		next = NULL;
	}
};
class queue
{
	node *front, * rare;
public:
	queue()
	{
		front = rare = NULL;
	}
	void enqueue(int x)
	{
		if (isFull())
		{
			cout << "\nmemory is full\n";
		}
		else {
			node* n = new node(x);
			if (isEmpty())
			{
				front = rare = n;
				cout << "\nenqueued";
			}
			else
			{
				rare->next = n;
				rare = n;
				cout << "\nenqueued";
			}
		}
	}
	//dequeue function
	node* dequeue()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = front;
			front = front->next;
			if (front == NULL)
			{
				rare = NULL;
			}
			return temp;
		}
	}
	//check empty
	bool isEmpty()
	{
		if (front == NULL && rare == NULL)
		{
			return true;
		}
		return false;
	}
	bool isFull()
	{
		node* temp;
		try {
			temp = new node;
			delete temp;
			return false;
		}
		catch (bad_alloc exception)
		{
			return true;
		}
	}
};
int main()
{
	queue s;
	node* n;
	int opt, x;
	do {
		cout << "press 1 to enqueue\npress 2 to dequeue \n"
			"press 3 to check queue is empty or not\n"
			"press 4 to check queue is full or not\npress 5 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "\nenter number to enqueue by value = ";
			cin >> x;
			s.enqueue(x);
			cout << endl << endl;
			break;
		case 2:
			n = s.dequeue();
			if (n == NULL)
			{
				cout << "\nqueue is empty";
			}
			else
				cout << endl << n->data << " is dequeued\n";
			cout << endl << "*****************************" << endl;
			break;
		case 3:
			if (s.isEmpty())
			{
				cout << "\nqueue is empty\n";
			}
			else
				cout << "\nqueue is not empty\n";
			cout << endl << "*****************************" << endl;
			break;
		case 4:
			if (s.isFull())
			{
				cout << "\nqueue is full\n";
			}
			else
				cout << "\nqueue is not full\n";
			cout << endl << "*****************************" << endl;
			break;
		case 5:
			break;
		default:
			cout << "\ninvalid choice\n";
		}

	} while (opt != 5);
}