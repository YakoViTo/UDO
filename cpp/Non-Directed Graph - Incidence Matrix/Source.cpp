#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

constexpr size_t size = 99;

enum error {
	invalidFile = 0,
	invalidFileFormat,
	invalidArguments
};

class Graph {
	size_t vertex;
	size_t arc;
	short matrix[size][size];
	string fileName = "input.txt";
public:
	Graph(const int vertex, const int arc) {
		if (vertex < 1 || arc < 1 || vertex >= size || arc >= size)
			throw invalidArguments;
		this->vertex = vertex;
		this->arc = arc;
		for (size_t i = 0; i < vertex; ++i)
			for (size_t j = 0; j < arc; ++j)
				matrix[i][j] = 0;
	}
	Graph(const int vertex, const int arc, const string& fileName) {
		Graph(vertex, arc);
		this->fileName = fileName;
	}
	void addFromFile();
	void deleteVertex(const int v);
	void deleteArc(const int a);
	string showMatrix();
	inline bool areIncident(const int v1, const int v2) {
		if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
			throw invalidArguments;
		for (size_t i = 0; i < arc; ++i)
			if (matrix[v1][i] && matrix[v2][i])
				return true;
		return false;
	}
};

void Graph::addFromFile() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw invalidFile;
	short value = 0;
	size_t i = 0;
	size_t j = 0;
	for (; file >> value; ++j) {
		if (value != 0 && value != 1)
			throw invalidFileFormat;
		if (j == arc) {
			j = 0;
			++i;
		}
		matrix[i][j] = value;
	}
	bool notFinished = i != (vertex - 1);
	bool invalidInput = !file.eof();
	if (invalidInput || notFinished)
		throw invalidFileFormat;
}

string Graph::showMatrix() {
	std::stringstream ss;
	for (size_t i = 0; i < vertex; ++i) {
		for (size_t j = 0; j < arc; ++j)
			ss << matrix[i][j] << ' ';
		ss << "\n";
	}
	return ss.str();
}

void Graph::deleteArc(const int a) {
	if (a < 0 || a >= arc)
		throw invalidArguments;
	if (a < arc - 1) {
		for (size_t j = a; j < arc - 1; ++j)
			for (size_t i = 0; i < vertex; ++i)
				matrix[i][j] = matrix[i][j + 1];
	}
	arc--;
}

void Graph::deleteVertex(const int v) {
	if (v < 0 || v >= vertex)
		throw invalidArguments;
	for (size_t j = 0; j < arc; ++j)
		if (matrix[v][j])
			for (size_t i = 0; i < vertex; ++i)
				matrix[i][j] = 0;
	for (size_t i = v; i < vertex - 1; ++i)
		for (size_t j = 0; j < arc; ++j)
			matrix[i][j] = matrix[i + 1][j];
	vertex--;
}

int main() {
	try {
		Graph g(4, 5);
		g.addFromFile();
		cout << g.showMatrix() << endl;
	}
	catch (const error& e) {
		if (e == invalidFile) {
			cerr << "Invalid File. Check file name" << endl;
			return -1;
		}
		else
			if (e == invalidArguments)
				cerr << "Invalid arguments. Check \"vertex\" or \"arc\" value" << endl;
			else
				if (e == invalidFileFormat) {
					cerr << "Invalid file format. Check graph size and standars established for it" << endl;
					return -2;
				}	
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
		return -3;
	}
	return 0;
}