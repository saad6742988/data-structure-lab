#include<iostream>
using namespace std;
class Stack
{
	int top;
	int* stack;
	int size;
public:
	Stack(int s)
	{
		size = s;
		stack = new int[size];
		top = -1;
	}
	bool isFull()
	{
		if (top == size - 1)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}
	void push(int value)
	{
		if (isFull())
		{
			cout << "stack is full\n";
			return;
		}
		stack[++top] = value;
		cout << value << " is pushed in stack\n";
	}
	int pop()
	{
		if (isEmpty())
		{
			return INT_MIN;
		}
		return stack[top--];
	}
	int get_top()
	{
		if (isEmpty())
		{
			return INT_MIN;
		}
		return stack[top];
	}
};
int main()
{
	int value,opt;
	cout << "enter the size of stack = ";
	cin >> value;
	Stack s(value);
	do
	{
		cout << "press 1 to push value\npress 2 to pop value\npress 3 to check top\n"
			"press 4 to check stack is empty or not\npress 5 to check stack is full or not\n"
			"press 6 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "enter value to push = ";
			cin >> value;
			s.push(value);
			cout << "*******************************\n\n";
			break;
		case 2:
			value = s.pop();
			if (value == INT_MIN)
			{
				cout << "stack is empty\n";
			}
			else
				cout << value << " is popped from the stack\n";
			cout << "*******************************\n\n";
			break;
		case 3:
			value = s.get_top();
			if (value == INT_MIN)
			{
				cout << "stack is empty\n";
			}
			else
				cout << value << " is at top of stack\n";
			cout << "*******************************\n\n";
			break;
		case 4:
			if (s.isEmpty())
			{
				cout << "stack is empty\n";
			}
			else
				cout << "stack is not empty\n";
			cout << "*******************************\n\n";
			break;
		case 5:
			if (s.isFull())
			{
				cout << "stack is full\n";
			}
			else
				cout << "stack is not full\n";
			cout << "*******************************\n\n";
			break;
		case 6:
			break;
		default:
			cout << "invalid input!!!\n";
		}
	} while (opt != 6);
}