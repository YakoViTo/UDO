#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

constexpr size_t max = 3;

enum error {
	overflow = 0,
	underflow
};

template<class T>
class Stack {
	int top;
	T S[max];
public:
	Stack() { top = -1; };
	void push(T x);
	T pop();
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == (max - 1);
	}
};

template<class T>
void Stack<T>::push(T x) {
	if (isFull())
		throw overflow;
	top++;
	S[top] = x;
}

template<class T>
T Stack<T>::pop() {
	if (isEmpty())
		throw underflow;
	top--;
	return S[top + 1];
}

int main() {
	Stack<int> s;
	try {
		s.push(5);
		s.push(8);
		s.push(10);
		s.push(9);
	}
	catch (const error& e) {
		if (e == overflow)
			std::cerr << "OVERFLOW EXCEPTION CAUGHT" << endl;
		else
			std::cerr << "UNDERFLOW EXCEPTION CAUGHT" << endl;
		return -1;
	}
	catch (...) {
		std::cerr << "UNKNOWN EXCEPTION CAUGHT!" << endl << "Quitting..." << endl;
		return -2;
	}
	return 0;
}