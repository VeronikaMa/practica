#include "stack.h"

void stack::push(int a) {
	arr[len] = a;
	len++;
}

int stack::pop() {
	len--;
	return arr[len];
}

int stack::back() {
	return arr[len-1];
}

int stack::size() {
	return len;
}

void stack::clear() {
	len = 0;
}