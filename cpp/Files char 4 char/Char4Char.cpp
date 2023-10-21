#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::fstream;

class FileManager {
	string name;
public:
	FileManager() { name = "file.xyz"; }
	//FileManager() = default;
	FileManager(const string& name) { this->name = name; }
	FileManager(const string& name, const string& extension) { this->name = name + extension; }
	void checkForErrors(fstream& f, const string& funcName);
	string lookPatrons(const string& p);
};

void FileManager::checkForErrors(fstream& f, const string& funcName) {
	if (!f) {
		if (f.fail())
			throw std::fstream::failure("fail() in " + funcName + ". Maybe file doesn't exist");
		if (f.bad())
			throw std::fstream::failure("bad() in " + funcName);
		throw std::fstream::failure("Unknown exception caught in " + funcName);
	}
}

string FileManager::lookPatrons(const string& p) {
	fstream file(name.c_str(), std::ios::in);
	checkForErrors(file, "lookPatrons(const string)");
	char ch = 'a';
	size_t quantity = 0;
	for (size_t i = 0, pSize = p.length() - 1; ch = file.get(); ) {
		if (file.eof())
			break;
		if (ch == p.at(i)) {
			if (pSize != i)
				i++;
			else {
				quantity++;
				i = 0;
			}
		}
		else
			i = 0;
	}
	file.close();
	file.open(name.c_str(), std::ios::trunc);
	return std::to_string(quantity) + " patrons found on file\n";
}

int main() {
	FileManager fm;
	try {
		cout << fm.lookPatrons("AB") << endl;
	}
	catch (const std::exception& e) {
		cerr << e.what() << endl;
	}
	catch (...) {
		cerr << "Unknown exception caught in main()" << endl;
		return -1;
	}
	return 0;
}