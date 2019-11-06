#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string razdel(string l, int k) {
	string t;
	int a, b,h=0,c=0,v=0,s=0,z;
	for (int i = l.size(); i > k; i--){
		if (l[i] >= '0' && l[i] <= '9') { t += l[i]; c++; }
		else { t = ' '; c = 0; }
	}
	reverse(t.begin(), t.end());
	b = atoi(t.c_str());
	t = ' ';
	for (int i = 0; i < k; i++) {
		if (l[i] >= '0' && l[i] <= '9') {
			t += l[i]; v++;
		}
		else { t = ' '; v = 0; }
	}

	a = atoi(t.c_str());
	t = ' ';
	
	if (l[k]=='+') {
		h = a + b;
	}
	if (l[k] == '*') {
		h = a * b;
	}
	if (l[k] == '/') {
		h = a / b;
	}
	if (l[k] == '-') {
		h = a - b;
	}

	s = v + c + 1;
	l.replace(k-v,s,"@");
	
	string j = to_string(h);
	z = l.find('@');
	l.erase(z,1);
	l.insert(z, j);
	return l;
}

int main()
{
	string line;
	int p=0,m=0,x=0,d=0,r=0;
	ifstream f("example.txt");
	getline(f, line);
	cout << line;
	int pos = -1, pos1 = -1;;
	while (x>-1 || d>-1){
		x = line.find('*');
		d = line.find('/');
		if (x == -1) {
			pos = d;
		}
		else if (d == -1) {
			pos = x;
		} else {
			pos = x > d ? d : x;
		}
		if (pos != -1)
			line=razdel(line, pos);
	}
	while (p > -1 || m > -1){
		p = line.find('+');
		m = line.find('-');
		if (m == -1) {
			pos1 = p;
		}
		else if (p == -1) {
			pos1 = m;
		}
		else {
			pos1 = p > m ? m : p;
		}
		if(pos1!=-1)
			line=razdel(line, pos1);
	}
	r = line.find('=');
	line.erase(r, 1);
	cout << line;
}