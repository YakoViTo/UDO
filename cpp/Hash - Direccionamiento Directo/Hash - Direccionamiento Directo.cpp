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


constexpr short max = 11;
constexpr short maxDato = 30;

struct Dato {
	char nombre[maxDato];
	char apellido[maxDato];
	short edad;
	char cedula[maxDato / 2];
	short clave;
};

class DirDirecto {
	Dato* t[max];
public:
	DirDirecto() {};
	string insertar(Dato* x);
	string eliminar(Dato* x);
	Dato* buscar(const short clave);
	string mostrar();
};

string DirDirecto::insertar(Dato* x) {
	if (x->clave >= max) {
		delete x;
		throw runtime_error("Clave fuera del rango\n");
	}
	t[x->clave] = x;
	return "Nodo insertado\n";
}

string DirDirecto::eliminar(Dato* x) {
	if (x->clave >= max) {
		delete x;
		throw runtime_error("Clave fuera del rango\n");
	}
	if (!buscar(x->clave)) {
		delete x;
		throw runtime_error("Nodo no exite");
	}
	t[x->clave] = nullptr;
	return "Nodo eliminado\n";
}

Dato* DirDirecto::buscar(const short clave) {
	return t[clave];
}

string DirDirecto::mostrar() {
	string s = "Datos:\n";
	for (int i = 0; i != max; i++)
		if (t[i])
			s.append(to_string(*t[i]->nombre) + "\n");
	return s;
}

void llenarDato(Dato*& d) {
	cout << "Nombre: ";
	cin >> d->nombre;
	cout << "Apellido: ";
	cin >> d->apellido;
	cout << "Edad: ";
	cin >> d->edad;
	cout << "Cedula: ";
	cin >> d->cedula;
	cout << "Clave: ";
	cin >> d->clave;
}

int main() {
	DirDirecto dd;
	char opc = '1';
	cout << "Hashing - Direccionamiento Directo" << endl;
	do {
		opc = leerChar("1 - Insertar\n2 - Eliminar\n3 - Mostrar Datos\n4 - Salir");
		try {
			switch (opc) {
			case '1': {
				Dato* d = new Dato;
				llenarDato(d);
				cout << dd.insertar(d) << endl;
				break;
			}
			case '2': {
				Dato* d;
				llenarDato(d);
				cout << dd.eliminar(d) << endl;
				break;
			}
			case '3':
				cout << dd.mostrar() << endl;
				break;
			case '4':
				break;
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '4');
	system("PAUSE");
	return 0;
}