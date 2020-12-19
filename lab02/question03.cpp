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
			}
			else
			{
				node* temp = top;
				top = n;
				top->next = temp;
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
	stack s,s1;
	int x,value;
	cout << "number of values you want to enter in stack = ";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter value no." << i + 1 << " = ";
		cin >> value;
		s.push(value);
	}
	cout << "displaying stack in lifo order : \n";
	s.display();
	//convert stack in fifo order
	cout << "\n\nconverting stack to queue(fifo)........\n\n";
	for (int i = 0; i < x; i++)
	{
		s1.push(s.pop()->data);
	}
	cout << "displaying stack after cinverting to queue(fifo) order : \n";
	s1.display();
}
