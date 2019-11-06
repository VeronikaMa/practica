#include "stack.h"

void stack::push(int a) {
	v.push_back(a);
}

int stack::pop() {
	return v.pop_back();
}

int stack::back() {
	return v.back();
}

int stack::size() {
	return v.size();
}

void stack::clear() {
	v.clear();
} 