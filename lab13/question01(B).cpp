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
	void add_person(string n = "",string c="")
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
	node(string n="",string c="")
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
	void append(string name,string cnic)
	{
		node* n = new node(name,cnic);
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
	int bucket;
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
		table = new linklist[bucket];
	}
	void insert(string name,string cnic)
	{
		int index = hashing(cnic);
		table[index].append(name,cnic);
	}
	void search(string cnic)
	{
		int index = hashing(cnic);
		cout << "following cnic are found at " << index << " index :\n";
		table[index].display(cnic);

	}

};

int main()
{
	string name, cnic;
	int size;
	cout << "how many persons you want to enter = ";
	cin >> size;
	cin.ignore();
	hashmap h(size);
	for (int i = 0; i < size; i++)
	{
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
	}
	cout << "\n\nenter person cnic to search = ";
	do
	{
		cin.ignore();
		getline(cin, name);
		if (cnic.length() != 15)
		{
			cout << "invalid cnic!!\nenter again = ";
		}
	} while (cnic.length() != 15);
	h.search(cnic);
}
