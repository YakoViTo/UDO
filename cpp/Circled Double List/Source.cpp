#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::string;

enum error {
	emptyFile = 0,
	invalidFile,
	emptyList,
	inexistentNode
};

template <class T>
class Node {
	Node<T>* next;
	Node<T>* prev;
	T key;
public:
	Node() { next = prev = this; key = 0; }
	Node(const T& key) { this->key = key; next = prev = this; }
	Node(const T& key, Node<T>* prev, Node<T>* next) { this->key = key; this->next = next; this->prev = prev; }
	Node<T>* getNext() const { return next; }
	Node<T>* getPrev() const { return prev; }
	T getKey() const { return key; }
	void setKey(const T& key) { this->key = key; }
	void setNext(Node<T>* next) { this->next = next; }
	void setPrev(Node<T>* prev) { this->prev = prev; }
	void setPrevNext(Node<T>* both) { next = prev = both; }
};

template <class T>
class CircledDoubleList {
	Node<T>* s;
	string fileName;
public:
	CircledDoubleList() { s = new Node<T>; fileName = "input.txt"; }
	CircledDoubleList(const string& fileName) { this->fileName = fileName; s = new Node<T>; }
	void addFromFile();
	void addToLast(Node<T>* newNode, Node<T>* theS);
	void addToLast(Node<T>* newNode);
	bool isEmpty() { return s->getNext() == s; }
	void remove(const T& nodeToRemove);
	Node<T>* search(const T& keyToSearch);
	void deleteList();
	void doOperation();
	inline void detach(Node<T>* x) {
		x->getNext()->setPrev(x->getPrev());
		x->getPrev()->setNext(x->getNext());
	}
	~CircledDoubleList() { deleteList(); }
};

template<class T>
Node<T>* CircledDoubleList<T>::search(const T& keyToSearch) {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = s->getNext();
	while (aux != s && aux->getKey() != keyToSearch)
		aux = aux->getNext();
	if (aux == s)
		throw inexistentNode;
	return aux;
}

template<class T>
void CircledDoubleList<T>::addToLast(Node<T>* newNode, Node<T>* theS) {
	newNode->setPrev(theS->getPrev());
	theS->getPrev()->setNext(newNode);
	newNode->setNext(theS);
	theS->setPrev(newNode);
}

template<class T>
void CircledDoubleList<T>::addToLast(Node<T>* newNode) {
	newNode->setPrev(s->getPrev());
	s->getPrev()->setNext(newNode);
	newNode->setNext(s);
	s->setPrev(newNode);
}

template <class T>
void CircledDoubleList<T>::addFromFile() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw invalidFile;
	for (T x = 0; file >> x; ) {
		Node<T>* n = new Node<T>(x, s->getPrev(), s);
		s->getPrev()->setNext(n);
		s->setPrev(n);
	}
}

template <class T>
void CircledDoubleList<T>::remove(const T& nodeToRemove) {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = search(nodeToRemove);
	detach(aux);
	aux->setPrevNext(nullptr);
	delete aux;
}

template <class T>
void CircledDoubleList<T>::deleteList() {
	Node<T>* aux = s->getPrev();
	for (Node<T>* x = aux->getPrev(); aux != s; aux = x) {
		x = aux->getPrev();
		x->setNext(s);
		aux->setPrevNext(nullptr);
		delete aux;
	}
	aux->setPrevNext(nullptr);
	delete aux;
}


template <class T>
void CircledDoubleList<T>::doOperation() {
	Node<T>* even = new Node<T>;
	Node<T>* odd = new Node<T>;
	Node<T>* choice = nullptr;
	for (Node<T>* aux = s->getNext(); aux != s; aux = s->getNext()) {
		detach(aux);
		(aux->getKey() % 2 == 0) ? choice = even : choice = odd;
		addToLast(aux, choice);
	}
}

/*template <class T>
class Node {
	Node<T>* next;
	Node<T>* prev;
	T key;
public:
	Node() { next = prev = this; key = 0; }
	Node(const T& key) { next = prev = this; this->key = key; }
	Node(const T& key, Node<T>* prev, Node<T>* next) { this->next = next; this->prev = prev; this->key = key; }
	Node(Node<T>* prev, Node<T>* next) { this->next = next; this->prev = prev; }
	Node<T>* getNext() const { return next; }
	Node<T>* getPrev() const { return prev; }
	T getKey() const { return key; }
	void setNext(Node<T>* next) { this->next = next; }
	void setPrev(Node<T>* prev) { this->prev = prev; }
	void setKey(const T& key) { this->key = key; }
	void setPrevNext(Node<T>* both) { next = prev = both; }
};

template <class T>
class CircledDoubleList {
	Node<T>* s;
	string name;
public:
	CircledDoubleList() { name = "input.txt"; s = new Node<T>(s, s); }
	CircledDoubleList(const string& name) { this->name = name; s = new Node<T>(s, s); }
	void add();
	Node<T>* search(const T& key);
	void remove(const T& nodeToRemove);
	void deleteList();
	bool isEmpty() const { return s->getNext() == s; }
	~CircledDoubleList() { deleteList(); }
};

template<class T>
Node<T>* CircledDoubleList<T>::search(const T& key) {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = s->getNext();
	while (aux != s && aux->getKey() != key)
		aux = aux->getNext();
	return aux;
}

template<class T>
void CircledDoubleList<T>::remove(const T& nodeToRemove) {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = search(nodeToRemove);
	if (aux == s)
		throw inexistentNode;
	aux->getNext()->setPrev(aux->getPrev());
	aux->getPrev()->setNext(aux->getNext());
	aux->setPrevNext(nullptr);
	delete aux;
}

template<class T>
void CircledDoubleList<T>::deleteList() {
	Node<T>* aux = s->getPrev();
	while (aux != s) {
		Node<T>* n = aux;
		aux = aux->getPrev();
		aux->setNext(s);
		n->setPrevNext(nullptr);
		delete n;
	}
	s->setPrevNext(nullptr);
	delete s;
}

template<class T>
void CircledDoubleList<T>::add() {
	std::ifstream file(name.c_str());
	if (!file) 
		throw invalidFile;
	T x = 0;
	file >> x;
	if (file.eof())
		throw emptyFile;
	Node<T>* aux = new Node<T>(x, s, s);
	s->setPrevNext(aux);
	while (file >> x) {
		Node<T>* n = new Node<T>(x, aux, s);
		aux->setNext(n);
		s->setPrev(n);
		aux = n;
	}
}*/

int main() {
	CircledDoubleList<int> cdl;
	try {
		cdl.addFromFile();
		cdl.remove(5);
		cdl.doOperation();
	}
	catch (const error& e) {
		if (e == invalidFile) {
			cerr << "INVALID FILE" << endl;
			return -1;
		}
		else
			if (e == emptyFile) {
				cerr << "EMPTY FILE" << endl;
				return -2;
			}
			else
				if (e == inexistentNode) {
					cerr << "INEXISTENT NODE" << endl;
					return -3;
				}
				else
					if (e == emptyList) {
						cerr << "EMPTY LIST" << endl;
						return -4;
					}
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT!" << endl;
		return -3;
	}
	return 0;
}