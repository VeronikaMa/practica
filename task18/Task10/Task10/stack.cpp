#include "stack.h"
#include <iostream>

using namespace std;

void stack::push(string a) {
	Item *itm=new Item;
	itm->value = a;
	itm->next = 0;
	count++;
	if (head == 0) {
		head = itm;
		tail = head; 
		return;
	}
	tail->next = itm;
	tail = itm;
}

string stack::pop() {
	Item* itm, * temp, * prev;
	string value_c;
	count--;
	if (count + 1 == 1) {
		value_c = head->value;
		delete head;
		head = 0;
		tail = 0;
		return value_c;
	}
	temp = head;
	prev = head;
	while (temp->next != 0) {
		prev = temp;
		temp = temp->next;
	}
	value_c = temp->value;
	delete temp;
	tail = prev;
	tail->next = 0;
	return value_c;
}

string stack::back() {
	return tail->value;
}

int stack::size() {
	return count;
}

void stack::clear() {
	Item* itm, * temp, * prev;
	temp = head;
	prev = head;
	while (temp->next != 0) {
		prev = temp;
		temp = temp->next;
		delete prev;
	}
	delete tail;
	tail = 0;
	head = 0;
	count = 0;
}