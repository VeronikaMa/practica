#pragma once
class Item {
public:
	int value;
	Item* next;
};
class stack {
protected:
	Item *head,*tail; 
	int count = 0;
public:
	void push(int a);
	int pop();
	int back();
	int size();
	void clear();
};
