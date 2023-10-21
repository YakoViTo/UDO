#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;
using std::fstream;

const short max_lenght = 25;

struct Product {
	char name[max_lenght];
	float price;
	short quantity;
};

class BadInput {
	string cause;
public:
	BadInput() { cause = "unknown"; }
	BadInput(const string& cause) { this->cause = cause; }
	string getCause() const { return cause; }
};

/*string formatString(const string& s) {
	if (s.empty())
		throw BadInput("Empty string\n");
	string newString = "";
	for (char x : s)
		if (isalpha(x))
			newString.push_back(toupper(x));
	if (newString.empty())
		throw BadInput("String doesn't have any alphabetical characters\n");
	return newString;
}*/

class FileManager {
	string name;
public:
	FileManager() { name = "file.bin"; }
	FileManager(const string& name) { this->name = name; }
	void checkForErrors(fstream& f, const string& funcName);
	string add(Product& p);
	string list();
	string remove(Product& p);
	string search(const int register);
};

string FileManager::search(const int r) {
	fstream file(name.c_str(), std::ios::binary | std::ios::in);
	checkForErrors(file, "search(const int)");

	long x = r * sizeof(Product);
	file.seekg(x, std::ios::beg);
	std::stringstream ss;
	Product p;
	file.read(reinterpret_cast<char*>(&p), sizeof(Product));
	ss << "Name: " << p.name << "\nPrice: " << p.price << "\nQunatiy: " << p.quantity << endl;
	return ss.str();
}

void FileManager::checkForErrors(fstream& f, const string& funcName) {
	if (!f) {
		if (f.fail())
			throw fstream::failure("fail() in " + funcName);
		if (f.bad())
			throw fstream::failure("bad() in " + funcName);
		throw fstream::failure("Unknown error in " + funcName);
	}
}

string FileManager::list() {
	fstream file(name.c_str(), std::ios::binary | std::ios::in);
	checkForErrors(file, "list()");
	file.seekg((long)0, std::ios::end);
	size_t size = file.tellg() / sizeof(Product);
	file.seekg(0, std::ios::beg);
	std::stringstream ss;
	ss << "Products:\n";
	Product p;
	for (size_t i = 0; i < size; ++i) {
		file.read(reinterpret_cast<char*>(&p), sizeof(Product));
		ss << "Name: " << p.name << "\nPrice: " << p.price << "\nQuantity: " << p.quantity << "\n\n";
	}
	return ss.str();
}


string FileManager::add(Product& p) {
	fstream file(name.c_str(), std::ios::binary | std::ios::out | std::ios::app);
	checkForErrors(file, "add(Product)");
	file.write(reinterpret_cast<char*>(&p), sizeof(Product));
	return "Product added\n";
}

string FileManager::remove(Product& pToRemove) {
	fstream file(name.c_str(), std::ios::binary | std::ios::in);
	checkForErrors(file, "remove(Product&)");
	file.seekg((long)0, std::ios::end);
	size_t size = file.tellg() / sizeof(Product);
	file.seekg(0, std::ios::beg);
	std::stringstream ss;
	Product p;
	for (size_t i = 0; i < size; ++i) {
		file.read(reinterpret_cast<char*>(&p), sizeof(Product));
		if (p.name != pToRemove.name && p.price != pToRemove.price)
			ss << p.name << ' ' << p.price << ' ' << p.quantity << ' ';
	}
	file.close();
	file.open(name.c_str(), std::ios::binary | std::ios::out);
	while (ss >> p.name >> p.price >> p.quantity) 
		file.write(reinterpret_cast<char*>(&p), sizeof(Product));
	return "Operation done\n";
}

Product fillProduct() {
	Product p;
	cout << "Product's name: ";
	cin >> p.name;
	//p.name = formatString(p.name);
	cout << "Product's price: ";
	cin >> p.price;
	if (!cin) {
		cin.clear();
		throw BadInput("Price must be float numbers only");
	}
	abs(p.price);
	cout << "Product's quantity: ";
	cin >> p.quantity;
	if (!cin) {
		cin.clear();
		throw BadInput("Quantity must be integer numbers only");
	}
	abs(p.quantity);
	return p;
}

int main() {
	FileManager fm;
	char opc = 'a';
	do {
		cout << "1 - Add\n2 - Remove\n3 - List\n4 - Search\n5 - Exit" << endl;
		cin >> opc;
		cin.ignore();
		try {
			switch (opc) {
			case '1': 
				cout << fm.add(fillProduct()) << endl;
				break;
			case '2': {
				Product p;
				cout << "Product's name: ";
				cin >> p.name;
				cout << "Product's price: ";
				cin >> p.price;
				cout << fm.remove(p) << endl;
				break;
			}
			case '3':
				cout << fm.list() << endl;
				break;
			case '4': {
				int x = 0;
				cout << "Enter registry number: ";
				cin >> x;
				cout << fm.search(x) << endl;
				break;
			}
			case '5':
				break;
			default:
				throw std::runtime_error("Option not available");
			}
		}
		catch (const BadInput& bi) {
			cerr << bi.getCause() << endl;
		}
		catch (const std::exception& e) {
			cerr << e.what() << endl;
		}
		catch (...) {
			cerr << "Unknown exception caught" << endl;
			return -1;
		}
	} while (opc != '5');
	return 0;
}