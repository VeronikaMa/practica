#include <iostream> 
#include <vector> 
#include <algorithm>
#include <iterator> 
#include <ctime>

using namespace std;

void pos(vector<int>& a, int n, int A, int B, int C, int  a1, int  a2) {
	vector<int> b;
	int i = 0;
	a.push_back(a1);
	a.push_back(a2);
	while (a.size() < n) {
		i++;
		a.push_back(A * a[i - 1] + B * a[i] + C);
	}
}

void Qsort(vector<int>& a, int left, int right,int k1,int k2) {
	int i, j, key, sum=0,k;
	k = a.size();
	for (i = 0; i < k; i++) {
		if (a.back() > a[i] && k-i!=k2) {
			a.pop_back();
			right--;
			break;
		}
	}
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

	if (left < j) Qsort(a,left, j,k1,k2);
	if (i < right) Qsort(a,i, right,k1,k2);
}

int main() {
	int n,k1,k2,A,B,C,a1,a2;
	vector<int> a;
	cin >> n>>k1>>k2;
	cin >> A >> B >> C >> a1 >> a2;
	pos(a, n, A ,B , C , a1 , a2);
	Qsort(a, 0, n - 1,k1,k2);
	cout << a[k1-1] << ' '<< a[k2-1];
}

