#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	node(int d = 0)
	{
		data = d;
		left = right = NULL;
	}
};
class tree
{
	node* root;
public:
	node* getRoot()
	{
		return root;
	}
	tree()
	{
		root = NULL;
	}
	bool isEmpty()
	{
		if (root == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void insert(int value)
	{
		node* n = new node(value);
		if (isEmpty())
		{
			root = n;
			cout << endl << value << " is inserted in tree\n";
		}
		else
		{
			node* temp = root;
			while (temp != NULL)
			{
				if (n->data == temp->data)
				{
					cout << "\nsame value found\n";
					break;
				}
				else if (n->data < temp->data && temp->left == NULL)
				{
					temp->left = n;
					cout << endl << value << " is inserted in tree\n";
					break;
				}
				else if (n->data > temp->data && temp->right == NULL)
				{
					temp->right = n;
					cout << endl << value << " is inserted in tree\n";
					break;
				}
				else if (n->data < temp->data && temp->left != NULL)
				{
					temp = temp->left;
				}
				else if (n->data > temp->data && temp->right != NULL)
				{
					temp = temp->right;
				}
			}
		}
	}
	void display(node* n, int space = 2)
	{
		if (n == NULL)
		{
			return;
		}
		space += 7;
		//first of all it will display the right most value by recurssion
		//spaces will be given by space=space+7 and this is done by for loop
		//after displaying all right value display will return to root and then display root 
		display(n->right, space);
		cout << endl;
		for (int i = 7; i < space; i++)
		{
			cout << " ";
		}
		cout << n->data << endl;
		//after displaying all right value and root it will start displaying left values by recursion 
		display(n->left, space);


	}
	void preorder(node* n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			cout << n->data << " , ";
			preorder(n->left);
			preorder(n->right);
		}
	}
	void merge(node* n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			insert(n->data);
			merge(n->left);
			merge(n->right);
		}
	}
};
int main()
{
	tree t, t1;
	int n, value;
	cout << "values you want to insert in first tree = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter value to insert in first tree = ";
		cin >> value;
		t.insert(value);
	}
	cout << "\n\n*******************************************\n\n";
	cout << "\n\nvalues you want to insert in second tree = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter value to insert in second tree = ";
		cin >> value;
		t1.insert(value);
	}
	cout << "\n\n*******************************************\n\n";
	cout << "first tree is = " << endl;
	t.display(t.getRoot());
	cout << "\n\n*******************************************\n\n";
	cout << "\nsecond tree is = " << endl;
	t1.display(t1.getRoot());
	cout << "\n\n*******************************************\n\n";
	cout << "inserting values from second tree to first tree\n";
	t.merge(t1.getRoot());
	cout << "\n\n*******************************************\n\n";
	cout << "\nafter merging second tree in first tree : " << endl;
	t.display(t.getRoot());
	system("pause");
	return 0;
}