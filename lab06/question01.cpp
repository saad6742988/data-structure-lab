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
	void insertLeft(int value)
	{
		node* n = new node(value);
		if (isEmpty())
		{
			root = n;
		}
		else
		{
			node* temp = root;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			temp->left = n;
			cout << "\ninserted at left\n";
		}
	}
	void insertRight(int value)
	{
		node* n = new node(value);
		if (isEmpty())
		{
			root = n;
		}
		else
		{
			node* temp = root;
			while (temp->right != NULL)
			{
				temp = temp->right;
			}
			temp->right = n;
			cout << "\ninserted at right\n";
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
	void deleteLeft(int value)
	{
		if (isEmpty())
		{
			cout << "\ntree is empty\n";
		}
		else if (root->data == value)
		{
			cout << endl << value << " is at root so we cant delete root\n";
		}
		else
		{
			node* temp = root, * pre = NULL;
			bool found = false;
			while (temp != NULL)
			{
				if (temp->data == value)
				{
					found = true;
					break;
				}
				pre = temp;
				temp = temp->left;
			}
			if (found)
			{
				if (temp == NULL)
				{
					pre->left = NULL;
				}
				else
				{
					pre->left = temp->left;
				}
			}
			else
				cout << endl << value << " value not found on left side\n";

		}
	}
	void deleteRight(int value)
	{
		if (isEmpty())
		{
			cout << "\ntree is empty\n";
		}
		else if (root->data == value)
		{
			cout << endl << value << " is at root so we cant delete root\n";
		}
		else
		{
			node* temp = root, * pre = NULL;
			bool found = false;
			while (temp != NULL)
			{
				if (temp->data == value)
				{
					found = true;
					break;
				}
				pre = temp;
				temp = temp->right;
			}
			if (found)
			{
				if (temp == NULL)
				{
					pre->right = NULL;
				}
				else
				{
					pre->right = temp->right;
				}
			}
			else
				cout << endl << value << " value not found on right side\n";

		}
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
	bool find(node* n, int value)
	{
		if (n == NULL)
		{
			return false;
		}
		else if (n->data == value)
		{
			return true;
		}
		else if (n->data < value)
		{
			return find(n->right, value);
		}
		else if (n->data > value)
		{
			return find(n->left, value);
		}
	}
};
int main()
{
	int value, opt;
	tree t;
	do
	{
		cout << "press 1 to insert\npress 2 to insert at most left\npress 3 to insert at most right"
			"\npress 4 to delete\npress 5 to delete from most left\npress 6 to delete from most right"
			"\npress 7 for preorder traversal\npress 8 for inorder traversal\npress 9 for postorder traversal"
			"\npress 10 to find the value in tree\npress 11 to display tree\npress 12 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "enter value to be inserted = ";
			cin >> value;
			t.insert(value);
			cout << endl << endl;
			t.display(t.getRoot());
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "enter value to be inserted at most left = ";
			cin >> value;
			t.insertLeft(value);
			cout << endl << value << " is inserted at most left in tree\n";
			cout << endl << endl;
			t.display(t.getRoot());
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "enter value to be inserted at most right = ";
			cin >> value;
			t.insertRight(value);
			cout << endl << value << " is inserted at most right in tree\n";
			cout << endl << endl;
			t.display(t.getRoot());
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "enter value to be deleted = ";
			cin >> value;
			t._delete(t.getRoot(), value);
			cout << endl << value << " is deleted from tree\n";
			cout << endl << endl;
			t.display(t.getRoot());
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "enter value to be deleted from most left = ";
			cin >> value;
			t.deleteLeft(value);
			cout << endl << value << " is deleted from most left in tree\n";
			cout << endl << endl;
			t.display(t.getRoot());
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "enter value to be deleted from most right = ";
			cin >> value;
			t.deleteRight(value);
			cout << endl << value << " is deleted from most right in tree\n";
			cout << endl << endl;
			t.display(t.getRoot());
			system("pause");
			break;
		case 7:
			system("cls");
			t.preorder(t.getRoot());
			cout << "\ntree is traversed in preorder\n";
			system("pause");
			break;
		case 8:
			system("cls");
			t.inorder(t.getRoot());
			cout << "\ntree is traversed in inorder\n";
			system("pause");
			break;
		case 9:
			system("cls");
			t.postorder(t.getRoot());
			cout << "\ntree is traversed in postorder\n";
			system("pause");
			break;
		case 10:
			system("cls");
			cout << "enter value to find in tree = ";
			cin >> value;
			if (t.find(t.getRoot(), value))
			{
				cout << endl << value << " is present in tree\n";
			}
			else
				cout << endl << value << " is not present in tree\n";
			system("pause");
			break;
		case 11:
			system("cls");
			t.display(t.getRoot());
			system("pause");
			break;
		case 12:
			break;
		default:
			cout << "\ninvalid choice!!\n";
		}

	} while (opt != 12);
}