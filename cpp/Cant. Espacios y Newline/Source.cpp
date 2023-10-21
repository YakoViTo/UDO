#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

//Invocar cuando suceda un error en el programa.
inline void error(const string& s) {
	throw runtime_error(s);
}

//Invocar cuando suceda un error en el programa, colocando otra cadena como parámetro para mostrar qué archivo tuvo el error.
inline void error(const string& s, const string& s2) {
	error(s + s2);
}

//Llamar cuando "ifstream archivo" sea falso. 
short int archivoError(ifstream& archivo, const string& nombre) {
	//Si fue un error de tipeo o el archivo simplemente no existe.
	if (archivo.fail()) {
		error("Ocurrió un error al intentar abrir el archivo: ", "\"" + nombre + "\"");
		return -1;
	}
	else
		//Si hubieron problemas peores que el de arriba.
		if (archivo.bad()) {
			error("Ocurrió un error crítico al intentar abrir el archivo: ", "\"" + nombre + "\"");
			return -2;
		}
	//Si alguno de los dos anteriores no se cumple. No debería ocurrir.
	error("Ocurrió un error desconocido al intentar abrir el archivo: ", "\"" + nombre + "\"");
	return -3;
}

//Clase GestionArchivo
class GestionArchivo {
	//Nombre de Archivo.
	string nombre;
public:
	//Constructor por defecto.
	GestionArchivo() { nombre = "archivo.txt"; }
	//Constructor sobrecargado.
	GestionArchivo(const string nombre) { this->nombre = nombre; }
	//El método principal.
	long cantEspaciosNewline();
};

long GestionArchivo::cantEspaciosNewline() {
	ifstream archivo(nombre.c_str());
	if (archivo) {
		long cant = 0;
		for (char ch = 'a'; ch = archivo.get();) {
			if (archivo.eof())
				return cant;
			//Si ch es un espacio o un caracter nueva linea, incremetar 'cant'.
			if (isspace(ch))
				cant++;
		}
	}
	//Retornar valores de error si no se lee exitosamente el archivo.
	return archivoError(archivo, nombre);
}

int main() {
	//Variable para nombre del archivo.
	string nombre = "";
	
	do {
		cout << "Nombre del archivo a leer: ";
		cin >> nombre;

		//Crear objeto.
		GestionArchivo g(nombre);
		try {
			//Mostrar cantidad retornada. Si ocurre un error, no se muestra nada, se mueve directo al bloque "catch".
			cout << g.cantEspaciosNewline() << " espacios y caracteres nueva linea" << endl;
			break;
		}
		catch (exception e) {
			//Mostrar en la pantalla qué error fue activado.
			cout << e.what() << endl;
		}
		//Realizar esto tantas veces sea necesario si los errores persisten.
	} while (true);

	//Pausar.
	system("PAUSE");

	return 0;
}