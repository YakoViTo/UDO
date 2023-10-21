#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

char leerChar(const string &s) {
	char ch = 0;
	do {
		try {
			cout << s << endl;
			cin >> ch;
			if (cin.fail()) {
				cin.clear();
				for (char ch; cin >> ch && isspace(ch) && isalpha(ch); );
				throw runtime_error("Error de entrada.");
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	return ch;
}

int leerEntero(const string& message) {
	int num = 0;
	do {
		try {
			cout << message;
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				for (char ch; cin >> ch && !isdigit(ch);)
					throw runtime_error("Error de entrada.");
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	return num;
}


template<class T>
class Nodo {
	Nodo<T>* proximo;
	T clave;
public:
	Nodo() { proximo = nullptr; clave = 0; }
	Nodo(const T clave) { proximo = nullptr; this->clave = clave; }
	Nodo<T>* getProximo() const { return proximo; }
	T getClave() const { return clave; }
	void setClave(const T clave) { this->clave = clave; }
	void setProximo(Nodo<T>* proximo) { this->proximo = proximo; }
};

template<class T>
class ListaSimple {
	Nodo<T>* inicio;
public:
	ListaSimple() { inicio = nullptr; }
	~ListaSimple() { vaciarLista(); }
	bool isEmpty() const {
		if (!inicio)
			return true;
		return false;
	}
	void vaciarLista();
	string insertar(Nodo<T>* n);
	string mostrar();
	string invertir();
};

template<class T>
string ListaSimple<T>::insertar(Nodo<T>* n) {
	if (inicio)
		n->setProximo(inicio);
	inicio = n;
	return "Nodo insertado\n";
}

template<class T>
string ListaSimple<T>::mostrar() {
	string s = "Nodos:\n";
	for (Nodo<T>* x = inicio; x; x = x->getProximo())
		s.append(to_string(x->getClave()) + "\n");
	return s;
}

//Función principal
template<class T>
string ListaSimple<T>::invertir() {
	Nodo<T>* aux = inicio->getProximo();
	inicio->setProximo(nullptr);
	while(aux) {
		Nodo<T>* auxProx = aux->getProximo();
		aux->setProximo(inicio);
		inicio = aux;
		aux = auxProx;
	}
	return "Lista invertida\n";
}

template<class T>
void ListaSimple<T>::vaciarLista() {
	while (Nodo<T>* aux = inicio) {
		inicio = inicio->getProximo();
		aux->setProximo(nullptr);
		delete aux;
	}
}

int main() {
	ListaSimple<int> l;
	char opc = '1';
	cout << "Lista Simple" << endl;
	do {
		opc = leerChar("1 - Insertar Nodo\n2 - Mostrar\n3 - Invertir lista\n4 - Salir");
		try {
			switch (opc) {
			case '1': {
				int clave = leerEntero("Clave del nodo: ");
				cout << l.insertar(new Nodo<int>(clave)) << endl;
				break;
			}
			case '2':
				cout << l.mostrar() << endl;
				break;
			case '3':
				cout << l.invertir() << endl;
				break;
			case '4':
				break;
			default:
				throw runtime_error("Opcion invalida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc = '4');
	system("PAUSE");
	return 0;
}