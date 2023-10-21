#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

char leerChar(const string& s) {
	char ch = 'a';
	do {
		cout << s << endl;
		cin >> ch;
		try {
			if (cin.fail()) {
				for (char ch = 'a'; cin >> ch && isalpha(ch); );
				throw runtime_error("Error de entrada");
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
			cin.clear();
		}
	} while (true);
	return ch;
}

int leerEntero(const string& s) {
	int num = 0;
	do {
		cout << s;
		cin >> num;
		try {
			if (cin.fail()) {
				for (char ch = 'a'; cin >> ch && isalpha(ch); );
				throw runtime_error("Error de entrada");
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
			cin.clear();
		}
	} while (true);
	return num;
}

template<class T>
class Nodo {
	Nodo<T>* proximo;
	T clave;
public:
	Nodo() {
		clave = 0;
		proximo = nullptr;
	}
	Nodo(const T clave) { this->clave = clave; proximo = nullptr; }
	Nodo<T>* getProximo() const { return proximo; }
	T getClave() const { return clave; }
	void setProximo(Nodo<T>* proximo) { this->proximo = proximo; }
	void setClave(const T clave) { this->clave = clave; }
};

template<class T>
class ListaSimple {
	Nodo<T>* inicio;
public:
	ListaSimple() { inicio = nullptr; }
	~ListaSimple();
	bool isEmpty() const;
	string insertar(Nodo<T>* n);
	string recortarLista(const int num);
};

template<class T>
ListaSimple<T>::~ListaSimple() {
	while (Nodo<T>* aux = inicio) {
		inicio = inicio->getProximo();
		aux->setProximo(nullptr);
		delete aux;
	}
}

template<class T>
bool ListaSimple<T>::isEmpty() const {
	if (!inicio)
		return true;
	return false;
}

template<class T>
string ListaSimple<T>::insertar(Nodo<T>* n) {
	if (!isEmpty())
		n->setProximo(inicio);
	inicio = n;
	return "Nodo insertado";
}

template<class T>
string ListaSimple<T>::recortarLista(const int num) {
	//Opcional
	if (isEmpty() || num <= 0)
		throw runtime_error("Lista vacia o numero negativo ingresado");
	Nodo<T>* x = inicio;
	for (int i = 0; x && i != num; i++)
		x = x->getProximo();
	if (x) {									  //Si el contador es igual al argumento...
		Nodo<T>* siguientes = x->getProximo();    //Auxiliar para el siguiente nodo
		x->setProximo(nullptr);
		while (Nodo<T>* nodoAEliminar = siguientes) {   //Ciclo para eliminar
			siguientes = siguientes->getProximo();
			nodoAEliminar->setProximo(nullptr);
			delete nodoAEliminar;
		}
	}
	else
		throw runtime_error("El numero no cumple con el tamano de la lista");
	return "Lista recortada";
}

int main() {
	ListaSimple<int> l;
	char opc = 'a';
	do {
		opc = leerChar("1 - Insertar nodo\n2 - Recortar Lista\n3 - Salir");
		try {
			switch (opc) {
			case '1': {
				int clave = leerEntero("Clave del nuevo nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				cout << l.insertar(n) << endl;
				break;
			}
			case '2': {
				int num = leerEntero("A cuantos nodos?: ");
				cout << l.recortarLista(num) << endl;
				break;
			}
			case '3':
				break;
			default:
				throw runtime_error("Opcion invalida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '3');
	return 0;
}