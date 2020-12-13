#include<iostream>
using namespace std;
class queue
{
private:
	int* arr,size,rare, front;
public:
	queue(int s)
	{
		arr = new int[s];
		size = s;
		rare = -1;
		front = -1;
	}
	bool isEmpty()
	{
		if (rare == -1 && front == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (rare == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue(int data)
	{
		if (isFull())
		{
			cout << "\nqueue limit is full\n";
			return;
		}
		else if (isEmpty())
		{
			front = rare = 0;
		}
		else
		{
			rare++;
		}
		arr[rare] = data;
		cout << data << " is enqueued \n";
	}
	int dequeue()
	{
		int temp;
		if (isEmpty())
		{
			return INT_MIN;
		}
		else if (rare == front)
		{
			temp = arr[front];
			rare = front = -1;
		}
		else
		{
			temp = arr[front];
			front++;
		}
		return temp;
	}
};
int main()
{
	int opt, x;
	cout<<"enter the size of queue = ";
	cin >> x;
	queue q(x);
	
	do {
		cout << "press 1 to enqueue\npress 2 to dequeue\npress 3 to check queue is empty or not\n"
			"press 4 to check queue is full or not\npress 5 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "\nenter number to enqueue = ";
			cin >> x;
			q.enqueue(x);
			cout << endl << endl;
			break;
		case 2:
			x = q.dequeue();
			if (x == INT_MIN)
			{
				cout << "\nqueue is empty\n";
			}
			else
			cout << x << " is dequeued \n";
			cout << endl << endl;
			break;
		case 3:
			
			if (q.isEmpty())
			{
				cout << "queue is empty" << endl << endl;
			}
			else
				cout << "queue is not empty" << endl << endl;
			break;
		case 4:
			if (!q.isFull())
			{
				cout << "queue is not full" << endl << endl;
			}
			else
				cout << "queue is full" << endl << endl;
			break;
		case 5:
			break;
		default:
			cout << "\ninvalid choice\n";
		}

	} while (opt != 5);



}