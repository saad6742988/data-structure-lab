 #include<iostream> 
using namespace std; 
class node
{
public:
	int data;
	node* left;
	node* right;
	int height;
	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
		height = 0;
	}
};

class avl
{
	
	int height(node* n)
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
	node* rightRotate(node* n)
	{
		node* temp = n->left;
		if (temp != NULL)
		{
			n->left = temp->right;
			temp->right = n;
			n->height = max(height(n->left), height(n->right)) + 1;
			temp->height = max(height(temp->left), height(temp->right)) + 1;
		}
		return temp;
	}
	node* leftRotate(node* n)
	{
		node* temp = n->right;
		if (temp != NULL)
		{
			n->right = temp->left;
			temp->left = n;
			n->height = max(height(n->left), height(n->right)) + 1;
			temp->height = max(height(temp->left), height(temp->right)) + 1;
		}
		return temp;
	}
	int balanceFactor(node* n)
	{
		if (n == NULL)
			return 0;
		return height(n->left) - height(n->right);
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
	node* root;
	avl()
	{
		root = NULL;
	}
	node* getRoot()
	{
		return root;
	}
	node* insert(node* n, int data)
	{
		
		if (n==NULL)
		{
			node* newnode = new node(data);
			n = newnode;
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
		
		n->height = 1 + max(height(n->left),height(n->right));
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
	node* _delete(node* n, int data)
	{
		if (n == NULL)
		{
			return n;
		}
		else if (n->data > data)
		{
			n->left = _delete(n->left, data);
		}
		else if (n->data < data)
		{
			n->right = _delete(n->right, data);
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
				n->data = temp->data;
				n->right = _delete(n->right, temp->data);//n->left = _delete(n->left, temp->data);
			}
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
	bool isAvl(node* n)
	{
		if (n == NULL)
		{
			return true;
		}
		int L_height = height(n->left);
		int R_height = height(n->right);
		int balance = L_height - R_height;
		balance = abs(balance);
		if (balance <= 1 && isAvl(n->left) && isAvl(n->right))
			return true;
		return false;
	}
}; 
int main()
{
	avl t;
	bool check;
	int value, opt;
	do {
		cout << "press 1 to insert\npress 2 to delete\npress 3 to display\npress 4 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			cout << "enter value to insert = ";
			cin >> value;
			t.root = t.insert(t.getRoot(), value);
			cout << endl << endl;
			break;
		case 2:
			cout << "enter value to delete = ";
			cin >> value;
			t.root = t._delete(t.getRoot(), value);
			cout << endl << endl;
			break;
		case 3:
			t.display(t.getRoot());
			cout << endl << endl;
			break;
		default:
			cout << "invalid choice!!";
			break;
		}
	} while (opt != 4);
	check = t.isAvl(t.getRoot());
	cout << check;
	return 0;
}

