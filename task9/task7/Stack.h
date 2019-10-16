#pragma once
class stack {
protected: 
	int* arr;
	int len = 0;
	int newlen = 0;
public:
	void push(int a);
	int pop();
	int back();
	int size();
	void clear();
};
