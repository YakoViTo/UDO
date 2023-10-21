/*
	Diseñe una función en C++ que elimine todas las ocurrencias 
	de una clave dada en una lista simplemente enlazada. 
	En la función se debe liberar el espacio de memoria de los nodos eliminados.

*/

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
	T clave;
	Nodo<T>* proximo;
public:
	Nodo() { proximo = nullptr; }
	Nodo(const T clave) { this->clave = clave; proximo = nullptr; }
	void setClave(const T clave) { this->clave = clave; }
	void setProximo(const Nodo<T>* proximo) { this->proximo = proximo; }
	T getClave() const { return clave; }
	Nodo<T>* getProximo() const { return proximo; }
};

template<class T>
class ListaSimple {
	Nodo<T>* inicio;
public:
	ListaSimple() { inicio = nullptr; }
	~ListaSimple() {vaciarLista();}
	bool isEmpty const();
	string insertar(Nodo<T>* n);		//Insertar al inicio.
	string eliminarOcurrencias(const T clave);
	void vaciarLista();
};

template<class T>
bool ListaSimple<T>::isEmpty const() {
	if (!inicio)
		return true;
	return false;
}

template<class T>
string ListaSimple<T>::insertar(Nodo<T>* n) {
	if (!isEmpty())
		n->setProximo(inicio);
	inicio = n;
	return "Inserción exitosa";
}

//Supongo que es así:
template<class T>
string ListaSimple<T>::eliminarOcurrencias(const T clave) {
	Nodo<T>* anterior = nullptr;
	for (Nodo<T>* x = inicio; x; x = x->getProximo()) {		//Mientras 'x' != nullptr...
		if (x->getClave() == clave) {						//Si la clave de 'x' es igual al argumento
			Nodo<T>* aux = x;								//Asigna ese apuntador a un auxiliar (?)
			if (!anterior)									//*Sólo por si acaso* Si "anterior" no es igual a nullptr...
				anterior->setProximo(x->getProximo());		//El "proximo" de "anterior" será el proximo de 'x'
			x->setProximo(nullptr);						
			delete aux;										//Y borra el auxiliar.
		}
		else
			anterior = x;									//Asigna 'x' a "anterior".
	}
	return "Proceso finalizado";
}

template<class T>									
void ListaSimple<T>::vaciarLista() {
	while (Nodo<T>* aux = inicio) {			//Mientras aux != nullptr (O mejor dicho, que inicio != nullptr)
		inicio = inicio->getProximo();		//Inicio será igual al nodo que le sigue
		aux->setProximo(nullptr);			//Auxiliar apuntará a nullptr
		delete aux;							//Y borralo
	}
}

int main() {
	ListaSimple<int> l;
	char opc = 'a';
	do {
		cout << "1 - Insertar nodo\n2 - Eliminar ocurrencias\n3 - Salir" << endl;
		cin >> opc;
		try {
			switch (opc) {
			case '1': {
				int clave = leerEntero("Clave del nuevo nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				cout << l.insertar(n) << endl;
				break;
			}
			case '2': {
				int clave = leerEntero("Clave del nodo a eliminar: ");
				cout << l.eliminarOcurrencias(clave) << endl;
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