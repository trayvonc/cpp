/*
#include<iostream>
#include<fstream>
using namespace std;
void ReadFile(char *s);
void Change(char *s1, char *s2);
int main()
{
	ReadFile("ff.txt");
	Change("ff.txt", "ff2.txt");
	ReadFile("ff2.txt");
	return 0;
}
void ReadFile(char *s)
{
	char str[50];
	ifstream in(s);
	if (!in)
	{
		cout << "Cannot open the file.\n";
		return;
	}
	in.getline(str, 50);
	cout << str << "\n";
	in.close(); 
}
void Change(char *s1, char *s2)
{
	char ch;
	ifstream in(s1);
	if (!in)
	{
		cout << "Cannot open the file.\n";
		return;
	}
	ofstream out(s2);
	if(!out)
	{
		cout << "Cannot open the file.\n";
		return;
	}
	while (in.get(ch))
	{
		if ('a' <= ch&&ch <= 'z')
		{
			ch -= 32;	
			out.put(ch);
		}
	}
	in.close();
	out.close();
}
*/