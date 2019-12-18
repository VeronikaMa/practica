﻿#include "stack.h"
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
		if (str[0] >= '0' && str[0] <= '9' ) {
			obj.push(str); 
		}
		if (str == "+") {
			k = obj.back();//+ сложение тута должно быть предположительно с  obj.back(obj.size()-1)
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
	}
	if (!obj.size()) cout << "Yes";
	else cout << "No";
	
	}