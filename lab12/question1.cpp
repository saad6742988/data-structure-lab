#include<iostream>
#include<iomanip>
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
	node* head;
public:
	stack()
	{
		head = NULL;
	}
	void push(int x)
	{
		node* n = new node(x);
		if (isEmpty())
		{
			head = n;
		}
		else
		{
			node* temp = head;
			head = n;
			head->next = temp;
		}
	}

	//pop function
	int pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	int top()
	{
		return head->data;
	}
	//check empty
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
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
	void enqueue(int x)
	{
		node* n = new node(x);
		if (isEmpty())
		{
			front = rare = n;
		}
		else
		{
			rare->next = n;
			rare = n;
		}
	}
	//dequeue function
	void dequeue()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			node* temp = front;
			front = front->next;
			delete temp;
			if (front == NULL)
				rare == NULL;
		}
	}
	//check empty
	bool isEmpty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;
	}
	int getFront()
	{
		return front->data;
	}

};
template <typename t>
class Adgency_matrix {
	int** adgency_matrix; //the adjacency matrix initially 0
	int vertices;
	int starting;
public:
	Adgency_matrix(int v, int s)
	{
		vertices = v;
		starting = s;
		adgency_matrix = new int* [vertices];
		for (int i = 0; i < vertices; i++)
		{
			adgency_matrix[i] = new int[vertices];
		}
		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				adgency_matrix[i][j] = 0;
	}
	void displayMatrix() {
		cout << "  ";
		for (int k = 0; k < vertices; k++)
		{
			cout << setw(3) << t(k + starting);
		}
		cout << endl << "  ";
		for (int k = 0; k < vertices; k++)
		{
			cout << setw(3) << "---";
		}
		cout << endl;
		for (int i = 0; i < vertices; i++) {
			cout << t(i + starting) << "|  ";
			for (int j = 0; j < vertices; j++) {
				cout << adgency_matrix[i][j] << "  ";
			}
			cout << endl;
		}
	}
	void add_edge(int u, int v) {       //function to add edge into the matrix
		adgency_matrix[u][v] = 1;
		adgency_matrix[v][u] = 1;
	}
	int** getMatrix()
	{
		return adgency_matrix;
	}
	void bfs()
	{
		int start_from;
		int temp;
		cout << "Enter Starting vertex = ";
		cin >> start_from;
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		queue q;
		q.enqueue(start_from);
		temp = start_from;
		while (q.isEmpty() != true)
		{
			start_from = q.getFront();
			cout << start_from << " ";
			for (int j = 0; j < vertices; j++)
			{
				if (adgency_matrix[start_from][j] == 1 && visited[j] == false && j != temp)
				{
					q.enqueue(j);
					visited[j] = true;
				}


			}
			q.dequeue();
		}

	}
	void dfs()
	{
		int start_from;
		cout << "Enter Starting vertex = ";
		cin >> start_from;
		bool visit = false;
		bool* visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}

		stack s;  //0
		cout << start_from << " ";
		s.push(start_from);
		int temp = start_from;
		//for (int k = 0; k<vertices-1;)
		while(!s.isEmpty())
		{
			start_from = s.top();
			visit = false;
			for (int j = 0; j < vertices; j++)
			{
				if (adgency_matrix[start_from][j] == 1 && visited[j] == false && temp != j)
				{
					s.push(j);
					cout << j << " ";
					visited[j] = true;
					start_from = j;
					visit = true;
					break;

				}


			}
			if (visit == false)
			{
				s.pop();
			}

		}
	}

};
int main()
{
	cout << "\t\tUNWEIGHTED AND UNDIRECTED GRAPH\n\n";
	int vertices, edges, to, from;
	int start;//start is the starting of your graph like it is starting from 0 ,1
	cout << "enter number of vertices = ";
	cin >> vertices;
	cout << "enter the start of your graph (i.e starting from 0 or 1) = ";
	cin >> start;
	cout << "enter number edges you want to create = ";
	cin >> edges;
	Adgency_matrix<int> matrix(vertices, start);
	for (int i = 0; i < edges; i++)
	{

		do {
			cout << "add edge :";
			cin >> from;
			cout << " to ";
			cin >> to;
			if ((to > vertices || to < start) || (from > vertices || from < start))
			{
				cout << "invalid edge input!!!\n";
			}
		} while ((to > vertices || to < start) || (from > vertices || from < start));
		matrix.add_edge(from - start, to - start);
	}
	cout << "adgency matrix :\n";
	matrix.displayMatrix();
	cout << endl << endl;
	cout << "bfs search :\n";
	matrix.bfs();
	cout << endl << endl;
	cout << "dfs search :\n";
	matrix.dfs();
}
