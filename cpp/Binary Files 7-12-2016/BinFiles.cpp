/*
	Binary file that writes integer numbers
*/
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

class BadInput {
	string cause;
public:
	BadInput() { cause = "unknown"; }
	BadInput(const string& cause) { this->cause = cause; }
	string getCause() const { return cause; }
};

int readInt(const string& question) {
	int n = 0;
	cout << question;
	cin >> n;
	if (!cin) {
		cin.clear();
		throw BadInput("Character not allowed in int-type variable\n");
	}
	return n;
}

class FileManager {
	string name;
public:
	FileManager() { name = "file.bin"; }
	FileManager(const string& name) { this->name = name; }
	void checkForErrors(std::fstream& file, const string& funcName);
	string add(int number);
	string list();
	long getTotalNumbers(std::fstream& file);
	long getTotalNumbers();
	string remove(const int numberToRemove);
	string search(const int numberToFind);
};

string FileManager::search(const int numberToFind) {
	std::fstream file(name.c_str(), std::ios::in | std::ios::binary);
	checkForErrors(file, "search()");

	int number = 0;
	size_t size = getTotalNumbers(file);
	file.seekg(0, std::ios::beg);
	size_t ocurrences = 0;
	for (size_t i = 0; i < size; ++i) {
		file.read(reinterpret_cast<char*>(&number), sizeof(int));
		if (number == numberToFind)
			ocurrences++;
	}
	if (ocurrences == 0)
		return "Number not found\n";
	else
		if (ocurrences == 1)
			return "There is one ocurrence of this number\n";
	return "There are " + std::to_string(ocurrences) + " ocurrences of this number\n";
}

long FileManager::getTotalNumbers(std::fstream& file) {
	file.seekg(long(0), std::ios::end);
	return (long)file.tellg() / sizeof(int);
}

long FileManager::getTotalNumbers() {
	std::fstream file(name.c_str(), std::ios::binary | std::ios::in);
	checkForErrors(file, "getTotalNumbers()");

	file.seekg(long(0), std::ios::end);
	return (long)file.tellg() / sizeof(int);
}

void FileManager::checkForErrors(std::fstream& file, const string& funcName) {
	if (!file) {
		if (file.fail())
			throw std::fstream::failure("fail() in " + funcName);
		if (file.bad())
			throw std::fstream::failure("bad() in " + funcName);
		throw std::fstream::failure("Unknown error in " + funcName);
	}
}

string FileManager::remove(const int numberToRemove) {
	std::fstream file(name.c_str(), std::ios::binary | std::ios::in);
	checkForErrors(file, "remove(int number)");
	
	int number = 0;
	size_t size = getTotalNumbers(file);
	file.seekg(0, std::ios::beg);
	std::vector<int> integers;
	for (size_t i = 0; i < size; ++i) {
		file.read(reinterpret_cast<char*>(&number), sizeof(int));
		if (number != numberToRemove)
			integers.push_back(number);
	}
	if (integers.size() == 0)
		return "Number not found\n";
	file.close();
	file.open(name.c_str(), std::ios::binary | std::ios::out);
	for (int x : integers)
		file.write(reinterpret_cast<char*>(&x), sizeof(int));
	return "Removal successful\n";
}

string FileManager::add(int number) {
	std::fstream file(name.c_str(), std::ios::binary | std::ios::app | std::ios::out);
	checkForErrors(file, "add(const int)");
	file.write(reinterpret_cast<char*>(&number), sizeof(int));
	return "Number added successfully\n";
}

string FileManager::list() {
	std::fstream file(name.c_str(), std::ios::binary | std::ios::in | std::ios::ate);
	checkForErrors(file, "list()");
	string s = "Numbers:\n";
	int number = 0;
	//int size = getTotalNumbers(file);
	int size = (long)file.tellg() / sizeof(int);
	file.seekg(0, std::ios::beg);
	for (int i = 0; i < size; ++i) {
		file.read(reinterpret_cast<char*>(&number), sizeof(int));
		s.append(std::to_string(number) + '\n');
	}
	return s;
}

int main() {
	FileManager fm;
	char opc = 'a';
	cout << "Binary File" << endl;
	do {
		cout << "1 - Add\n2 - List all numbers in file\n3 - Search\n4 - Remove\n5 - Exit" << endl;
		cin >> opc;
		cin.ignore();
		try {
			switch (opc) {
			case '1':
				cout << fm.add(readInt("Enter integer number to add: ")) << endl;
				break;
			case '2':
				cout << fm.list() << endl;
				break;
			case '3':
				cout << fm.search(readInt("Enter integer number to search: ")) << endl;
				break;
			case '4':
				cout << fm.remove(readInt("Enter integer number to remove: ")) << endl;
				break;
			case '5':
				break;
			default:
				throw std::runtime_error("Option unavailable\n");
			}
		}
		catch (const BadInput& bi) {
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cerr << bi.getCause() << endl;
		}
		catch (const std::exception& e) {
			cerr << e.what() << endl;
		}
		catch (...) {
			cerr << "Unknown exception caught." << endl << "Quitting..." << endl;
			return -1;
		}
	} while (opc != '5');
	return 0;
}