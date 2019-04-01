#include <iostream>
#include <string.h>
using namespace std;

const int LEN = 100;
bool  Reflexivity();   //�Է���
bool  Symmetry();      //�Գ���
bool  Transmission();  //������
bool  Irreflexivity();  //���Է���
bool  Irsymmetry();    //���Գ���
void  Warshall();       //Warshall�㷨

//����ȫ�ֱ���
int num;
int relation_num;
int relation[LEN][LEN];
int A[LEN][LEN];

int main()
{
	int flag = 1;
	while (flag == 1)
	{
		cout << "�����뼯��AԪ�صĸ���" << endl;
		cin >> num;
		while (num<1)
		{
			cout << "���벻�Ϸ�������������" << endl;
			cin >> num;
		}
		cout << "�������ϵRԪ�صĸ���" << endl;
		cin >> relation_num;
		while (num<1)
		{
			cout << "���벻�Ϸ�������������" << endl;
			cin >> num;
		}

		int tmp1, tmp2;
		memset(relation, 0, sizeof(relation));
		memset(A, 0, sizeof(A));
		cout << "������ÿһ����ż�ڵ���" << endl;
		for (int i = 1; i <= relation_num; i++)
		{
			cin >> tmp1 >> tmp2;
			relation[tmp1][tmp2] = 1;
		}

		if (Reflexivity())
		{
			cout << "�����Է�...";
		}
		else
		{
			cout << "�������Է�...";
		}
		cout << endl;

		if (Symmetry())
		{
			cout << "����Գ�...";
		}
		else
		{
			cout << "������Գ�...";
		}
		cout << endl;

		if (Transmission())
		{
			cout << "���㴫��...";
		}
		else
		{
			cout << "�����㴫��...";
		}
		cout << endl;

		if (Irreflexivity())
		{
			cout << "���㷴�Է�...";
		}
		else
		{
			cout << "�����㷴�Է�...";
		}
		cout << endl;

		if (Irsymmetry())
		{
			cout << "���㷴�Գ�...";
		}
		else
		{
			cout << "�����㷴�Գ�...";
		}
		cout << endl;
		cout << "���������밴1�����������밴0" << endl;
		cin >> flag;

	}
	return 0;
}

bool  Reflexivity()  //�Է��ԣ��Խ�������Ԫ��Ϊ1
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

bool  Symmetry()     //�Գ��ԣ�������ÿһ��Ԫ�ض�Ҫ�Գ�
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

bool  Transmission()  //������
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

bool  Irreflexivity()  //���Է��ԣ��Խ�������Ԫ�ض�Ϊ0
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

bool  Irsymmetry()    //���Գ���,ֻ��Ҫ�ж��ϰ������ֻ���жϵ������ڶ���
{
	for (int i = 1; i <= num - 1; i++)
	{
		for (int j = i + 1; j <= num; j++)
		{
			if (relation[i][j] == 1 && relation[j][i] == 1)
			{
				if (i != j)//������Բ���Ҫ
				{
					return false;
				}
			}
		}
	}
	return true;
}

void  Warshall()       //Warshall�㷨,�����i����1���ѵ�
{
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= num; j++)
		{
			A[i][j] = relation[i][j];
		}
	}
	for (int i = 1; i <= num; i++)//��i�ε���
	{
		for (int j = 1; j <= num; j++)//�кż�һ
		{
			if (A[j][i] == 1)//���μ���i�У���i���з���Ԫ�أ����¸���
			{
				for (int k = 1; k <= num; k++)
				{
					A[j][k] = A[j][k] + A[i][k];//�ѵ�i�мӵ���J��
					if (A[j][k] >= 1)
					{
						A[j][k] = 1;//�߼��ӷ�
					}
				}
			}
		}
	}

}
