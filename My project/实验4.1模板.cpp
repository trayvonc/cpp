/*
#include<iostream>
using namespace std;
template<class T>
class Complex
{
private:
	T real;
	T imag;
public:
	Complex(T r = 0, T i = 0)
	{
		real = r;
		imag = i;
	}
	void print()
	{
		cout << real;
		if (imag != 0)
		{
			if (imag > 0)cout << "+";
			cout << imag << "i";
		}
		cout << endl;
	}
	friend Complex operator+(const Complex<T> &a, const Complex<T> &b);
};
template<class T>
Complex<T> operator+(const Complex<T> &a, const Complex<T> &b)
{
	Complex<T> temp;
	temp.real = a.real + b.real;
	temp.imag = a.imag + b.imag;
	return temp;
}
int main()
{
	Complex<float> A2(3.6, 2.8);
	Complex<float> A3;
	Complex<float> A1(2.3, 4.6);//, A2(3.6, 2.8);
	A3 = A1 + A2;
	//cout << endl <<"A3=A1+A2=";
	//A3.print();
	return 0;
}
*/