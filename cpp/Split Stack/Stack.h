#pragma once
constexpr size_t max = 10;

enum error {
	overflow = 0,
	underflow
};

template<class T>
class Stack {
	int top;
	T s[max];
public:
	Stack() { top = -1; }
	bool isEmpty() const { return top == -1; }
	bool isFull() const { return top == (max - 1); }
	void push(T x);
	T pop();
	void splitStack(Stack& positive, Stack& negative);
};

template<class T>
void Stack<T>::push(T x) {
	if (isFull())
		throw overflow;
	top++;
	s[top] = x;
}

template<class T>
T Stack<T>::pop() {
	if (isEmpty())
		throw underflow;
	top--;
	return s[top + 1];
}

template<class T>
void Stack<T>::splitStack(Stack& positive, Stack& negative) {
	while (!isEmpty()) {
		int x = pop();
		if (x < 0)
			negative.push(x);
		else
			positive.push(x);
	}
}
