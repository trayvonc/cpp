// 矩阵连乘.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stdlib.h>
using namespace std;
void MatrixChain(int n, int *p, int **m, int **s)
{
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	for (int r = 2; r <= n; r++)
		for (int i = 1; i <= n - r + 1; i++)
		{
			int j = i + r - 1;
			m[i][j] = m[i + 1][j] + p[i] * p[i + 1] * p[j + 1];  	//省略了m[i][i]=0项
			s[i][j] = i;
			for (int k = i + 1; k<j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (t<m[i][j])
				{
					m[i][j] = t;
					cout << "更新m[" << i << "][" << j << "]的值为：" << t << endl;
					s[i][j] = k;
					cout << "更新s[" << i << "][" << j << "]的值为：" << k << endl;
				}
			}
			cout << "最终求出：m[" << i << "][" << j << "]的值为：" << m[i][j] << endl;
		}
}
void Traceback(int i, int j, int **s)
{
	if (i == j) { cout << 'A' << i << ' '; return; }
	if (i<s[i][j]) cout << '(';
	Traceback(i, s[i][j], s);
	if (i<s[i][j]) cout << ')';
	if (s[i][j] + 1<j) cout << '(';
	Traceback(s[i][j] + 1, j, s);
	if (s[i][j] + 1<j) cout << ')';
}
int MatrixChain::LookupChain(int i, int j)
{
	if (m[i][j] > 0)return m[i][j];
	if (i == j)return 0;
	int u = LookupChain(i + 1, j) + p[i] * p[i + 1] * p[j + 1];
	s[i][j] = i;
	for (int k = i + 1; k < j; k++) {
		int t = LookupChain(i, k) + LookupChain(k + 1, j) + p[i] * p[k + 1] * p[j + 1];
		if (t < u) {
			u = t; s[i][j] = k;
		}

	}
	m[i][j] = u; return u;
}
int MatrixChain::LookupChain()
{
	return LookupChain(0, n - 1);
}

int main()
{
	return 0;
}

