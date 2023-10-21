#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
using std::cin;
using std::cout;
using std::string;
using std::cerr;
using std::endl;

struct Product {
	string name;
	float price;
	int quantity;
};

/*void newCadena(string& s) {
	size_t f = 0;
	do {
		f = s.find(' ');
		if (f == string::npos)
			break;
		s.at(f) = '_';
	} while (true);
}*/

class BadInput {
	string cause;
public:
	BadInput() { cause = "Unknown"; }
	BadInput(const string& cause) { this->cause = cause; }
	string getCause() const { return cause; }
};

class FileManager {
	string name;
public:
	FileManager() { name = "archivo.xyz"; }
	FileManager(const string& name) { this->name = name; }
	string add(Product& p);
	string remove(const string& name);
	bool isProductNameRepeated(const string& p);
	string formatProductString(const string& s);
	void checkForFileErrors(const std::fstream& f, const string& funcName);
	string search(const string& name);
};

string FileManager::search(const string& product) {
	std::fstream file(name.c_str(), std::ios::in);
	checkForFileErrors(file, "search(const string)");
	string pName = "";
	std::stringstream ss;
	float pPrice = 0;
	int pQuantity = 0;
	while (file >> pName >> pPrice >> pQuantity)
		if (pName.compare(product) == 0) {
			ss << "Product name: " << pName << '\n' << "Price: " << pPrice << '\n' << "Quantity: " << pQuantity << '\n';
			return ss.str();
		}
	return "No product found\n";
}

string FileManager::remove(const string& product) {
	std::fstream file(name.c_str(), std::ios::in);
	checkForFileErrors(file, "remove(const string)");
	string pName = "";
	std::stringstream s;
	float pPrice = 0;
	int pQuantity = 0;
	while (file >> pName >> pPrice >> pQuantity)
		if (pName.compare(product) != 0)
			s << pName << ' ' << pPrice << ' ' << pQuantity << endl;
	file.close();
	file.open(name.c_str(), std::ios::out);
	file << s.str();
	return "File updated";
}

string FileManager::add(Product& p) {
	std::fstream file(name.c_str(), std::ios::out | std::ios::app);
	checkForFileErrors(file, "add(const Product)");
	p.name = formatProductString(p.name);
	if (isProductNameRepeated(p.name))
		throw std::runtime_error("Product name is repeated");
	file << p.name << " " << p.price << " " << p.quantity << endl;
	return "Product added successfully";
}

string FileManager::formatProductString(const string& s) {
	if (s.empty())
		throw std::runtime_error("Empty string!");
	string newString = "";
	for (char x : s)
		if (isalpha(x))
			newString.push_back(toupper(x));
		else
			if (x == ' ')
				newString.push_back('_');
	if (newString.empty())
		throw std::runtime_error("The entered string doesn't meet the established conditions (Use only alphabetical chars.)");
	return newString;
}

bool FileManager::isProductNameRepeated(const string& p) {
	std::fstream file(name.c_str(), std::ios::in);
	checkForFileErrors(file, "isProductNameRepeated(const string)");
	string pName = "";
	int quantity = 0;
	float price = 0.0;
	while (file >> pName >> price >> quantity)
		if (pName.compare(p) == 0)
			return true;
	return false;
}

void FileManager::checkForFileErrors(const std::fstream& f, const string& funcName) {
	if (!f) {
		if (f.fail())
			throw std::fstream::failure("fail() in " + funcName);
		if (f.bad())
			throw std::fstream::failure("bad() in " + funcName);
		throw std::fstream::failure("Unknown error in " + funcName);
	}
}

void fillProduct(Product& p, FileManager& fm) {
	cout << "Product name: ";
	getline(cin, p.name);
	cout << "Price: ";
	cin >> p.price;
	if (!cin) {
		cin.clear();
		throw BadInput("Price value must be numbers");
	}
	abs(p.price);
	cout << "Quatity: ";
	cin >> p.quantity;
	if (!cin) {
		cin.clear();
		throw BadInput("Price value must be numbers");
	}
	abs(p.quantity);
	cout << fm.add(p) << endl;
}

int main() {
	FileManager fm("file.xyz");
	Product p;
	char opc = '0';
	cout << "File Manager Products" << endl;
	do {
		try {
			cout << "1 - Add product\n2 - Delete product\n3 - Search for Product\n4 - Exit" << endl;
			cin >> opc;
			cin.ignore();
			switch (opc) {
			case '1':
				fillProduct(p, fm);
				break;
			case '2': {
				string name = "";
				cout << "Enter product's name: ";
				getline(cin, name);
				name = fm.formatProductString(name);
				cout << fm.remove(name) << endl;
				break;
			}
			case '3': {
				string name = "";
				cout << "Enter product's name: ";
				getline(cin, name);
				name = fm.formatProductString(name);
				cout << fm.search(name) << endl;
				break;
			}
			case '4':
				break;
			default:
				throw std::runtime_error("Unavailable choice");
			}
		}
		catch(const BadInput& b) {
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cerr << b.getCause() << endl;
		}
		catch(const std::exception& e) {
			cerr << e.what() << endl;
		}
		catch(...) {
			cerr << "Unknown exception caught in main()" << endl;
			return -1;
		}
	} while (opc != '4');
	return 0;
}
