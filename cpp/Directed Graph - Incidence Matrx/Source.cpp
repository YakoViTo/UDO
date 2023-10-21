#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

constexpr size_t vertex = 99;
constexpr size_t arc = 99;

string removeSpaces(string& input) {
	input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
	return input;
}

enum error {
	invalidVAmount = 0,
	invalidAAmount,
	invalidArc,
	invalidVertex
};

enum errorFile {
	invalidFile = 0,
	invalidArcSize,
	invalidVertexSize
};

class Graph {
	size_t vertexAmount;
	size_t arcAmount;
	short matrix[vertex][arc];
	string fileName;
public:
	Graph(const int v, const int a) {
		if (v < 1 || v >= vertex)
			throw invalidVAmount;
		if (a < 1 || a >= arc)
			throw invalidAAmount;
		vertexAmount = v;
		arcAmount = a;
		for (size_t i = 0; i < vertexAmount; ++i)
			for (size_t j = 0; j < arcAmount; ++j)
				matrix[i][j] = 0;
		fileName = "input.txt";
	}
	string addFromFile();
	string addFromBinaryFile();
	void createBin();
	bool isParallelArc(const int v1, const int v2) {
		bool first = false;			//v1 == 1 && v2 == -1
		bool second = false;		//v1 == -1 && v2 == 1
		for (size_t i = 0; i < arcAmount; ++i) {
			if (first || second) {
				if (first)
					if (matrix[v1][i] == -1 && matrix[v2][i])
						return true;
				if (second)
					if (matrix[v1][i] && matrix[v2][i] == -1)
						return true;
			}
			else {
				if (matrix[v1][i] && matrix[v2][i] == -1)
					first = true;
				else
					if (matrix[v1][i] == -1 && matrix[v2][i])
						second = true;
			}
		}
		return false;
	}
	bool isArcBetVertex(const int v1, const int v2) { 
		for (size_t i = 0; i < arcAmount; ++i)
			if ((matrix[v1][i] == -1 && matrix[v2][i]) || (matrix[v1][i] && matrix[v2][i] == -1))
				return true;
		return false;
	}
	size_t parallelArcsAmount();
	string deleteArc(const int a);
	string deleteVertex(const int v);
	string showMatrix();
};

string Graph::addFromFile() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw invalidFile;
	short arc = 0;
	for (size_t i = 0, j = 0; file >> arc; ++j) {
		if (j == arcAmount) {
			i++;
			j = 0;
		}
		matrix[i][j] = arc;
	}
	return "OK";
}

string Graph::addFromBinaryFile() {
	std::ifstream file(fileName.c_str(), std::ios::binary);
	if (!file)
		throw invalidFile;
	short number = 0;
	for (size_t i = 0, j = 0; file.read(reinterpret_cast<char*>(&number), sizeof(short)); ++j) {
		if (j == arcAmount) {
			i++;
			j = 0;
		}
		matrix[i][j] = number;
	}
	return "OK";
}

void Graph::createBin() {
	std::ofstream file(fileName.c_str(), std::ios::binary);
	if (!file)
		throw invalidFile;
	short s[4][5] = {
		{0, 1, 1, 0, -1 },
		{1, 0, -1, 0, 0 },
		{0, -1, 0, 1, 1 },
		{-1, 0, 0, -1, 0 }
	};
	for (size_t i = 0; i < vertexAmount; ++i)
		for (size_t j = 0; j < arcAmount; ++j)
			file.write(reinterpret_cast<char*>(&s[i][j]), sizeof(short));
}

string Graph::deleteArc(const int a) {
	if (a < 0)
		throw invalidArc;
	if (a < arcAmount - 1) 
		for (size_t j = a; j < arcAmount - 1; ++j)
			for (size_t i = 0; i < vertexAmount; ++i)
				matrix[i][j] = matrix[i][j + 1];
	else
		for (size_t i = 0; i < vertexAmount; ++i)
			matrix[i][a] = 0;
	arcAmount--;
	return "Done";
}

string Graph::deleteVertex(const int v) {
	if (v < 0)
		throw invalidVertex;
	if (v < vertexAmount) {
		for (size_t j = 0; j < arcAmount; ++j)
			if (matrix[v][j] || (matrix[v][j] == -1))
				for (size_t i = 0; i < vertexAmount; ++i)
					if (matrix[i][j] || matrix[i][j] == -1)
						matrix[i][j] = 0;
		for (size_t i = v; i < vertexAmount - 1; ++i)
			for (size_t j = 0; j < arcAmount; ++j)
				matrix[i][j] = matrix[i + 1][j];
	}
	vertexAmount--;
	return "Done";
}

string Graph::showMatrix() {
	string s = "";
	for (size_t i = 0; i < vertexAmount; ++i) {
		for (size_t j = 0; j < arcAmount; ++j) {
			string x = std::to_string(matrix[i][j]);
			if (x == "-1")
				s = s.append(x + ' ');
			else
				s = s.append(' ' + x + ' ');
		}
		s = s.append("\n");
	}
	return s;
}

size_t Graph::parallelArcsAmount() {
	size_t amount = 0;
	for (size_t i = 0; i < vertexAmount - 1; ++i)
		for (size_t j = i + 1; j < vertexAmount; ++j)
			if (isParallelArc(i, j))
				amount++;
	return amount;
}

int main() {
	try {
		Graph g(4, 5);
		//g.addFromFile();
		g.createBin();
		g.addFromBinaryFile();
		cout << g.showMatrix() << endl;
		cout << g.parallelArcsAmount() << endl;
		cout << g.deleteArc(2) << endl;
		cout << g.showMatrix() << endl;
		cout << g.deleteVertex(1) << endl;
		cout << g.showMatrix() << endl;
	}
	catch (const error& e) {
		if (e == invalidVAmount)
			cerr << "Invalid vertex amount. (Amount > 1)" << endl;
		else
			if (e == invalidAAmount)
				cerr << "Invalid arc amount. (Amount > 1)" << endl;
	}
	catch (const errorFile& e) {
		if (e == invalidFile) {
			cerr << "Invalid file. File may not exist" << endl;
			return -1;
		}
		else
			if (e == invalidArcSize) {
				cerr << "Invalid arc size. Arcs are not equal sized" << endl;
				return -2;
			}
			else
				if (e == invalidVertexSize) {
					cerr << "Invalid vertex size. Vertex are not equal sized" << endl;
					return -3;
				}
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
		return -3;
	}
	return 0;
}