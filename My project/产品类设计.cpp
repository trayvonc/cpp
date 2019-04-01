/*
#include<iostream>
#include<string.h>
using namespace std;
class Product;
class Date
{
private:
	int year, month, day;
public:
	Date(int y = 2000, int m = 1, int d = 1)
	{
		year = y;
		month = m;
		day = d;
	}
	int Getyear()
	{
		return year;
	}
	int Getmonth()
	{
		return month;
	}
	int Getday()
	{
		return day;
	}
	friend Product;
};
class Product
{
	char *name;
	double price;
	Date deptime;
	char *factory;
	bool easy_break;
	Date valtime;
	char *colour;
	double weight;
public:
	Product(char *n);
	Product(char *n, double p);
	Product(char *n, double p, int y, int m, int d);
	void SetProduct(char *n, double p, int y, int m, int d, char *f, bool eb, int y1, int m1, int d1, char *c, double w)
	{
		name = new char[strlen(n) + 1];
		strcpy(name, n);
		price = p;
		deptime.year = y;
		deptime.month = m;
		deptime.day = d;
		factory = new char[strlen(f) + 1];
		strcpy(factory, f);
		easy_break = eb;
		valtime.year = y1;
		valtime.month = m1;
		valtime.day = d1;
		colour = new char[strlen(c) + 1];
		strcpy(colour, c);
		weight = w;
	}
	void output();
	//~Product()
	//{
	//	if (name)
	//		delete []name;
	//	if (factory)
	//		delete []factory;
	//	if (colour)
	//		delete []colour;
	//}
};
Product::Product(char *n)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	cout << "Constrcting One...." << endl;
}
Product::Product(char *n, double p)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	price = p;
	factory = new char[10];
	factory = "unnamed" ;
	easy_break = false;
	cout << "Constrcting Two...." << endl;
}
Product::Product(char *n, double p, int y, int m, int d) :deptime(y, m, d)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	price = p;
	factory = new char[10];
	factory =  "unnamed" ;
	easy_break = false;
	cout << "Constrcting Three...." << endl;
}

void Product::output()
{
	cout << name << " " << price << endl;
	cout << deptime.Getyear() << "-" << deptime.Getmonth() << "-" << deptime.Getday() << endl;
	cout << factory << " " << easy_break << endl;
	cout << valtime.Getyear() << "-" << valtime.Getmonth() << "-" << valtime.Getday() << endl;
}
int main()
{
	char s[10];
	cin >> s;
	Product p1("car");
	Product p2("glass", 3.00);
	Product p3("pen", 5.00, 2009, 3, 14);
	p1.SetProduct("car", 100000.0, 2009, 3, 14, "nanjing", 0, 2010, 10, 14, "red", 1.5);
	p1.output();
	p2.output();
	p3.output();
	return 0;
}
*/