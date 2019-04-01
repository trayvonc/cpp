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
//产品类
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
	//构造函数
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
	//显示时间
	void timedisp(int x)
	{
		cout << year[x] << ".";
		cout << month[x] << ".";
		cout << day[x] << ",\t";
		cout << hour[x] << ":";
		cout << minute[x] << ":";
		cout << sec[x] << endl;
	}
	//修改最近入货时间
	void changetime(int y, int mon, int d, int h, int min, int s)
	{
		year[0] = y;
		month[0] = mon;
		day[0] = d;
		hour[0] = h;
		minute[0] = min;
		sec[0] = s;
	}
	//修改入库价格
	void changeip(double ip)
	{
		inprize = ip;
	}
	//修改售格
	void changeprize(double p)
	{
		prize = p;
	}
	//修改名字
	void changename(char* n)
	{
		strcpy(name, n);
	}
	//修改分类
	void changetype(char* n)
	{
		strcpy(type, n);
	}
	//显示产品对象信息
	void disp()
	{
		if (!ifcode())
		{
			cout << "\t产品编号\t" << number << endl;
			cout << "\t产品名称\t" << name << endl;
			cout << "\t货品种类\t" << type << endl;
			cout << "\t最近入库时间\t";
			timedisp(0);
			cout << "\t最近入库量\t" << innumber << endl;
			cout << "\t库存总量\t" << totalnumber << endl;
			cout << "\t产品入库价格\t" << inprize << endl;
			cout << "\t产品售价\t" << prize << endl;
			cout << endl;
		}
	}
	//入货函数
	void inproduct(int innum)
	{
		SYSTEMTIME sysTime;
		ZeroMemory(&sysTime, sizeof(sysTime));
		innumber = innum;
		totalnumber += innum;
		GetLocalTime(&sysTime);
		changetime(sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
	}
	//出货函数
	void outproduct(int outnum)
	{
		totalnumber -= outnum;
	}
	//获取账户密码
	char* getpw()
	{
		return name;
	}
	//修改账户密码
	void changepw(char pw[])
	{
		char temp[20];
		strcpy(name, ::encrypt(pw, temp));
	}
	//库存提醒检查函数
	bool checknum(int alarmnumber)
	{
		if (totalnumber<alarmnumber)
			return true;
		else
			return false;
	}
	//入货时间比较
	bool checktime(int y, int mon, int d)
	{
		if ((year[0] == y) && (month[0] == mon) && (day[0] == d))
			return true;
		else
			return false;

	}
	//查找对应信息产品对象的字符串比较
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
	//查找对应信息产品对象的数字比较
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
	//判断对象是否为账户
	bool ifcode()
	{
		if (strcmp(type, "guanliyuan") == 0)
			return true;
		else
			return false;
	}
	//显示账户信息
	void mimadisp()
	{
		char tempac[20], temppw[20];
		cout << "\t账户名\t" << ::decrypt(number, tempac) << endl;
		cout << "\t密码\t" << ::decrypt(name, temppw) << endl;
		cout << "\t创建/修改时间\t";
		timedisp(0);
		cout << endl;
	}
	//验证用户名和密码
	bool checkcode(char ac[], char pw[])
	{
		char tempac[20], temppw[20];
		if ((strcmp(ac, decrypt(number, tempac)) == 0) && (strcmp(pw, decrypt(name, temppw)) == 0))
			return true;
		else
			return false;
	}
};
//对象大小
const int SZ = sizeof(Product);
//建立新产品
void newfiles(char b[])
{
	SYSTEMTIME sysTime;
	ZeroMemory(&sysTime, sizeof(sysTime));
	char name[20], type[20];
	int innumber;
	double inprize, prize, discount;
	int year[3], month[3], day[3], hour[3], minute[3], sec[3];
	cout << "\t新产品入库" << endl;
	cout << "\t请输入产品名称:";
	cin >> name;
	while (1)
	{
		cout << "\t请输入货物种类:";
		cin >> type;
		if (strcmp(type, "guanliyuan") == 0)
			cout << "\t种类不能为guanliyuan." << endl;
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
	cout << "\t请输入产品入库数量:";
	cin >> innumber;
	cout << "\t请输入产品入库价格:";
	cin >> inprize;
	cout << "\t请输入产品售价:";
	cin >> prize;
	Product a(b, name, type, year[0], month[0], day[0], hour[0], minute[0], sec[0], innumber, innumber, inprize, prize, year[1], month[1], day[1], hour[1], minute[1], sec[1], year[2], month[2], day[2], hour[2], minute[2], sec[2]);
	fstream file;
	file.open("Encryptedfile.dat", ios::out | ios::in | ios::binary);
	file.seekp(0, ios::end);
	file.write((char*)&a, SZ);
	file.close();
}
//检索产品是否已存在 存在则入货
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
			cout << "\t产品已有记录." << endl;
			a.disp();
			cout << "\t请输入入货数量:";
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
//建立新账户
void newaccount(char ac[])
{
	SYSTEMTIME sysTime;
	ZeroMemory(&sysTime, sizeof(sysTime));
	char pw[20], type[20], tempac[20], temppw[20];
	int year, month, day, hour, minute, sec;
	cout << "\t新账户." << endl;
	cout << "\t请输入密码:";
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
//检索账户是否已存在 存在则修改密码
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
			cout << "\t账户已存在." << endl;
			cout << "\t请输入当前账户密码:";
			cin >> opw;
			if (strcmp(decrypt(a.getpw(), temppw), opw) == 0)
			{
				cout << "\t密码正确." << endl; 
				cout << "\t请输入新密码:";
				cin >> npw;
				a.changepw(npw);
				file.seekp(file.tellp(), ios::beg);
				file.seekp(-SZ, ios::cur);
				file.write((char*)&a, sizeof(a));
				GetLocalTime(&sysTime);
				a.changetime(sysTime.wYear, sysTime.wMonth, sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
			}
			else
				cout << "\t密码错误." << endl;
		}
	}
	file.close();
	if (!fd)
	{
		newaccount(s);
	}
}
//按字符查询产品函数
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
				cout << "\t产品记录已找到." << endl;
				fdt = false;
			}
			if (file.eof())
				break;
			a.disp();
		}
	}
	if (!fd)
		cout << "找不到对应的产品." << endl;
	file.close();
}
//按数据查找产品对象
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
				cout << "\t产品记录已找到." << endl;
				fdt = false;
			}
			if (file.eof())
				break;
			a.disp();
		}
	}
	if (!fd)
		cout << "找不到对应的产品." << endl;
	file.close();
}
//按时间查找产品对象
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
				cout << "\t产品记录已找到." << endl;
				fdt = false;
			}
			if (file.eof())
				break;
			a.disp();
		}
	}
	if (!fd)
		cout << "找不到对应的产品." << endl;
	file.close();
}
//查找库存不足货物
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
				cout << "\t产品记录已找到." << endl;
				cout << "\t当前库存量低于" << s << "的货物:" << endl;
				fd = true;
			}
			a.disp();

		}
	}
	if (!fd)
		cout << "找不到对应的产品." << endl;
	file.close();
}
//出货函数
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
			cout << "\t产品已有记录." << endl;
			a.disp();
			cout << "\t请输入出货数量:";
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
		cout << "找不到对应的产品." << endl;
	}
}

//修改价格
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
			cout << "\t产品已有记录." << endl;
			a.disp();
			cout << "\t请输入新的入库价格:";
			cin >> ip;
			cout << "\t请输入新的售格:";
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
		cout << "找不到对应的产品." << endl;
	}
}
//修改名字类别
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
			cout << "\t产品已有记录." << endl;
			a.disp();
			cout << "\t请输入新的名字:";
			cin >> n;
			cout << "\t请输入新的类别:";
			while (1)
			{
				cout << "\t请输入货物种类:";
				cin >> t;
				if (strcmp(t, "guanliyuan") == 0)
					cout << "\t种类不能为guanliyuan." << endl;
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
		cout << "找不到对应的产品." << endl;
	}
}
//一级菜单
int meum1()
{
	int numx;
	cout << "\t+--------------------------------------------------------------+\n";
	cout << "\t\t1.存入货物" << endl;
	cout << "\t\t2.出货" << endl;
	cout << "\t\t3.补货查询" << endl;
	cout << "\t\t4.产品查询" << endl;
	cout << "\t\t5.库存清单" << endl;
	cout << "\t\t6.修改信息" << endl;
	cout << "\t\t7.创建账户/修改密码" << endl;
	cout << "\t\t8.账户信息查询" << endl;
	cout << "\t\t9.退出系统" << endl;
	cout << "\t\t请输入选项数字:";
	cin >> numx;
	return numx;
}
//一级菜单选项1
void cho1()
{
	char numberx[20];
	cout << "\t请输入产品编号:";
	cin >> numberx;
	changefile(numberx);
}
//一级菜单选项2
void cho2()
{
	char numberx[20];
	cout << "\t请输入产品编号:";
	cin >> numberx;
	changefile2(numberx);
}
//一级菜单选项3
void cho3()
{
	int anum;
	cout << "\t请输入所需查找产品最低存货量:";
	cin >> anum;
	findfile2(anum);
}
//一级菜单选项4
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
		cout << "\t\t1.按编号查询\n";
		cout << "\t\t2.按名称查询\n";
		cout << "\t\t3.按种类查询\n";
		cout << "\t\t4.按最近入库量查询\n";
		cout << "\t\t5.按库存量查询\n";
		cout << "\t\t6.按入库价格查询\n";
		cout << "\t\t7.按售格查询\n";
		cout << "\t\t8.按最近入库时间查询\n";
		cout << "\t\t9.返回上级菜单\n";
		cout << "\t\t请输入选项数字:";
		cin >> chnum;
		//二级菜单判断
		switch (chnum)
		{
		case 1:cout << "\t请输入产品编号:";
			cin >> a;
			findfile(a, 1);
			break;
		case 2:cout << "\t请输入产品名称:";
			cin >> a;
			findfile(a, 2);
			break;
		case 3:cout << "\t请输入产品种类:";
			cin >> a;
			findfile(a, 3);
			break;
		case 4:cout << "\t请输入最近入库量:";
			cin >> p;
			findfile(p, 1);
			break;
		case 5:cout << "\t请输入存量:";
			cin >> p;
			findfile(p, 2);
			break;
		case 6:cout << "\t请输入入库价格:";
			cin >> p;
			findfile(p, 3);
			break;
		case 7:cout << "\t请输入售价:";
			cin >> p;
			findfile(p, 4);
			break;
		case 8:cout << "\t请输入最经入库日期:(格式:XXXX.XX.XX)";
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
//一级菜单选项5
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
//一级菜单选项6
void cho6()
{
	char a[20];
	int chnum;
	int n = 1;
	while (n)
	{
		cout << "\t+--------------------------------------------------------------+\n";
		cout << "\t\t1.修改名称&种类\n";
        cout << "\t\t2.修改入库价格&售格\n";
		cout << "\t\t3.返回上级菜单\n";
		cout << "\t\t请输入选项数字:";
		cin >> chnum;
		//二级菜单判断
		switch (chnum)
		{
		case 1:cout << "\t请输入产品编号:";
			cin >> a;
			changeinfo(a);
			break;
        case 2:cout << "\t请输入产品编号:";
            cin>>a;
            changeprize(a);
            break;
		case 3:n = 0;
			break;
		default:break;
		}
	}
}
//一级菜单选项7
void cho7()
{
	char ac[20];
	cout << "\t请输入账户名:";
	cin >> ac;
	changepasswords(ac);
}
//一级菜单选项8
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
//一级菜单判断
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
//字符串加密函数
char* encrypt(char* str, char *temp)
{
	strcpy(temp,str);
	char* p = temp;
	int i = 0;
	while (*p != '\0')
		*p++ ^= i++;//二进制位异或
	return temp;
}
//字符串解密函数
char* decrypt(char* str, char *temp)
{
	strcpy(temp,str);
	char* p = temp;
	int i = 0;
	while (*p != '\0')
		*p++ ^= i++;
	return temp;
}
//验证用户名和密码
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
	cout << "\t+--------------------欢迎来到仓库产品管理系统------------------+" << endl << endl;
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
		cout << "\t\t请及时创建管理员账户!" << endl;
	else
		while (n<3)
		{
			cout << "\t请输入账户名:";
			cin >> ac;
			cout << "\t请输入密码:";
			cin >> pw;
			if (checkac(ac, pw))
				break;
			n++;
		}
	if (n == 3)
	{
		cout << "\t密码错误超过三次,强制退出!" << endl;
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
