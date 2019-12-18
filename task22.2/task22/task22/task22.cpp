#include <iostream> 
#include <vector> 
#include <algorithm>

#include <iterator> 

using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
	int i = 0, j = 0, k=100;
	int n = a.size(), m = b.size();
	vector<int> c;
	while (i < n || j < m) {
		if (i<j && a[i]>a[j]) cout << k<< ' ' ;
		if (j == m || (i < n && a[i] <= b[j]))
		{
			c.push_back(a[i]);    i++;
		}
		else {
			c.push_back(b[j]);    j++;
		}
		
	}
	return c,k;
}

vector<int> merge_sort(vector <int>& a,int L,int R) {
	int n = a.size();
	int mid = (R + L) / 2;
	if (n == 1) { return a; }
	vector<int> left, right;
	copy(a.begin(), a.begin() + n / 2, back_inserter(left));
	copy(a.begin() + n / 2, a.end(), back_inserter(right));
	left = merge_sort(left, L , mid);
	right = merge_sort(right,mid,R);
	
	vector<int> b = merge(left, right);
	cout << L + 1 << ' ' << R << ' ' << b.front() << ' ' << b.back() << endl;
	return b;
	}


int main() {
	int n, k;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a.push_back(k);
	}
	vector<int> b = merge_sort(a, 0, n);
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << ' ';
	return 0;
}