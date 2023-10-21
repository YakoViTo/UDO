#include <iostream>
#include <string>
#include <stdexcept>
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

class Arco {
	string nombre;
	int peso;
	string nombreVertice;
	Arco* proximoArco;
public:
	Arco() { proximoArco = nullptr; }
	Arco(const string nombre) { this->nombre = nombre; proximoArco = nullptr; }
	Arco(const string nombre, const int peso) { this->nombre = nombre; this->peso = peso; proximoArco = nullptr; }
	string getNombre() const { return nombre; }
	string getNombreVertice() const { return nombreVertice; }
	int getPeso() const { return peso; }
	Arco* getProximoArco() const { return proximoArco; }
	void setNombre(const string nombre) { this->nombre = nombre; }
	void setPeso(const int peso) { this->peso = peso; }
	void setNombreVertice(const string nombreVertice) { this->nombreVertice = nombreVertice; }
	void setProximoArco(Arco* proximoArco) { this->proximoArco = proximoArco; }
};

class Vertice {
	string nombre;
	Vertice* proximoVertice;
	Arco* proximoArco;
public:
	Vertice(const string nombre) { 
		this->nombre = nombre;
		proximoArco = nullptr; 
		proximoVertice = nullptr; 
	}
	void setNombre(const string nombre) { this->nombre = nombre; }
	void setProximoVertice(Vertice* proximoVertice) { this->proximoVertice = proximoVertice; }
	void setProximoArco(Arco* proximoArco) { this->proximoArco = proximoArco; }
	string getNombre() const { return nombre; }
	Vertice* getProximoVertice() const { return proximoVertice; }
	Arco* getProximoArco() const { return proximoArco; }
};

class GrafoDirigido {
	Vertice* inicioVertice;
	//Agregado
	Arco* inicioArco;
public:
	GrafoDirigido() { inicioVertice = nullptr; inicioArco = nullptr; }
	string agregarVertice(Vertice* x);
	Vertice* buscarVertice(const string nombreVertice);
	Vertice* buscarVerticeAnterior(Vertice*& v);
	Arco* buscarArcoAnterior(Arco*& a);
	Arco* buscarArco(const string nombreArco);
	string agregarArco(const string verticeIncSalida, const string verticeIncEntrada, const int peso, const string nombreArco);
	string mostrarVertices();
	string mostrarArcos();
	int cantVerticesAislados();
	int cantLazos();
	int cantArcosParalelos();
	string eliminarArco(const string nombre);
	string eliminarVertice(const string nombre);
	bool isVerticeSumidero(Vertice*& v);
	bool isVerticeFuente(Vertice*& v);
	bool isVerticeAislado(Vertice*& v);
	int gradoVertice(Vertice*& v);
};

string GrafoDirigido::agregarVertice(Vertice* x) {
	if (buscarVertice(x->getNombre()))
		return "Existe otro vertice con el mismo nombre\n";
	x->setProximoVertice(inicioVertice);
	inicioVertice = x;
	return "Vertice Agregado\n";
}

Vertice* GrafoDirigido::buscarVertice(const string nombreVertice) {
	Vertice* x = inicioVertice;
	for (; x && x->getNombre() != nombreVertice; x = x->getProximoVertice());
	return x;
}

Arco* GrafoDirigido::buscarArco(const string nombreArco) {
	Arco* x = inicioArco;
	for (; x && x->getNombre() != nombreArco; x = x->getProximoArco());
	return x;
}

Vertice* GrafoDirigido::buscarVerticeAnterior(Vertice*& v) {
	Vertice* vAnterior = inicioVertice;
	for (Vertice* x = inicioVertice; x != v; x = x->getProximoVertice())
		vAnterior = x;
	return vAnterior;
}

Arco* GrafoDirigido::buscarArcoAnterior(Arco*& a) {
	Arco* aAnterior = inicioArco;
	for (Arco* x = inicioArco; x != a; x = x->getProximoArco())
		aAnterior = x;
	return aAnterior;
}

//AGREGAR ARCO
string GrafoDirigido::agregarArco(const string verticeIncSalida, const string verticeIncEntrada, const int peso, const string nombreArco) {
	Vertice* v = buscarVertice(verticeIncSalida);		//Busca el vertice con inc. de salida
	Vertice* v2 = buscarVertice(verticeIncEntrada);		//Busca el vertice con inc. de entrada
	if (!v || !v2)										//Si alguno de los dos son nullptr, retorna mensaje
		return "No existe uno o ambos vertices\n";
	if (buscarArco(nombreArco))							//Si el nombre del arco a agregar existe, retorna mensaje
		return "El nombre del arco existe\n";
	Arco* a = new Arco(nombreArco, peso);				//Crea el nuevo arco
	Vertice* aux = nullptr;								//Auxiliar para llegar al último vértice adyacente con el vertice 'v'
	for (Arco* x = v->getProximoArco(); x; x = aux->getProximoArco())		//Ciclo para recorrer las adyacencias de 'v'
		aux = buscarVertice(x->getNombreVertice());
	if (!aux)											//Si el aux sigue siendo nullptr
		aux = v;										//Aux será igual al vertice con inc. de salida
	aux->setProximoArco(a);								//Aux tendrá el próximo arco
	Vertice* v2Copy = new Vertice(v2->getNombre());
	a->setNombreVertice(v2->getNombre());				//El nombre del vertice que apunta 'a', será el nombre de v2
	//Agregando para fijar arcos siguientes
	a->setProximoArco(inicioArco);						//El nuevo arco tendrá "inicioArco" como el proximo arco
	inicioArco = a;										//"inicioArco" será el nuevo arco
	//
	return "Arco agregado\n";							//Retorna el mensaje
	
	//*Vieja manera. Altera los vertices*
	/*Vertice* v = buscarVertice(verticeIncSalida);		//Busca el vertice con inc. de salida
	Vertice* v2 = buscarVertice(verticeIncEntrada);		//Busca el vertice con inc. de entrada
	if (!v || !v2)										//Si alguno de los dos son nullptr, retorna mensaje
		return "No existe uno o ambos vertices\n";	
	if (buscarArco(nombreArco))							//Si el nombre del arco a agregar existe, retorna mensaje
		return "El nombre del arco existe\n";
	Arco* a = new Arco(nombreArco, peso);				//Crea el nuevo arco
	Vertice* aux = nullptr;								//Auxiliar para llegar al último vértice adyacente con el vertice 'v'
	for (Arco* x = v->getProximoArco(); x; x = aux->getProximoArco())
		aux = buscarVertice(x->getNombreVertice());
	aux->setProximoArco(a);								//El vertice con inc. de salida tendrá este nuevo arco
	a->setNombreVertice(v2->getNombre());				//El nuevo arco tendrá el vertice con inc. de entrada como su siguiente vertice
	//Agregado para fijar arcos siguientes
	a->setProximoArco(inicioArco);						//El nuevo arco tendrá "inicioArco" como el proximo arco
	inicioArco = a;										//"inicioArco" será el nuevo arco
	//
	return "Arco agregado\n";							//Retorna el mensaje*/
}

string GrafoDirigido::mostrarVertices() {
	string s = "Vertices: \n";
	for (Vertice* v = inicioVertice; v; v = v->getProximoVertice())
		s.append(v->getNombre() + '\n');
	return s;
}

string GrafoDirigido::mostrarArcos() {
	string s = "Arcos: \n";
	for (Arco* a = inicioArco; a; a = a->getProximoArco())
		s.append(a->getNombre() + '\n');
	return s;
}

int GrafoDirigido::cantVerticesAislados() {
	int cant = 0;
	for (Vertice* v = inicioVertice; v; v = v->getProximoVertice())
		if (isVerticeAislado(v))
			cant++;
	//Manera anterior antes de crear isVerticeAislado();
	/*for (Vertice* v = inicioVertice; v; v = v->getProximoVertice()) {
		Arco* a = nullptr;
		for (a = inicioArco; a && a->getNombreVertice() != v->getNombre(); a = a->getProximoArco());
		if (!a)
			cant++;
	}*/
	return cant;
}

int GrafoDirigido::cantLazos() {
	int cant = 0;
	for (Arco* a = inicioArco; a; a = a->getProximoArco()) {
		Vertice* vEntrada = buscarVertice(a->getNombreVertice());
		if (vEntrada->getProximoArco() == a)
			cant++;
	}
	return cant;
}

int GrafoDirigido::cantArcosParalelos() {
	int cant = 0;
	for (Arco* a = inicioArco; a; a = a->getProximoArco()) {
		Vertice* vEntrada = buscarVertice(a->getNombreVertice());
		Vertice* vSalida = buscarVerticeAnterior(vEntrada);
		for (Arco* a2 = a->getProximoArco(); a2; a2 = a2->getProximoArco()) {
			Vertice* v2Entrada = buscarVertice(a2->getNombreVertice());
			Vertice* v2Salida = buscarVerticeAnterior(v2Entrada);
			if (vEntrada == v2Entrada && vSalida == v2Salida)
				cant++;
		}
	}
	return cant;
}

string GrafoDirigido::eliminarArco(const string arco) {
	Arco* x = buscarArco(arco);
	if (!x)
		return "No se encontro el arco\n";
	Vertice* v = buscarVertice(x->getNombreVertice());	//Buscar el vertice al que apunta el arco
	Vertice* vAnterior = buscarVerticeAnterior(v);		//Buscar el vertice con inc. de salida del arco
	vAnterior->setProximoArco(nullptr);					//El vertice con inc. de salida se le quita la dirección al arco
	if (x == inicioArco)								//*Actualizar la lista de arcos* Si el arco a eliminar es igual a "inicioArco"
		inicioArco = inicioArco->getProximoArco();		//Corre "inicioArco" para el siguiente arco
	else {
		Arco* xAnterior = buscarArcoAnterior(x);		//Sino, busca el arco anterior al deseado
		xAnterior->setProximoArco(x->getProximoArco());		//El anterior arco, su proximo arco será el proximo del arco a eliminar.
	}
	x->setProximoArco(nullptr);							//Coloca el proximo arco del arco a eliminar como nullptr
	delete x;											//Borra el arco
	return "Arco eliminado\n";
}

string GrafoDirigido::eliminarVertice(const string vertice) {
	Vertice* x = buscarVertice(vertice);
	if (!x)
		return "No se encontro el vertice\n";
	
	if (x == inicioVertice)
		inicioVertice = inicioVertice->getProximoVertice();
	else {
		Vertice* xAnterior = buscarVerticeAnterior(x);
		xAnterior->setProximoVertice(x->getProximoVertice());
	}
	x->setProximoVertice(nullptr);
	delete x;
	return "Vertice eliminado\n";
}

bool GrafoDirigido::isVerticeAislado(Vertice*& v) {
	if (!v->getProximoArco()) {
		for (Arco* a = inicioArco; a; a = a->getProximoArco()) {
			Vertice* x = buscarVertice(a->getNombreVertice());
			if (v == x)
				return false;
		}
		return true;
	}
	return false;
}

bool GrafoDirigido::isVerticeSumidero(Vertice*& v) {
	if (!v->getProximoArco()) {
		for (Arco* a = inicioArco; a; a = a->getProximoArco()) {
			Vertice* x = buscarVertice(a->getNombreVertice());
			if (x == v)
				return true;
		}
	}
	return false;
}

bool GrafoDirigido::isVerticeFuente(Vertice*& v) {
	if (v->getProximoArco()) {
		for (Arco* a = inicioArco; a; a = a->getProximoArco()) {
			Vertice* x = buscarVertice(a->getNombreVertice());
			if (x == v)
				return false;
		}
		return true;
	}
	return false;
}

int GrafoDirigido::gradoVertice(Vertice*& v) {
	int grado = 0;
	for (Arco* a = inicioArco; a; a = a->getProximoArco()) {
		Vertice* x = buscarVertice(a->getNombreVertice());
		if (x == v)
			grado++;
	}
	if (v->getProximoArco()) {

	}
}

int main() {
	GrafoDirigido g;
	char opc = '1';
	cout << "Grafo Dirigido" << endl;
	do {
		opc = leerChar("1 - Agregar vertice\n2 - Agregar arco\n3 - Mostrar vertices\n4 - Mostrar arcos\n5 - Cant. vertices aislados\n6 - Cant. lazos\n7 - Cant. arcos paralelos\n8 - Eliminar arco\n9 - Eliminar vertice\n10 - Salir");
		switch (opc) {
		case '1': {
			string nombre;
			cout << "Nombre del vertice: ";
			cin >> nombre;
			cout << g.agregarVertice(new Vertice(nombre)) << endl;
			break;
		}
		case '2': {
			string vIEntrada, vISalida, nombre;
			cout << "Nombre del vertice incidente de entrada: ";
			cin >> vIEntrada;
			cout << "Nombre del vertice incidente de salida: ";
			cin >> vISalida;
			cout << "Nombre del arco: ";
			cin >> nombre;
			int peso = leerEntero("Peso del arco: ");
			cout << g.agregarArco(vISalida, vIEntrada, peso, nombre) << endl;
			break;
		}
		case '3':
			cout << g.mostrarVertices() << endl;
			break;
		case '4':
			cout << g.mostrarArcos() << endl;
			break;
		case '5':
			cout << g.cantVerticesAislados() << endl;
			break;
		case '6':
			cout << g.cantLazos() << endl;
			break;
		case '7':
			cout << g.cantLazos() << endl;
			break;
		case '8': {
			string nombre = "";
			cout << "Nombre del arco: ";
			cin >> nombre;
			cout << g.eliminarArco(nombre) << endl;
			break;
		}
		case '9': {
			string nombre = "";
			cout << "Nombre del vertice: ";
			cin >> nombre;
			cout << g.eliminarVertice(nombre) << endl;
			break;
		}
		case '10':
			break;
		default:
			throw runtime_error("Opcion inválida");
		}
	} while (opc != '5');
	cin.ignore();
	return 0;
}