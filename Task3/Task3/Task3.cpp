#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int a[100];
	int max=0,k=0;
	int* pa = a;
	srand(time(NULL));
   for (int i = 0; i < 100; i++) {
		a[i] = 10 + rand() % 90;
	}
	for (int i = 0; i < 100; ++i) {
		if (*(pa + i) > max){ max = *(pa + i); k = 0;}
		if (*(pa + i) == max) k++;
	}
	cout << max << ' ' << k << ' ';
}