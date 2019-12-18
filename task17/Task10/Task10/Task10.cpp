#include "stack.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	stack obj;
	int n = 0, k = 0, r;
	string str, s, a, b;
	ifstream f("input.txt");
	while (f >> str) {
		if (str[0] >= '0' && str[0] <= '9') {
			obj.push(str);
		}
		if (str == "+") {
			a = obj.pop();
			b = obj.pop();
			r = stoi(a) + stoi(b);
			s = to_string(r);
			obj.push(s);
		}
		if (str == "*") {
			a = obj.pop();
			b = obj.pop();
			r = stoi(a) * stoi(b);
			s = to_string(r);
			obj.push(s);
		}
		if (str == "/") {
			a = obj.pop();
			b = obj.pop();
			r = stoi(b) / stoi(a);
			s = to_string(r);
			obj.push(s);
		}
		if (str == "-") {
			a = obj.pop();
			b = obj.pop();
			r = stoi(b) - stoi(a);
			s = to_string(r);
			obj.push(s);
		}
	}
	cout << obj.back() << ' ';
}