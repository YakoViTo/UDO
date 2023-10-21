#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

//Para revisar por errores en la entrada.
int leerEntero(const string &s) {
	int x = 0;
	do {
		try {
			cout << s;
			cin >> x;
			if (cin.fail()) {
				cin.clear();
				for (char ch; cin >> ch && !isdigit(ch););
					throw runtime_error("Error de entrada.");
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	return x;
}

//Para revisar por errores en la entrada.
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

//Nodo
template<class T>
class Nodo {
	T clave;
	Nodo* proximo;
public:
	Nodo() {proximo = nullptr;}
	Nodo(const T clave) {
		this->clave = clave;
		proximo = nullptr;
	}
	Nodo(const T clave, Nodo* p) {
		this->clave = clave;
		proximo = p;
	}
	~Nodo() {				//Destructor (que no sé si estoy destuyendo bien el objeto solo poniendo un atributo en nullptr).
		proximo = nullptr;
	}
	void setProximo(Nodo<T>* proximo) { this->proximo = proximo; }
	void setClave(const T clave) { this->clave = clave; }
	Nodo<T>* getProximo() const { return proximo; }
	T getClave() const { return clave; }
};

template<class T>
class ListaSimple {
	Nodo<T>* inicio;
public:
	ListaSimple() { inicio = nullptr; }
	ListaSimple(Nodo<T>* inicio) { this->inicio = inicio; }
	
	~ListaSimple() {vaciarLista();}		//Destructor.
	
	bool isEmpty() const;								//Revisa si la lista está vacía.
	
	Nodo<T>* buscar(const T valor);				//Buscar cierto nodo que se le envíe como parámetro.
	
	Nodo<T>* buscarAnterior(Nodo<T>* n);	//Esto es para retornar el nodo anterior a cierto nodo que se le envíe como argumento.
	
	string insertarAlInicio(Nodo<T>* n);		//Insertado hacia atrás, sobreescribiendo el apuntador "inicio" con la dirección del nodo agregado.
	
	string insertar(Nodo<T>* n, const T valor);	//Insertar después de un Nodo dado (El valor constante que se envía como parámetro será para buscar el nodo por su Clave).
	
	string insertarAlFinal(Nodo<T>* n);		//Insertar después del último nodo (El nodo cuyo "proximo" es nullptr).
	
	string eliminar(const T valor);			//Eliminar según un nodo dado, y sobreescribir el "proximo" del anterior nodo con la dirección del "proximo" del nodo a eliminar.
	
	string eliminarUltimo();	//Eliminar Ultimo Agregado (Es decir, el de la dirección de "inicio").
	
	string eliminarPrimero();	//Eliminar Primero (Es decir, el que tiene como "proximo" una dirección nullptr, al final de la lista).
	
	string mostrarNodos();		//Mostrar las claves de los nodos (Desde "inicio" hasta el nodo que tiene como "proximo" un nullptr).
	
	void vaciarLista();			//Sólo cuando el usuario quiera salir del programa. Elimina toda la lista.

	string sortAscendente();	//Ordenar de forma ascendente (Es decir, siendo "inicio" el nodo con la clave más pequeña que el resto).
};

template<class T>
bool ListaSimple<T>::isEmpty() const {
	if (!inicio)
		return true;
	return false;
}

template<class T>
Nodo<T>* ListaSimple<T>::buscar(const T valor) {
	Nodo<T>* x = inicio;
	while (x && x->getClave() != valor)	//Mientras 'x' sea distinto de null y la clave de 'x' sea distinto del argumento dado.
		x = x->getProximo();			//Mueve el apuntador al siguiente nodo.
	return x;
}

template<class T>
Nodo<T>* ListaSimple<T>::buscarAnterior(Nodo<T>* n) {
	Nodo<T>* anterior = nullptr;
	for (Nodo<T>* x = inicio; x != n; x = x->getProximo())		//Guarda "inicio" en una variable auxiliar y mientras la auxiliar no sea igual al argumento dado...
		anterior = x;											//iguala otra variable con el valor aumentado.
	return anterior;											//Retorna el nodo anterior.
}

template<class T>
string ListaSimple<T>::insertar(Nodo<T>* n, const T valor) {
	Nodo<T>* x = buscar(valor);
	if (!x)																//Si el nodo que el usuario quiere buscar no existe, envía un mensaje.
		return "El nodo no existe. No se logró insertar el nuevo nodo";	
	n->setProximo(x->getProximo());										//Sino, sobreescribe el "proximo" del nodo a insertar con el "proximo" del anterior nodo.
	x->setProximo(n);													//Y sobreescribe el "proximo" del anterior nodo con el nuevo nodo.
	return "Insertado exitoso";
}

template<class T>
string ListaSimple<T>::insertarAlInicio(Nodo<T>* n) {
	if (inicio)													//Si "inicio" != nullptr, el nodo a insertar tendrá el "proximo" con la dirección del último nodo agregado ("inicio").
		n->setProximo(inicio);
	inicio = n;													//Asigna el nuevo nodo a "inicio"
	return "Insertado exitoso";
}

template<class T>
string ListaSimple<T>::insertarAlFinal(Nodo<T>* n) {
	Nodo<T>* x = inicio;										
	for ( ; x->getProximo(); x = x->getProximo());				//Mientras el "proximo" de 'x' != nullptr, mueve 'x'.
	x->setProximo(n);											//Ya como se tiene el nodo final, sobreescribe su "proximo" con el nuevo nodo.
	return "Insertado exitoso";
}

template<class T>
string ListaSimple<T>::eliminar(const T valor) {
	if (isEmpty())												//Si la lista está vacía envía un mensaje.
		return "Lista vacia";
	Nodo<T>* aux = buscar(valor);								//Sino, busca el nodo a eliminar y guardalo en una variable auxiliar.
	if (!aux)													//Si la búsqueda tiró un nullptr, envía un mensaje.
		return "El nodo no existe";
	if (aux == inicio)											//Si la búsqueda es igual al "inicio", sólo incrementa el "inicio"
		inicio = inicio->getProximo();
	else {							
		Nodo<T>* anterior = buscarAnterior(aux);				//Sino, busca el nodo anterior al auxiliar.
		anterior->setProximo(aux->getProximo());				//Y al nodo anterior, sobreescribe su "proximo" con el "proximo" del nodo a eliminar
	}
	aux->setProximo(nullptr);									//Asigna nulo el apuntador del siguiente.
	delete aux;													//Borra el apuntador a eliminar.
	return "Eliminado exitoso";
}

//PRIMER NODO AGREGADO. El que tiene el apuntador nullptr.
template<class T>
string ListaSimple<T>::eliminarPrimero() {
	if (isEmpty())												//Si la lista está vacía, retorna mensaje.
		return "Lista vacia";
	Nodo<T>* anterior = nullptr;								//Un auxiliar para guardar el nodo anterior al primer nodo agregado.
	Nodo<T>* x = inicio;										//Auxiliar para el inicio.
	for (; x->getProximo(); x = x->getProximo())				//Para llegar al primer nodo.
		anterior = x;
	anterior->setProximo(nullptr);								//Como ya tenemos el nodo anterior al último, establece ése nodo como el primero, que su "proximo" apunte a un nullptr.
	delete x;													//Borra el viejo primer nodo (Ya como es el último, tiene el apuntador de próximo a nullptr).
	return "Eliminado exitoso";
}

//ULTIMO AGREGADO. Es decir el último nodo agregado.
template<class T>
string ListaSimple<T>::eliminarUltimo() {					
	if (isEmpty())												//Si la lista está vacía, retorna mensaje.
		return "Lista vacia";
	Nodo<T>* x = inicio;										//Auxiliar para el inicio.
	inicio = inicio->getProximo();								//Mueve el apuntador al siguiente nodo.
	x->setProximo(nullptr);
	delete x;													//Elimina el último nodo.
	return "Eliminado exitoso";
}

template<class T>
string ListaSimple<T>::mostrarNodos() {							
	string s = "Nodos: \n";										//Para retornar toda una cadena de Claves de nodos.
	for (Nodo<T>* x = inicio; x; x = x->getProximo())			//Recorre la lista...
		s.append(to_string(x->getClave()) + '\n');				//Y agrega las claves al string
	return s;													//Retornalo
}

template<class T>									
void ListaSimple<T>::vaciarLista() {
	while (Nodo<T>* aux = inicio) {			//Mientras aux != nullptr (O mejor dicho, que inicio != nullptr)
		inicio = inicio->getProximo();		//Inicio será igual al nodo que le sigue
		aux->setProximo(nullptr);			//Auxiliar apuntará a nullptr
		delete aux;							//Y borralo
	}
	

	/*for (; inicio; inicio = inicio->getProximo()) {
		Nodo<T>* aux = inicio;
		aux->setProximo(nullptr);
		delete aux;
	}*/

}

//Un método de ordenamiento burbuja 
template<class T>
string ListaSimple<T>::sortAscendente() {
	if (isEmpty())				//Si la lista está vacía, envía mensaje.
		return "Lista vacía";
	if (inicio->getProximo()) {	//Si existe más de un nodo
		
		bool pasada = false;	
		
		do {
			pasada = false;
			for (Nodo<T>* x = inicio; x->getProximo(); ) {	//Mientras el próximo de 'x' != nullptr
				Nodo<T>* proximo = x->getProximo();			//Guarda el "proximo" de 'x' en una variable
		
				if (proximo->getClave() < x->getClave()) {	//Si la clave del proximo nodo a 'x' es menor a la clave de 'x'...
					Nodo<T>* anterior = buscarAnterior(x);	//Busca anterior nodo
					x->setProximo(proximo->getProximo());	//El siguiente nodo de 'x' será el siguiente nodo de "proximo".
					proximo->setProximo(x);					//El siguiente nodo de proximo será 'x'
					anterior->setProximo(proximo);			//El anterior nodo a 'x' debe apuntar al nuevo nodo. 
					if (x == inicio)						//Si x == inicio...
						inicio = proximo;					//Inicio será igual a proximo 
					pasada = true;							//Y ocurrió una pasada.
				}
				else
					x = x->getProximo();					//Sino aumenta 'x'

			}
		} while (pasada);									//Sigue realizando esto siempre que se intercambien de posición los nodos.
		return "Ordenamiento exitoso";						//Retorna un mensaje
	}
	return "Solo existe un nodo. No es posible un ordenamiento";	//Si existe un sólo nodo...
}
int main() {
	ListaSimple<int> l;
	char opc = 'a';
	
	do {
		opc = leerChar("1 - Insertar nodo despúes de otro\n2 - Insertar nodo (Al inicio)\n3 - Insertar nodo (Al final)\n4 - Eliminar nodo\n5 - Eliminar primer nodo agregado\n6 - Eliminar ultimo nodo agregado\n7 - Mostrar Nodos\n8 - Ordenar ascendentemente\n9 - Salir");
		try {
			switch (opc) {
			case '1': {	//Insertar nodo despúes de otro
				int clave = leerEntero("Clave del nuevo nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				clave = leerEntero("Clave del nodo existente: ");
				cout << l.insertar(n, clave) << endl;
				break;
			}
			case '2': {	//Insertar nodo (Al inicio)
				int clave = leerEntero("Clave del nuevo nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				cout << l.insertarAlInicio(n) << endl;
				break;
			}
			case '3': {	//Insertar nodo (Al final)
				int clave = leerEntero("Clave del nuevo nodo: ");
				Nodo<int>* n = new Nodo<int>(clave);
				cout << l.insertarAlFinal(n) << endl;
				break;
			}
			case '4': {	//Eliminar nodo
				int clave = leerEntero("Clave del nodo a eliminar: ");
				cout << l.eliminar(clave) << endl;
				break;
			}
			case '5':	//Eliminar primer nodo agregado
				cout << l.eliminarPrimero() << endl;
				break;
			case '6':	//Eliminar ultimo nodo agregado
				cout << l.eliminarUltimo() << endl;
				break;
			case '7':	//Mostrar Nodos
				cout << l.mostrarNodos() << endl;
				break;
			case '8':
				cout << l.sortAscendente() << endl;
				break;
			case '9':	//Salir
				break;
			default:
				throw runtime_error("Opcion invalida");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '9');

	system("PAUSE");
	return 0;
}