#pragma once
#include <iostream>
constexpr size_t max = 5;

template<class T>
class Stack {
	int top;
	T s[max];
public:
	Stack() { top = -1; }
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == (max - 1);
	}
	void push(T x);
	T pop();
};
