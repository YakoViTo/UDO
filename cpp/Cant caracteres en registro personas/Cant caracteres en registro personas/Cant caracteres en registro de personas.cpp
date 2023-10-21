#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
using namespace std;

//Para definir el tamaño de los arreglos.
constexpr short int max = 30;

inline void error(const string& s) {
	throw runtime_error(s);
}

//Struct
struct Persona {
	char nombre[max];
	char apellido[max];
};

//Clase
class GestionArchivo {
	string nombre;
public:
	GestionArchivo() { nombre = "archivo.txt"; }
	GestionArchivo(const string nombre) { this->nombre = nombre; }
	void errorArchivo(fstream& archivo);
	void escribirArchivo(Persona& c);
	long cantCaracteres();
	//void cantCaracteres(long& nom, long& ape);
};

//Tuve que escribir para crear el archivo binario
void GestionArchivo::escribirArchivo(Persona& c) {
	fstream archivo(nombre.c_str(), ios::out | ios::binary | ios::app);
	if (!archivo)
		errorArchivo(archivo);
	archivo.write(reinterpret_cast<char*>(&c), sizeof(Persona));
}

void GestionArchivo::errorArchivo(fstream& archivo) {
	if (archivo.fail())
		error("Archivo no encontrado.");
	else
		if (archivo.bad())
			error("Error crítico al leer el archivo.");
	error("Ocurrió un error desconocido al leer el archivo");
}

//Función principal
long GestionArchivo::cantCaracteres() {
	fstream archivo(nombre.c_str(), ios::in | ios::binary);
	if (archivo) {
		//Cantidad a retornar
		long cant = 0;
	
		for (Persona p; archivo.read(reinterpret_cast<char*>(&p), sizeof(Persona)); ) {
			
			//Recorrer el arreglo para contar.
			for (short i = 0; p.nombre[i] != '\0'; i++) {
				char ch = p.nombre[i];
				//Por si acaso, analiza si es un caracter alfábetico.
				if (isalpha(ch))
					cant++;
			}

			//Recorrer el arreglo para contar.
			for (short i = 0; p.apellido[i] != '\0'; i++) {
				char ch = p.apellido[i];
				//Por si acaso, analiza si es un caracter alfábetico.
				if (isalpha(ch))
					cant++;
			}
			
		}
		return cant;
	}
	//Si ocurrió un error arriba. Tira error.
	errorArchivo(archivo);
}

//De otra manera...
//Pasando como argumento dos variables long para el nombre y el apellido.
/*void GestionArchivo::cantCaracteres(long& nom, long& ape) {
	fstream archivo(nombre.c_str(), ios::in | ios::binary);
	if (archivo) {
		for (Persona p; archivo.read(reinterpret_cast<char*>(&p), sizeof(Persona)); ) {

			for (short i = 0; p.nombre[i] != '\0'; i++) {
				char ch = p.nombre[i];
				if (isalpha(ch))
					nom++;
			}

			for (short i = 0; p.apellido[i] != '\0'; i++) {
				char ch = p.apellido[i];
				if (isalpha(ch))
					ape++;
			}

		}
	}
	errorArchivo(archivo);
}*/


void escribirPersona(Persona& p) {
	cout << "Nombre: ";
	cin >> p.nombre;
	cout << "Apellido: ";
	cin >> p.apellido;
}

int main() {
	string s = "";
	char opc = 'a';
	cout << "Nombre del archivo: ";
	cin >> s;
	GestionArchivo g(s);
	do {
		try {
			cout << "1 - Escribir archivo\n2 - Leer Archivo\n3 - Salir" << endl;
			cin >> opc;

			switch (opc) {
			case '1':
				Persona p;
				for (char ch = 'a'; ch != 'x' && ch != 'X'; ) {
					escribirPersona(p);
					g.escribirArchivo(p);
					cout << "Agregar otra persona? (Presione 'x' para salir): ";
					cin >> ch;
				}
				break;
			case '2':
				//long cantNom = 0;
				//long cantApe = 0;
				cout << g.cantCaracteres() << " caracteres entre nombre y apellido." << endl;
				//g.cantCaracteres(cantNom, cantApe);
				//cout << cantNom << " caracteres totales en nombre." << endl;
				//cout << cantApe << " caracteres totales en apellido." << endl;
				break;
			case '3':
				break;
			default:
				error("Opción inválida.");
			}
		}
		catch (runtime_error e) {
			cout << e.what() << endl;
		}
	} while (opc != '3');
	system("PAUSE");
	return 0;
}