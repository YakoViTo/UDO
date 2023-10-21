/*
8. Dise�e una funci�n en C++ que permita almacenar en un arreglo de objetos
del tipo String todas las l�neas almacenadas en un archivo de texto. El arreglo 
debe ser retornado o enviado como par�metro por referencia a la funci�n
*/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

//Tirar excepci�n
inline void error(const string& s) {
	throw runtime_error(s);
}

//Sobrecarga
inline void error(const string& s, const string& s2) {
	//Muestra el mensaje y encierra en comillas el objeto que activ� el error.
	error(s + "\"" + s2 + "\"");
}

string leerCadena(const string& s) {
	string s2 = "";
	do {
		try {
			cout << s;
			cin >> s2;
			if (cin.fail()) {
				cin.clear();
				throw runtime_error("Error de entrada.");
			}
			break;
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	return s2;
}

//Clase
class GestionArchivo {
	string nombre;
public:
	GestionArchivo() { nombre = "archivo.txt"; }
	GestionArchivo(const string nombre) { this->nombre = nombre; }
	void errorArchivo(ifstream& archivo);
	string* almacenarLineas();
};

//Tirame el error correspondiente si te llamamos
void GestionArchivo::errorArchivo(ifstream& archivo) {
	if (archivo.fail())
		error("Ocurri� un error al leer el archivo: ", nombre);
	else
		if (archivo.bad())
			error("Ocurri� un error cr�tico al leer el archivo: ", nombre);
	error("Ocurri� un error desconocido al leer el archivo: ", nombre);
}

//Funci�n principal
string* GestionArchivo::almacenarLineas() {
	ifstream archivo(nombre.c_str());
	if (!archivo)
		errorArchivo(archivo);
	
	//Operaci�n principal
	//El tama�o para el arreglo.
	int tamano = 0;

	//Para determinar cu�ntas l�neas existen en el archivo
	for (string s = ""; getline(archivo, s); tamano++);
													//Se lee en una variable 's', pero se pierde la l�nea completa.

	string* texto = new string[tamano];		//Crea el arreglo din�mico y define su tama�o seg�n el valor de "tamano".
	archivo.seekg(0, ios::beg);				//Regresa el apuntador al inicio.
	
	//Almacena las l�neas en el arreglo.
	for (int i = 0; i < tamano; i++) {
		
		string linea = "";		//Crea una variable "string" para almacenar la l�nea (nuevamente)...
		getline(archivo, linea);
		texto[i] = linea;		//...y almacenala en el arreglo.
	
	}

	//Finalmente retornalo
	return texto;
}

//No entiendo por qu� de este modo no funciona. 
//La �nica diferencia de aqu� es que leo por caracter en vez de la l�nea completa.
//Pero luego en el ciclo donde se almacenan las cadenas en el arreglo, "linea" est� vac�a.
/*string* GestionArchivo::almacenarLineas() {
	ifstream archivo(nombre.c_str());
	if (!archivo)
		errorArchivo(archivo);
	
	int tamano = 0;
	string linea = "";
	//	for (char c = 'a'; !archivo.eof(); ) {
	//	archivo.read(reinterpret_cast<char*>(&c), sizeof(char));
	//	if (c == '\r')
	//		tamano++;
	//}
	while (true) {
		char ch = archivo.get();
		if (archivo.eof())
			break;
		if (ch == '\r')
			tamano++;
	}
	string* texto = new string[tamano];
	archivo.seekg(0, ios::beg);
	for (int i = 0; i < tamano; i++) {
		getline(archivo, linea);
		texto[i] = linea;
	}
	return texto;
}*/

//main
int main() {
	do {
		string s = leerCadena("Nombre del archivo: ");		//Almacena la cadena.
		GestionArchivo g(s);								//Crea la instancia.
		try {
			string* kk = g.almacenarLineas();				//Realiza la operaci�n.
			/*
				Si quisiera mostrar en la consola las l�nes obtenidas, tendr�a que cambiar el tipo de retorno para
				tener en el main() el tama�o del arreglo.
			*/
			delete[] kk;									//Como ya se us�, borrala.
			break;											//Termina el programa si todo sali� bien.
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (true);
	system("PAUSE");
	return 0;
}