#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	int n, i, arr[100],b[100];
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> arr[i];
	cout << 1 <<' ';
	for (i = 1; i < n; ++i) {
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			swap(arr[j], arr[j + 1]);
			j--;
		}
		cout << j + 2 << ' ';
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		cout << arr[i]<< ' ';
	}
	
}

