#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int c = 0;
	fstream f("in.txt");
	fstream g("out.txt");
	char *a= new char [1000];
	f.getline(a, 1000);
	while (*a != 0) {
		if (*a >= 'a' && *a <= 'z')* a -= 32;
		else if (*a >= 'A' && *a <= 'Z')* a += 32;
		a++;
		c++;
	}
	a = a - c;
	g << a;
}
