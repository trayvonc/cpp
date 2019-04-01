/*
#include<iostream>
#include<string.h>
using namespace std;
class Station
{
protected:
	char from[20];
	char to[20];
public:
	Station(char *f, char *t);
	void disp();
};
Station::Station(char *f, char *t)
{
	strcpy(from, f);
	strcpy(to, t);
}
void Station::disp()
{
	cout << from << " " << to;
}
class Mile
{
protected:
	double mile;
public:
	Mile(double s)
	{
		mile = s;
	}
	void disp()
	{
		cout << mile;
	}
};
class Price :public Station, public Mile
{
private:
	double price;
public:
	Price(char *f, char *t,double s):Station(f,t),Mile(s)
	{
		if (s<=3)
		{
			price = 8;
		}
		else
		{
		
			if ((s-(int)s) <= 0.5&& (s - (int)s)!=0)
			{
				price = ((int)s-3)*1.4+0.7 + 8;
			}
			else if ((s - (int)s) == 0)
			{
				price = ((int)s - 3)*1.4+8;
			}
			else
			{
				price = ((int)s-3)*1.4 + 1.4+ 8;
			}
			
		}
	}
	void disp()
	{
		Station::disp();
		cout << " ";
		Mile::disp();
		cout <<" " << price<<endl;
	}
};
int main()
{
	char from[10], to[10];
	double s;
	cin >> from >> to >> s;
	Price p(from,to,s);
	p.disp();
	return 0;
}
*/