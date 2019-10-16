#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	stack obj;
	int a;
	string str;
	while (cin >> str) {
		if (str == "push") {
			cin >> a; obj.push(a); cout << "OK"<<endl;
		}
		if (str == "pop") 
			if (obj.size() == 0)
				cout << "error" << endl; 
		else cout << obj.pop() << endl;
		if (str == "back") {
			if (obj.size()==0)
				cout << "error" << endl;
			else cout << obj.back() << endl;
		}
		if (str == "size") cout << obj.size() << endl; 
		if (str == "clear") {
			obj.clear(); cout << "OK" << endl;
		}
		if (str == "exit") { cout << "bb"; break; }
	}
}

//try {
	//obj.size();
//}
//catch (...) {
	//cout << "error" << endl;
//}