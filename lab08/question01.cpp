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
	void search(node* n, int value)
	{
		static int count = 0;
		if (n == NULL)
		{
			cout << endl << value << " not found after " << count << " iterations\n";
			count = 0;
		}
		else
		{
			if (n->data == value)
			{
				count++;
				cout << endl << value << "found after " << count << " iterations\n";
				count = 0;
			}
			else if (n->data < value)
			{
				count++;
				search(n->right, value);
			}
			else {
				count++;
				search(n->left, value);
			}
		}
	}
	bool valueExist(node* n, int value)
	{
		if (n == NULL)
		{
			return false;
		}
		else
		{
			if (n->data == value)
			{
				return true;
			}
			else if (n->data < value)
			{
				valueExist(n->right, value);
			}
			else {
				valueExist(n->left, value);
			}
		}
	}
	void ancestors(node* n, int value)
	{
		//// static int count = 0;
		//if (n == NULL)
		//{
		//	cout << endl << value << " not found\n";// << count << " iterations\n";
		//	//count = 0;
		//}
		//else
		{
			if (n->data == value)
			{
				//count++;
				//cout << endl << value << "found after " << count << " iterations\n";
				//count = 0;
				return;
			}
			else if (n->data < value)
			{
				//count++;
				cout << n->data << " ";
				ancestors(n->right, value);
			}
			else {
				//count++;
				cout << n->data << " ";
				ancestors(n->left, value);
			}
		}
	}
};
int main()
{
	tree t;
	int opt, value;
	do
	{
		cout << "press 1 to insert in binary tree\npress 2 to search in binary tree\n"
			"press 3 to print ancestors of nodes\npress 4 to display tree\npress 5 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "enter value to insert = ";
			cin >> value;
			t.insert(value);
			cout << endl<<endl;
			t.display(t.getRoot());
			cout << "\n\n**************************************************\n\n";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "enter value to search = ";
			cin >> value;
			t.search(t.getRoot(), value);
			cout << "\n\n**************************************************\n\n";
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "enter value to print ancestors = ";
			cin >> value;
			if (t.valueExist(t.getRoot(), value))
			{
				cout << "ancestors are : ";
				t.ancestors(t.getRoot(), value);
			}
			else
				cout << "\nvalue in not present in tree\n\n";
			t.display(t.getRoot());
			cout << "\n\n**************************************************\n\n";
			system("pause");
			break;
		case 4:
			system("cls");
			t.display(t.getRoot());
			cout << "\n\n**************************************************\n\n";
			system("pause");
			break;
		case 5:
			break;
		default:
			cout << "invalid input!!!!\n";
		}
	} while (opt != 5);
}