#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Arco {
	string nombreArco;
	int peso;
	string nombreVertice;
	Arco* proximoArco;
public:
	Arco() { proximoArco = nullptr; }
	Arco(const string nombre, const string nombreVertice, const int peso) { 
		proximoArco = nullptr; 
		this->peso = peso;
		this->nombreVertice = nombreVertice;
		this->nombreArco = nombre;  
	}
	string getNombreArco() const { return nombreArco; }
	string getNombreVertice() const { return nombreVertice; }
	int getPeso() const { return peso; }
	Arco* getProximoArco() const { return proximoArco; }
	void setNombreArco(const string nombreArco) { this->nombreArco = nombreArco; }
	void setNombreVertice(const string nombreVertice) { this->nombreVertice = nombreVertice; }
	void setPeso(const int peso) { this->peso = peso; }
	void setProximoArco(Arco* proximoArco) { this->proximoArco = proximoArco; }
};

class Vertice {
	string nombre;
	Vertice* proximoVertice;
	Arco* proximoArco;
public:
	Vertice() { proximoVertice = nullptr; proximoArco = nullptr; }
	Vertice(const string nombre) { proximoVertice = nullptr; proximoArco = nullptr; this->nombre = nombre; }
	string getNombre() const { return nombre; }
	Vertice* getProximoVertice() const { return proximoVertice; }
	Arco* getProximoArco() const { return proximoArco; }
	void setNombre(const string nombre) { this->nombre = nombre; }
	void setProximoVertice(Vertice* proximoVertice) { this->proximoVertice = proximoVertice; }
	void setProximoArco(Arco* proximoArco) { this->proximoArco = proximoArco; }
};

class GrafoDirigido {
	Vertice* inicio;
public:
	GrafoDirigido() { inicio = nullptr; }
	string agregarVertice(Vertice* v);
	Vertice* buscarVertice(const string nombre);
	string eliminarVertice(const string nombre);
	Arco* buscarArco(const string nombre);
	string agregarArco(const string verticeIncSalida, const string verticeIncEntrada, const int peso, const string nombreArco);
	string eliminarArco(const string nombreArco);
	int cantidadLazos();
	int cantidadVerticesAislados();
	int cantArcosParalelos();
	bool isArcosParalelosYAisladosIguales();
};

string GrafoDirigido::agregarVertice(Vertice* v) {
	v->setProximoVertice(inicio);
	inicio = v;
}

Vertice* GrafoDirigido::buscarVertice(const string nombre) {
	Vertice* v = inicio;
	for (; v && v->getNombre() != nombre; v = v->getProximoVertice());
	return v;
}

string GrafoDirigido::agregarArco(const string verticeIncSalida, const string verticeIncEntrada, const int peso, const string nombreArco) {
	Vertice* vSalida = buscarVertice(verticeIncSalida);
	Vertice* vEntrada = buscarVertice(verticeIncEntrada);
	if (!vSalida || !vEntrada)
		return "No se encontraron los vertices\n";
	Arco* a = new Arco(nombreArco, vEntrada->getNombre(), peso);
	Arco* x = vSalida->getProximoArco();
	if (!x)
		vSalida->setProximoArco(a);
	else {
		for (; x->getProximoArco(); x = x->getProximoArco());
		x->setProximoArco(a);
	}
	return "Arco agregado\n";
}

Arco* GrafoDirigido::buscarArco(const string nombre) {
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		for (Arco* a = v->getProximoArco(); a; a = a->getProximoArco())
			if (a->getNombreArco() == nombre)
				return a;
	}
	return nullptr;
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

string GrafoDirigido::eliminarArco(const string nombre) {
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		Arco* anterior = v->getProximoArco();
		for (Arco* a = v->getProximoArco(); a; a = a->getProximoArco()) {
			if (a->getNombreArco() == nombre) {
				if (anterior == v->getProximoArco())
					v->setProximoArco(anterior->getProximoArco());
				else
					anterior->setProximoArco(a->getProximoArco());
				a->setProximoArco(nullptr);
				delete a;
				return "Arco eliminado\n";
			}
			anterior = a;
		}
	}
	return "Eliminado fallido\n";
}

int GrafoDirigido::cantidadLazos() {
	int cant = 0;
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		for (Arco* a = v->getProximoArco(); a; a = a->getProximoArco()) {
			if (a->getNombreVertice() == v->getNombre())
				cant++;
		}
	}
	return cant;
}

int GrafoDirigido::cantArcosParalelos() {
	int cant = 0;
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		for (Arco* a = v->getProximoArco(); a; a = a->getProximoArco()) {
			for (Arco* x = a->getProximoArco(); x; x = x->getProximoArco())
				if (a->getNombreVertice() == x->getNombreVertice())
					cant++;
		}
	}
	return cant;
}

int GrafoDirigido::cantidadVerticesAislados() {
	int cant = 0;
	for (Vertice* v = inicio; v; v->getProximoVertice()) {
		if (!v->getProximoArco()) {
			Vertice* x = inicio;
			for (; x; x = x->getProximoVertice()) {
				Arco* a = x->getProximoArco();
				for (; a && a->getNombreVertice() != x->getNombre(); a = a->getProximoArco());
				if (!a)
					continue;
				if (a->getNombreVertice() == v->getNombre())
					break;
			}
			if (!x)
				cant++;
		}
	}
	return cant;
}

bool GrafoDirigido::isArcosParalelosYAisladosIguales() {
	int cantParalelos, cantAislados;
	cantParalelos = cantAislados = 0;
	for (Vertice* v = inicio; v; v = v->getProximoVertice()) {
		for (Arco* a = v->getProximoArco(); a; a = a->getProximoArco()) {
			for (Arco* x = a->getProximoArco(); x; x = x->getProximoArco())
				if (a->getNombreVertice() == x->getNombreVertice())
					cantParalelos++;
		}
	}
	for (Vertice* v = inicio; v; v->getProximoVertice()) {
		if (!v->getProximoArco()) {
			Vertice* x = inicio;
			for (; x; x = x->getProximoVertice()) {
				Arco* a = x->getProximoArco();
				for (; a && a->getNombreVertice() != x->getNombre(); a = a->getProximoArco());
				if (!a)
					continue;
				if (a->getNombreVertice() == v->getNombre())
					break;
			}
			if (!x)
				cantAislados++;
		}
	}
	if (cantParalelos == cantAislados)
		return true;
	return false;

	/*De otra manera:
	int cantParalelos = cantArcosParalelos();
	int cantAislados = cantidadVerticesAislados();
	if (cantParalelos == cantAislados)
		return true;
	return false;
	*/
}

int main() {
	return 0;
}