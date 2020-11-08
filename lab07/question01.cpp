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
	int count;
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
		count = 0;
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
	void search(node* n, int value)
	{
		static int temp_count = 0;
		if (n == NULL)
		{
			cout << endl << value << " not found after " << temp_count << " iterations\n";
			temp_count = 0;
		}
		else
		{
			if (n->data == value)
			{
				temp_count++;
				cout << endl << value << "found after " << temp_count << " iterations\n";
				temp_count = 0;
			}
			else if (n->data < value)
			{
				temp_count++;
				search(n->right, value);
			}
			else {
				temp_count++;
				search(n->left, value);
			}
		}
	}
	bool isleaf(node* n)
	{
		if (n != NULL)
		{
			if (n->left == NULL && n->right == NULL)
			{
				return true;
			}
		}
		return false;
	}
	bool isNonleaf(node* n)
	{
		if (n != NULL)
		{
			if (n->left != NULL || n->right != NULL)
			{
				return true;
			}
		}
		return false;
	}
	node* getNode(node* n, int value)
	{
		if (n == NULL)
		{
			cout << value << " not found!!!!";
			return NULL;
		}
		else if (n->data == value)
		{
			return n;
		}
		else if (n->data > value)
		{
			return getNode(n->left, value);
		}
		else
			return getNode(n->right, value);
	}
	int getCount()
	{
		int x = count;
		count = 0;
		return x;
	}
	void totalNodes(node* n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			totalNodes(n->left);
			//count++;
			totalNodes(n->right);
			count++;
		}
	}
	bool isParent(node* parent, node* child)
	{
		if (parent != NULL&&child !=NULL)
		{
			if ((parent->left != NULL && parent->left->data == child->data) || (parent->right != NULL && parent->right->data == child->data))
				return true;
		}
		return false;
	}
	bool isChild(node* parent, node* child)
	{
		if (parent != NULL&&child != NULL)
		{
			if ((parent->left != NULL && parent->left->data == child->data) || (parent->right != NULL && parent->right->data == child->data))
				return true;
		}
		return false;
	}
	int degreeOfNode(node* n)
	{
		if (n!= NULL) {
			if (n->left == NULL && n->right == NULL)
			{
				return 0;
			}
			else if (n->left != NULL && n->right != NULL)
			{
				return 2;
			}
			return 1;
		}
		return 0;
	}
	void levelOfNode(node* n, int value)
	{
		static int temp_count = 0;
		if (n == NULL)
		{
			cout << value << " not found!!!!";
			temp_count = 0;
		}
		else if (n->data == value)
		{
			cout << "level of node  = " << temp_count << endl;
			temp_count = 0;
		}
		else if (n->data > value)
		{
			temp_count++;
			levelOfNode(n->left, value);
		}
		else
		{
			temp_count++;
			levelOfNode(n->right, value);
		}
	}
	bool isSibling(node* parent, node* child, node* child1)
	{
		if (parent != NULL && child != NULL&&child1!=NULL)
		{
			if (isParent(parent, child) && isParent(parent, child1))
				return true;
		}
		return false;
	}
	void leafNodeCount(node *n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			leafNodeCount(n->left);
			leafNodeCount(n->right);
			if (n->left == NULL && n->right == NULL)
				count++;
		}
	}
	void nonleafNodeCount(node* n)
	{
		if (n == NULL)//base case
		{
			return;
		}
		else
		{
			nonleafNodeCount(n->left);
			nonleafNodeCount(n->right);
			if (n->left != NULL || n->right != NULL)
				count++;
		}
	}
	bool isDesendent(node* desendent, node* successor)
	{
		if (desendent != NULL&&successor!=NULL)
		{
			if ((desendent->left!=NULL&&desendent->left->data == successor->data) || (desendent->right != NULL && desendent->right->data == successor->data))
			{
				return true;
			}
			else if (desendent->data < successor->data)
			{
				return isDesendent(desendent->right, successor);
			}
			else
				return isDesendent(desendent->left, successor);
		}
		return false;
	}
	bool isSuccessor(node* desendent, node* successor)
	{
		if (desendent != NULL && successor != NULL)
		{
			if ((desendent->left != NULL && desendent->left->data == successor->data) || (desendent->right != NULL && desendent->right->data == successor->data))
			{
				return true;
			}
			else if (desendent->data < successor->data)
			{
				return isSuccessor(desendent->right, successor);
			}
			else
				return isSuccessor(desendent->left, successor);
		}
		return false;
	}
	int height(node* n)
	{
		if (n == NULL)
			return 0;
		else
		{
			int height1 = height(n->left)+1;
			int height2 = height(n->right)+1;
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
	//1 60 1 70 1 50 1 45 1 55 1 75
	int value, opt, value1,value2;
	tree t;
	do
	{
		cout << "press 1 to insert\npress 2 to delete\npress 3 to search the value in tree\npress 4 to display tree\npress 5 to check is leaf or not\n"
			"press 6 to check is non leaf or not\npress 7 to count total nodes\npress 8 to check parent\npress 9 to check child\npress 10 to check degree of node\n"
			"press 11 to check level of node\npress 12 to check siblings\npress 13 to count leaf nodes\n"
			"press 14 to count non leaf node\npress 15 to check desendent\npress 16 to check successor\n"
			"press 17 to check height of treee\npress 18 to exit\n";
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
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "enter value to be deleted = ";
			cin >> value;
			t._delete(t.getRoot(), value);
			cout << endl << value << " is deleted from tree\n";
			cout << endl << endl;
			t.display(t.getRoot());
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "enter value to search in tree = ";
			cin >> value;
			t.search(t.getRoot(), value);
			cout << endl << endl;
			t.display(t.getRoot());
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 4:
			system("cls");
			t.display(t.getRoot());
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "enter value you want to check weather the node is leaf or not = ";
			cin >> value;
			if (t.isleaf(t.getNode(t.getRoot(), value)))
			{
				cout << endl << value << " is at leaf node\n";
			}
			else {
				cout << endl << value << " is not at leaf node\n";
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 6:
			system("cls");
			cout << "enter value you want to check weather the node is leaf or not = ";
			cin >> value;
			if (t.isNonleaf(t.getNode(t.getRoot(), value)))
			{
				cout << endl << value << " is at non leaf node\n";
			}
			else {
				cout << endl << value << " is not at non leaf node\n";
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 7:
			system("cls");
			t.totalNodes(t.getRoot());
			cout << "total nodes = " <<t.getCount() << endl;
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 8:
			system("cls");
			cout << "enter value of parent = ";
			cin >> value;
			cout << "enter value of child = ";
			cin >> value1;
			if (t.isParent(t.getNode(t.getRoot(), value), t.getNode(t.getRoot(), value1)))//isParent(adress of parent,adress of child)
			{
				cout << endl << value << " is parent of " << value1 << endl;
			}
			else {
				cout << endl << value << " is not parent of " << value1 << endl;
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 9:
			system("cls");
			cout << "enter value of parent = ";
			cin >> value;
			cout << "enter value of child = ";
			cin >> value1;
			if (t.isChild(t.getNode(t.getRoot(), value), t.getNode(t.getRoot(), value1)))//isChild(adress of parent,adress of child)
			{
				cout << endl << value1 << " is child of " << value << endl;
			}
			else {
				cout << endl << value1 << " is not child of " << value << endl;
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 10:
			system("cls");
			cout << "enter value of node you want to check degree = ";
			cin >> value;
			cout << "dergree of node  = " << t.degreeOfNode(t.getNode(t.getRoot(),value)) << endl;
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 11:
			system("cls");
			cout << "enter value of node you want to check level = ";
			cin >> value;
			t.levelOfNode(t.getRoot(), value);
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 12:
			system("cls");
			cout << "enter value of parent = ";
			cin >> value;
			cout << "enter value of first child = ";
			cin >> value1;
			cout << "enter value of second child = ";
			cin >> value2;
			if (t.isSibling(t.getNode(t.getRoot(), value), t.getNode(t.getRoot(), value1), t.getNode(t.getRoot(), value2)))//isSibling(adress of parent,adress of child1,adress of child2)
			{
				cout << endl << value1 << " And " << value2<<" are siblings" << endl;
			}
			else {
				cout << endl << value1 << " And " << value2 << " are not siblings" << endl;
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 13:
			system("cls");
			t.leafNodeCount(t.getRoot());
			cout << "total leaf nodes = " << t.getCount()  << endl;
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 14:
			system("cls");
			t.nonleafNodeCount(t.getRoot());
			cout << "total non leaf nodes = " << t.getCount() << endl;
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 15:
			system("cls");
			cout << "enter value of desendent = ";
			cin >> value;
			cout << "enter value of successor = ";
			cin >> value1;
			if (t.isDesendent(t.getNode(t.getRoot(), value), t.getNode(t.getRoot(), value1)))//isDesendent(adress of desendent,adress of successor)
			{
				cout << endl << value << " is Desendent of " << value1 << endl;
			}
			else {
				cout << endl << value << " is not Desendent of " << value1 << endl;
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 16:
			system("cls");
			cout << "enter value of desendent = ";
			cin >> value;
			cout << "enter value of successor = ";
			cin >> value1;
			if (t.isSuccessor(t.getNode(t.getRoot(), value), t.getNode(t.getRoot(), value1)))//isSuccessor(adress of desendent,adress of successor)
			{
				cout << endl << value1 << " is Successor of " << value << endl;
			}
			else {
				cout << endl << value1 << " is not Successor of " << value << endl;
			}
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 17:
			system("cls");
			cout << "height of tree = " << t.height(t.getRoot()) << endl;
			cout << "\n***************************************\n";
			system("pause");
			break;
		case 18:
			break;
		default:
			cout << "\ninvalid choice!!\n";
		}

	} while (opt != 18);
}
