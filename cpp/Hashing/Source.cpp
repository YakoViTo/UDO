#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;

constexpr size_t hashTableMax = 7;

enum error {
	emptyList = 0,
	fileError
};

template <class T, class U>
class Node {
	T key;
	U value;
	Node<T, U>* next;
	Node<T, U>* prev;
public:
	Node() { key = 0; value = 0; next = prev = nullptr; }
	Node(const T& key, const U& value) { this->key = key; this->value = value; next = prev = nullptr; }
	Node<T, U>* getNext() const { return next; }
	Node<T, U>* getPrev() const { return prev; }
	T getKey() const { return key; }
	U getValue() const { return value; }
	inline void deleteNode() { next = prev = nullptr; delete this; }
	inline void setNext(Node<T, U>* next) { this->next = next; }
	inline void setPrev(Node<T, U>* prev) { this->prev = prev; }
	inline void disjoint() {
		this->next->setPrev(this->prev);
		this->prev->setNext(this->next);
	}
};

template <class T, class U>
class DoubleList {
	Node<T, U>* first;
public:
	DoubleList() { first = nullptr; }
	Node<T, U>* search(const T& key);
	void add(Node<T, U>* newNode);
	void remove(const T& key);
	inline bool isEmpty() const { return !first; }
	void deleteList() {
		while (Node<T, U>* n = first) {
			first = first->getNext();
			n->disjoint();
			n->deleteNode();
		}
	}
	~DoubleList() { deleteList(); }
};

template<class T, class U>
void DoubleList<T,U>::add(Node<T,U>* newNode) {
	newNode->setNext(first);
	if (first)
		first->setPrev(newNode);
	first = newNode;
}

template <class T, class U>
Node<T,U>* DoubleList<T,U>::search(const T& key) {
	Node<T,U>* n = first;
	for (; n != nullptr && n->getKey() != key; n = n->getNext());
	return n;
}

template <class T, class U>
void DoubleList<T, U>::remove(const T& key) {
	if (isEmpty())
		throw emptyList;
	Node<T,U>* node = search(key);
	node->disjoint();
	node->deleteNode();
}

template <class T, class U>
class HashTable {
	DoubleList<T, U>* sl[hashTableMax];
	string fileName;
public:
	HashTable() {
		fileName = "input.txt";
		for (size_t i = 0; i < hashTableMax; ++i)
			sl[i] = new DoubleList<T,U>;
	}
	HashTable(const string& s) {
		fileName = s;
		for (size_t i = 0; i < hashTableMax; ++i)
			sl[i] = new DoubleList<T,U>;
	}
	int hash(const T& key) const { return key % hashTableMax; }
	int hash(const string& key);
	void add();
	Node<T,U>* search(const T& key);
};

template<class T, class U>
Node<T, U>* HashTable<T, U>::search(const T& key) {
	return sl[key]->search(key);
}

template<class T, class U>
int HashTable<T,U>::hash(const string& key) {
	int k = 0;
	for (size_t i = 0, lenght = key.length(); i < lenght; ++i)
		value += key.at(i);
	return k % hashTableMax;
}

template <class T, class U>
void HashTable<T, U>::add() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw fileError;
	T x;
	U y;
	while (file >> x >> y)
		sl[(hash(x))]->add(new Node<T,U>(x, y));
}

int main() {
	HashTable<int, string> ht;
	try {
		ht.add();
	}
	catch (const error& e) {
		if (e == emptyList)
			cerr << "EMPTY LIST" << endl;
		else
			if (e == fileError)
				cerr << "FILE ERROR" << endl;
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
	}
	return 0;
}

