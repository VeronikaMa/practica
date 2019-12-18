#include <iostream> 
#include <vector> 
#include <algorithm>

#include <iterator> 

using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b) {
	int i = 0, j = 0; 
	int n = a.size(), m = b.size();
	vector<int> c;
	while (i < n || j < m) { 
		if (j == m || (i < n && a[i] <= b[j])) 
		{ c.push_back(a[i]);    i++; } 
		else { c.push_back(b[j]);    j++; } }
	return c;
}

vector<int> merge_sort(vector <int>& a) {
	int n = a.size();  
	if (n == 1) { return a; }

	vector<int> left, right;
	copy(a.begin(), a.begin() + n / 2, back_inserter(left)); 
	copy(a.begin() + n / 2, a.end(), back_inserter(right));
	left = merge_sort(left);  right = merge_sort(right);
	return merge(left, right);
}

int main() {
	int n,k;
	vector<int> a;
	for (i = 0; i < n; i++) {
		cin >> k;
		a.push_back(k);
	}
	vector<int> b = merge_sort(a);
	return 0;