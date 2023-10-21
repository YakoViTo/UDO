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
		cout << s << endl;
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
	Nodo() { clave = 0; proximo = nullptr; }
	Nodo(const T clave) { this->clave = clave; proximo = nullptr; }
	void setProximo(Nodo<T>* n) { this->proximo = proximo; }
	void setClave(const T clave) { this->clave = clave; }
	T getClave() const { return clave; }
	Nodo<T>* getProximo() const { return proximo; }
};

template <class T>
class ListaSimple {
	Nodo<T>* inicio;
public:
	ListaSimple() { inicio = nullptr; }
	ListaSimple(const Nodo<T> inicio) { this->inicio = inicio; }
	~ListaSimple() { vaciarLista(); };
	bool isEmpty() const;
	string insertar(Nodo<T>* n);
	string sloop();
	void vaciarLista();
};

template <class T>
bool ListaSimple<T>::isEmpty() const{
	if (!inicio)
		return true;
	return false;
}

template <class T>
string ListaSimple<T>::insertar(Nodo<T>* n) {
	if (inicio)
		n->setProximo(inicio);
	inicio = n;
	return "Insercion exitosa";
}

template <class T>
string ListaSimple<T>::sloop() {
	if (isEmpty())				//Si está vacío, envía mensaje
		return "Lista vacia";	
	Nodo<T>* x = inicio;		//Auxiliar para el inicio.
	while (x->getProximo())		//Ciclo para llegar al nodo final.
		x = x->getProximo();	//Actualiza el auxiliar con 'x'.
	x->setProximo(x);			//El último nodo, se apuntará a sí mismo.
	return "Se ha realizado el sloop";		//Retorna mensaje exitoso.
}

template <class T>
void ListaSimple<T>::vaciarLista() {
	while (Nodo<T>* aux = inicio) {
		inicio = inicio->getProximo();
		aux->setProximo(nullptr);
		delete aux;
	}
}

int main() {
	ListaSimple<int> l;
	char opc = 'a';
	do {
		opc = leerChar("1 - Insertar nodo\n2 - Sloop\n3 - Salir");
		switch (opc) {
		case '1': {
			int clave = leerEntero("Clave del nodo: ");
			Nodo<int>* n = new Nodo<int>(clave);
			cout << l.insertar(n) << endl;
			break;
		}
		case '2':
			cout << l.sloop() << endl;
			break;
		case '3':
			break;
		default:
			throw runtime_error("Opcion invalida");
		}
	} while (opc != '3');
	return 0;
}