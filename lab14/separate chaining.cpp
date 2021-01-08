#include<iostream>
#include<sstream>
#include<string>
using namespace std;
class person
{
public:
	string name, cnic;
	person()
	{
		name = cnic = "";
	}
	void add_person(string n = "", string c = "")
	{
		name = n;
		cnic = c;
	}
	void display()
	{
		cout << "name = " << name << endl;
		cout << "cnic = " << cnic << endl;
	}
};
class node
{
public:
	person p;
	node* next;
	node(string n = "", string c = "")
	{
		p.add_person(n, c);
		next = NULL;
	}
};
class linklist
{
	node* start;
public:
	linklist()
	{
		start = NULL;
	}
	bool isEmpty()
	{
		if (start == NULL)
		{
			return true;
		}
		return false;
	}
	void append(string name, string cnic)
	{
		node* n = new node(name, cnic);
		if (isEmpty())
		{
			start = n;
		}
		else
		{
			node* temp = start;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = n;
		}
	}
	bool delete_node(string cnic)
	{
		node* temp = start, * previos = NULL;
		while (temp != NULL)
		{
			if (temp->p.cnic == cnic)
				break;
			previos = temp;
			temp = temp->next;
		}

		if (temp == start)
		{
			start = start->next;
			return true;
		}
		else if (temp->next == NULL)
		{
			previos->next = NULL;
			return true;
		}
		else
		{
			previos->next = temp->next;
			return true;
		}
		return false;
	}
	void display(string cnic)
	{
		node* temp = start;
		while (temp != NULL)
		{
			if (temp->p.cnic == cnic)
			{
				temp->p.display();
				break;
			}
			temp = temp->next;
		}
	}
};
class hashmap
{
	int bucket,size;
	linklist* table;
	int hashing(string cnic)
	{
		int center_code = getCenterCode(cnic);
		return center_code % bucket;
	}
	int getCenterCode(string s)
	{
		string temp = "";
		for (int i = 6; i <= 12; i++)
		{
			temp = temp + s[i];
		}
		stringstream convert(temp);
		int number;
		convert >> number;
		return number;
	}
public:
	hashmap(int b)
	{
		this->bucket = b;
		size = -1;
		table = new linklist[bucket];
	}
	void insert(string name, string cnic)
	{
		if (size != bucket)
		{
			int index = hashing(cnic);
			table[index].append(name, cnic);
			size++;
		}
		else
			cout << "bucket is full\n";
	}
	void search(string cnic)
	{
		int index = hashing(cnic);
		cout << "following cnic are found at " << index << " index :\n";
		table[index].display(cnic);

	}
	void Delete(string cnic)
	{
		int index = hashing(cnic);
		cout << "deleting following data: \n";
		table[index].display(cnic);
		if (table[index].delete_node(cnic))
		{
			size--;
		}
		else
		{
			cout << "no data found\n";
		}
	}

};

int main()
{
	string name, cnic;
	int opt,size;
	cout << "enter the size of map = ";
	cin >> size;
	hashmap h(size);
	do
	{
		cout << "press 1 to enter person data\npress 2 to search person\npress 3 to delete person\npress 4 to exit\n";
		cin >> opt;
		cin.ignore();
		switch (opt)
		{
		case 1:
			cout << "enter name = ";
			getline(cin, name);
			cout << "enter cnic with dashes = ";
			do
			{
				getline(cin, cnic);
				if (cnic.length() != 15)
				{
					cout << "invalid cnic!!\nenter again = ";
				}
			} while (cnic.length() != 15);
			h.insert(name, cnic);
			cout << "person added\n\n";
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "enter cnic with dashes to search = ";
			do
			{
				getline(cin, cnic);
				if (cnic.length() != 15)
				{
					cout << "invalid cnic!!\nenter again = ";
				}
			} while (cnic.length() != 15);
			h.Delete(cnic);
			cout << "person deleted\n\n";
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "enter cnic with dashes to delete = ";
			do
			{
				getline(cin, cnic);
				if (cnic.length() != 15)
				{
					cout << "invalid cnic!!\nenter again = ";
				}
			} while (cnic.length() != 15);
			h.Delete(cnic);
			cout << "person deleted\n\n";
			system("pause");
			system("cls");
			break;
		case 4:
			break;
		default:
			cout << "invalid input!!!\ntry again = ";

		}
	} while (opt != 4);
}
