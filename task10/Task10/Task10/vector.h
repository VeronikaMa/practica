#pragma once
class vector {
protected:
	int arr[1000];
	int len = 0;
public:
	void push_back(int a);
	void push_front(int a);
	int pop_back();
	int pop_front();
	int back();
	int size();
	void clear();
};