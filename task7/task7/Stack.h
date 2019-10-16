#pragma once
class stack {
protected:
	int arr[1000];
	int len = 0;
public:
	void push(int a);
	int pop();
	int back();
	int size();
	void clear();
};
