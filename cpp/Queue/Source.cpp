#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

constexpr size_t max = 3;

enum error {
	overflow = 0,
	underflow
};

template<class T>
class Queue {
	T q[max];
	size_t first, last;
public:
	Queue() { first = last = 0; }
	void enQueue(T x);
	T deQueue();
	bool isEmpty() {
		return first == last;
	}
	bool isFull() {
		return (last == (max - 1) && first == 0) || last == first - 1;
	}
};

template<class T>
void Queue<T>::enQueue(T x) {
	if (isFull())
		throw overflow;
	q[last] = x;
	(last == (max - 1)) ? last = 0 : last++;
}

template<class T>
T Queue<T>::deQueue() {
	if (isEmpty())
		throw underflow;
	(first == (max - 1)) ? first = 0 : first++;
	return q[first - 1];
}

/*template<class T>
class Queue {
	T q[max];
	size_t first;
	size_t last;
public:
	Queue() { first = last = 0; }
	void enQueue(T x);
	T deQueue();
	bool isEmpty() {
		return first == last;
	}
	bool isFull() {
		return ((last == (max - 1) && first == 0) || first == (last + 1));
	}
};

template<class T>
void Queue<T>::enQueue(T x) {
	if (isFull())
		throw overflow;
	q[last] = x;
	(last == (max - 1)) ? last = 0 : last++;
}

template<class T>
T Queue<T>::deQueue() {
	if (isEmpty())
		throw underflow;
	(first == (max - 1)) ? first = 0 : first++;
	return q[first - 1];
}

/*template<class T>
bool Cola<T>::isEmpty() {
	if (primero == ultimo)
		return true;
	return false;
}

template<class T>
bool Cola<T>::isFull() {
	if ((ultimo == (max - 1) && primero == 0) || primero == (ultimo + 1))
		return true;
	return false;
}

template<class T>
void Cola<T>::enQueue(T x) {
	if (isFull())
		throw runtime_error("Cola llena");
	q[ultimo] = x;
	(ultimo == (max - 1)) ? ultimo = 0 : ultimo++;
}

template<class T>
T Cola<T>::deQueue() {
	if (isEmpty())
		throw runtime_error("Cola vacia");
	(primero == (max - 1)) ? primero = 0 : primero++;
	return q[primero - 1];
}*/

int main() {
	Queue<int> q;
	try {
		q.enQueue(5);
		q.enQueue(6);
		q.deQueue();
		q.enQueue(4);
	}
	catch (const error& e) {
		if (e == overflow)
			cerr << "OVERFLOW EXCEPTION CAUGHT" << endl;
		else
			cerr << "UNDERFLOW EXCEPTION CAUGHT" << endl;
		return -1;
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
		return -2;
	}
	return 0;
}