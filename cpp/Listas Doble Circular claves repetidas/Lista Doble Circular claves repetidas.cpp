/*
	 Suponga que se tiene una lista doble circular con claves repetidas. 
	 Escriba una función en C++ que retorne todas las ocurrencias de una clave dada.
*/

#include <iostream>
#include <stdexcept>
#include <string>
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
	Nodo<T>* anterior;
	Nodo<T>* proximo;
	T clave;
public:
	Nodo() { anterior = proximo = nullptr; }
	Nodo(const T clave) { this->clave = clave; anterior = proximo = nullptr; }
	Nodo<T>* getAnterior() const { return anterior; }
	Nodo<T>* getProximo() const { return proximo; }
	T getClave() const { return clave; }
	void setAnterior(Nodo<T>* anterior) { this->anterior = anterior; }
	void setProximo(Nodo<T>* proximo) { this->proximo = proximo; }
	void setClave(const T clave) { this->clave = clave; }
};

template<class T>
class ListaDobleCircular {
	Nodo<T>* s;
public:
	ListaDobleCircular() {
		s = new Nodo<T>;
		s->setProximo(s);
		s->setAnterior(s);
	}
	~ListaDobleCircular() { vaciarLista(); }
	string insertar(Nodo<T>* n);
	string mostrar();
	ListaDobleCircular<T> retornarOcurrencias(const T clave);
	string eliminarOcurrencias(const T clave);
	bool isEmpty() const;
	void vaciarLista();
};

template<class T>
bool ListaDobleCircular<T>::isEmpty() const {
	if (s->getProximo() == s && s->getAnterior() == s)
		return true;
	return false;
}

template<class T>
string ListaDobleCircular<T>::insertar(Nodo<T>* n) {
	Nodo<T>* aux = s->getProximo();
	aux->setAnterior(n);
	n->setProximo(s->getProximo());
	s->setProximo(n);
	n->setAnterior(s);
	return "Nodo insertado\n";
}

template<class T>
string ListaDobleCircular<T>::mostrar() {
	string cad = "";
	for (Nodo<T>* x = s->getProximo(); x != s; x = x->getProximo())
		cad.append(to_string(x->getClave()) +  "\n");
	return cad;
}

template<class T>
void ListaDobleCircular<T>::vaciarLista() {
	for (Nodo<T>* x = s->getProximo(); x != s; ) {
		Nodo<T>* aux = x;
		x = x->getProximo();
		aux->setProximo(nullptr);
		aux->setAnterior(nullptr);
		delete aux;
	}
	s->setProximo(nullptr);
	s->setAnterior(nullptr);
	delete s;
}

template<class T>
string ListaDobleCircular<T>::eliminarOcurrencias(const T clave) {
	if (isEmpty())
		throw runtime_error("Lista vacia");
	for (Nodo<T>* x = s->getProximo(); x != s;) {
		if (x->getClave() == clave) {
			Nodo<T>* aux = x->getAnterior();
			aux->setProximo(x->getProximo());
			aux = x->getProximo();
			aux->setAnterior(x->getAnterior());
			aux = x;
			x = x->getProximo();
			aux->setProximo(nullptr);
			aux->setAnterior(nullptr);
			delete aux;
		}
		else
			x = x->getProximo();
	}
	return "Proceso completado";
}

//Función principal
template<class T>
ListaDobleCircular<T> ListaDobleCircular<T>::retornarOcurrencias(const T clave) {
	ListaDobleCircular<T> nuevaLista;
	for (Nodo<T>* aux = s->getProximo(); aux != s; aux = aux->getProximo())
		if (aux->getClave() == clave)
			nuevaLista.insertar(new Nodo<T>(clave));
	return nuevaLista;
}

int main() {
	ListaDobleCircular<int> l;
	char opc = '1';
	cout << "Lista Doble Circular" << endl;
	do {
		opc = leerChar("1 - Insertar nodo\n2 - Mostrar\n3 - Retornar claves repetidas\n4 - Eliminar ocurrencias\n5 - Salir");
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
			case '3': {
				int clave = leerEntero("Clave repetida: ");
				ListaDobleCircular<int> a = l.retornarOcurrencias(clave);
				break;
			}
			case '4': {
				int clave = leerEntero("Clave del nodo: ");
				cout << l.eliminarOcurrencias(clave) << endl;
				break;
			}
			case '5':
				break;
			default:
				throw runtime_error("Opcion invalida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '5');
	system("PAUSE");
	return 0;
}