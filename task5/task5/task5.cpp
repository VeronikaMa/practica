#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	int max = 0, k = 0,s=0;
	int* pa = a;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % (10);
		cout << a[i]<<' ';
	}
	max = *pa;
	for (int i = 0; i < n; ++i) {
		if (*(pa + i) == max) {k++; }
		else {
			max = *(pa + i); k = 1;
		}
		if (s < k) { s = k; }
	}
	cout << "peew " << s << ' ';
}
