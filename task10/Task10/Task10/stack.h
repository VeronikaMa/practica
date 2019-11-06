#pragma once
#include "vector.h"
class stack {
protected:
	vector v;
public:
	void push(int a);
	int pop();
	int back();
	int size();
	void clear();
};
