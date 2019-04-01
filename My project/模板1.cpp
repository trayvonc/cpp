/*
#include<iostream>
#include<string>
using namespace std;
template<class T>
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	cout << a <<" "<< b;
}
/*void Swap(char*a, char*b)
{
	char *temp;
	strcpy(temp, a);
	strcpy(a,b);
	strcpy(b,temp);
	cout << *a <<" "<< *b;
}*/                          //学习疑惑，能否实现在主函数中判别输入内容实现数字和字符串的交换
/*
int main()
{
	double m,n;
	cin >> m >> n;
	Swap(m, n);
}
*/