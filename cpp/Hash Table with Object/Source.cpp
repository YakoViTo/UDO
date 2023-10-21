#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::cerr;

constexpr size_t hashTableMax = 13;

enum error {
	emptyList = 0,
	invalidFile,
	FileNotSupported
};

enum PersonError {
	invalidAge = 0,
	invalidId
};

size_t radix(const string& s) {
	size_t result = 0;
	for (size_t i = 0, length = s.length(); i < length; ++i)
		result += (size_t) s.at(i) * pow((double)128, (double)i);
	return result;
}

class Person {
	string name, lastName;
	int id;
	short age;
public:
	Person() {
		name = lastName = "UNDEFINED";
		id = 0;
		age = 0;
	}
	Person(const string& name, const string& lastName, const int id, const short age) { 
		if (age < 1 || age > 100)
			throw invalidAge;
		if (id < 1 || id > 100000000)
			throw invalidId;
		this->name = name; 
		this->lastName = lastName; 
		this->id = id; 
		this->age = age; 
	}
	string getName() const { return name; }
	string getLastName() const { return lastName; }
	int getId() const { return id; }
	short getAge() const { return age; }
};


class Node {
	Node* next;
	Node* prev;
	size_t key;
	Person value;
public:
	Node(Person& value) { next = prev = nullptr; this->value = value; key = (size_t) value.getAge(); }
	Node* getNext() const { return next; }
	Node* getPrev() const { return prev; }
	size_t getKey() const { return key; }
	Person getValue() const { return value; }
	void disjoint() {
		if (next)
			next->prev = prev;
		if (prev)
			prev->next = next;
	}
	void setNext(Node* next) { this->next = next; }
	void setPrev(Node* prev) { this->prev = prev; }
	void deleteNode() {
		next = prev = nullptr;
		delete this;
	}
};

class DoubleList {
	Node* first;
public:
	DoubleList() { first = nullptr; }
	void add(Node* n);
	void remove(const size_t key);
	Node* search(const size_t key);
	void deleteList() {
		for (; Node* n = first; n->deleteNode()) {
			first = first->getNext();
			n->disjoint();
		}
	}
	~DoubleList() { deleteList(); }
	bool isEmpty() const { return !first; }
};

Node* DoubleList::search(const size_t key) {
	if (isEmpty())
		throw emptyList;
	Node* n = first;
	for ( ; n && n->getKey() != key; n = n->getNext());
	return n;
}

void DoubleList::add(Node* n) {
	n->setNext(first);
	if (first)
		first->setPrev(n);
	first = n;
}

void DoubleList::remove(const size_t key) {
	Node* n = search(key);
	if (n == first)
		first = first->getNext();
	n->disjoint();
	n->deleteNode();
}

class HashTable {
	DoubleList* dl[hashTableMax];
	string fileName;
public:
	HashTable() {
		fileName = "input.txt";
		for (size_t i = 0; i < hashTableMax; ++i)
			dl[i] = new DoubleList();
	}
	HashTable(const string& fileName) {
		this->fileName = fileName;
		for (size_t i = 0; i < hashTableMax; ++i)
			dl[i] = new DoubleList();
	}
	int hash(const size_t& key) {
		return key % hashTableMax;
	}
	int hash(const string& key) {
		return radix(key) % hashTableMax;
	}
	void add();
	Node* search(const size_t key);
	void remove(const size_t key);
	void deleteTable() {
		for (size_t i = 0; i < hashTableMax; ++i)
			dl[i]->~DoubleList();
	}
	~HashTable() { deleteTable(); }
};

Node* HashTable::search(const size_t key) {
	return dl[hash(key)]->search(key);
}

void HashTable::remove(const size_t key) {
	dl[hash(key)]->remove(key);
}

void HashTable::add() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw invalidFile;
	string x, y;
	int id;
	short age;
	while (file >> x >> y >> id >> age) {
		Person p(x,y,id,age);
		dl[hash(x)]->add(new Node(p));
	}
	if (!file && !id && !age)
		throw FileNotSupported;
}

int main() {
	HashTable ht;
	try {
		ht.add();
		ht.remove(19);
		ht.remove(31);
	}
	catch (const error& e) {
		if (e == emptyList) {
			cerr << "EMPTY LIST!" << endl;
			return -1;
		}
		else
			if (e == FileNotSupported) {
				cerr << "FILE NOT SUPPORTED, PLEASE MEET THE STANDARDS" << endl;
				return -2;
			}
	}
	catch (...) {
		cerr << "UNKNOW EXCEPTION CAUGHT" << endl;
		return -2;
	}
	return 0;
}