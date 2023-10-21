#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Arco {
	string nombre;
	string nombreVertice;
	int peso;
	Arco* proximoArco;
public:
	Arco() { proximoArco = nullptr; }
	Arco(const string nombre, const string nombreVertice, const int peso) {
		this->nombre = nombre;
		this->nombreVertice = nombreVertice;
		this->peso = peso;
		proximoArco = nullptr;
	}
	string getNombre() const { return nombre; }
	string getNombreVertice() const { return nombreVertice; }
	int getPeso() const { return peso; }
	Arco* getProximoArco() const { return proximoArco; }
	void setNombre(const string nombre) { this->nombre = nombre; }
	void setNombreVertice(const string nombreVertice) { this->nombreVertice = nombreVertice; }
	void setPeso(const int peso) { this->peso = peso; }
	void setProximoArco(Arco* proximoArco) { this->proximoArco = proximoArco; }
};

class Vertice {
	string nombre;
	Vertice* proximoVertice;
	Arco* proximoArco;
	string color;
	Vertice* camino;
	int d;	//Tiempo descubir
	int f;	//Tiempo fin
public:
	Vertice() { proximoArco = nullptr; proximoArco = nullptr; nombre = ""; }
	Vertice(const string nombre) { this->nombre = nombre; proximoArco = nullptr; proximoArco = nullptr; }
	string getNombre() const { return nombre; }
	Vertice* getProximoVertice() const { return proximoVertice; }
	Arco* getProximoArco() const { return proximoArco; }
	string getColor() const { return color; }
	Vertice* getCamino() const { return camino; }
	int getD() const { return d; }
	int getF() const { return f; }
	void setNombre(const string nombre) { this->nombre = nombre; }
	void setProximoVertice(Vertice* proximoVertice) { this->proximoVertice = proximoVertice; }
	void setProximoArco(Arco* proximoArco) { this->proximoArco = proximoArco; }
	void setColor(const string color) { this->color = color; }
	void setCamino(Vertice* camino) { this->camino = camino; }
	void setD(const int d) { this->d = d; }
	void setF(const int f) { this->f = f; }
};

class GrafoDirigido {
	Vertice* inicio;
public:
	GrafoDirigido() { inicio = nullptr; }
	string agregarVertice(Vertice* v);
	string eliminarVertice(const string nombre);
	Vertice* buscarVertice(const string nombre);
	void DFS();
	void DFSVisitar(Vertice*& v, int& tiempo);
};

void GrafoDirigido::DFS() {
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		v->setColor("blanco");
		v->setCamino(nullptr);
	}
	int tiempo = 0;
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		if (v->getColor() == "blanco")
			DFSVisitar(v, tiempo);
	}
}

void GrafoDirigido::DFSVisitar(Vertice*& u, int& tiempo) {
	u->setColor("gris");
	tiempo++;
	u->setD(tiempo);
	for (Arco* a = u->getProximoArco(); a; a = a->getProximoArco()) {
		Vertice* v = buscarVertice(a->getNombreVertice());
		if (v->getColor == "blanco") {
			v->setCamino(u);
			DFSVisitar(v, tiempo);
		}	
	}
	u->setColor("negro");
	tiempo++;
	u->setF(tiempo);
}

Vertice* GrafoDirigido::buscarVertice(const string nombre) {
	Vertice* v = inicio;
	for (; v && v->getNombre() != nombre; v = v->getProximoVertice());
	return v;
}

string GrafoDirigido::agregarVertice(Vertice* v) {
	v->setProximoVertice(inicio);
	inicio = v;
}

string GrafoDirigido::eliminarVertice(const string nombre) {
	Vertice* anterior = inicio;
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		if (v->getNombre() == nombre) {
			for (Arco* a = v->getProximoArco(); a; a = a->getProximoArco()) {
				Arco* aux = a;
				aux->setProximoArco(nullptr);
				delete aux;
			}
			if (anterior == inicio)
				inicio = inicio->getProximoVertice();
			else
				anterior->setProximoVertice(v->getProximoVertice());
			v->setProximoVertice(nullptr);
			v->setProximoArco(nullptr);
			delete v;
			return "Vertice eliminado\n";
		}
	}
	return "Eliminado fallido\n";
}

int main() {
	return 0;
}