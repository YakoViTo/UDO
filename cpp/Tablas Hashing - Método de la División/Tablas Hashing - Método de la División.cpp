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

int leerShort(const string& message) {
	short num = 0;
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

const short max = 11;

template<class T>
class Item {
	Item* proximo;
	Item* anterior;
	T clave;
public:
	Item() { clave = 0; proximo = anterior = nullptr; }
	Item(const T clave) { this->clave = clave; proximo = anterior = nullptr; }
	Item<T>* getProximo() const { return proximo; }
	Item<T>* getAnterior() const { return anterior; }
	short getClave() const { return clave; }
	void setProximo(Item<T>* n) { this->proximo = proximo; }
	void setAnterior(Item<T>* a) { this->anterior = anterior; }
	void setClave(const T clave) { this->clave = clave; }
};

template<class T>
class ListaDoble {
	Item<T>* inicio;
public:
	ListaDoble() { inicio = nullptr; }
	~ListaDoble() { vaciarLista(); }
	Item<T>* getInicio() const { return inicio; }
	void insertar(Item<T>* n);
	void eliminar(const T clave);
	Item<T>* buscar(const T clave);
	void vaciarLista();
};

template<class T>
void ListaDoble<T>::vaciarLista() {
	while (Item<T>* aux = inicio) {
		inicio = inicio->getProximo();
		aux->setProximo(nullptr);
		aux->setAnterior(nullptr);
		delete aux;
	}
}

template<class T>
Item<T>* ListaDoble<T>::buscar(const T clave) {
	Item<T>* x = inicio;
	for (; x && x->getClave() != clave; x = x->getProximo());
	return x;
}

template<class T>
void ListaDoble<T>::insertar(Item<T>* n) {
	n->setProximo(inicio);
	if (inicio)
		inicio->setAnterior(n);
	inicio = n;
}

template<class T>
void ListaDoble<T>::eliminar(const T clave) {
	Item<T>* n = buscar(clave);
	if (!n)
		throw runtime_error("Nodo inexistente");
	if (n->getAnterior()) {
		Item<T>* aux = n->getAnterior();
		aux->setProximo(n->getProximo());
	}
	else
		inicio = n->getProximo();
	if (n->getProximo()) {
		Item<T>* aux = n->getProximo();
		aux->setAnterior(n->getAnterior());
	}
}

template<class T>
class Hashing {
	ListaDoble<T>* t[max];
public:
	Hashing() {
		for (short i = 0; i < max; i++)
			t[i] = new ListaDoble<T>;
	}
	short hash(const T clave);
	string insertar(Item<T>* n);
	string eliminar(const T clave);
	ListaDoble<T>* buscar(const T clave);
};

template<class T>
ListaDoble<T>* Hashing<T>::buscar(const T clave) {
	short index = hash(clave);
	return t[index];
}

template<class T>
short Hashing<T>::hash(const T clave) {
	return clave % max;
}

template<class T>
string Hashing<T>::insertar(Item<T>* n) {
	t[hash(n->getClave())]->insertar(n);
	return "Nodo insertado";
}

template<class T>
string Hashing<T>::eliminar(const T clave) {
	t[hash(clave)]->eliminar(clave);
	/*ListaDoble<T>* listaX = buscar(clave);
	listaX->eliminar(clave);*/
	return "Nodo eliminado";
}

int main() {
	Hashing<int> h;
	char opc = '1';
	cout << "Tablas Hashing" << endl;
	do {
		opc = leerChar("1 - Insertar item\n2 - Eliminar item\n3 - Mostrar\n4 - Salir");
		try {
			switch (opc) {
			case '1': {
				short clave = leerShort("Clave del item: ");
				cout << h.insertar(new Item<int>(clave)) << endl;
				break;
			}
			case '2': {
				short clave = leerShort("Clave del item: ");
				cout << h.eliminar(clave) << endl;
				break;
			}
			case '3':
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