#include "stack.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	stack obj;
	int n=0,k=0;
	string str;
	ifstream f("input.txt");
	while (f >> str) {
		if (str == "(" ) {
			obj.push(str); 
		}
		if (str == "[") {
			obj.push(str); 
		}
		if (str == "{") {
			obj.push(str);
		}
		if (str == "]") {
			if (obj.size() && obj.back() == "[" ) {
				obj.pop(); 
			}
			else {
				cout << "No";
				return 0;
			}
		}
		if (str == ")") {
			if (obj.size() && obj.back() == "(" ) {
				obj.pop(); 
			}
			else {
				cout << "No";
				return 0;
			}
		}
		if (str == "}") {
			if (obj.size() && obj.back() == "{") {
				obj.pop();
			}
			else {
				cout << "No";
				return 0;
			}
		}
	}
	if (!obj.size()) cout << "Yes";
	else cout << "No";
	
	}