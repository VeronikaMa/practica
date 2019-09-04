#include <iostream>
using namespace std;
int main()
{
	int a[10];
	int c = 0, b = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 10; i++)
	{
		if (a[i] % 2 == 0) c++;
		else b++;
	}
	cout << c << endl;
	cout << b << endl;
}
