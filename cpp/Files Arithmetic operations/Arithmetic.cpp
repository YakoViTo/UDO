#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::cerr;
using std::ifstream;

class FileManager {
	string name;
public:
	FileManager() { name = "file.xyz"; }
	FileManager(const string& name) { this->name = name; }
	void checkForFileErrors(const ifstream& f, const string& funcName);
	string arithmeticOperations();
};

void FileManager::checkForFileErrors(const ifstream& f, const string& funcName) {
	if (!f) {
		if (!f.fail())
			throw std::fstream::failure("fail() in " + funcName + ". File maybe don't exist!");
		if (!f.bad())
			throw std::fstream::failure("bad() in " + funcName);
		throw std::fstream::failure("Unknown error in " + funcName);
	}
}

string FileManager::arithmeticOperations() {
	ifstream file(name.c_str());
	checkForFileErrors(file, "arithmeticOperations()");
	int n, n2;
	n = n2 = 0;
	char op = '+';
	std::stringstream ss;
	
	while (file >> n >> op >> n2) {
		ss << n << ' ' << op << ' ' << n2 << " = ";
		switch (op) {
		case '+':
			ss << n + n2;
			break;
		case '-':
			ss << n - n2;
			break;
		case '*':
			ss << n * n2;
			break;
		case '/':
			if (n2 != 0)
				ss << n / n2;
			else
				ss << "infinite";
			break;
		}
		ss << '\n';
	}
	if (ss.str().empty())
		throw std::runtime_error("File is empty!");
	return ss.str();
}

int main() {
	FileManager fm("arithmetic values.math");
	try {
		cout << fm.arithmeticOperations() << endl;
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
		return -1;
	}
	catch (...) {
		cerr << "Unknown exception caught in main()." << endl << "Quitting...";
		return -1;
	}
	return 0;
}

