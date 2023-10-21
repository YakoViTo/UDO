#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;

class FileManager {
	string name;
public:
	FileManager() { name = "file.txt"; }
	FileManager(const string name) { this->name = name; };
	void readFile(const char c, const char r);
	string getFileName() const { return name; }
	void replaceCharacterInString(string& s, const char c, const char r);
};

void FileManager::readFile(const char c, const char r) {
	std::fstream file(name.c_str(), std::ios::in);
	if (!file) {
		string functionName = "replaceWhitespace()";
		if (file.fail())
			throw std::runtime_error("fail() in " + functionName + '\n');
		if (file.bad())
			throw std::runtime_error("bad() in " + functionName + '\n');
		throw std::runtime_error("Unknown error in " + functionName + '\n');
	}
	string newString;
	for (string auxString = ""; getline(file, auxString); )
		newString.append(auxString + '\n');
	replaceCharacterInString(newString, c, r);
	file.close();
	file.open(name.c_str(), std::ios::out);
	file << newString;
}

void FileManager::replaceCharacterInString(string& s, const char c, const char r) {
	for (size_t i = 0; i < s.size(); ++i)
		if (s.at(i) == c)
			s.at(i) = r;
}

int main() {
	char c = 'a';
	char r = 'a';
	try {
		FileManager fm("archivo.txt");
		cout << "Enter character to be replaced: ";
		cin >> c;
		cout << "Enter replacing character: ";
		cin >> r;
		fm.readFile(c, r);
		cout << "Replacement successful" << endl;
	}
	catch (std::runtime_error& e) {
		cerr << e.what() << endl;
		return -1;
	}
	catch (...) {
		cerr << "Unknown exception caught in main()" << endl;
		return -2;
	}
	return 0;
}