#include "vector.h"
#include<iostream>


void vector::push_back(int a) {
	arr[len] = a;
	len++;
}
 
void vector::push_front(int a) {
	len++;
	for (int i = len - 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = a;
}

int vector::pop_back() {
	len--;
	return arr[len];
}

int vector::pop_front() {
	int a = arr[0];
	for (int i = 0; i < len; i++)
		arr[i] = arr[i + 1];
	len--;
	return a;
}

int vector::back() {
	return arr[len - 1];
}

int vector::size() {
	return len;
}

void vector::clear() {
	len = 0;
}