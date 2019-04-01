/*
#include<iostream>
using namespace std;
const double PI = 3.1416;
class Container
{
protected:
	double radius;
public:
	Container(double r)
	{
		radius = r;
	}
	virtual double area() = 0;
	virtual double volume() = 0;
	virtual void print() = 0;
};
class Cube:public Container
{
	double a;
public:
	Cube(double aa, double t):Container(t)
	{
		a = aa;
	}
	double area()
	{
		return 6 * a*a;
	}
	double volume()
	{
		return a*a*a;
	}
	void print()
	{
		cout << "正方体边长为" << a<<endl;
	}
};
class Sphere :public Container
{
	double r;
public:
	Sphere(double rr,double t):r(rr),Container(t)
	{}
	double area()
	{
		return 4 * PI*r*r;
	}
	double volume()
	{
		return (4 * PI*r*r*r) / 3;
	}
	void print()
	{
		cout << "球的半径为" << r<<endl;
	}
};
class Cylinder :public Container
{
	double r, height;
public:
	Cylinder(double rr, double h,double t) :r(rr), height(h),Container(t)
	{}
	double area()
	{
		return ((2*PI*r*r)+2*PI*r*height);
	}
	double volume()
	{
		return PI*r*r*height;
	}
	void print()
	{
		cout << "圆柱体的半径为" << r<<endl;
		cout << "圆柱体的高为" << height<<endl;
	}
};
void TopPrint(Container &r)
{
	r.print();
}
int main()
{
	Container *p;
//	Container p;
	Cube c(1,1);
	Sphere s(2,1);
	Cylinder b(3,4,1);
	p = &c;
	cout << p->area() << endl;
	cout << p->volume() << endl;
	//p->print();
	TopPrint(*p);
	p = &s;
	cout << p->area() << endl;
	cout << p->volume() << endl;
	p->print();
	p = &b;
	cout << p->area() << endl;
	cout << p->volume() << endl;
	p->print();
	return 0;
}
*/