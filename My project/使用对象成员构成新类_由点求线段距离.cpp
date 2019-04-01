/*
#include<iostream>
#include <iomanip>
#include<math.h>
using namespace std;
class Point
{
private:
	double X, Y;
public:
	Point(double a, double b);
	Point(Point &p);
	double GetX()
	{
		return X;
	}
	double GetY()
	{
		return Y;
	}
};
Point::Point(double a, double b)
{
	X = a;
	Y = b;
}
Point::Point(Point &p)
{
	X = p.GetX();
	Y = p.GetY();
}
class Line
{
private:
	Point A, B;
	double length;
public:
	Line(Point p1, Point p2);
	double GetLength()
	{
		return length;
	}
};
Line::Line(Point p1, Point p2):A(p1),B(p2)
{
	length = sqrt(((p1.GetX()) - (p2.GetX()))*((p1.GetX()) - (p2.GetX())) + ((p1.GetY()) - (p2.GetY()))*((p1.GetY()) - (p2.GetY())));
}

int main()
{
	double x1, y1, x2, y2;
	cin >> x1>> y1>> x2>> y2;
	Point A(x1,y1), B(x2,y2);
	Line L(A, B);
	cout<< fixed <<setprecision(2)<<L.GetLength();
}
*/