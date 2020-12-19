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
class stack
{
	node* top;
public:
	stack()
	{
		top = NULL;
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
	void push(int x)
	{
		if (isFull())
		{
			cout << "stack is full\n";
		}
		else {
			node* n = new node(x);
			if (isEmpty())
			{
				top = n;
				cout << x << " is pushed\n";
			}
			else
			{
				node* temp = top;
				top = n;
				top->next = temp;
				cout << x << " is pushed\n";
			}
		}
	}
	//pop function
	node* pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = top;
			top = top->next;
			return temp;
		}
	}
	//check empty
	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}
	void display()
	{
		node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	node* get_top()
	{
		return top;
	}
};
int main()
{
	stack s;
	node* n;
	int opt, x;
	do {
		cout << "press 1 to push\npress 2 to pop\npress 3 to get top of stack\n"
			<< "press 4 to display all elements\npress 5 to check stack is empty or not\n"
			"press 6 to check stack is full or not\npress 7 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "\nenter number to push = ";
			cin >> x;
			s.push(x);
			cout <<"***********************\n\n";
			break;
		case 2:
			n = s.pop();
			if (n == NULL)
			{
				cout << "stack is empty\n";
			}
			else
				cout << n->data << " is popped\n";
			cout << "***********************\n\n";
			break;
		case 3:
			n = s.get_top();
			if (n == NULL)
			{
				cout << "stack is empty\n";
			}
			else
				cout << n->data << " is at top of stack\n";
			cout << "***********************\n\n";
			break;
		case 4:
			cout << "stack: ";
			s.display();
			cout << endl << "*****************************" << endl;
			break;
		case 5:
			if (s.isEmpty())
			{
				cout << "stack is empty\n";
			}
			else
				cout << "stack is not empty\n";
			cout << "***********************\n\n";
			break;
		case 6:
			if (s.isFull())
			{
				cout << "stack is full\n";
			}
			else
				cout << "stack is not full\n";
			cout << "***********************\n\n";
			break;
		case 7:
			break;
		default:
			cout << "invalid choice!!\n";
		}

	} while (opt != 7);

}