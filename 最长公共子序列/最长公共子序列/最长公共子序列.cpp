// 最长公共子序列.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
using namespace std;
int const MaxLen = 50;

class LCS
{

public:
	LCS(int nx, int ny, char *x, char *y)
	{
		m = nx;
		n = ny;
		a = new char[m + 2];
		b = new char[n + 2];
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for (int i = 0; i < nx + 2; i++)
			a[i + 1] = x[i];
		for (int i = 0; i < ny + 2; i++)
			b[i + 1] = y[i];
		c = new int[MaxLen][MaxLen];
		s = new int[MaxLen][MaxLen];
		memset(c, 0, sizeof(c));
		memset(s, 0, sizeof(s));
	}
	int LCSLength();

	void CLCS()
	{
		CLCS(m, n);
	}

private:
	void CLCS(int i, int j);
	int(*c)[MaxLen], (*s)[MaxLen];
	int m, n;
	char *a, *b;
};

int LCS::LCSLength()
{
	for (int i = 1; i <= m; i++)
		c[i][0] = 0;
	for (int j = 1; j <= n; j++)
		c[0][j] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == b[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				s[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				s[i][j] = 2;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				s[i][j] = 3;
			}
		}
	}
	return c[m][n];
}

void LCS::CLCS(int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (s[i][j] == 1)
	{
		CLCS(i - 1, j - 1);
		cout << a[i];
	}
	else if (s[i][j] == 2)
		CLCS(i - 1, j);
	else
		CLCS(i, j - 1);
}

int main()
{
	int nx, ny;
	char *x = new char[MaxLen], *y = new char[MaxLen];
	cout << "请输入X (不含空格)" << endl;
	cin >> x;
	nx = strlen(x);
	cout << "请输入Y (不含空格)" << endl;
	cin >> y;
	ny = strlen(y);
	LCS lcs(nx, ny, x, y);
	cout << "X和Y最长公共子序列的长度为：" << lcs.LCSLength() << endl;
	cout << "该序列为" << endl;
	lcs.CLCS();
	cout << endl;
	delete[]x;
	delete[]y;
	system("pause");
	return 0;

}


