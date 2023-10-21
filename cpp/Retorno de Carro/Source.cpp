#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

inline void error(const string& s) {
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2) {
	error(s + s2);
}

//Clase
class GestionArchivo {
	string nombre;
public:
	GestionArchivo() { nombre = "archivo.txt"; }
	GestionArchivo(const string nombre) { this->nombre = nombre; }
	long contarCaracterCarga();
	void errorArchivo(ifstream& archivo);
};

//Error Archivo
void GestionArchivo::errorArchivo(ifstream& archivo) {
	if (archivo.fail())
		error("Ocurrio un error al intentar abrir el archivo: ", "\"" + nombre + "\"");
	else
		if (archivo.bad())
			error("Ocurrio un error critico al intentar abrir el archivo: ", "\"" + nombre + "\"");
	error("Ocurrio un error desconocido al intentar abrir el archivo: ", "\"" + nombre + "\"");
}

//Contar Caracter de Carga
long GestionArchivo::contarCaracterCarga() {
	//Abrir el archivo en Binario
	ifstream archivo{ nombre.c_str(), ios::binary };
	
	//Si ocurre un error, tíra una excepción.
	if (!archivo)
		errorArchivo(archivo);
	
	//Sino realiza la operación
	char e = 'a';
	long cantCaracteres = 0;

	//Conocer el tamaño del archivo y guardalo en una variable.
	archivo.seekg(0, ios::end);
	long tamano = archivo.tellg();
	archivo.seekg(0, ios::beg);

	for (long i = 0; i < tamano; i++) {
		archivo.read(reinterpret_cast<char*>(&e), sizeof(char));
		if (e == '\r')
			//Aumenta la variable si encontró el caracter buscado.
			cantCaracteres++;
	}
	//Y retornalo
	return cantCaracteres;
}

int main() {
	//Para el nombre del archivo.
	string s = "";
	do {
		cout << "Nombre del archivo: ";
		cin >> s;
		
		GestionArchivo g(s);
		try {
			cout << g.contarCaracterCarga() << " caracteres de carro existen en el archivo." << endl;
			break;
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		
	} while (true);
	system("PAUSE");
	return 0;
}