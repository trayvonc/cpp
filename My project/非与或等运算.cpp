/*
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#include "math.h"
#define N 50
void panduan(int b[N], int f);
int tkh(char sz[N], char ccu[N], int icu[N], int h0);//ccu存字母，icu存真值指派，sz式子
int fkh(char sz[N], char ccu[N], int icu[N], int h0);
int main()
{
	int i1, i2, d = 1, icu[N], kh = 0, jg, j = 0, h0;//jg结果，j和h0是变量个数,kh括号
	int bj = 0, hq[N], h = 0, x = 0, xq[N];//hq合取(h数量），xq析取（x数量）
	char sz[N], ccu[N], sz0[N], s;
	hq[0] = -1;
	xq[0] = -1;
	printf("***************************************\n");
	printf("**               实验一              **\n");
	printf("**              用!表示非            **\n");
	printf("**              用&表示与            **\n");
	printf("**              用|表示或            **\n");
	printf("**             用^表示蕴含           **\n");
	printf("**            用~表示双条件          **\n");
	printf("***************************************\n");
	printf("请输入一个合法的命题公式:\n");
	gets_s(sz);
	strcpy(sz0, sz);
	for (i1 = 0; i1<strlen(sz); i1++)
	{
		if (sz[i1] == ')' || sz[i1] == '(')
			kh++;                                   //括号的数量
		if (sz[i1] >= 'a' && sz[i1] <= 'z' || sz[i1] >= 'A' && sz[i1] <= 'Z')
		{
			for (i2 = 0; i2<j; i2++)
				if (ccu[i2] == sz[i1])
					d = 0;
			if (d == 1)
			{
				ccu[j] = sz[i1];
				j++;                                  //变量个数
			}
			d = 1;
		}
	}
	printf("\n该式子中的变量个数为：%d\n", j);
	h0 = j;
	printf("\n输出真值表如下：\n \n");
	for (i1 = 0; i1<h0; i1++)
		printf(" %c ", ccu[i1]);
	printf(" ");
	puts(sz);
	printf("\n");
	for (i1 = 0; i1<j; i1++)
		icu[i1] = 0;
	for (i2 = 0; i2<j; i2++)
		printf(" %d ", icu[i2]);
	jg = tkh(sz, ccu, icu, h0);
	if (jg == 0)
		hq[h++] = bj;
	else
		xq[x++] = bj;
	printf("    %d\n", jg);
	strcpy(sz, sz0);
	for (i1 = 0; i1<(int)pow(2, j) - 1; i1++)
	{
		++bj;
		panduan(icu, j - 1);
		jg = tkh(sz, ccu, icu, h0);
		if (jg == 0)
			hq[h++] = bj;
		else
			xq[x++] = bj;
		strcpy(sz, sz0);
		for (i2 = 0; i2<j; i2++)
			printf(" %d ", icu[i2]);
		printf("    %d\n", jg);
	}
	if (hq[0] == -1)
		printf("\n该命题公式不存在主合取范式。\n");
	else
	{
		printf("\n该命题公式的主合取范式：\n\t");
		for (i1 = 0; i1<h; i1++)
		{
			if (i1>0)
				printf("/\\");
			printf("M(%d)", hq[i1]);
		}
	}
	if (xq[0] == -1)
		printf("\n该命题公式不存在主析取范式。\n");
	else
	{
		printf("\n\n该命题公式的主析取范式：\n\t");
		for (i1 = 0; i1<x; i1++)
		{
			if (i1>0)
				printf("\\/");
			printf("m(%d)", xq[i1]);
		}
	}
	printf("\n");
	printf("\n欢迎下次再次使用！\n ");
	//getch();
}
void panduan(int b[N], int f)
{
	int i;
	i = f;
	if (b[f] == 0)
		b[f] = 1;
	else
	{
		b[f] = 0;
		panduan(b, --i);
	}
}
int tkh(char sz[N], char ccu[N], int icu[N], int h0)//提取
{
	int i, j, h, s, kh = 0, wz[N], a;//wz括号的位置，ckh对应位置括号的类型
	char xs1[N], ckh[N];
	s = strlen(sz);
	for (i = 0; i<s; i++)
		if (sz[i] == '(' || sz[i] == ')')
		{
			wz[kh] = i;
			ckh[kh] = sz[i];
			kh++;
		}
	if (kh == 0)
		return fkh(sz, ccu, icu, h0);
	else
	{
        for (i = 0; i<kh; i++)
			if (ckh[i] == ')')
				break;
		for (j = wz[i - 1] + 1, h = 0; j<wz[i]; j++, h++)
			xs1[h] = sz[j];                               //xs小式，即括号之间的部分
		xs1[h] = '\0';
		a = fkh(xs1, ccu, icu, h0);
		if (a == 1)
			sz[wz[i - 1]] = 1;
		else
			sz[wz[i - 1]] = -2;
		for (j = wz[i - 1] + 1; j<s + wz[i - 1] - wz[i]; j++)
			sz[j] = sz[j + wz[i] - wz[i - 1]];
		sz[j] = '\0';
		return tkh(sz, ccu, icu, h0);
	}
}
int fkh(char sz[N], char ccu[N], int icu[N], int h0)//运算
{
	int i, h = 0, j = 0, j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, i1, i2, p1 = -1, p2 = -1, s;
	char dt[N];
	s = strlen(sz);
	if (s == 1)
		if (sz[0] == -2)
			return 0;
		else
			return 1;
	else
	{
		for (i = 0; i<s - j; i++)
			if (sz[i] == '!')
			{
				for (i1 = 0; i1<h0; i1++)
					if (sz[i + 1] == ccu[i1])
						p1 = icu[i1];
				if (sz[i + 1] == -2)
					p1 = 0;
				if (p1 == -1)
					p1 = sz[i + 1];
				dt[j + 2] = !p1;
				sz[i] = j + 2;
				j++;
				p1 = 0;
				for (i1 = i + 1; i1<s - j; i1++)
					sz[i1] = sz[i1 + 1];
			}
		p1 = -1;
		j1 = j;
		for (i = 0; i<s - j1 - 2 * j2; i++)
			if (sz[i] == '&')
			{
				for (i1 = 0; i1<h0; i1++)
				{
					if (sz[i - 1] == ccu[i1])
						p1 = icu[i1];
					if (sz[i + 1] == ccu[i1])
						p2 = icu[i1];
				}
				for (i2 = 2; i2<j + 2; i2++)
				{
					if (sz[i - 1] == i2)
						p1 = dt[i2];
					if (sz[i + 1] == i2)
						p2 = dt[i2];
				}
				if (sz[i - 1] == -2)
					p1 = 0;
				if (sz[i + 1] == -2)
					p2 = 0;
				if (p1 == -1)
					p1 = (int)(sz[i - 1]);
				if (p2 == -1)
					p2 = (int)(sz[i + 1]);
				dt[j + 2] = p1 && p2;
				sz[i - 1] = j + 2;
				j++;
				j2++;
				p1 = -1;
				p2 = -1;
				for (i1 = i; i1<s - j1 - 2 * j2; i1++)
					sz[i1] = sz[i1 + 2];
				i = i - 1;
			}
		for (i = 0; i<s - j1 - 2 * j2 - 2 * j3; i++)
			if (sz[i] == '|')
			{
				for (i1 = 0; i1<h0; i1++)
				{
			    if (sz[i - 1] == ccu[i1])
						if (sz[i + 1] == ccu[i1])
							p2 = icu[i1];
				}
				for (i2 = 2; i2<j + 2; i2++)
				{
					if (sz[i - 1] == i2)
						p1 = dt[i2];
					if (sz[i + 1] == i2)
						p2 = dt[i2];
				}
				if (sz[i - 1] == -2)
					p1 = 0;
				if (sz[i + 1] == -2)
					p2 = 0;
				if (p1 == -1)
					p1 = sz[i - 1];
				if (p2 == -1)
					p2 = sz[i + 1];
				dt[j + 2] = p1 || p2;
				sz[i - 1] = j + 2;
				j++;
				j3++;
				p1 = -1;
				p2 = -1;
				for (i1 = i; i1<s - j1 - 2 * j2 - 2 * j3; i1++)
					sz[i1] = sz[i1 + 2];
				i--;
			}
		for (i = 0; i<s - j1 - 2 * j2 - 2 * j3 - 2 * j4; i++)
			if (sz[i] == '^')
			{
				for (i1 = 0; i1<h0; i1++)
				{
					if (sz[i - 1] == ccu[i1])
						p1 = icu[i1];
					if (sz[i + 1] == ccu[i1])
						p2 = icu[i1];
				}
				for (i2 = 2; i2<j + 2; i2++)
				{
					if (sz[i - 1] == i2)
						p1 = dt[i2];
					if (sz[i + 1] == i2)
						p2 = dt[i2];
				}
				if (sz[i - 1] == -2)
					p1 = 0;
				if (sz[i + 1] == -2)
					p2 = 0;
				if (p1 == -1)
					p1 = sz[i - 1];
				if (p2 == -1)
					p2 = sz[i + 1];
				dt[j + 2] = !p1 || p2;
				sz[i - 1] = j + 2;
				j++;
				j4++;
				p1 = -1;
				p2 = -1;
				for (i1 = i; i1<s - j1 - 2 * j2 - 2 * j3 - 2 * j4; i1++)
					sz[i1] = sz[i1 + 2];
				i--;
			}
		for (i = 0; i<s - j1 - 2 * j2 - 2 * j3 - 2 * j4 - 2 * j5; i++)
			if (sz[i] == '~')
			{
				for (i1 = 0; i1<h0; i1++)
				{
					if (sz[i - 1] == ccu[i1])
						p1 = icu[i1];
					if (sz[i + 1] == ccu[i1])
						p2 = icu[i1];
				}
				for (i2 = 2; i2<j + 2; i2++)
				{
					if (sz[i - 1] == i2)
						p1 = dt[i2];
					if (sz[i + 1] == i2)
						p2 = dt[i2];
				}
				if (sz[i - 1] == -2)
					p1 = 0;
				if (sz[i + 1] == -2)
					p2 = 0;
				if (p1 == -1)
					p1 = sz[i - 1];
				if (p2 == -1)
					p2 = sz[i + 1];
				dt[j + 2] = (!p1 || p2) && (!p2 || p1);
				sz[i - 1] = j + 2;
				j++;
				j5++;
				p1 = -1;
				p2 = -1;
				for (i1 = i; i1<s - j1 - 2 * j2 - 2 * j3 - 2 * j4 - 2 * j5; i1++)
					sz[i1] = sz[i1 + 2];
				i--;
			}
		return dt[j + 1];
	}
}
*/

