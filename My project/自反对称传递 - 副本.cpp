#include <iostream>
#include <string.h>
using namespace std;

const int LEN = 100;
bool  Reflexivity();   //自反性
bool  Symmetry();      //对称性
bool  Transmission();  //传递性
bool  Irreflexivity();  //反自反性
bool  Irsymmetry();    //反对称性
void  Warshall();       //Warshall算法

//定义全局变量
int num;
int relation_num;
int relation[LEN][LEN];
int A[LEN][LEN];

int main()
{
	int flag = 1;
	while (flag == 1)
	{
		cout << "请输入集合A元素的个数" << endl;
		cin >> num;
		while (num<1)
		{
			cout << "输入不合法，请重新输入" << endl;
			cin >> num;
		}
		cout << "请输入关系R元素的个数" << endl;
		cin >> relation_num;
		while (num<1)
		{
			cout << "输入不合法，请重新输入" << endl;
			cin >> num;
		}

		int tmp1, tmp2;
		memset(relation, 0, sizeof(relation));
		memset(A, 0, sizeof(A));
		cout << "请输入每一个序偶内的数" << endl;
		for (int i = 1; i <= relation_num; i++)
		{
			cin >> tmp1 >> tmp2;
			relation[tmp1][tmp2] = 1;
		}

		if (Reflexivity())
		{
			cout << "满足自反...";
		}
		else
		{
			cout << "不满足自反...";
		}
		cout << endl;

		if (Symmetry())
		{
			cout << "满足对称...";
		}
		else
		{
			cout << "不满足对称...";
		}
		cout << endl;

		if (Transmission())
		{
			cout << "满足传递...";
		}
		else
		{
			cout << "不满足传递...";
		}
		cout << endl;

		if (Irreflexivity())
		{
			cout << "满足反自反...";
		}
		else
		{
			cout << "不满足反自反...";
		}
		cout << endl;

		if (Irsymmetry())
		{
			cout << "满足反对称...";
		}
		else
		{
			cout << "不满足反对称...";
		}
		cout << endl;
		cout << "继续输入请按1，结束程序请按0" << endl;
		cin >> flag;

	}
	return 0;
}

bool  Reflexivity()  //自反性，对角线所有元素为1
{
	//  bool flag = false;
	for (int i = 1; i <= num; i++)
	{
		if (relation[i][i] != 1)
		{
			return false;
		}
	}
	return true;
}

bool  Symmetry()     //对称性，矩阵中每一个元素都要对称
{
	for (int i = 1; i <= num - 1; i++)
	{
		for (int j = i + 1; j <= num; j++)
		{
			if (relation[i][j] != relation[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

bool  Transmission()  //传递性
{
	Warshall();
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			if (A[i][j] != relation[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

bool  Irreflexivity()  //反自反性，对角线所有元素都为0
{
	for (int i = 1; i <= num; i++)
	{
		if (relation[i][i] == 1)
		{
			return false;
		}
	}
	return true;
}

bool  Irsymmetry()    //反对称性,只需要判断上半矩阵，且只需判断到倒数第二行
{
	for (int i = 1; i <= num - 1; i++)
	{
		for (int j = i + 1; j <= num; j++)
		{
			if (relation[i][j] == 1 && relation[j][i] == 1)
			{
				if (i != j)//这个可以不需要
				{
					return false;
				}
			}
		}
	}
	return true;
}

void  Warshall()       //Warshall算法,如果第i列有1，把第
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			A[i][j] = relation[i][j];
		}
	}
	for (int i = 1; i <= num; i++)//第i次迭代
	{
		for (int j = 1; j <= num; j++)//行号加一
		{
			if (A[j][i] == 1)//依次检查第i列，第i列有非零元素，记下该行
			{
				for (int k = 1; k <= num; k++)
				{
					A[j][k] = A[j][k] + A[i][k];//把第i行加到第J行
					if (A[j][k] >= 1)
					{
						A[j][k] = 1;//逻辑加法
					}
				}
			}
		}
	}

}
