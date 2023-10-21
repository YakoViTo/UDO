#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::endl;
using std::cerr;

constexpr size_t maxName = 12;
constexpr size_t maxTable = 13;

enum error {
	outOfRange = 0,
	inexistentNode
};

class Person {
	string name, lastName;
	size_t key;
public:
	Person(const string& name, const string& lastName, const size_t& key) { this->name = name; this->lastName = lastName; this->key = key; }
};

template<class T>
class HashTable {
	T* t[maxTable];
	string fileName;
public:
	HashTable() { 
		fileName = "input.txt";
		for (size_t i = 0; i < maxTable; ++i)
			t[i] = nullptr;
	}
	HashTable(const string& fileName) { 
		this->fileName = fileName; 
		for (size_t i = 0; i < maxTable; ++i)
			t[i] = nullptr;
	}
	string insert();
	string remove(const size_t& key);
	T* search(const size_t& key);
	inline bool isOutOfRange(const size_t& key) const { return key >= maxTable; }
	void deleteTable() {
		for (size_t i = 0; i < maxTable; ++i)
			if (t[i]) {
				delete t[i];
				t[i] = nullptr;
			}
	}
	~HashTable() { deleteTable(); }
};

template<class T>
string HashTable<T>::insert() {
	/*if (isOutOfRange(p->key)) {
		delete p;
		throw outOfRange;
	}
	ht[p->key] = p;*/
	std::ifstream file(fileName.c_str());
	string n, ln;
	for (size_t k; file >> n >> ln >> k; ) {
		if (isOutOfRange(k))
			throw outOfRange;
		t[k] = new Person(n, ln, k);
	}		
	return "Insert successful\n";
}

template<class T>
T* HashTable<T>::search(const size_t& key) {
	if (isOutOfRange(key))
		throw outOfRange;
	return t[key];
}

template<class T>
string HashTable<T>::remove(const size_t& key) {
	Person* p = search(key);
	delete p;
	t[key] = nullptr;
	return "Removal successful\n";
}

int main() {
	HashTable<Person> ht;
	try {
		ht.insert();
		ht.remove(3);
	}
	catch (const error& e) {
		if (e == outOfRange) {
			cerr << "OUT OF RANGE" << endl;
			return -1;
		}
		else
			if (e == inexistentNode) {
				cerr << "INEXISTENT NODE" << endl;
				return -2;
			}
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
		return -3;
	}
	return 0;
}