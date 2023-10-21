#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

constexpr int max = 5;

template<class T>

class Pila {
	T s[max];
	int tope;
public:
	Pila() { tope = -1; }
	string push(T x);
	T pop();
	bool isPilaVacia();
	bool isPilaLlena();
};

template<class T>
bool Pila<T>::isPilaLlena() {
	return tope == (max - 1);
}

template<class T>
bool Pila<T>::isPilaVacia() {
	return tope == -1;
}

template<class T>
string Pila<T>::push(T x) {
	if (isPilaLlena())
		throw runtime_error("Pila llena");
	tope++;
	s[tope] = x;
	return "Numero agregado.";
}

template<class T>
T Pila<T>::pop() {
	if (isPilaVacia())
		throw runtime_error("Pila vacia");
	tope--;
	return s[tope + 1];
}

int main() {
	Pila <float> p;
	char ch = 'a';
	
	do {
		
		try {
			cout << "1 - Agregar numero a la pila.\n2 - Quitar numero de la pila\n3 - Salir" << endl;
			cin >> ch;
			switch (ch) {
			case '1': {
				float num = 0;
				cout << "Numero: ";
				cin >> num;
				cout << p.push(num) << endl;
				break;
			}
			case '2':
				cout << "Ultimo numero: " << p.pop() << endl;
				break;
			case '3':
				break;
			default:
				throw runtime_error("Opcion invalida.");
			}

		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}

	} while (ch != '3');

	system("PAUSE");
	return 0;
}