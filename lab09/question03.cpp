#include<iostream> 
using namespace std;
class avlNode
{
public:
	int data;
	avlNode* left;
	avlNode* right;
	int height;
	avlNode(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
		height = 0;
	}
};
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
class avl
{

	int height(avlNode* n)
	{
		if (n == NULL)
			return 0;
		return n->height;
	}
	int max(int a, int b)
	{
		if (a >= b)
			return a;
		return b;
	}
	avlNode* rightRotate(avlNode* n)
	{
		avlNode* temp = n->left;
		if (temp != NULL)
		{
			n->left = temp->right;
			temp->right = n;
			n->height = max(height(n->left), height(n->right)) + 1;
			temp->height = max(height(temp->left), height(temp->right)) + 1;
		}
		return temp;
	}
	avlNode* leftRotate(avlNode* n)
	{
		avlNode* temp = n->right;
		if (temp != NULL)
		{
			n->right = temp->left;
			temp->left = n;
			n->height = max(height(n->left), height(n->right)) + 1;
			temp->height = max(height(temp->left), height(temp->right)) + 1;
		}
		return temp;
	}
	int balanceFactor(avlNode* n)
	{
		if (n == NULL)
			return 0;
		return height(n->left) - height(n->right);
	}
public:
	avlNode* root;
	avl()
	{
		root = NULL;
	}
	avlNode* getRoot()
	{
		return root;
	}
	avlNode* insert(avlNode* n, int data)
	{

		if (n == NULL)
		{
			avlNode* newavlNode = new avlNode(data);
			n = newavlNode;
			n->height = 1 + max(height(n->left), height(n->right));
			return n;
		}

		if (data < n->data)
			n->left = insert(n->left, data);
		else if (data > n->data)
			n->right = insert(n->right, data);
		else
		{
			cout << "same value already found in tree!!!\n";
			return n;
		}

		n->height = 1 + max(height(n->left), height(n->right));
		int balance = balanceFactor(n);


		// Left Left Case  
		if (balance > 1 && data < n->left->data)
			return rightRotate(n);
		// Right Right Case  
		if (balance < -1 && data > n->right->data)
			return leftRotate(n);
		// Left Right Case  
		if (balance > 1 && data > n->left->data)
		{
			n->left = leftRotate(n->left);
			return rightRotate(n);
		}
		// Right Left Case  
		if (balance < -1 && data < n->right->data)
		{
			n->right = rightRotate(n->right);
			return leftRotate(n);
		}
		return n;
	}
	void display(avlNode* n, int space = 2)
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
	void convert(node* treeRoot)
	{
		if (treeRoot == NULL)
		{
			return;
		}
		else
		{
			root = insert(root, treeRoot->data);
			convert(treeRoot->left);
			convert(treeRoot->right);
		}
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
};
int main()
{
	avl t;
	tree tr;
	int x,value;
	cout << "values you want to enter in binary tree = ";
	cin >> x;
	cout << "enter values in  tree:\n";
	for (int i = 0; i < x; i++)
	{
		cin >> value;
		tr.insert(value);
	}
	cout << endl << endl;
	cout << "simple bst : \n\n";
	tr.display(tr.getRoot());
	cout << "\n\nconverting bst to avl tree......\n\n";
	t.convert(tr.getRoot());
	cout << endl << endl;
	cout << "avl tree : \n\n";
	t.display(t.getRoot());
}

