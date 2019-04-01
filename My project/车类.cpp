/*
#include<iostream>
using namespace std;
class Vehicle
{
protected:
	int MaxSpeed;
	int Weight;
public:
	Vehicle(int m, int w)
	{
		MaxSpeed = m;
		Weight = w;
		cout << "Constring Vehicle...\n";
	}
	~Vehicle()
	{
		cout << "Destructing Vehivle...\n";
	}
		void Run()
	{
		cout << "The vehicle is running!\n";
	}
	void Stop()
	{
		cout << "Please stop running!\n";
	}
	void Show()
	{
		cout << "It's maxspeed is:" << MaxSpeed << endl;
		cout << "It's weight is:" << Weight << endl;
	}
};

class Bicycle :public Vehicle
{
protected:
	int Height;
public:
	Bicycle(int m, int w, int h):Vehicle(m,w)
	{
		Height = h;
		cout << "Constring Bicycle...\n";
	}
	~Bicycle()
	{
		cout << "Destructing Bicycle...\n";
	}
		void Show()
	{
		Vehicle::Show();
		cout << "It's height is:" <<Height << endl;
	}

};
int main()
{
	Bicycle b(1, 1, 1);
	b.Run();
	b.Stop();
	b.Show();
	return 0;
}
*/