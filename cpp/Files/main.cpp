#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void error (string x) {
    cerr << x;
}

class GestorArchivo {
    string nombre;
    
    public:
        GestorArchivo() {}
        GestorArchivo(string nombre) {this->nombre = nombre;}
        int contarLineasEspacios();
};

int GestorArchivo::contarLineasEspacios() {
    ifstream archivo (nombre.c_str(), ios::binary);
    if (archivo) {
        int contador = 0;
        while (true) {
            char c = archivo.get();
            if (archivo.eof())
                return contador;
            else
                if (c == ' ' || c == '\n')
                    contador++;
       }
    error("Hubo un error al leer: " + nombre);
    return -1;
}

int main () {
    
    string nombre = "";
    int valor = 0;
    cout << "Ingrese el nombre del archivo: ";
    cin >> nombre;
    
    GestorArchivo a (nombre);
    
    valor = a.contarLineasEspacios();
    
    /*if (valor == 0 || valor == 1)
        cout << "La cantidad de espacios y lineas que existen en el archivo es " << valor;
    else
        if (valor > 1)
            cout << "La cantidad de espacios y lineas que existen en el archivo son " << valor;
        else
            return -1;*/
        
    return 0;
}

