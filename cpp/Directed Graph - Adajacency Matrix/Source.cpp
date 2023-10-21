#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

constexpr size_t maxSize = 99;

enum error {
	invalidSize = 0,
	invalidFile,
	invalidFileFormat,
	invalidVertex
};

class Graph {
	size_t size;
	string fileName;
	bool matrix[maxSize][maxSize];
public:
	Graph(const int size) {
		if (size < 0 || size >= maxSize)
			throw invalidSize;
		this->size = size;
		for (size_t i = 0; i < size; ++i)
			for (size_t j = 0; j < size; ++j)
				matrix[i][j] = false;
		fileName = "input.txt";
	}
	string addFromFile();
	void deleteAdjacency(const int v1, const int v2);
	string showMatrix();
	inline bool areAdjacent(const int v1, const int v2) {
		if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
			throw invalidVertex;
		return matrix[v1][v2] && matrix[v2][v1];
	}
	inline bool isBuckle(const int v) {
		if (v < 1 || v >= size)
			throw invalidVertex;
		return matrix[v][v];
	}
	inline size_t getSize() const { return size; }
};

string Graph::addFromFile() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw invalidFile;
	bool value = false;
	size_t i = 0;
	size_t j = 0;
	for (; file >> value; ++j) {
		if (j == size) {
			++i;
			j = 0;
		}
		matrix[i][j] = value;
	}
	bool f = !file && !file.eof();
	bool notFinished = i != (size - 1) && j != (size - 1);
	if (notFinished || f)
		throw invalidFileFormat;
	return "OK";
}

void Graph::deleteAdjacency(const int v1, const int v2) {
	if (v1 < 0 || v2 < 0 || v1 >= size || v2 >= size)
		throw invalidVertex;
	matrix[v1][v2] = matrix[v2][v1] = 0;
}

string Graph::showMatrix() {
	std::stringstream ss;
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j)
			ss << matrix[i][j] << ' ';
		ss << "\n";
	}
	return ss.str();
}

int main() {
	try {
		Graph g(4);
		g.addFromFile();
		cout << g.showMatrix() << endl;
		g.deleteAdjacency(0, 3);
		cout << g.showMatrix() << endl;
	}
	catch (const error& e) {
		if (e == invalidFile) {
			cerr << "Invalid file. Check file name" << endl;
			return -1;
		}
		else
			if (e == invalidVertex)
				cerr << "Invalid vertex. Check graph size" << endl;
			else
				if (e == invalidFileFormat)
					cerr << "Invalid file format. Check graph size and standars" << endl;
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl << "Quitting..." << endl;
		return -2;
	}
	return 0;
}