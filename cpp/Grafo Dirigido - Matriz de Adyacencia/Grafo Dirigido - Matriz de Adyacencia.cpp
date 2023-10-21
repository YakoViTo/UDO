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


class GrafoDirigido {
	bool** matrizAdyacencia;
	int cantVertices;
public:
	GrafoDirigido(const short cantVertices) {
		this->cantVertices = cantVertices;
		matrizAdyacencia = new bool*[cantVertices];
		for (int i = 0; i < cantVertices; i++) {
			matrizAdyacencia[i] = new bool[cantVertices];
			for (int j = 0; j < cantVertices; j++)
				matrizAdyacencia[i][j] = false;
		}
	}
	string agregarArco(int i, int j) {
		if (i >= 0 && i < cantVertices && j >= 0 && j < cantVertices) {
			if (matrizAdyacencia[i][j] != 1) {
				matrizAdyacencia[i][j] = true;
				return "Arco agregado\n";
			}
			else
				return "Ya existe un arco entre los vertices\n";
		}
		throw runtime_error("Vertices invalidos\n");
	}

	string eliminarArco(int i, int j) {
		if (i >= 0 && i < cantVertices && j >= 0 && j < cantVertices) {
			if (matrizAdyacencia[i][j] != 0) {
				matrizAdyacencia[i][j] = false;
				return "Arco eliminado\n";
			}
			else
				return "No existe un arco entre los vertices\n";
		}
		throw runtime_error("Vertices invalidos\n");
	}

	bool isArco(int i, int j) {
		return matrizAdyacencia[i][j];
	}

	string mostrarMatriz() {
		string s = "Matriz:\n";
		for (int i = 0; i < cantVertices; i++) {
			for (int j = 0; j < cantVertices; j++)
				s.append(to_string(matrizAdyacencia[i][j]) + ' ');
			s.append("\n");
		}
		return s;
	}

	~GrafoDirigido() {
		for (int i = 0; i < cantVertices; i++)
			delete[] matrizAdyacencia[i];
		delete[] matrizAdyacencia;
	}
};


int main() {
	char opc = '1';
	int cant = leerEntero("Cant. de vertices: ");
	GrafoDirigido g(cant);
	cout << "Grafo Dirigido - Matriz de Adayacencia" << endl;
	do {
		opc = leerChar("1 - Agregar arco\n2 - Eliminar Arco\n3 - Arco entre vertice vi y vj\n4 - Mostrar matriz\n5 - Salir");
		try {
			switch (opc) {
			case '1': {
				int v1 = leerEntero("Vertice de salida: ");
				int v2 = leerEntero("Vertice de entrada: ");
				cout << g.agregarArco(--v1, --v2) << endl;
				break;
			}
			case '2': {
				int v1 = leerEntero("Vertice de salida: ");
				int v2 = leerEntero("Vertice de entrada: ");
				cout << g.eliminarArco(--v1, --v2) << endl;
				break;
			}
			case '3': {
				int v1 = leerEntero("Vertice de salida: ");
				int v2 = leerEntero("Vertice de entrada: ");
				cout << g.isArco(--v1, --v2) << endl;
				break;
			}
			case '4':
				cout << g.mostrarMatriz() << endl;
				break;
			case '5':
				break;
			default:
				throw runtime_error("Opcion invalida\n");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '5');
	return 0;
}