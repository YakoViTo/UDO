#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

const char maxCant = 30;

inline void error (const string& message) {
    throw runtime_error(message);
}

inline void error (const string& message, const string& name) {
     error(message + name);
}

struct Cliente {
    char nombre[maxCant/2];
    char apellido[maxCant/2];
    char email[maxCant];
    char telefono[15];
    short int edad;
};

class GestionArchivo {
    string nombre;

public:
    GestionArchivo(){}
    GestionArchivo(string nombre){ this->nombre = nombre; }
    void escribirCliente(Cliente& c);
};

void GestionArchivo::escribirCliente(Cliente& c) {
    ofstream archivo{nombre.c_str(), ios_base::app};
    if (archivo) {
        archivo << "Nombre: " << c.nombre << endl
        << "Apellido: " << c.apellido << endl
        << "Edad: " << c.edad << endl
        << "Telefono: " << c.telefono << endl
        << "E-mail: " << c.email << endl
        << "\n---------------------\n" << endl;
    }
    else
        error ("Ocurrió un error al crear el archivo: ", nombre);
}



inline void leer (const string message, Cliente& c, const char& car) {
    cout << message;
    switch (car) {
        case 'n': case 'N':
            cin >> c.nombre;
            break;
        case 'a': case 'A':
            cin >> c.apellido;
            break;
        case '@':
            cin >> c.email;
            break;
        case 't': case 'T':
            cin >> c.telefono;
            break;
        case 'e': case 'E':
            cin >> c.edad;
            break;
        default:
            error("Campo no encontrado en cliente.");
    }
}

int main()
{
    string nombre;

    cout << "Ingrese nombre del archivo a crear: ";
    cin >> nombre;

    GestionArchivo ga(nombre);

    Cliente c;

    leer("Ingrese nombre: ", c, 'n');
    leer("Ingrese apellido: ", c, 'a');
    leer("Ingrese edad: ", c, 'e');
    leer("Ingrese email: ", c, '@');
    leer("Ingrese telefono: ", c, 't');

    try {
        ga.escribirCliente(c);
    }
    catch (runtime_error& e) {
        cout << e.what() << endl;
        return -1;
    }
    cout << "Exito" << endl;
    /*cout << "Ingrese nombre y apellido del cliente: ";
    cin >> c.nombre >> c.apellido;

    cout << "Ingrese telefono: ";
    cin >> c.telefono;

    cout << "Ingrese email: ";
    cin >> c.email;

    cout << "Ingrese edad: ";
    cin >> c.edad;*/


    return 0;
}
