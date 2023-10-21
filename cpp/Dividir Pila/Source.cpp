#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

constexpr int max = 2;

template<class T>

class Pila {
	T s[max];
	int tope;
public:
	Pila() { tope = -1; }
	void push(T x);
	T pop();
	string dividirPila(Pila& pos, Pila& neg);
	bool isPilaVacia();
};

template <class T>
bool Pila<T>::isPilaVacia() {
	if (tope == -1)
		return true;
	return false;
}

template<class T>
void Pila<T>::push(T x) {
	if (tope == (max - 1))
		throw runtime_error("Pila llena");
	tope++;
	s[tope] = x;
}

template<class T>
T Pila<T>::pop() {
	if (isPilaVacia())
		throw runtime_error("Pila vacia");
	tope--;
	return s[tope + 1];
}

template<class T>
string Pila<T>::dividirPila(Pila& pos, Pila& neg) {
	if (isPilaVacia())
		throw runtime_error("Pila vacia");
	for (int i = 0; i <= tope; i++)
		(s[i] < 0) ? neg.push(s[i]) : pos.push(s[i]);
	return "sucess";
}


int main() {
	Pila <int> p;
	char ch = 'a';
	do {
		try {
			cout << "1 - Agregar numero\n2 - Remover numero\n3 - Dividir numeros\n4 - Salir";
			cin >> ch;
			switch (ch) {
			case '1': {
				int val = 0;
				cout << "Numero: ";
				cin >> val;
				p.push(val);
				cout << "Numero agregado" << endl;
				break;
			}
			case '2':
				cout << "Ultimo numero: " << p.pop() << endl;
				break;
			case '3': {
				Pila<int> pos, neg;
				cout << p.dividirPila(pos, neg) << endl;
				break;
			}	
			case '4':
				break;
			default:
				throw runtime_error("Opcion invalida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (ch != '4');
	return 0;
}