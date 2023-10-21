#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::endl;
using std::cerr;
using std::string;

enum error {
	inexistentVertex = 0,
	inexistentArc,
	inexistentFile,
	invalidVertexAmount,
	invalidArcAmount
};

class Arc {
	string arc, vertex;
	int weight;
	Arc* next;
public:
	Arc(const string& arc, const string& vertex, const int weight) {
		this->arc = arc;
		this->weight = weight;
		this->vertex = vertex;
	}
	Arc(const string& arc, const string& vertex, const int weight, Arc* next) {
		this->next = next;
		this->weight = weight;
		this->vertex = vertex;
		this->arc = arc;
	}
	inline string getArcName() const { return arc; }
	inline string getVertex() const { return vertex; }
	inline int getWeight() const { return weight; }
	inline Arc* getNext() const { return next; }
	inline void setNext(Arc* next) { this->next = next; }
	inline void deleteArc() {
		next = nullptr;
		delete this;
	}
};

class Vertex {
	string name;
	Vertex* nextVertex;
	Arc* nextArc;
public:
	Vertex(const string& name) { this->name = name; nextVertex = nullptr; nextArc = nullptr; }
	Vertex(const string& name, Vertex* nextVertex, Arc* nextArc) {
		this->name = name;
		this->nextVertex = nextVertex;
		this->nextArc = nextArc;
	}
	inline string getName() const { return name; }
	inline Vertex* getNextVertex() const { return nextVertex; }
	inline Arc* getNextArc() const { return nextArc; }
	inline void setNextVertex(Vertex* nextVertex) { this->nextVertex = nextVertex; }
	inline void setNextArc(Arc* nextArc) { this->nextArc = nextArc; }
	inline void deleteVertex() {
		nextVertex = nullptr;
		nextArc = nullptr;
		delete this;
	}
};

class NonDirectedGraph {
	Vertex* first;
	string fileName;
	size_t vertex;
	size_t arc;
public:
	NonDirectedGraph() { first = nullptr; fileName = "input.txt"; vertex = 1; arc = 1; addFromFile(); }
	void addFromFile();
	Vertex* searchVertex(const string&);
	Arc* searchArc(const string&);
	Arc* searchArc(const string&, Vertex*);
	Arc* searchArc(const string& arc, Vertex* v, Arc*& prev);
	void deleteArc(const string&);
	void deleteVertex(const string&);
	string showGraph();
	inline void addVertex(Vertex* v) {
		v->setNextVertex(first);
		first = v;
	}
	void addArc(const string&, const string&, const int, const string&);
};

Vertex* NonDirectedGraph::searchVertex(const string& v) {
	Vertex* x = first;
	for (; x && x->getName() != v; x = x->getNextVertex());
	return x;
}

Arc* NonDirectedGraph::searchArc(const string& arc) {
	Arc* a = nullptr;
	for (Vertex* v = first; v; v = v->getNextVertex()) {
		a = v->getNextArc();
		for (; a && a->getArcName() != arc; a = a->getNext());
		if (a)
			break;
	}
	return a;
}

Arc* NonDirectedGraph::searchArc(const string& arc, Vertex* v) {
	Arc* a = v->getNextArc();
	for (; a && a->getArcName() != arc; a = a->getNext());
	return a;
}

Arc* NonDirectedGraph::searchArc(const string& arc, Vertex* v, Arc*& prev) {
	Arc* a = v->getNextArc();
	for (; a && a->getArcName() != arc; a = a->getNext())
		prev = a;
	return a;
}

void NonDirectedGraph::addArc(const string& vExit, const string& vEntry, const int weight, const string& arc) {
	Vertex* v1 = searchVertex(vExit);
	Vertex* v2 = searchVertex(vEntry);
	if (!v1 || !v2)
		throw inexistentVertex;
	Arc* a = v1->getNextArc();
	if (a) {
		for (; a->getNext(); a = a->getNext());
		a->setNext(new Arc(arc, vEntry, weight));
	}
	else
		v1->setNextArc(new Arc(arc, vEntry, weight));
	a = v2->getNextArc();
	if (a) {
		for (; a->getNext(); a = a->getNext());
		a->setNext(new Arc(arc, vExit, weight));
	}
	else
		v2->setNextArc(new Arc(arc, vExit, weight));
}

void NonDirectedGraph::deleteArc(const string& arc) {
	Vertex* sV = nullptr;
	for (Vertex* v = first; v; v = v->getNextVertex()) {
		Arc* prev = nullptr;
		Arc* a = searchArc(arc, v, prev);
		if (a) {
			(prev)? prev->setNext(a->getNext()) : v->setNextArc(a->getNext());
			sV = searchVertex(a->getVertex());
			a->deleteArc();
		}
	}
	Arc* prev = nullptr;
	Arc* a = searchArc(arc, sV, prev);
	if (a) {
		(prev) ? prev->setNext(a->getNext()) : sV->setNextArc(a->getNext());
		sV = searchVertex(a->getVertex());
		a->deleteArc();
	}

}

void NonDirectedGraph::addFromFile() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw inexistentFile;
	file >> vertex >> arc;
	if (vertex < 0)
		throw invalidVertexAmount;
	if (arc < 0)
		throw invalidArcAmount;
	string arco = "";
	for (int i = vertex - 1; i >= 0; --i)
		addVertex(new Vertex(std::to_string(i)));
	for (int i = 0, v1 = 0, v2 = 0, w = 0; file >> v1 >> v2 >> arco >> w && i < arc; ++i)
		addArc(std::to_string(v1), std::to_string(v2), w, arco);
}


string NonDirectedGraph::showGraph() {
	std::stringstream ss;
	for (Vertex* v = first; v; v = v->getNextVertex()) {
		ss << v->getName() << ' ';
		for (Arc* a = v->getNextArc(); a; a = a->getNext())
			ss << a->getArcName() << ' ' << a->getVertex() << ' ';
		ss << '\n';
	}
	return ss.str();
}


int main() {
	try {
		NonDirectedGraph g;
		cout << g.showGraph() << endl;
		g.deleteArc("a6");
		cout << g.showGraph() << endl;
	}
	catch (const error& e) {
		if (e == inexistentFile) {
			cerr << "Inexistent File" << endl;
			return -1;
		}
		else
			if (e == inexistentVertex)
				cerr << "Inexistent Vertex" << endl;
			else
				if (e == inexistentArc)
					cerr << "Inexistent Arc" << endl;
				else
					if (e == invalidVertexAmount)
						cerr << "Inavlid Vertex Amount" << endl;
					else
						if (e == invalidArcAmount)
							cerr << "Invalid Arc Amount" << endl;
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
		return -2;
	}
	return 0;
}