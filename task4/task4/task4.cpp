#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void razdel(string l, int k) {
	string t;
	int a, b,h=0,c=0,v=0,s=0,z;
	for (int i = l.size(); i > k; i--){
		if (l[i] >= '0' && l[i] <= '9') { t += l[i]; c++; }
		else { t = ' '; c = 0; }
	}
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
	cout << l;
	
}

int main()
{
	string line;
	int p=0,m=0,x=0,d=0,r=0;
	ifstream f("example.txt");
	getline(f, line);
	p = line.find('+');
	m = line.find('-');
	x = line.find('*');
	d = line.find('/');
	r= line.find('=');
	if (x>0) razdel(line,x);
	if (d>0) razdel(line, d);
	if(p>0) razdel(line, p);
	if(m>0) razdel(line, m);
	if (r > 0) cout <<line<<endl;
}