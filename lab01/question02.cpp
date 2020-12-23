#include<iostream>
using namespace std;
//class for the matrix
class matrix3x3 {
	int** ptr;
	int row, col;
public:
	matrix3x3() { //default constructor 
		row = 3;
		col = 3;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			ptr[i] = new int[col];
		}
	}
	//input function for matrix

	void input()
	{
		
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << "enter the entry no.[" << i << "][" << j << "] = ";
				cin >> ptr[i][j];

			}
		}
		system("cls");//to clear screen after getting all inputs for a matrix
	}
	//additon function
	matrix3x3 add(matrix3x3 a)
	{
			matrix3x3 result;
			result.ptr = new int* [row];
			for (int i = 0; i < row; i++)
			{
				result.ptr[i] = new int[col];
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					result.ptr[i][j] = ptr[i][j] + a.ptr[i][j];
				}
			}
			return result;
	}
	matrix3x3 multiply(matrix3x3 a)
	{
		matrix3x3 result;
		for (int i = 0; i < result.row; i++)
		{
			for (int j = 0; j < result.col; j++)
			{
				result.ptr[i][j] = 0;
			}
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < a.col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					result.ptr[i][j] += ptr[i][k] * a.ptr[k][j];
				}
			}
		}
		return result;
	}
	///function for output
	void display()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (j != 0)
					cout << " , " << ptr[i][j];
				else
					cout << ptr[i][j];
			}
			cout << endl;
		}
	}
};

int main()
{
	matrix3x3 A[3]; 
	cout << "input data for first matrix\n";
	A[0].input();
	cout << "input data for second matrix\n";
	A[1].input();
	A[2] = A[0].add(A[1]);   //adding matrix A and B
	cout << "first matrix:" << endl;
	A[0].display();
	cout << "second matrix:" << endl;
	A[1].display();
	cout << "resultant matrix after adding first and second:" << endl;
	A[2].display();
	A[2] = A[0].multiply(A[1]);   //multiplying matrix A and B
	cout << "resultant matrix after multiplying first and second:" << endl;
	A[2].display();
}
