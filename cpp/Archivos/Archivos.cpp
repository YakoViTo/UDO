#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

string formatString(string& s) {
	if (s.empty())
		return "NONAME";
	string newString;
	for (string::iterator it = s.begin(); it != s.end(); ++it)
		if (isalpha(*it))
			newString.push_back(toupper(*it));
	if (s.empty())
		return "NONAME";
	return newString;
}

class GestorInventario {
	float precio;
	string nombreProducto;
	int cantidad;
	string nombreArchivo;
public:
	GestorInventario(const string s) { nombreArchivo = s; }
	void fijarNombreArchivo(const string s) { nombreArchivo = s; }
	void mostrarInventario();
	void agregarProducto();
	bool isProductNameRepeated(const string& s);
};

void GestorInventario::mostrarInventario() {
	std::ifstream archivo (nombreArchivo.c_str());
	if (!archivo) {
		string functionName = "mostrarInventario()";
		if (archivo.fail())
			throw std::runtime_error("fail() in " + functionName + "\n");
		if (archivo.bad())
			throw std::runtime_error("bad() in " + functionName + "\n");
		throw std::runtime_error("Unknown error in " + functionName + "\n");
	}
	cout << "Inventario actual:" << endl << endl;
	while (archivo >> nombreProducto >> cantidad >> precio) {
		cout << "Producto: " << nombreProducto << endl;
		cout << "Cantidad: " << cantidad << endl;
		cout << "Precio: " << precio << endl << endl;
	}
}

bool GestorInventario::isProductNameRepeated(const string& s) {
	std::ifstream archivo(nombreArchivo.c_str());
	string nombre;
	int cant;
	float precio;
	while (archivo >> nombre >> cant >> precio)
		if (nombre.compare(s) == 0)
			return true;
	return false;
}

void GestorInventario::agregarProducto() {
	std::ofstream archivo (nombreArchivo.c_str(), std::ios::app);
	if (!archivo) {
		string functionName = "agregarProducto()";
		if (archivo.fail())
			throw std::runtime_error("fail() in " + functionName + "\n");
		if (archivo.bad())
			throw std::runtime_error("bad() in " + functionName + "\n");
		throw std::runtime_error("Unknown error in " + functionName + "\n");
	}
	
	do {
		cout << "Producto: ";
		getline(cin, nombreProducto);
		nombreProducto = formatString(nombreProducto);
		if (isProductNameRepeated(nombreProducto))
			cout << "Nombre repetido. Escoja otro\n";
		else
			break;
	} while (true);
	
	cout << "Cantidad: ";
	cin >> cantidad;
	cout << "Precio: ";
	cin >> precio;
	archivo << nombreProducto << ' ' << cantidad << ' ' << precio << endl;
}

int main() {
	GestorInventario gi("Inventario.dat");
	try {
		gi.agregarProducto();
		gi.mostrarInventario();
	}
	catch (std::runtime_error& e) {
		cerr << e.what() << endl;
		return -1;
	}
	catch (...) {
		cerr << "Unknown exception caught in main()" << endl;
		return -2;
	}
	return 0;
}