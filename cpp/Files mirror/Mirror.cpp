#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;


class FileManager {
	string name;
public:
	FileManager() { name = "mirror.hahaha"; }
	FileManager(const string& name) { this->name = name; }
	string toMirrorFile();
	void checkForErrors(std::ifstream& file);
};

void FileManager::checkForErrors(std::ifstream& file) {
	if (!file) {
		if (!file.fail())
			throw std::ifstream::failure("fail() in file");
		if (!file.bad())
			throw std::ifstream::failure("bad() in file");
		throw std::ifstream::failure("Unknown error in file");
	}
	//file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
}

string FileManager::toMirrorFile() {
	std::ifstream file(name.c_str());
	checkForErrors(file);
	//file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	checkForErrors(file);
	string mirrorContent = "";
	string toReverse = "";
	while (getline(file, toReverse)) {
		//reverse(toReverse.begin(), toReverse.end());
		mirrorContent.append('\n' + toReverse);
	}
	if (mirrorContent.empty())
		throw std::runtime_error("File is empty!");
	file.close();
	std::ofstream output("File.mirror");
	for (size_t i = mirrorContent.length() - 1; i >= 0; --i)
		output << mirrorContent.at(i);
	//output << ss.str();
	return "Mirror file created\n";
}

int main() {
	FileManager fm("mirror.hahaha");
	try {
		cout << fm.toMirrorFile() << endl;
	}
	catch (const std::ifstream::failure& f) {
		cerr << "Failure in reading file." << endl;
		return -1;
	}
	catch(const std::exception& e) {
		cerr << e.what() << endl;
		return -2;
	}
	catch (...) {
		cerr << "Unknown exception caught in main()" << endl << "Quitting...";
		return -3;
	}
	return 0;
}