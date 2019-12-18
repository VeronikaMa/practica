#include <iostream> 
#include <vector> 
#include <algorithm>
#include <iterator> 
#include <ctime>

using namespace std;


void Qsort(vector<int>& a, int left, int right) {
	int i, j, key, sum=0;
	key = a[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j) {
		while (a[i] < key) {
			i++;
			sum++;
		}
		while (key<a[j]) {
			j--; sum++;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++; j--;
		}
	}

	if (left < j) Qsort(a,left, j);
	if (i < right) Qsort(a,i, right);
}

void pos(vector<int>& a, int n) {
	vector<int> b;
	while (a.size() < n) {
			for (int i = 0; i < n; i++) {
				if (i % 2)	b.push_back(i + 1);
				else a.push_back(i + 1);
			}
			if (n % 2) {
			a.insert(a.end(), b.begin(), b.end());
		}
		else {
			b.pop_back();
			a.push_back(n);
			a.insert(a.end(), b.begin(), b.end());
		}
	}
}

int main() {
	int n,k;
	vector<int> a;
	cin >> n;
	pos(a,n);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
}

