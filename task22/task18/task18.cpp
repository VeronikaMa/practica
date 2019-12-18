#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int n, i, b[100];
	float  arr[100];
	pair <int, int> a[100];
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	for (i = 0; i < n; ++i) {
		int j = i - 1;
		while (j >= 0 && a[j].first > a[j + 1].first) {
			swap(a[j], a[j+1]);
			j--;
		}
		if (i+1 != j+2) {
			cout << "Swap elements at indices " << j+2 << " and " << i+1  << ' ';
			cout << endl;
		}
	}
	cout << "No more swaps needed.";
	cout << endl;
	for (i = 0; i < n; ++i) {
		cout << "element " << a[i].first << ' ' << "index " << a[i].second + 1;
		cout << endl;
	}
}
	

