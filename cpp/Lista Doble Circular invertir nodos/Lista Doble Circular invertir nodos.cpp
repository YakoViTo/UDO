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
	string invertir();
	string mostrar();
	void vaciarLista();
};

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
	string cad = "Nodo: \n";
	for (Nodo<T>* x = s->getProximo(); x != s; x = x->getProximo())
		cad.append(to_string(x->getClave()) + "\n");
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

//Función principal
template<class T>
string ListaDobleCircular<T>::invertir() {
	Nodo<T>* aux = s;
	do {
		Nodo<T>* prox = aux->getProximo();
		aux->setProximo(aux->getAnterior());
		aux->setAnterior(prox);
		aux = aux->getAnterior();
	} while (aux != s);
	
	//Manera desoptimizada:
	/*for (Nodo<T>* aux = s->getProximo(); aux != s; aux = aux->getAnterior()) {
		Nodo<T>* prox = aux->getProximo();
		aux->setProximo(aux->getAnterior());
		aux->setAnterior(prox);
	}
	Nodo<T>* prox = s->getProximo();
	s->setProximo(s->getAnterior());
	s->setAnterior(prox);*/

	return "Lista invertida";
}

int main() {
	ListaDobleCircular<int> l;
	char opc = '1';
	cout << "Lista Doble Circular" << endl;
	do {
		opc = leerChar("1 - Insertar nodo\n2 - Mostrar\n3 - Invertir lista\n4 - Salir");
		try {
			switch (opc) {
			case '1': {
				int clave = leerEntero("Clave del nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				cout << l.insertar(n) << endl;
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
				throw runtime_error("Opción inválida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '4');
	system("PAUSE");
	return 0;
}