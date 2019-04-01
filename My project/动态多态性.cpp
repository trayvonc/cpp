/*
#include<iostream>
using namespace std;
const double PI = 3.1415;
class shape
{
public:
	virtual double volume()const = 0;
};
class cylinder :public shape
{
private:
	double radius, height;
public:
	cylinder(double r, double h):radius(r),height(h)
	{}
	double volume()const;
};

class sphere :public shape
{
private:
	double radius;
public:
	sphere(double r): radius(r)
	{}
	double volume()const;
};
double cylinder::volume()const
{
	return PI*radius*radius*height;
}
double sphere::volume()const
{
	return (4 * PI*radius*radius*radius) / 3;
}

int main() {
	shape *p;
	double  r, h;
	cout << "input r & h£º" << endl;
	cin >> r >> h;
	cylinder cy(r, h);
	sphere sp(r);
	p = &cy;
	cout << p->volume() << endl;
	p = &sp;
	cout << p->volume() << endl;
	return 0;
}
*/