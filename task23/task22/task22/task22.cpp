#include <iostream> 
#include <vector> 
#include <algorithm>
#include <iterator> 

using namespace std;

vector<int> merge(vector<int>& a, vector<int>& b, int &count) {
	int i = 0, j = 0,x=0;
	int n = a.size(), m = b.size();
	vector<int> c;
	while (i < n || j < m) {
		
		if (j != b.size() && i != a.size() && a[i] > b[j]) {
			count += a.size() - i;
		}

		/*10 
		1 8 2 1 4 7 3 2 3 6*/
		

		if (j == m || (i < n && a[i] <= b[j]))
		{
			c.push_back(a[i]);  i++;
			
		}
		else {
			c.push_back(b[j]);  j++;
			
		}
	}
	return c;
}

vector<int> merge_sort(vector <int>& a,int L,int R, int& count) {
	int n = a.size();
	int mid = (R + L) / 2;
	if (n == 1) { return a; }
	vector<int> left, right;
	copy(a.begin(), a.begin() + n / 2, back_inserter(left));
	copy(a.begin() + n / 2, a.end(), back_inserter(right));
	left = merge_sort(left, L , mid, count);
	right = merge_sort(right,mid,R, count);
	
	vector<int> b = merge(left, right, count);
	cout << L + 1 << ' ' << R << ' ' << b.front() << ' ' << b.back() << endl;
	return b;
	}


int main() {
	int n, k,count=0;
	vector<int> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a.push_back(k);
	}
	vector<int> b = merge_sort(a, 0, n,count);
	for (int i = 0; i < b.size(); i++)
		cout << b[i] << ' ';
	cout <<"kol-vo" <<count;
	return 0;
}