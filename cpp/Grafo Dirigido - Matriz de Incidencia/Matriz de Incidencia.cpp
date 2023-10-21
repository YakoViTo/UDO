#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

const int cantVertices = 1;

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

class GrafoDirigido {
	int cant;
	bool matrizAdyacencia[cantVertices][cantVertices];
public:
	GrafoDirigido(const int cantVertices) {
		//matrizAdyacencia[cantVertices][cantVertices];
		cant = cantVertices;
		for (int i = 0; i < cant; i++) {
			for (int j = 0; j < cant; j++)
				matrizAdyacencia[i][j] = false;
		}
	}
	string agregarArco(const int i, const int j);
	string eliminarArco(const int i, const int j);
	bool isArcoEntreVertice(const int i, const int j);
	bool isArcoParalelo(const int i, const int j);
	int cantArcosParalelos();
	string mostrar();
};

string GrafoDirigido::agregarArco(const int i, const int j) {
	if (i >= 0 && i < cant&& j >= 0 && j < cant) {
		if (matrizAdyacencia[i][j] == 0) {
			matrizAdyacencia[i][j] = 1;
			return "Arco agregado\n";
		}
		else
			return "Vertices son adyacentes. Agregar ignorado\n";
	}
	throw runtime_error("Vertice invalido\n");
}

string GrafoDirigido::eliminarArco(const int i, const int j) {
	if (i >= 0 && i < cant && j >= 0 && j < cant) {
		if (matrizAdyacencia[i][j] == 1) {
			matrizAdyacencia[i][j] = 0;
			return "Arco eliminado\n";
		}
		else
			return "Vertices no son incidentes. Eliminar ignorado\n";
	}
	throw runtime_error("Vertice invalido\n");
}

bool GrafoDirigido::isArcoEntreVertice(const int i, const int j) {
	return matrizAdyacencia[i][j];
}

bool GrafoDirigido::isArcoParalelo(const int i, const int j) {
	if (matrizAdyacencia[i][j] == 1 && matrizAdyacencia[j][i] == 1)
		return true;
	return false;
}

int GrafoDirigido::cantArcosParalelos() {
	int cant = 0;
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < cant; j++)
			if (isArcoParalelo(i, j))
				cant++;
	}
	return cant;
}

string GrafoDirigido::mostrar() {
	string s = "Matriz de Adyacencia:\n";
	for (int i = 0; i < cant; i++) {
		for (int j = 0; j < cant; j++) {
			s.append(to_string(matrizAdyacencia[i][j]) + ' ');
		}
		s.append("\n");
	}
	return s;
}

int main() {
	char opc = '1';
	int cant = leerEntero("Cant. de vertices: ");
	GrafoDirigido g(cant);
	cout << "Grafo Dirigido - Matriz de Adayacencia" << endl;
	do {
		opc = leerChar("1 - Agregar arco\n2 - Eliminar Arco\n3 - Arco entre vertice vi y vj\n4 - Mostrar matriz\n5 - Cant. arcos paralelos\n6 - Salir");
		try {
			switch (opc) {
			case '1': {
				int vSalida = leerEntero("Vertice salida: ");
				int vEntrada = leerEntero("Vertice entrada: ");
				cout << g.agregarArco(--vSalida, --vEntrada) << endl;
				break;
			}
			case '2': {
				int vSalida = leerEntero("Vertice salida: ");
				int vEntrada = leerEntero("Vertice entrada: ");
				cout << g.eliminarArco(--vSalida, --vEntrada) << endl;
				break;
			}
			case '3': {
				int vSalida = leerEntero("Vertice salida: ");
				int vEntrada = leerEntero("Vertice entrada: ");
				cout << g.isArcoEntreVertice(--vSalida, --vEntrada) << endl;
				break;
			}
			case '4':
				cout << g.mostrar() << endl;
				break;
			case '5':
				cout << g.cantArcosParalelos() << endl;
				break;
			case '6':
				break;
			default:
				throw runtime_error("Opcion invalida\n");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '6');
	return 0;
}