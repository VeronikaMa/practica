#include "stack.h"

void stack::push(int a) {
	
	
	if (newlen == len) {
		newlen=len+1;
		int* new_arr = new int[newlen];
		for (int i = 0; i < len; ++i)
			new_arr[i] = arr[i];
		delete []arr;
		arr = new_arr;
		arr[newlen-1] = a;
	}
	else { arr[len] = a; } 
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