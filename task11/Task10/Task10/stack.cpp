#include "stack.h"

void stack::push(int a) {
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

int stack::pop() {
	Item* itm, * temp, * prev;
	int value_c;
	if (count == 1) {
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
	count--;
	return value_c;
}

int stack::back() {
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