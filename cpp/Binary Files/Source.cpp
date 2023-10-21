#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

//Para definir tama�os en los arreglos de tipo 'char' en struct Cliente
constexpr char max = 30;

//Invocar cuando ocurra un error en el programa.
inline void error(const string& s) {
	throw runtime_error(s);
}

//Invocar cuando ocurra un error en el programa e indicar con el segundo par�metro, qu� archivo fue el que activ� el error.
inline void error(const string& s, const string& s2) {
	error(s + s2);
}

//Struct Cliente
struct Cliente {
	char nombre[max];
	char apellido[max];
	char telefono[max / 2];
	char email[max * 2];
	char cedula[max / 3];
	//Prefer� usar una variable de tipo "short" que un arreglo de tipo "char" de tama�o dos.
	short int edad;
};

//Funci�n para llenar todos los datos del Struct
void iniciarCliente(Cliente& c) {
	cout << "Nombre: ";
	cin >> c.nombre;
	cout << "Apellido: ";
	cin >> c.apellido;
	cout << "Edad: ";
	cin >> c.edad;
	cout << "Cedula: ";
	cin >> c.cedula;
	cout << "Telefono: ";
	cin >> c.telefono;
	cout << "Correo electronico: ";
	cin >> c.email;
}

//Igual que el primero, pero este muestra en la pantalla los datos.
void imprimirCliente(Cliente &c) {
	cout << "Nombre: " << c.nombre << endl;
	cout << "Apellido: " << c.apellido << endl;
	cout << "Cedula: " << c.cedula << endl;
	cout << "Email: " << c.email << endl;
	cout << "Telefono: " << c.telefono << endl;
	cout << "Edad: " << c.edad << endl << endl;
}

//Invocar cuando una variable de tipo "fstream" active un error. 
//Todos los m�todos deben tener una variable de tipo "fstream" (no "ifstream" o "ofstream") para que esta funci�n sea �til.
//En el caso de tener que ajustar esta funci�n con respecto a "ofstream" o "ifstream", lo �nico que se me ocurre ser�a sobrecargar la funci�n.
void errorArchivo(fstream& archivo, const string& nombre) {
	if (archivo.fail())
		error("fail(): Hubo un error al intentar abrir el archivo: ", "\"" + nombre + "\"");
	else
		if (archivo.bad())
			error("bad(): Hubo un error cr�tico al intentar abrir el archivo: ", "\"" + nombre + "\"");
	error("unknown: Ocurri� un error desconocido al intentar abrir el archivo: ", "\"" + nombre + "\"");
}

//Clase GestionArchivo
class GestionArchivo {
	//Nombre Archivo
	string nombre;

public:
	//Constructor por defecto.
	GestionArchivo() { nombre = "undefined.txt"; }
	
	//Constructor sobrecargado.
	GestionArchivo(const string nombre) { this->nombre = nombre; }
	
	//Extrae un Cliente del archivo binario y lo guarda en el objeto Cliente que se pase por argumento.
	void leerCliente(Cliente& c, long numRegistro);
	
	//Escribe en un archivo binario todos los datos del objeto Cliente que se pase por argumento.
	void escribirCliente(Cliente& c);
	
	//Retorna cantidad de registros
	long cantidadRegistros();
	
	//Mostrar una lista con los Clientes contenido en el archivo binario
	void mostrarClientes(Cliente& c);

	//Modifa clientes de la lista
	string modificarCliente(const long numRegistro, Cliente& c);

	//Elimina clientes de la lista
	string eliminarCliente(const long numRegistro);

};

void GestionArchivo::leerCliente(Cliente& c, long numRegistro) {
	//�Existe una diferencia si uso "fstream" s�lo para leer en vez de "ifstream" (el mismo caso sucede para escribir con "ofstream")? 
	//S�lo lo uso para respetar la funci�n "errorArchivo".
	fstream archivo{ nombre.c_str(), ios::in | ios::binary };
	if (!archivo)
		errorArchivo(archivo, nombre);
	
	archivo.seekg((long)numRegistro * sizeof(Cliente), ios::beg);	//Mover el apuntador de lectura seg�n el calculo a continuaci�n
	archivo.read(reinterpret_cast<char*>(&c), sizeof(Cliente));		//Leer la secci�n y guardarla en 'c'.
}

void GestionArchivo::escribirCliente(Cliente& c) {
	//De nuevo, "fstream", donde aqu� s�lo se escribe.
	fstream archivo{ nombre.c_str(), ios::out | ios::binary | ios::app };
	if (!archivo)
		errorArchivo(archivo, nombre);

	archivo.write(reinterpret_cast<char*>(&c), sizeof(Cliente));	//Escribir en la siguiente secci�n disponible.
}

long GestionArchivo::cantidadRegistros() {
	fstream archivo(nombre.c_str(), ios::in | ios::binary);
	if (!archivo)
		errorArchivo(archivo, nombre);

	archivo.seekg(long(0), archivo.end);	//Mover apuntador al final, para revisar tama�o del archivo.
	return (long) archivo.tellg()/ sizeof(Cliente);		//Retornar cantidad de bytes totales entre el tama�o del Struct Cliente.
}

void GestionArchivo::mostrarClientes(Cliente& c) {
	fstream archivo(nombre.c_str(), ios::in | ios::binary);
	if (!archivo)
		errorArchivo(archivo, nombre);

	while (archivo.read(reinterpret_cast<char*>(&c), sizeof(Cliente)))
		imprimirCliente(c);
}

string GestionArchivo::modificarCliente(const long numReg, Cliente& c) {
	fstream archivo(nombre.c_str(), ios::out | ios::binary);
	if (!archivo)
		errorArchivo(archivo, nombre);
	archivo.seekp(numReg * sizeof(Cliente), ios::beg);
	archivo.write(reinterpret_cast<char*>(&c), sizeof(Cliente));
	return "Exito";
}

string GestionArchivo::eliminarCliente(const long numReg) {
	fstream archivo(nombre.c_str(), ios::in | ios::binary);
	if (!archivo)
		errorArchivo(archivo, nombre);
	
	char nuevoNombre[] = "temp.bin";
	fstream nuevoArchivo(nuevoNombre, ios::out | ios::binary | ios::app);
	Cliente c;

	archivo.seekg(numReg * sizeof(Cliente), ios::beg);
	long pos = archivo.tellg();
	archivo.seekg(0, ios::beg);
	
	while (archivo.read(reinterpret_cast<char*>(&c), sizeof(Cliente))) {
		long curr = archivo.tellg();
		if (curr != pos)
			nuevoArchivo.write(reinterpret_cast<char*>(&c), sizeof(Cliente));
	}

	archivo.close();
	nuevoArchivo.close();

	remove(nombre.c_str());
	rename(nuevoNombre, nombre.c_str());
	return "Exito";
}


int main() {
	//Pocas opciones en el men�. Prefiero declarar una variable de tipo "char" en vez de short.
	char opc = '1';
	//Objeto Cliente
	Cliente c;
	//Para el nombre del archivo
	string nArchivo = "";

	cout << "Nombre del archivo: ";
	cin >> nArchivo;

	//Creaci�n del objeto GestionArchivo
	GestionArchivo ga(nArchivo);
	
	//Do
	do {
		//Men�
		cout << "1 - Escribir datos a archivo\n2 - Leer datos en archivo\n3 - Ver tama�o de registros\n4 - Mostrar Clientes\n5 - Modificar Cliente\n6 - Eliminar\n7 - Salir" << endl;
		//Tomar opci�n ingresada por el usuario.
		cin >> opc;

		//Switch
		switch (opc) {
		//Escribir datos.
		case '1': {
			//Try
			try {
				for (char opc = 'a'; opc != 'n' && opc != 'N'; ) {
					//Llenar datos.
					iniciarCliente(c);
					//Enviar datos al objeto GestionArchivo
					ga.escribirCliente(c);
					//Opci�n.
					cout << "�Ingresar otro cliente? (Presione cualquier tecla para continuar, 'n' para salir): ";
					cin >> opc;
				}
			}
			//Catch
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		//Leer datos.
		case '2': {
			//Para el n�mero del registro
			long reg = 0;

			cout << "Que registro desea leer? (S�lo valores n�mericos positivos): ";
			cin >> reg;
			try {
				//Leer. Se envia como parametro el objeto Cliente declarado arriba y la variable "reg".
				ga.leerCliente(c, reg);
				//Imprimir el Cliente extraido.
				imprimirCliente(c);
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
		case '3':
			//Ver tama�o de registros.
			try {
				//Retornar tama�o de registro. Si ocurre error, pasa al bloque "catch"
				cout << ga.cantidadRegistros() << endl;
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		case '4':
			//Mostrar una lista con los Clientes en el archivo binario
			try {
				//Si falla, pasa al bloque "catch"
				ga.mostrarClientes(c);
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		case '5': {
			long numReg = 0;
			cout << "Ingrese n�mero de registro a modificar: ";
			cin >> numReg;
			iniciarCliente(c);
			cout << ga.modificarCliente(numReg, c) << endl;
			break;
		}
		case '6': {
			long numReg = 0;
			cout << "Ingrese n�mero de registro eliminar: ";
			cin >> numReg;
			cout << ga.eliminarCliente(numReg) << endl;
			break;
		}
		case '7':
			break;
		default:
			//Usuario ingres� valor indeseado.
			try {
				error("Opci�n inv�lida."); //Esto nunca debe ocurrir.
			}
			catch (exception e) {
				cout << e.what() << endl;
			}
			break;
		}
	//Repite esto siempre y cuando el usuario no ingrese '5' (Salir del programa).
	} while (opc != '7');
	
	//Pausar
	system("PAUSE");
	
	return 0;
}