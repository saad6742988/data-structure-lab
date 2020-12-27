//https://www.geeksforgeeks.org/infix-to-prefix-conversion-using-two-stacks/
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;

//Structure of Node
struct Node
{
	string data;
	Node* next;
};
class List
{
private:
	Node* head; //Address of Head Node.
	int length; //Get current size of list.
public:
	List(); //Initialize function
	bool IsFull() const;
	bool IsEmpty() const;
	int GetLength() const;
	void MakeEmpty();
	string ReadHead() const;
	void InsertAtHead(string value);
	string DeleteFromHead();
	void Display();
};

List::List() // Constructor of class
{
	length = 0;
	head = NULL;
}

//Check if there is enough system memory available;
bool List::IsFull() const
{
	Node* temp;
	try {
		temp = new Node;
		delete temp;
		return false;
	}
	catch (bad_alloc exception)
	{
		return true;
	}
}

bool List::IsEmpty() const
{
	return (length == 0 || head == NULL);
}

void List::MakeEmpty()
{
	Node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
	length = 0;
}

int List::GetLength() const
{
	return length;
}

//Function returns the data vaule at head of the list, use as helper function to implement top() of stack
string List::ReadHead() const
{
	string data = "";
	if (head != NULL)
	{
		data = head->data;
	}
	return data;
}

//Insert a new node with value at the head of List
void List::InsertAtHead(string value)
{
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;

	head = newNode;
	length++;
}
//Delete node with value of a from List
string List::DeleteFromHead()
{
	string data = "";
	if (head != NULL)
	{
		Node* temp = head;
		head = temp->next;
		data = temp->data;
		delete temp;
		length--;
	}
	return data;
}

//Show the complete list to user
void List::Display()
{
	if (head != NULL)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << "| " << temp->data << " |";
			if (temp->next != NULL)
			{
				cout << " -> ";
			}
			temp = temp->next;
		}
		cout << endl;
	}
	else
	{
		cout << "List is Empty\r\n";
	}
}


class Stack
{
private:
	List list;
public:
	bool isFull() const;
	bool isEmpty() const;
	string top() const;
	void push(string value);
	string pop();
};

bool Stack::isFull() const
{
	return list.IsFull();
}
bool Stack::isEmpty() const
{
	return list.IsEmpty();
}
string Stack::top() const
{
	return list.ReadHead();
}
void Stack::push(string value)
{
	list.InsertAtHead(value);
}
string Stack::pop()
{
	return list.DeleteFromHead();
}

enum expressionType { prefix, infix, postfix };

class Expression
{
private:
	string expression;
	expressionType expression_type;

	int evaluatePrefix();
	int evaluateInfix();
	int evaluatePostfix();

	void prefixToInfix();
	void prefixToPostfix();
	void infixToPrefix();
	void infixToPostfix();
	void postfixToPrefix();
	void postfixToInfix();

	bool  isOperand(string ch) const
	{
		// If the scanned character is an operand, add it to output string. 
		return ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z"));
	}

	bool  isOperator(string ch) const
	{
		// If the scanned character is an operand, add it to output string. 
		return (ch == "^" || ch == "*" || ch == "/" || ch == "+" || ch == "-");
	}
	// to check the precedence of operators.
	int precedence(string c)
	{
		if (c == "^")
			return 3;
		else if (c == "*" || c == "/")
			return 2;
		else if (c == "+" || c == "-")
			return 1;
		else
			return -1;
	}
	int applyOperation(int a,int b,char op)
	{
		switch (op) {
		case '+': return a + b;
		case '-': return b - a;
		case '*': return a * b;
		case '/': return b / a;
		}
	}

public:
	Expression()
	{
		this->expression = "00000000000000000000000";
		this->expression_type = infix;
	}

	void convertExpression(expressionType convertTo)
	{
		if (this->expression_type == prefix)
		{
			switch (convertTo)
			{
			case infix:
				prefixToInfix();
				break;
			case postfix:
				prefixToPostfix();
				break;
			}
		}
		else if (this->expression_type == infix)
		{
			switch (convertTo)
			{
			case prefix:
				infixToPrefix();
				break;
			case postfix:
				infixToPostfix();
				break;
			}
		}
		else if (this->expression_type == postfix)
		{
			switch (convertTo)
			{
			case prefix:
				postfixToPrefix();
				break;
			case infix:
				postfixToInfix();
				break;
			}
		}
	}
	int evaluateExpression()
	{
		switch (this->expression_type)
		{
		case prefix:
			return evaluatePrefix();
			break;
		case infix:
			return evaluateInfix();
			break;
		case postfix:
			return evaluatePostfix();
			break;
		}
	}
	void Display()
	{
		switch (this->expression_type)
		{
		case prefix:
			cout << "Prefix ";
			break;
		case infix:
			cout << "Infix ";
			break;
		case postfix:
			cout << "Postfix ";
			break;
		}
		cout << "Notation: " << this->expression << endl;
	}
	void setExpression(string expression, expressionType expression_type)
	{
		this->expression = expression;
		this->expression_type = expression_type;
	}
};

void Expression::infixToPostfix()
{
	Stack stack;
	string postfixStr;
	//Check weather it is an infix expression or not.
	if (this->expression_type == infix)
	{
		for (int i = 0; i < this->expression.length(); i++)
		{
			// If the scanned character is an operand, add it to output string. 
			string ch(1, this->expression[i]);
			if (isOperand(ch))
			{
				postfixStr += ch;
			}
			// If the scanned character is an ‘(‘, push it to the stack. 
			else if (ch == "(")
			{
				stack.push(ch);
			}

			// If the scanned character is an ‘)’, pop and to output string from the stack 
			// until an ‘(‘ is encountered. 
			else if (ch == ")")
			{
				while (stack.top() != "(" && !stack.isEmpty())
				{
					string op = stack.pop();
					postfixStr += op;
				}
				if (stack.top() == "(")
				{
					stack.pop();
				}
			}
			//If an operator is scanned 
			else {
				while (!stack.isEmpty() && precedence(ch) <= precedence(stack.top()))
				{
					string op = stack.pop();
					postfixStr += op;
				}
				stack.push(ch);
			}
		}
		//Pop all the remaining elements from the stack 
		while (!stack.isEmpty())
		{
			string op = stack.pop();
			postfixStr += op;
		}

		this->expression = postfixStr;
		this->expression_type = postfix;
	}
	else
	{
		cout << "Sorry given expression is not in Infix notation." << endl;
	}

}
//This funcion will convert expression in infix notation to prefix notation
void Expression::infixToPrefix()
{
	Stack operators_stack;
	Stack operands_stack;
	string prefixStr;
	//Check weather it is an infix expression or not.
	if (this->expression_type == infix)
	{
		for (int i = 0; i < this->expression.length(); i++)
		{
			// If the scanned character is an operand, add it to output string. 
			string ch(1, this->expression[i]);

			// If current character is an 
			// opening bracket, then 
			// push into the operators stack. 
			if (ch == "(")
			{
				operators_stack.push(ch);
			}

			// If current character is a 
			// closing bracket, then pop from 
			// both stacks and push result 
			// in operands stack until 
			// matching opening bracket is 
			// not found. 
			else if (ch == ")")
			{
				while (!operators_stack.isEmpty() && operators_stack.top() != "(")
				{
					// operand 1 
					string op1 = operands_stack.pop();

					// operand 2 
					string op2 = operands_stack.pop();

					// operator 
					string op = operators_stack.pop();

					// Add operands and operator 
					// in form operator + 
					// operand1 + operand2. 

					string tmp = op + op2 + op1;
					operands_stack.push(tmp);
				}

				// Pop opening bracket from 
				// stack. 
				operators_stack.pop();
			}
			// If current character is an 
			// operand then push it into 
			// operands stack. 
			else if (!isOperator(ch)) {
				operands_stack.push(ch);
			}

			// If current character is an 
			// operator, then push it into 
			// operators stack after popping 
			// high priority operators from 
			// operators stack and pushing 
			// result in operands stack. 
			else {
				while (!operators_stack.isEmpty() && precedence(ch) <= precedence(operators_stack.top())) {

					string op1 = operands_stack.pop();
					string op2 = operands_stack.pop();
					string op = operators_stack.pop();

					string tmp = op + op2 + op1;
					operands_stack.push(tmp);
				}

				operators_stack.push(ch);
			}
		}

		// Pop operators from operators stack 
		// until it is empty and add result 
		// of each pop operation in 
		// operands stack. 
		while (!operators_stack.isEmpty()) {
			string op1 = operands_stack.pop();
			string op2 = operands_stack.pop();
			string op = operators_stack.pop();
			string tmp = op + op2 + op1;
			operands_stack.push(tmp);
		}

		// Final prefix expression is 
		// present in operands stack. 
		this->expression = operands_stack.top();
		this->expression_type = prefix;
	}
	else
	{
		cout << "Sorry given expression is not in Infix notation." << endl;
	}
}
void Expression::postfixToInfix()
{

	Stack stack;
	if (this->expression_type != postfix)
	{
		cout << "Sorry given expression is not in postfix notation." << endl;
	}
	else
	{
		{
			for (int i = 0; i < this->expression.length(); i++)
			{
				string ch(1, expression[i]);
				// Push operands 
				if (isOperand(ch))
				{
					stack.push(ch);
				}
				// if character is operator an operator. 
				else
				{
					string op1 = stack.pop();
					string op2 = stack.pop();
					stack.push("(" + op2 + expression[i] +
						op1 + ")");
				}
			}

		}
		this->expression = stack.top();
		this->expression_type = infix;
	}
}
void Expression::postfixToPrefix()
{
	Stack stack;
	if (this->expression_type != postfix)
	{
		cout << "Sorry given expression is not in postfix notation." << endl;
	}
	else
	{
		// reading from right to left
		for (int i = 0; i < this->expression.length(); i++)
		{
			string ch(1, expression[i]);
			// check if symbol is operator
			if (isOperator(ch))
			{

				// pop two operands from stack
				string op1 = stack.pop();
				string op2 = stack.pop();
				// Push concatinated the operands and operator
				stack.push(expression[i] + op2 + op1);
			}
			// if symbol is an operand
			else {
				string ch(string(1, expression[i]));
				// push the operand to the stack
				stack.push(ch);
			}
		}

		this->expression = "";
		while (!stack.isEmpty()) {
			this->expression += stack.pop();
		}
		this->expression_type = prefix;
	}
}
void Expression::prefixToInfix()
{
	Stack stack;
	if (this->expression_type != prefix)
	{
		cout << "Sorry given expression is not in prefix notation." << endl;
	}
	else
	{
		// reading from right to left
		for (int i = this->expression.length() - 1; i >= 0; i--)
		{
			string ch(1, expression[i]);
			// check if character is operator
			if (isOperator(ch))
			{
				// pop two operands from stack
				string op1 = stack.pop();
				string op2 = stack.pop();
				// Push concatinated operands and operator with brakets
				stack.push("(" + op1 + expression[i] + op2 + ")");
			}
			// if character is an operand
			else {

				// push the operand to the stack
				stack.push(ch);
			}
		}
		this->expression = stack.top();
		this->expression_type = infix;
	}
}
void Expression::prefixToPostfix()
{
	Stack stack;
	if (this->expression_type != prefix)
	{
		cout << "Sorry given expression is not in prefix notation." << endl;
	}
	else
	{
		// reading from right to left
		for (int i = this->expression.length() - 1; i >= 0; i--)
		{
			string ch(1, expression[i]);
			// check if character is operator
			if (isOperator(ch))
			{
				// pop two operands from stack
				string op1 = stack.pop();
				string op2 = stack.pop();
				// Push concatinated operands and operator
				stack.push(op1 + op2 + expression[i]);
			}
			// if character is an operand
			else {

				// push the operand to the stack
				stack.push(string(1, expression[i]));
			}
		}
		this->expression = stack.top();
		this->expression_type = postfix;
	}
}
int Expression::evaluateInfix()
{
	// stack to store integer values.
	Stack values;
	// stack to store operators.
	Stack op;

	for (int i = 0; i < this->expression.length(); i++) {

		// Current character is a whitespace,
		// skip it.
		string ch(1, expression[i]);
		if (this->expression[i]==' ')
			continue;

		// Current character is an opening brace, push it to 'op stack'
		else if (this->expression[i] == '(') {
			op.push(ch);
		}

		// Current character is a number, push it to stack for numbers.
		else if (isdigit(this->expression[i])) {
			string val = "";
			// There may be more than one digits in number.
			while (i < this->expression.length() &&isdigit(this->expression[i]))
			{
				val = val + expression[i];
				i++;
			}
			values.push(val);
			i--;
		}
		// Closing brace encountered, solve entire brace.
		else if (this->expression[i] == ')')
		{
			while (!op.isEmpty() && op.top() != "(")
			{
				string v = values.pop();
				string v1 = values.pop();
				stringstream temp(v1);
				int val1;
				temp >> val1;
				stringstream temp1(v);
				int val;
				temp1 >> val;
				string op_string = op.pop();
				char oper[2];
				strcpy_s(oper, op_string.c_str());
				int ans = applyOperation(val, val1, oper[0]);
				values.push(to_string(ans));
			}
			// pop opening brace.
			if (!op.isEmpty())
				op.pop();
		}
		// Current character is an operator.
		else
		{
			while (!op.isEmpty() && precedence(op.top())>= precedence(ch))
			{
				string v = values.pop();
				string v1 = values.pop();
				stringstream temp(v1);
				int val1;
				temp >> val1;
				stringstream temp1(v);
				int val;
				temp1 >> val;
				string op_string = op.pop();
				char oper[2];
				strcpy_s(oper, op_string.c_str());
				int ans = applyOperation(val, val1, oper[0]);
				values.push(to_string(ans));
			}
			// Push current operator to 'op stack'.
			op.push(ch);
		}
	}

	// Entire expression has been parsed at this point, apply remaining ops to remaining values.
	while (!op.isEmpty()) {
		string v = values.pop();
		string v1 = values.pop();
		stringstream temp(v1);
		int val1;
		temp >> val1;
		stringstream temp1(v);
		int val;
		temp1 >> val;
		string op_string = op.pop();
		char oper[2];
		strcpy_s(oper, op_string.c_str());
		int ans = applyOperation(val, val1, oper[0]);
		values.push(to_string(ans));
	}

	string final_ans = values.pop();
	stringstream temp(final_ans);
	int result;
	temp >> result;
	// Top of 'values' contains result, return it.
	return result;
}
int Expression::evaluatePostfix()
{
	Stack stack;
	for (int i = 0; i<this->expression.length(); i++)
	{
		if (expression[i] == ' ')
			continue;
		// If the  character is an operand (i.e number),  
		// push it to the stack.
		if (isdigit(expression[i]))
		{
			string val = "";

			// There may be more than one
			// digits in number.
			while (i < this->expression.length() && isdigit(this->expression[i]))
			{
				val = val + expression[i];
				i++;
			}
			stack.push(val);
			i--;
		}

		// If the character is an operator, pop two elements from stack apply the operator  
		else
		{
			string v = stack.pop();
			string v1 = stack.pop();
			stringstream temp(v1);
			int val1;
			temp >> val1;
			stringstream temp1(v);
			int val;
			temp1 >> val;
			int ans = applyOperation(val, val1, expression[i]);
			stack.push(to_string(ans));
		}
	}
	string final_ans = stack.pop();
	stringstream temp(final_ans);
	int result;
	temp >> result;
	// Top of 'values' contains result, return it.
	return result;
}
int Expression::evaluatePrefix()
{
	Stack stack;
	for (int i = this->expression.length()-1;i>=0; i--)
	{
		if (expression[i] == ' ')
			continue;
		if (isdigit(expression[i]))
		{
			string val = "";

			// There may be more than one digits in number.
			while (i < this->expression.length() && isdigit(this->expression[i]))
			{
				val = val + expression[i];
				i--;
			}
			//reversing the string because digit is read from right to left
			reverse(val.begin(), val.end());
			stack.push(val);
			i++;
		}

		// If the scanned character is an operator, pop two  
		// elements from stack apply the operator  
		else
		{
			string v = stack.pop();
			string v1 = stack.pop();
			stringstream temp(v1);
			int val1;
			temp >> val1;
			stringstream temp1(v);
			int val;
			temp1 >> val;
			int ans = applyOperation(val1, val, expression[i]);
			stack.push(to_string(ans));
		}
	}
	string final_ans = stack.pop();
	stringstream temp(final_ans);
	int result;
	temp >> result;
	// Top of 'values' contains result, return it.
	return result;
}
int main()
{
	Expression E1;
	// infix = ((A-(B/C))*((A/K)-L))  ((20-(200/2))*((20/5)-50))
	// postfix = ABC/-AK/L-*  20 200 2 / - 20 5 / 50 - *
	//prefix = *-A/BC-/AKL * - 20 / 200 2- / 20 5 50 
	string expression;
	int opt,opt1;
	do
	{
		cout << "press 1 to convert expression\npress 2 to evalute expression\n"
			"press 3 to exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "press 1 for infix to postfix conversion\npress 2 for infix to prefix conversion\n"
				"press 3 for prefix to postfix conversion\npress 4 for prefix to infix conversion\n"
				"press 5 for postfix to infix conversion\npress 6 for postfix to prefix conversion\npress 7 to exit\n";
			cin >> opt1;
			cin.ignore();
			switch (opt1)
			{
			case 1:
				cout << "enter your infix expression = ";
				getline(cin, expression);
				E1.setExpression(expression, infix);
				E1.convertExpression(postfix);
				E1.Display();
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "enter your infix expression = ";
				getline(cin, expression);
				E1.setExpression(expression, infix);
				E1.convertExpression(prefix);
				E1.Display();
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "enter your prefix expression = ";
				getline(cin, expression);
				E1.setExpression(expression, prefix);
				E1.convertExpression(postfix);
				E1.Display();
				system("pause");
				system("cls");
				break;
			case 4:
				cout << "enter your prefix expression = ";
				getline(cin, expression);
				E1.setExpression(expression, prefix);
				E1.convertExpression(infix);
				E1.Display();
				system("pause");
				system("cls");
				break;
			case 5:
				cout << "enter your postfix expression = ";
				getline(cin, expression);
				E1.setExpression(expression, postfix);
				E1.convertExpression(infix);
				E1.Display();
				system("pause");
				system("cls");
				break;
			case 6:
				cout << "enter your postfix expression = ";
				getline(cin, expression);
				E1.setExpression(expression, postfix);
				E1.convertExpression(prefix);
				E1.Display();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				break;
			default:
				cout << "invald input!!!!\n";
				system("pause");
				system("cls");
			}
			break;
		case 2:
			system("cls");
			cout << "press 1 for infix evaluation\npress 2 for postfix evaluation\n"
				"press 3 for prefix evaluation\npress 4 to exit\n";
			cin >> opt1;
			cin.ignore();
			switch (opt1)
			{
			case 1:
				cout << "enter your infix expression with proper braces = ";
				getline(cin, expression);
				E1.setExpression(expression, infix);
				cout<<"result = "<<E1.evaluateExpression()<<endl<<endl;
				system("pause");
				system("cls");
				break;
			case 2:
				cout << "enter your postfix expression with proper spaces = ";
				getline(cin, expression);
				E1.setExpression(expression, postfix);
				cout << "result = " << E1.evaluateExpression() << endl << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				cout << "enter your prefix expression with proper spaces = ";
				getline(cin, expression);
				E1.setExpression(expression, prefix);
				cout << "result = " << E1.evaluateExpression() << endl << endl;
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				break;
			default:
				cout << "invald input!!!!\n";
				system("pause");
				system("cls");
			}
		case 3:
			break;
		default:
			cout << "invald input!!!!\n";
			system("pause");
			system("cls");
		}
	} while (opt != 3);

	return 0;
}