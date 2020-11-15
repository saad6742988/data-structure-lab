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
	node* minValue(node* n)
	{
		node* temp = n;
		if (temp->left == NULL)
		{
			return n;
		}
		return minValue(temp->left);
	}
	node* maxValue(node* n)
	{
		node* temp = n;
		if (temp->right == NULL)
		{
			return n;
		}
		return maxValue(temp->right);
	}
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
	node* _delete(node* n, int value)
	{
		if (n == NULL)
		{
			return n;
		}
		else if (n->data > value)
		{
			n->left = _delete(n->left, value);
		}
		else if (n->data < value)
		{
			n->right = _delete(n->right, value);
		}
		else
		{
			if (n->left == NULL)
			{
				node* temp = n->right;
				delete n;
				return temp;
			}
			else if (n->right == NULL)
			{
				node* temp = n->left;
				delete n;
				return temp;
			}
			else
			{
				node* temp = minValue(n->right);//node*temp=maxValue(n->left);
				//minValue funtion will get the minimum value from the right node
				//if there are two child nodes
				n->data = temp->data;
				n->right = _delete(n->right, temp->data);//n->left = _delete(n->left, temp->data);
			}
		}
		return n;
	}
};
int main()
{
	tree t;
	int value, opt;
	do
	{
		cout << "press 1 to insert\npress 2 to delete\npress 3 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "enter velue to insert in tree = ";
			cin >> value;
			t.insert(value);
			t.display(t.getRoot());
			cout << "\n********************************************\n\n";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "enter velue to delete from tree = ";
			cin >> value;
			t._delete(t.getRoot(),value);
			t.display(t.getRoot());
			cout << "\n********************************************\n\n";
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "invalid input!!!!\n";
		}
	} while (opt != 3);
}