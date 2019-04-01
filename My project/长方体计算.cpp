/*
#include<iostream>
using namespace std;
class Rectangle
{
protected:
	float length, width;
public:
	Rectangle(float l, float w)
	{
		length = l;
		width = w;
	}
	float area()
	{
		return length*width;
	}
	void disp()
	{
		cout<<area();
	}
};

class Cuboid :public Rectangle
{
private:
	float height;
public:
	Cuboid(float l, float w, float h) :Rectangle(l, w)
	{
		height = h;
	}
	float calv()
	{
		return length*width*height;
	}
	void disp()
	{
		cout<<calv();
	}
};
int main()
{
	float length, width, height;
	cin >> length >> width >> height;
	Cuboid x(length,width,height);
	x.Rectangle::disp();
	cout << " ";
	x.disp();
	return 0;
}
*/