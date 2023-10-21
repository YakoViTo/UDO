#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

inline void error (const string& s) {
    throw runtime_error(s);
}

inline void error (const string& s, const string& s2) {
   error(s + s2);
}

class Cliente {
    static const short int maxValue = 30;
    vector<char> nombre, apellido, telefono, email;
    short int edad;
    static int regNum;

public:
    Cliente (const vector<char>& n, const vector<char>& a, const vector<char>& t, const vector<char>& e, const short int ed) {
        nombre = n;
        apellido = a;
        email = e;
        telefono = t;
        edad = ed;
        regNum++;
    }
    int getRegNum () { return regNum; }
    short int getEdad() { return edad; }
    vector<char> getNombre () { return nombre; }
    vector<char> getApellido () { return apellido; }
    vector<char> getTelefono () { return telefono; }
    vector<char> getEmail () { return email; }
};

class GestorArchivo {
    string nombre;
public:
    GestorArchivo() {}
    GestorArchivo(const string nombre) { this->nombre = nombre; }
    short int leerDatos ();
};

short int GestorArchivo::leerDatos() {
    ifstream archivo {nombre.c_str()};
    if (!archivo) {
        if (archivo.fail()) {
            error("Ocurrió un error al leer el archivo: ", "\"" + nombre + "\"");
            return -1;
        }
        else
            if (archivo.bad()) {
               error("Error crítico al leer el archivo: ", "\"" + nombre + "\"");
               return -2; 
            }
        error("Ocurrió un error.");
        return -3;
    }
    vector<string> datos;
    for (string s; archivo >> s;)
        datos.push_back(s);
    for (string s : datos)
        cout << s << endl;
    return 0;
}

int main() {
    string nombreA;
    char op = 'n';
    cout << "Nombre del archivo: ";
    cin >> nombreA;
    
    GestorArchivo c (nombreA);
    short int operation = c.leerDatos();
    if (operation == -1)
        return -1;
        else
            if (operation == -2)
                return -2;
    
    /*char nombre[30];
    char apellido[30];
    char telefono[15];
    char email[60];
    short int edad = 0;*/
    
    /*do {
        cout << "Nombre y Apellido: ";
        cin >> nombre >> apellido;
        cout << "Edad: ";
        cin >> edad;
        cout << "Telefono: ";
        cin >> telefono;
        cout << "Email: ";
        cin >> email;
        cout << "¿Desea agregar otro cliente?: ";
    } while (cin >> op && (op != 'n' && op != 'N'));*/
    
    return 0;
}
