#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

constexpr int max = 2;

template<class T>

class Cola {
	T q[max];
	int primero;
	int ultimo;
public:
	Cola() { primero = ultimo = 0; }
	bool isEmpty() {
		if (primero = ultimo)
			return true;
		return false;
	}
	bool isFull() {
		if ((ultimo == (max - 1) && primero == 0) || primero == (ultimo + 1))
			return true;
		return false;
	}
	void enQueue(T x) {
		if (isFull())
			throw runtime_error("Cola llena");
		q[ultimo] = x;
		(ultimo == (max - 1)) ? ultimo = 0 : ultimo++;
	}
	T deQueue() {
		if (isEmpty())
			throw runtime_error("Cola vacia");
		(primero == (max - 1)) ? primero = 0 : primero++;
		return q[primero - 1];
	}

	void espejo(Cola& c) {
		Cola <int>
	}

};
