#pragma once
#include <iostream>
class Item {
public:
	std::string value;
	Item* next;
};
class stack {
protected:
	Item *head,*tail; 
	int count = 0;
public:
	void push(std::string a);
	std::string pop();
	std::string back();
	int size();
	void clear();
};
