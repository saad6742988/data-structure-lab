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
	void inorder(node* n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			inorder(n->left);
			cout << n->data << " , ";
			inorder(n->right);
		}
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
	void postorder(node* n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			postorder(n->left);
			postorder(n->right);
			cout << n->data << " , ";
		}
	}
};
int main()
{
	tree t;
	int n, value;
	cout << "enter number of values you want to insert in tree = ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter value to insert = ";
			cin >> value;
		t.insert(value);
	}
	cout << "\nyour tree is : \n\n";
	t.display(t.getRoot());
	cout << "\n\npostorder traversal = ";
	t.postorder(t.getRoot());
	cout << "\n\ninorder traversal = ";
	t.inorder(t.getRoot());
	cout << "\n\npreorder traversal = ";
	t.preorder(t.getRoot());
}