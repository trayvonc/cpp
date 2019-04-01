/*
#include <iostream> 
using namespace std;
#include <stdlib.h>
class Matrix
{
	int *m, row, col;
public:
	Matrix(const Matrix &);
	Matrix(int, int);
	Matrix();
	~Matrix();
	friend Matrix operator+( const Matrix &, const Matrix &);
	Matrix & operator=(const Matrix &);
	void disp();
};
Matrix::Matrix(const Matrix &r)
{
	if (r.m)
	{
		m = new int[r.row*r.col];
		col = r.col;
		row = r.row;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				*(m + i*col + j) = *(r.m + i*r.col + j);
	}
	else {
		col = 0;
		row = 0;
		m = 0;
	}

}
Matrix::Matrix()
{
	row = col = 0;
}
Matrix::Matrix(int r, int c)
{
	row = r; col = c;
	m = new int[row*col];
	cout << "请输入该矩阵元素:" << endl;
	for (int i = 0; i<row; i++)
		for (int j = 0; j<col; j++)
			cin >> m[i*col + j];
}
Matrix::~Matrix()
{
		delete[]m;
}


Matrix operator+( const Matrix &mat1, const Matrix &mat2)
{
	if (mat1.col != mat2.col || mat1.row != mat2.row)
	{
		cout << "program terminated!" << endl;
		exit(0);
	}
	else
	{
		Matrix mat3;
		mat3.row = mat1.row;
		mat3.col = mat1.col;
		mat3.m = new int[mat1.row*mat1.col];
			for (int i = 0; i < mat1.row; i++)
				for (int j = 0; j < mat1.col; j++)
					(*(mat3.m + i*mat3.col + j)) =((*(mat1.m + i*mat1.col + j))+(*(mat2.m + i*mat2.col + j)));
		return mat3;
	}
}
Matrix & Matrix::operator=(const Matrix &mat)
{
	this->m = new int[mat.row*mat.col];
	this->row = mat.row;
	this->col = mat.col;
	for (int i = 0; i<row; i++)
		for (int j = 0; j<col; j++)
			*(m + i*col + j) = *(mat.m + i*mat.col + j);
	return *this;
}
void Matrix::disp()
{
	for (int i = 0; i<row; i++)
	{
		cout << '\t';
		for (int j = 0; j<col; j++)
			cout << *(m + i*col + j) << '\t';
		cout << endl;
	}
}
int main()
{
	int row_a, col_a, row_b, col_b;
	cout << "请输入am矩阵的行数和列数:" << endl;
	cin >> row_a >> col_a;
	Matrix am(row_a, col_a);
	cout << "请输入bm矩阵的行数和列数:" << endl;
	cin >> row_b >> col_b;
	Matrix bm(row_b, col_b), cm;
	cout << "am:" << endl;
	am.disp();
	cout << "bm:" << endl;
	bm.disp();
	cm = am + bm;
	cout << "cm=am+bm:" << endl;
	cm.disp();
	am = bm;
	cout << "am=bm:" << endl;
	am.disp();
	return 0;
}
*/