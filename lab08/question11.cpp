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
		}
		else
		{
			node* temp = root;
			while (temp != NULL)
			{
				if (n->data == temp->data)
				{
					break;
				}
				else if (n->data < temp->data && temp->left == NULL)
				{
					temp->left = n;
					break;
				}
				else if (n->data > temp->data && temp->right == NULL)
				{
					temp->right = n;
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
	int height(node* n)
	{
		if (n == NULL)
			return 0;
		else
		{
			int height1 = height(n->left) + 1;
			int height2 = height(n->right) + 1;
			if (height1 > height2)
			{
				return(height1);
			}
			else {
				return(height2);
			}
		}
	}
};
int main()
{
	int x,value;
	tree t;
	cout << "enter the size of array you want to create = ";
	cin >> x;
	int* array = new int[x];
	for (int i = 0; i < x; i++)
	{
		cout << "enter value no." << i + 1 << " = ";
		cin >> array[i];
		t.insert(array[i]);
	}
	cout << "\nyour array is converted into binary tree\n";
	cout << "length of your array = " << x<<endl;
	cout << "height of created binary tree = " << t.height(t.getRoot()) << endl;


}