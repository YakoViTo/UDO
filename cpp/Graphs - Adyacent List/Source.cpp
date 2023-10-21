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

class DirectedGraph {
	Vertex* first;
	string fileName;
	size_t vertex;
	size_t arc;
public:
	DirectedGraph() { first = nullptr; fileName = "input.txt"; vertex = 1; arc = 1; }
	DirectedGraph(const int vertex, const int arc) { fileName = "input.txt"; this->vertex = vertex; this->arc = arc; }
	DirectedGraph(Vertex* first, const int vertex, const int arc) { this->first = first; fileName = "input.txt"; this->vertex = vertex; this->arc = arc; }
	void addFromFile();
	void addVertex(Vertex* v) {
		v->setNextVertex(first);
		first = v;
	}
	Vertex* searchVertex(const string&);
	Vertex* searchVertex(const string&, Vertex*);
	Arc* searchVertexPointedByArc(const string&, Vertex*, Arc*&);
	Arc* searchArc(const string&);
	Arc* searchArc(const string& arc, Vertex* v, Arc*& prev);
	void addArc(const string& exitVertex, const string& entryVertex, const int weight, const string& arc);
	void deleteVertex(const string& vertex);
	void deleteArc(const string& arcName);
	string showGraph();
};

void DirectedGraph::deleteVertex(const string& vertex) {
	Vertex* prev = first;
	Vertex* current = first;
	for (Vertex* v = first; v->getNextVertex(); v = v->getNextVertex()) {
		if (v->getNextVertex()->getName() == vertex) {
			prev = v;
			current = v->getNextVertex();
			continue;
		}
		Arc* prev = nullptr;
		Arc* a = searchVertexPointedByArc(vertex, v, prev);
		if (a) {
			if (prev)
				prev->setNext(a->getNext());
			else
				v->setNextArc(a->getNext());
			a->deleteArc();
		}
	}
	if (!current)
		throw inexistentVertex;
	for (Arc* a = current->getNextArc(); a; ) {
		Arc* aux = a;
		a = a->getNext();
		aux->deleteArc();
	}
	if (current == first)
		first->setNextVertex(first->getNextVertex());
	else
		prev->setNextVertex(current->getNextVertex());
	current->deleteVertex();
}

void DirectedGraph::deleteArc(const string& arcName) {
	for (Vertex* v = first; v; v = v->getNextVertex()) {
		Arc* prev = nullptr;
		Arc* a = searchArc(arcName, v, prev);
		if (a) {
			if (prev)
				prev->setNext(a->getNext());
			else
				v->setNextArc(a->getNext());
			a->deleteArc();
			break;
		}
	}
}

Vertex* DirectedGraph::searchVertex(const string& vertex) {
	Vertex* v = first;
	for (; v && v->getName() != vertex; v = v->getNextVertex());
	if (!v)
		throw inexistentVertex;
	return v;
}

Arc* DirectedGraph::searchVertexPointedByArc(const string& vertex, Vertex* v, Arc*& prev) {
	Arc* a = v->getNextArc();
	for (; a && a->getVertex() != vertex; prev = a, a = a->getNext());
	return a;
}

Vertex* DirectedGraph::searchVertex(const string& vertex, Vertex* prev) {
	Vertex* v = first;
	for (; v && v->getName() != vertex; v = v->getNextVertex())
		prev = v;
	if (!v)
		throw inexistentVertex;
	return v;
}

Arc* DirectedGraph::searchArc(const string& arc) {
	Arc* a = nullptr;
	for (Vertex* v = first; v; v = v->getNextVertex())
		for (a = v->getNextArc(); a && a->getArcName() != arc; a = a->getNext());
	if (!a)
		throw inexistentArc;
	return a;
}

Arc* DirectedGraph::searchArc(const string& arc, Vertex* v, Arc*& prev) {
	Arc* a = nullptr;
	for (a = v->getNextArc(); a && a->getArcName() != arc; a = a->getNext())
		prev = a;
	return a;
}

void DirectedGraph::addArc(const string& exitVertex, const string& entryVertex, const int weight, const string& arc) {
	Vertex* entryV = searchVertex(entryVertex);
	Vertex* exitV = searchVertex(exitVertex);
	if (!entryV || !exitV)
		throw inexistentVertex;
	Arc* a = new Arc(arc, entryVertex, weight, nullptr);
	Arc* x = exitV->getNextArc();
	if (!x)
		exitV->setNextArc(a);
	else {
		for (; x->getNext(); x = x->getNext());
		x->setNext(a);
	}
}

string DirectedGraph::showGraph() {
	std::stringstream ss;
	for (Vertex* v = first; v; v = v->getNextVertex()) {
		ss << v->getName() << ' ';
		for (Arc* a = v->getNextArc(); a; a = a->getNext())
			ss << a->getArcName() << ' ' << a->getVertex() << ' ';
		ss << '\n';
	}
	return ss.str();
}

void DirectedGraph::addFromFile() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw inexistentFile;
	int weight = 0;
	string arcFromFile = "";
	string v1 = "";
	string v2 = "";
	file >> vertex >> arc;
	if (vertex < 0)
		throw invalidVertexAmount;
	else
		if (arc < 0)
			throw invalidArcAmount;
	for (int i = vertex - 1; i >= 0 ; --i)
		addVertex(new Vertex(std::to_string(i)));
	for (size_t i = 0, arcAmount = 0; file >> v1 >> v2 >> arcFromFile >> weight && arcAmount < arc; ++arc)
		addArc(v1, v2, weight, arcFromFile);
}


int main() {
	DirectedGraph g;
	try {
		g.addFromFile();
		cout << g.showGraph() << endl;
		g.deleteVertex("2");
		cout << g.showGraph() << endl;
	}
	catch (const error& e) {
		if (e == inexistentFile) {
			cerr << "Inexistent File" << endl;
			return 1;
		}
		else
			if (e == inexistentVertex)
				cerr << "Inexistent Vertex" << endl;
			else
				if (e == inexistentArc)
					cerr << "Inexistent Arc" << endl;
				else
					if (e == invalidVertexAmount)
						cerr << "Invalid Vertex Amount" << endl;
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