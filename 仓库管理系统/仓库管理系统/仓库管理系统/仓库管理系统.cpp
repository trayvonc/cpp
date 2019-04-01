#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
void newfiles(char b[]);
void changefile(char b[]);
void changefile2(char b[]);
void changeprize(char b[]);
void changeinfo(char b[]);
void cho1();
void cho2();
void cho3();
void cho4();
void cho5();
void cho6();
void cho7();
void cho8();
//void findfile(char s[]);
void findfile(double, int);
void findfile2(int);
char* decrypt(char* str, char *temp);
char* encrypt(char* str, char *temp);
int meum2(int);
int meum1();
//��Ʒ��
class Product
{
private:
	int year[3];
	int month[3];
	int day[3];
	int hour[3];
	int minute[3];
	int sec[3];
	char number[20];
	int innumber;
	int totalnumber;
	char name[20];
	char type[20];
	double inprize;
	double prize;
public:
	//���캯��
	Product(char n[] = "null", char nam[] = "null", char typ[] = "null", int iy = 2017, int imo = 11, int id = 20, int ih = 0, int imi = 0, int is = 0, int innum = 0, int tonum = 0, double ip = 0, double p = 0,  int dsy = 2011, int dsmo = 10, int dsd = 24, int dsh = 0, int dsmi = 0, int dss = 0, int dey = 2011, int demo = 10, int ded = 24, int deh = 0, int demi = 0, int des = 0)
	{
		year[0] = iy; month[0] = imo; day[0] = id; hour[0] = ih; minute[0] = imi; sec[0] = is; year[1] = dsy; month[1] = dsmo; day[1] = dsd; hour[1] = dsh; minute[1] = dsmi; sec[1] = dss; year[2] = dey; month[2] = demo; day[2] = ded; hour[2] = deh; minute[2] = demi; sec[2] = des;
		strcpy(number, n);
		innumber = innum;
		totalnumber = tonum;
		strcpy(name, nam);
		strcpy(type, typ);
		inprize = ip;
		prize = p;
	}
	//��ʾʱ��
	void timedisp(int x)
	{
		cout << year[x] << ".";
		cout << month[x] << ".";
		cout << day[x] << ",\t";
		cout << hour[x] << ":";
		cout << minute[x] << ":";
		cout << sec[x] << endl;
	}
	//�޸�������ʱ��
	void changetime(int y, int mon, int d, int h, int min, int s)
	{
		year[0] = y;
		month[0] = mon;
		day[0] = d;
		hour[0] = h;
		minute[0] = min;
		sec[0] = s;
	}
	//�޸����۸�
	void changeip(double ip)
	{
		inprize = ip;
	}
	//�޸��۸�
	void changeprize(double p)
	{
		prize = p;
	}
	//�޸�����
	void changename(char* n)
	{
		strcpy(name, n);
	}
	//�޸ķ���
	void changetype(char* n)
	{
		strcpy(type, n);
	}
	//��ʾ��Ʒ������Ϣ
	void disp()
	{
		if (!ifcode())
		{
			cout << "\t��Ʒ���\t" << number << endl;
			cout << "\t��Ʒ����\t" << name << endl;
			cout << "\t��Ʒ����\t" << type << endl;
			cout << "\t������ʱ��\t";
			timedisp(0);
			cout << "\t��������\t" << innumber << endl;
			cout << "\t�������\t" << totalnumber << endl;
			cout << "\t��Ʒ���۸�\t" << inprize << endl;
			cout << "\t��Ʒ�ۼ�\t" << prize << endl;
			cout << endl;
		}
	}
	//�������
	void inproduct(int innum)
	{
		SYSTEMTIME sysTime;
		ZeroMemory(&sysTime, sizeof(sysTime));
		innumber = innum;
		totalnumber += innum;
		GetLocalTime(&sysTime);
		changetime(sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	}
	//��������
	void outproduct(int outnum)
	{
		totalnumber -= outnum;
	}
	//��ȡ�˻�����
	char* getpw()
	{
		return name;
	}
	//�޸��˻�����
	void changepw(char pw[])
	{
		char temp[20];
		strcpy(name, ::encrypt(pw, temp));
	}
	//������Ѽ�麯��
	bool checknum(int alarmnumber)
	{
		if (totalnumber<alarmnumber)
			return true;
		else
			return false;
	}
	//���ʱ��Ƚ�
	bool checktime(int y, int mon, int d)
	{
		if ((year[0] == y) && (month[0] == mon) && (day[0] == d))
			return true;
		else
			return false;

	}
	//���Ҷ�Ӧ��Ϣ��Ʒ������ַ����Ƚ�
	bool find(char x[], int w)
	{
		switch (w)
		{
		case 1:if (strcmp(number, x) == 0)
			return true;
			   else
				   return false;
		case 2:if (strcmp(name, x) == 0)
			return true;
			   else
				   return false;
		case 3:if (strcmp(type, x) == 0)
			return true;
			   else
				   return false;
		default: return false;
		}
	}
	//���Ҷ�Ӧ��Ϣ��Ʒ��������ֱȽ�
	bool find(double x, int w)
	{
		switch (w)
		{
		case 1:if (innumber == x)
			return true;
			   else
				   return false;
		case 2:if (totalnumber == x)
			return true;
			   else
				   return false;
		case 3:if (inprize == x)
			return true;
			   else
				   return false;
		case 4:if (prize == x)
			return true;
			   else
				   return false;
		default: return false;
		}
	}
	//�ж϶����Ƿ�Ϊ�˻�
	bool ifcode()
	{
		if (strcmp(type, "guanliyuan") == 0)
			return true;
		else
			return false;
	}
	//��ʾ�˻���Ϣ
	void mimadisp()
	{
		char tempac[20], temppw[20];
		cout << "\t�˻���\t" << ::decrypt(number, tempac) << endl;
		cout << "\t����\t" << ::decrypt(name, temppw) << endl;
		cout << "\t����/�޸�ʱ��\t";
		timedisp(0);
		cout << endl;
	}
	//��֤�û���������
	bool checkcode(char ac[], char pw[])
	{
		char tempac[20], temppw[20];
		if ((strcmp(ac, decrypt(number, tempac)) == 0) && (strcmp(pw, decrypt(name, temppw)) == 0))
			return true;
		else
			return false;
	}
};
//�����С
const int SZ = sizeof(Product);
//�����²�Ʒ
void newfiles(char b[])
{
	SYSTEMTIME sysTime;
	ZeroMemory(&sysTime, sizeof(sysTime));
	char name[20], type[20];
	int innumber;
	double inprize, prize, discount;
	int year[3], month[3], day[3], hour[3], minute[3], sec[3];
	cout << "\t�²�Ʒ���" << endl;
	cout << "\t�������Ʒ����:";
	cin >> name;
	while (1)
	{
		cout << "\t�������������:";
		cin >> type;
		if (strcmp(type, "guanliyuan") == 0)
			cout << "\t���಻��Ϊguanliyuan." << endl;
		else
			break;
	}
	GetLocalTime(&sysTime);
	year[0] = sysTime.wYear;
	month[0] = sysTime.wMonth;
	day[0] = sysTime.wDay;
	hour[0] = sysTime.wHour;
	minute[0] = sysTime.wMinute;
	sec[0] = sysTime.wSecond;
	cout << "\t�������Ʒ�������:";
	cin >> innumber;
	cout << "\t�������Ʒ���۸�:";
	cin >> inprize;
	cout << "\t�������Ʒ�ۼ�:";
	cin >> prize;
	Product a(b, name, type, year[0], month[0], day[0], hour[0], minute[0], sec[0], innumber, innumber, inprize, prize, year[1], month[1], day[1], hour[1], minute[1], sec[1], year[2], month[2], day[2], hour[2], minute[2], sec[2]);
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	file.seekp(0, ios::end);
	file.write((char*)&a, SZ);
	file.close();
}
//������Ʒ�Ƿ��Ѵ��� ���������
void changefile(char b[])
{
	Product a;
	fstream file;
	int innumber;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false;
	while (!file.eof() && !fd)
	{
		file.read((char*)&a, SZ);
		if (fd = a.find(b, 1) && (!a.ifcode()))
		{
			cout << "\t��Ʒ���м�¼." << endl;
			a.disp();
			cout << "\t�������������:";
			cin >> innumber;
			a.inproduct(innumber);
			file.seekp(file.tellp(), ios::beg);
			file.seekp(-SZ, ios::cur);
			file.write((char*)&a, sizeof(a));
		}
	}
	file.close();
	if (!fd)
	{
		newfiles(b);
	}
}
//�������˻�
void newaccount(char ac[])
{
	SYSTEMTIME sysTime;
	ZeroMemory(&sysTime, sizeof(sysTime));
	char pw[20], type[20], tempac[20], temppw[20];
	int year, month, day, hour, minute, sec;
	cout << "\t���˻�." << endl;
	cout << "\t����������:";
	cin >> pw;
	strcpy(type, "guanliyuan");
	GetLocalTime(&sysTime);
	year = sysTime.wYear;
	month = sysTime.wMonth;
	day = sysTime.wDay;
	hour = sysTime.wHour;
	minute = sysTime.wMinute;
	sec = sysTime.wSecond;
	Product a(encrypt(ac, tempac), encrypt(pw, temppw), type, year, month, day, hour, minute, sec);
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	file.seekp(0, ios::end);
	a.mimadisp();
	file.write((char*)&a, SZ);
	file.close();
}
//�����˻��Ƿ��Ѵ��� �������޸�����
void changepasswords(char s[])
{
	SYSTEMTIME sysTime;
	ZeroMemory(&sysTime, sizeof(sysTime));
	Product a;
	fstream file;
	char opw[20], npw[20], tempac[20], temppw[20];
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false;
	while (!file.eof() && !fd)
	{
		file.read((char*)&a, SZ);
		if (fd = (a.ifcode() && a.find(encrypt(s, tempac), 1)))
		{
			cout << "\t�˻��Ѵ���." << endl;
			cout << "\t�����뵱ǰ�˻�����:";
			cin >> opw;
			if (strcmp(decrypt(a.getpw(), temppw), opw) == 0)
			{
				cout << "\t������ȷ." << endl; 
				cout << "\t������������:";
				cin >> npw;
				a.changepw(npw);
				file.seekp(file.tellp(), ios::beg);
				file.seekp(-SZ, ios::cur);
				file.write((char*)&a, sizeof(a));
				GetLocalTime(&sysTime);
				a.changetime(sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
			}
			else
				cout << "\t�������." << endl;
		}
	}
	file.close();
	if (!fd)
	{
		newaccount(s);
	}
}
//���ַ���ѯ��Ʒ����
void findfile(char s[], int x)
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false, fdt = false;
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (a.find(s, x) && (!a.ifcode()))
		{
			fd = true;
			if (fd && !fdt)
			{
				cout << "\t��Ʒ��¼���ҵ�." << endl;
				fdt = false;
			}
			if (file.eof())
				break;
			a.disp();
		}
	}
	if (!fd)
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	file.close();
}
//�����ݲ��Ҳ�Ʒ����
void findfile(double s, int x)
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false, fdt = false;
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (a.find(s, x) && (!a.ifcode()))
		{
			fd = true;
			if (fd && !fdt)
			{
				cout << "\t��Ʒ��¼���ҵ�." << endl;
				fdt = false;
			}
			if (file.eof())
				break;
			a.disp();
		}
	}
	if (!fd)
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	file.close();
}
//��ʱ����Ҳ�Ʒ����
void findtime(int y, int m, int d)
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false, fdt = false;
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (a.checktime(y, m, d) && (!a.ifcode()))
		{
			fd = true;
			if (fd && !fdt)
			{
				cout << "\t��Ʒ��¼���ҵ�." << endl;
				fdt = false;
			}
			if (file.eof())
				break;
			a.disp();
		}
	}
	if (!fd)
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	file.close();
}
//���ҿ�治�����
void findfile2(int s)
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false, fdt = false;
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (file.eof())
			break;
		if (a.checknum(s) && (!a.ifcode()))
		{
			fd = true;
			if (fd && !fdt)
			{
				cout << "\t��Ʒ��¼���ҵ�." << endl;
				cout << "\t��ǰ���������" << s << "�Ļ���:" << endl;
				fd = true;
			}
			a.disp();

		}
	}
	if (!fd)
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	file.close();
}
//��������
void changefile2(char b[])
{
	Product a;
	fstream file;
	int outnumber;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false;
	while (!file.eof() && !fd)
	{
		file.read((char*)&a, SZ);
		if (fd = a.find(b, 1) && (!a.ifcode()))
		{
			cout << "\t��Ʒ���м�¼." << endl;
			a.disp();
			cout << "\t�������������:";
			cin >> outnumber;
			a.outproduct(outnumber);
			file.seekp(file.tellp(), ios::beg);
			file.seekp(-SZ, ios::cur);
			file.write((char*)&a, sizeof(a));
		}
	}
	file.close();
	if (!fd)
	{
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	}
}

//�޸ļ۸�
void changeprize(char b[])
{
	Product a;
	fstream file;
	double ip, prize, disc;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false;
	while (!file.eof() && !fd)
	{
		file.read((char*)&a, SZ);
		if (fd = a.find(b, 1) && (!a.ifcode()))
		{
			cout << "\t��Ʒ���м�¼." << endl;
			a.disp();
			cout << "\t�������µ����۸�:";
			cin >> ip;
			cout << "\t�������µ��۸�:";
			cin >> prize;
			a.changeip(ip);
			a.changeprize(prize);
			file.seekp(file.tellp(), ios::beg);
			file.seekp(-SZ, ios::cur);
			file.write((char*)&a, sizeof(a));
		}
	}
	file.close();
	if (!fd)
	{
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	}
}
//�޸��������
void changeinfo(char b[])
{
	Product a;
	fstream file;
	char n[20], t[20];
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	bool fd = false;
	while (!file.eof() && !fd)
	{
		file.read((char*)&a, SZ);
		if (fd = a.find(b, 1) && (!a.ifcode()))
		{
			cout << "\t��Ʒ���м�¼." << endl;
			a.disp();
			cout << "\t�������µ�����:";
			cin >> n;
			cout << "\t�������µ����:";
			while (1)
			{
				cout << "\t�������������:";
				cin >> t;
				if (strcmp(t, "guanliyuan") == 0)
					cout << "\t���಻��Ϊguanliyuan." << endl;
				else
					break;
			}
			a.changename(n);
			a.changetype(t);
			file.seekp(file.tellp(), ios::beg);
			file.seekp(-SZ, ios::cur);
			file.write((char*)&a, sizeof(a));
		}
	}
	file.close();
	if (!fd)
	{
		cout << "�Ҳ�����Ӧ�Ĳ�Ʒ." << endl;
	}
}
//һ���˵�
int meum1()
{
	int numx;
	cout << "\t+--------------------------------------------------------------+\n";
	cout << "\t\t1.�������" << endl;
	cout << "\t\t2.����" << endl;
	cout << "\t\t3.������ѯ" << endl;
	cout << "\t\t4.��Ʒ��ѯ" << endl;
	cout << "\t\t5.����嵥" << endl;
	cout << "\t\t6.�޸���Ϣ" << endl;
	cout << "\t\t7.�����˻�/�޸�����" << endl;
	cout << "\t\t8.�˻���Ϣ��ѯ" << endl;
	cout << "\t\t9.�˳�ϵͳ" << endl;
	cout << "\t\t������ѡ������:";
	cin >> numx;
	return numx;
}
//һ���˵�ѡ��1
void cho1()
{
	char numberx[20];
	cout << "\t�������Ʒ���:";
	cin >> numberx;
	changefile(numberx);
}
//һ���˵�ѡ��2
void cho2()
{
	char numberx[20];
	cout << "\t�������Ʒ���:";
	cin >> numberx;
	changefile2(numberx);
}
//һ���˵�ѡ��3
void cho3()
{
	int anum;
	cout << "\t������������Ҳ�Ʒ��ʹ����:";
	cin >> anum;
	findfile2(anum);
}
//һ���˵�ѡ��4
void cho4()
{
	char a[20];
	double p;
	int chnum;
	int n = 1;
	int year, month, day;
	while (n)
	{
		cout << "\t+--------------------------------------------------------------+\n";
		cout << "\t\t1.����Ų�ѯ\n";
		cout << "\t\t2.�����Ʋ�ѯ\n";
		cout << "\t\t3.�������ѯ\n";
		cout << "\t\t4.������������ѯ\n";
		cout << "\t\t5.���������ѯ\n";
		cout << "\t\t6.�����۸��ѯ\n";
		cout << "\t\t7.���۸��ѯ\n";
		cout << "\t\t8.��������ʱ���ѯ\n";
		cout << "\t\t9.�����ϼ��˵�\n";
		cout << "\t\t������ѡ������:";
		cin >> chnum;
		//�����˵��ж�
		switch (chnum)
		{
		case 1:cout << "\t�������Ʒ���:";
			cin >> a;
			findfile(a, 1);
			break;
		case 2:cout << "\t�������Ʒ����:";
			cin >> a;
			findfile(a, 2);
			break;
		case 3:cout << "\t�������Ʒ����:";
			cin >> a;
			findfile(a, 3);
			break;
		case 4:cout << "\t��������������:";
			cin >> p;
			findfile(p, 1);
			break;
		case 5:cout << "\t���������:";
			cin >> p;
			findfile(p, 2);
			break;
		case 6:cout << "\t���������۸�:";
			cin >> p;
			findfile(p, 3);
			break;
		case 7:cout << "\t�������ۼ�:";
			cin >> p;
			findfile(p, 4);
			break;
		case 8:cout << "\t��������������:(��ʽ:XXXX.XX.XX)";
			cin >> year;
			cin.ignore();
			cin >> month;
			cin.ignore();
			cin >> day;
			findtime(year, month, day);
			break;
		case 9:n = 0;
			break;
		default:break;
		}
	}
}
//һ���˵�ѡ��5
void cho5()
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (file.eof())
			break;
		a.disp();
	}
}
//һ���˵�ѡ��6
void cho6()
{
	char a[20];
	int chnum;
	int n = 1;
	while (n)
	{
		cout << "\t+--------------------------------------------------------------+\n";
		cout << "\t\t1.�޸�����&����\n";
        cout << "\t\t2.�޸����۸�&�۸�\n";
		cout << "\t\t3.�����ϼ��˵�\n";
		cout << "\t\t������ѡ������:";
		cin >> chnum;
		//�����˵��ж�
		switch (chnum)
		{
		case 1:cout << "\t�������Ʒ���:";
			cin >> a;
			changeinfo(a);
			break;
        case 2:cout << "\t�������Ʒ���:";
            cin>>a;
            changeprize(a);
            break;
		case 3:n = 0;
			break;
		default:break;
		}
	}
}
//һ���˵�ѡ��7
void cho7()
{
	char ac[20];
	cout << "\t�������˻���:";
	cin >> ac;
	changepasswords(ac);
}
//һ���˵�ѡ��8
void cho8()
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (file.eof())
			break;
		if (a.ifcode())
			a.mimadisp();
	}
}
//һ���˵��ж�
int meum2(int ch)
{
	int num = 0;
	switch (ch)
	{
	case 1:
		cho1();
		break;
	case 2:
		cho2();
		break;
	case 3:
		cho3();
		break;
	case 4:
		cho4();
		break;
	case 5:
		cho5();
		break;
	case 6:
		cho6();
		break;
	case 7:
		cho7();
		break;
	case 8:
		cho8();
		break;
	case 9:
		exit(1);
	default:
		break;
	}
	return num;
}
//�ַ������ܺ���
char* encrypt(char* str, char *temp)
{
	strcpy(temp,str);
	char* p = temp;
	int i = 0;
	while (*p != '\0')
		*p++ ^= i++;//������λ���
	return temp;
}
//�ַ������ܺ���
char* decrypt(char* str, char *temp)
{
	strcpy(temp,str);
	char* p = temp;
	int i = 0;
	while (*p != '\0')
		*p++ ^= i++;
	return temp;
}
//��֤�û���������
bool checkac(char ac[], char pw[])
{
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (a.ifcode())
		{
			if (a.checkcode(ac, pw))
				return true;
		}
	}
	return false;
}
int main()
{
	int ch1 = 0;
	bool ic = false;
	int n = 0;
	char ac[20], pw[20];
	cout << "\t+--------------------��ӭ�����ֿ��Ʒ����ϵͳ------------------+" << endl << endl;
	Product a;
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	while (!file.eof())
	{
		file.read((char*)&a, SZ);
		if (a.ifcode())
			ic = true;
	}
	if (!ic)
		cout << "\t\t�뼰ʱ��������Ա�˻�!" << endl;
	else
		while (n<3)
		{
			cout << "\t�������˻���:";
			cin >> ac;
			cout << "\t����������:";
			cin >> pw;
			if (checkac(ac, pw))
				break;
			n++;
		}
	if (n == 3)
	{
		cout << "\t������󳬹�����,ǿ���˳�!" << endl;
		exit(1);
	}
	while (1)
	{
		ch1 = meum1();
		meum2(ch1);
		if (!ch1)
			continue;
	}
}
