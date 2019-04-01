/*
#include<iostream>
#include<String>
using namespace std;
class Employee
{
protected:
	char name[30];
	int working_years;
public:
	Employee(const char nm[30] = "unnamed", int wy = 0);
	char *Getname()
	{
		return name;
	}
	double ComputePay()
	{
		return 35 * working_years;
	}
	void SetWorkyears(int wy);
};
Employee::Employee(const char nm[], int wy)
{
	working_years = wy;
	strcpy(name, nm);
}
void Employee::SetWorkyears(int wy)
{
	working_years = wy;
}
class Worker:public Employee
{
protected:
	double pay_per_hour=50;
	int work_time;
public:
	Worker(const char nm[], int wy, int wt);
	double count_pay();
	void SetWorktime(int wt);
	void Setpay_per_hour(int x);
};
Worker::Worker(const char nm[],int wy,int wt):Employee(nm,wy)
{
	work_time = wt;
}
double Worker::count_pay()
{
	return pay_per_hour*work_time + Employee::ComputePay();
}
void Worker::SetWorktime(int wt)
{
	work_time = wt;
}
void Worker::Setpay_per_hour(int x)
{
	pay_per_hour = x;
}
class SalesPerson :public Employee
{
protected:
	double pay_per_hour;
	double saleroom;
	int work_time;
public:
	SalesPerson(const char nm[30], int wy, int sr, int pph);
	double count_pay();
	void SetWorktime(int wt);
	void Setpay_per_hour(int x);
	void Setsalesroom(double sr);
};
SalesPerson::SalesPerson(const char nm[30], int wy, int sr, int pph):Employee(nm, wy)
{
	pay_per_hour = pph;
	saleroom = sr;
}
double SalesPerson::count_pay()
{
	return pay_per_hour*work_time + Employee::ComputePay() +0.01*saleroom;
}
void SalesPerson::SetWorktime(int wt)
{
	work_time = wt;
}
void SalesPerson::Setpay_per_hour(int x)
{
	pay_per_hour = x;
}
void SalesPerson::Setsalesroom(double sr)
{
	saleroom = sr;
}
class Manager :public Employee
{
public:
	double count_pay()
	{
		return 1000 + Employee::ComputePay();
	}
public:
	Manager(const char nm[30], int wy) :Employee(nm, wy)
	{}
};
int main()
{
	Worker work("zhangqiang", 3, 200);
	cout << "¹¤×Ê=" << work.count_pay() << endl;
	work.SetWorktime(180);
	work.SetWorkyears(10);
	work.Setpay_per_hour(30);
	cout << work.Getname() << "  " << work.count_pay() << endl;

	SalesPerson sales("wangjun", 5, 300000, 25);

	sales.SetWorktime(40);
	sales.Setpay_per_hour(80);
	sales.Setsalesroom(450000);
	cout << sales.Getname() << "  " << sales.count_pay() << endl;

	Manager mana("sunchao", 20);
	cout << mana.Getname() << "  " << mana.count_pay() << endl;
	return 0;
}
*/