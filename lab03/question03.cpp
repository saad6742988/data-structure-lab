#include<iostream>
using namespace std;
class node
{
public:
	int data;
	int pirority;
	node* next;
	node(int d = 0, int p = 0)
	{
		pirority = p;
		data = d;
		next = NULL;
	}
};
class queue
{
	node* front, * rare;
public:
	queue()
	{
		front = rare = NULL;
	}
	void enqueue(int x, int p)
	{
		node* n = new node(x, p);
		if (isEmpty())
		{
			front = rare = n;
			cout << "\nenqueued";
		}
		else
		{
			if (n->pirority <= front->pirority)
			{
				n->next = front;
				front = n;
				cout << "\nenqueued";
			}
			else
			{
				node* temp = front;
				while (temp->next != NULL)
				{
					if (temp->next->pirority >= n->pirority)
					{
						break;
					}
					temp = temp->next;
				}
				if (temp == rare)
				{
					rare->next = n;
					rare = n;
					cout << "\nenqueued";
				}
				else
				{
					n->next = temp->next;
					temp->next = n;
					cout << "\nenqueued";
				}

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
};
int main()
{
	queue q;
	int x, priority,data;
	cout << "values you want to enter in queue : ";
	cin >> x;
	for (int i = 1; i <= x; i++)
	{
		cout << "enter data of value no." << i << " = ";
		cin >> data;
		cout << "enter priority of value no." << i << " = ";
		cin >> priority;
		q.enqueue(data, priority);
		cout << endl;
	}
	cout << "\n\ndequeuing all data wit respeect of priority : " << endl;
	for (; !q.isEmpty();)
	{
		cout << q.dequeue()->data << " , ";
	}
	return 0;
}