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
	void enQueue(T x);
	T deQueue();
	bool isEmpty();
	bool isFull();
};

template<class T>
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
}

int main() {
	Cola<int> c;
	char ch = '3';
	do {
		try {
			cout << "1 - Agregar numero\n2 - Quitar numero\n3 - Salir" << endl;
			cin >> ch;
			switch (ch) {
			case '1': {
				int num = 0;
				cout << "Numero: ";
				cin >> num;
				c.enQueue(num);
				break;
			}
			case '2':
				c.deQueue();
				break;
			case '3':
				break;
			default:
				throw runtime_error("Opcion invalida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (ch != '3');
	system("PAUSE");
	return 0;
}