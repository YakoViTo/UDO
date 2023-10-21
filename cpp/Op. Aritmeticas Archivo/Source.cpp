#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

inline void error(const string& s) {
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2) {
	error(s + "\"" + s2 + "\"");
}

string leerCadena(const string& message) {
	string s = "";
	do {
		try {
			cout << message;
			cin >> s;
			if (cin.fail())
				throw runtime_error("Error de entrada.");
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	return s;
}

class GestionArchivo {
	string nombre;
public:
	GestionArchivo() { nombre = "archivo.txt"; }
	GestionArchivo(const string nombre) { this->nombre = nombre; }
	void errorArchivo(ifstream& archivo);
	string opAritmeticas();
};

//Error archivo
void GestionArchivo::errorArchivo(ifstream& archivo) {
	if (archivo.fail())
		error("Ocurrió un error intentando leer el archivo: ", nombre);
	else
		if (archivo.bad())
			error("Ocurrió un error critico intentando leer el archivo: ", nombre);
	error("Ocurrió un error desconocido intentando leer el archivo: ", nombre);
}

string GestionArchivo::opAritmeticas() {
	ifstream archivo{ nombre.c_str() };
	
	if (!archivo)
		errorArchivo(archivo);
	
	string s = "";
	
	while (!(archivo.eof())) {
		string linea = "";
		long lineValue = 0;
		char op = 'a';

		getline(archivo, linea);
		
		for (string::iterator i = linea.begin(); i != linea.end(); ) {
			
			if (isdigit(*i) && !isspace(*i)) {
				int auxValue = 0;
				
				for (int x = 1; i != linea.end() && isdigit(*i); i++) {
					auxValue *= x;
					auxValue += *i - '0';
					x *= 10;
				}

				switch (op) {
				case '+':
					lineValue += auxValue;
					break;
				case '-':
					lineValue -= auxValue;
					break;
				case '*':
					lineValue *= auxValue;
					break;
				default:
					lineValue = auxValue;
				}

			}
			else {
				if (!isspace(*i))
					op = *i;
				i++;
			}
		}

		s.append(to_string(lineValue) + '\n');
	}
	
	return s;
}

int main() {
	do {
		string s = leerCadena("Nombre del archivo: ");
		GestionArchivo g(s);
		try {
			cout << g.opAritmeticas() << endl;
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	system("PAUSE");
	return 0;
}