#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void swap_st(int** b, int n, int m, int l1, int l2) {
	for (int i = 0; i < m; i++) {
		swap(*(*(b + l1) + i), *(*(b + l2) + i));
	}
}

void swap_sb(int** c, int n, int m, int sb1, int sb2) {
	for (int i = 0; i < n; i++) {
		swap(*(*(c + i) + sb1), *(*(c + i) + sb2));
	}
}


void show(int** a, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << *(*(a + i) + j) << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	int** a = new int *[n];
	int** b = new int* [n];
	int** c = new int* [n];
	int* sum1 = new int[n];
	int* sum2 = new int[n];
	for (int i = 0; i < n; i++) { 
	a[i] = new int[m];
	b[i] = new int[m];
	c[i] = new int[m];
	}
	int max = 0, k = 0, s = 0;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = rand() % (10);
			b[i][j] = a[i][j];
			c[i][j] = a[i][j];
		}
	}
	int* st = sum1;
	int* sb = sum2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s = *(a[i] + j) + s;
		}
		*(st+i) = s; s = 0;
	}

	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0 && sum1[j]>sum1[j+1]; j--){
				swap(sum1[j], sum1[j + 1]);
				swap_st(b, n, m, j, j + 1);
			}
	}
	cout << endl;
	//show(b, n, m);
	for (int i = 0; i < n; i++)
		cout << "sum1 " << sum1[i] << ' ';
	cout << endl;
	
	
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			s = *(a[i] + j) + s;
		}
		*(sb + j) = s; s = 0;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0 && sum2[j] < sum2[j + 1]; j--) {
				swap(sum2[j], sum2[j + 1]);
				swap_sb(c, n, m, j, j + 1);
			}
	}
	for (int i = 0; i < m; i++)
		cout << "sum2 " << sum2[i] << ' ';
	cout << endl;
	show(a, n, m);
	cout << endl;
	show(b, n, m);
	cout << endl;
	show(c, n, m);
	cout << endl;
}