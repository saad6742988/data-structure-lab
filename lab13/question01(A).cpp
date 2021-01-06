#include<iostream>
#include<string>
using namespace std;
#define start 17551
class student
{
	string name;
	int roll, age;
public:
	student()
	{
		name = "";
		roll = 0;
		age = 0;
	}
	void add_student(string n = "", int r = 0, int a = 0)
	{
		name = n;
		roll = r;
		age = a;
	}
	void display()
	{
		cout << "name = " << name<<endl;
		cout << "roll number = " << roll << endl;
		cout << "age = " << age << endl;
	}
};
int hashing(int key)
{
	return key - start;
}
int main()
{
	int x,age,roll;
	string name;
	student s[450];
	cout << "enter the number of students you want to enter = ";
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cout << "enter the name of student = ";
		cin.ignore();
		getline(cin, name);
		cout << "enter the roll number of student(17551 to 18000) = ";
		do
		{
			cin >> roll;
			if (roll < 17551 || roll>18000)
				cout << "invalid roll number!!\n";
		} while (roll < 17551 || roll>18000);
		cout << "enter the age of student = ";
		cin >> age;
		s[hashing(roll)].add_student(name, roll, age);
	}
	cout << "\n\nenter the roll number to search student = ";
	cin >> roll;
	s[hashing(roll)].display();
}
