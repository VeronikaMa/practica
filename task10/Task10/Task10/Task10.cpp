#include "stack.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	stack obj;
	int a,n;
	string str;
	ifstream f("input.txt");
	f >> n;
	while (n) {
		f >> str;
		if (str == "+") {
			f >> a; obj.push(a);
		}
		if (str == "-")
			if (obj.size() == 0)
				cout << "error" << endl;
			else cout << obj.pop() << endl;
		n--;
	}
	}

//try {
	//obj.size();
//}
//catch (...) {
	//cout << "error" << endl;
//}