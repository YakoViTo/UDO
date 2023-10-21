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
	Nodo(const T clave) { anterior = proximo = nullptr; this->clave = clave; }
	Nodo<T>* getProximo() const { return proximo; }
	Nodo<T>* getAnterior() const { return anterior; }
	T getClave() const { return clave; }
	void setClave(const T clave) { this->clave = clave; }
	void setProximo(Nodo<T>* proximo) { this->proximo = proximo; }
	void setAnterior(Nodo<T>* anterior) { this->anterior = anterior; }
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
	string insertar(Nodo<T>* x);
	string eliminar(const T num);
	Nodo<T>* buscar(const T num);
	string mostrar();
	void vaciarLista();
};

template<class T>
string ListaDobleCircular<T>::mostrar() {
	string cad = "Nodos: \n";
	for (Nodo<T>* x = s->getProximo(); x != s; x = x->getProximo())
		cad.append(to_string(x->getClave()) + "\n");
	return cad;
}

template<class T>
Nodo<T>* ListaDobleCircular<T>::buscar(const T num) {
	Nodo<T>* x = s->getProximo();
	while (x != s && num != x->getClave())
		x = x->getProximo();
	return x;
}

template<class T>
string ListaDobleCircular<T>::insertar(Nodo<T>* x) {
	Nodo<T>* aux = s->getProximo();
	aux->setAnterior(x);
	x->setProximo(s->getProximo());
	s->setProximo(x);
	x->setAnterior(s);
	return "Nodo insertado\n";
}

//Este método recibía como parámetro un apuntador, lo cambié a un valor para conveniencia. 
template<class T>
string ListaDobleCircular<T>::eliminar(const T num) {
	Nodo<T>* x = buscar(num);
	if (x == s)
		throw runtime_error("No existe el nodo");
	Nodo<T>* aux = x->getAnterior();
	aux->setProximo(x->getProximo());
	aux = x->getProximo();
	aux->setAnterior(x->getAnterior());
	x->setProximo(nullptr);
	x->setAnterior(nullptr);
	delete x;
	return "Eliminacion exitosa\n";
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

	/*
		for (Nodo<T>* x = s->getProximo(); true; ) {
		Nodo<T>* aux = x;
		if (x != s)
			x = x->getProximo();
		aux->setProximo(nullptr);
		aux->setAnterior(nullptr);
		delete aux;
	}
	s->setProximo(nullptr);
	s->setAnterior(nullptr);
	delete s;
	*/
}

int main() {
	ListaDobleCircular<int> l;
	char opc = '1';
	cout << "Lista Doble Circular" << endl;
	do {
		opc = leerChar("1 - Insertar nodo\n2 - Eliminar nodo\n3 - Mostrar nodos\n4 - Salir");
		try {
			switch (opc) {
			case '1': {
				int clave = leerEntero("Clave del nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				cout << l.insertar(n) << endl;
				break;
			}
			case '2': {
				int clave = leerEntero("Clave del nodo: ");
				cout << l.eliminar(clave) << endl;
				break;
			}
			case '3':
				cout << l.mostrar() << endl;
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
	} while (opc != '4');
	system("PAUSE");
	return 0;
}