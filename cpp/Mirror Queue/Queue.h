#pragma once

constexpr size_t max = 10;

enum error {
	overflow = 0,
	underflow
};

template<class T>
class Queue {
	size_t first, last;
	T q[max];
public:
	Queue() { first = last = 0; }
	T deQueue();
	void enQueue(T x);
	void mirror(Queue& m);
	bool isEmpty() { return first == last; }
	bool isFull() { return (last == (max - 1) && first == 0) || first == last + 1; }
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

template<class T>
void Queue<T>::mirror(Queue& m) {
	Queue x = m;
	while (!x.isEmpty()) {
		m.enQueue(x.deQueue());
	}
}
