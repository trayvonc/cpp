/*
#include<iostream>
using namespace std;
class Complex
{
private:
	float real;
	float imag;
public:
	Complex(float r = 0,float i = 0)
	{
		real = r;
		imag = i;
	}
	void print();
	friend Complex operator++(Complex &a);
	friend Complex operator++(Complex &a, int);
	friend Complex operator+(const Complex &a, const Complex &b);
	friend Complex operator-(const Complex &a, const Complex &b);
	friend Complex operator*(const Complex &a, const Complex &b);
	friend Complex operator/(const Complex &a, const Complex &b);
};
Complex operator+(const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}
Complex operator-(const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = a.real - b.real;
	temp.imag = a.imag - b.imag;
	return temp;
}
Complex operator*(const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = a.real*b.real-a.imag*b.imag;
	temp.imag = a.imag*b.real + a.real*b.imag;
	return temp;
}
Complex operator/(const Complex &a, const Complex &b)
{
	Complex temp;
	temp.real = (a.real*b.real + a.imag*b.imag) / ((b.imag*b.imag) + (b.real*b.real));
	temp.imag = (a.imag*b.real + a.real*b.imag) / ((b.imag*b.imag) + (b.real*b.real));
	return temp;
}
Complex operator++(Complex &a)
{
	++a.real;
	++a.imag;
	return a;
}
Complex operator++(Complex &a, int)
{
	Complex temp(a);
	a.real++;
	a.imag++;
	return temp;
}
void Complex::print()
{
	cout << real;
	if (imag != 0)
	{
		if (imag > 0)cout << "+";
		cout << imag << "i";
	}
	cout << endl;
}
int main()
{
	Complex A1(2.3, 4.6), A2(3.6, 2.8);
	Complex A3, A4, A5, A6;
	A3 = A1 + A2;
	A4 = A1 - A2;
	A5 = A1*A2;
	A6 = A1 / A2;
	cout << "A1=";
	A1.print();
	cout << endl << "A2=";
	A2.print();
	cout << endl << "A3=A1+A2=";
	A3.print();
	cout << endl << "A4=A1-A2=";
	A4.print();
	cout << endl << "A5=A1*A2=";
	A5.print();
	cout << endl << "A6=A1/A2=";
	A6.print();
	A3 = ++A1;
	cout << endl << "after A3 = ++A1"<<endl;
	cout << "A1=";
	A1.print();
	cout << "A3=";
	A3.print();
	A4 = A2++;
	cout << endl << "after A4 = A2++"<<endl;
	cout << "A2=";
	A2.print();
	cout << "A4=";
	A4.print();
	return 0;
}
*/