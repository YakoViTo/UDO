#include <iostream>
#include <fstream>
using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::cerr;

enum error {
	inexistentNode = 0,
	emptyList,
	invalidFile
};

template <class T>
class Node {
	T key;
	Node<T>* next;
	Node<T>* prev;
public:
	Node() { next = prev = nullptr; key = 0; }
	Node(const T& key) { next = prev = nullptr; this->key = key; }
	Node(Node<T>* next, Node<T>* prev) { this->next = next; this->prev = prev; key = 0; }
	Node(Node<T>* next, Node<T>* prev, const T& key) { this->next = next; this->prev = prev; this->key = key; }
	Node<T>* getNext() const { return next; }
	Node<T>* getPrev() const { return prev; }
	T getKey() const { return key; }
	void setNext(Node<T>* next) { this->next = next; }
	void setPrev(Node<T>* prev) { this->prev = prev; }
	void setNextPrev(Node<T>* next, Node<T>* prev) { this->next = next; this->prev = prev; }
	void setNextPrev(Node<T>* both) { next = prev = both; }
	void setKey(const T& key) { this->key = key; }
};

template <class T>
class DoubleList {
	Node<T>* first;
	string fileName;
public:
	DoubleList() { first = nullptr; fileName = "input.txt"; }
	DoubleList(Node<T>* first) { this->first = first; fileName = "input.txt"; }
	Node<T>* search(const T& node);
	void add(Node<T>* newNode, const T& prevNode);
	void add();
	void remove(const T& nodeToRemove);
	bool isEmpty() const { return !first; }
	void deleteList();
	~DoubleList() { deleteList(); }
};

template <class T>
Node<T>* DoubleList<T>::search(const T& node) {
	if (isEmpty())
		throw emptyList;
	Node<T>* x = first;
	while (x && x->getKey() != node)
		x = x->getNext();
	return x;
}


template <class T>
void DoubleList<T>::deleteList() {
	if (!isEmpty())
		while (Node<T>* aux = first) {
			first = first->getNext();
			aux->setNextPrev(nullptr);
			delete aux;
		}
}


template <class T>
void DoubleList<T>::add(Node<T>* newNode, const T& prevNode) {
	/*if (!isEmpty()) {
		Node<T>* x = search(prevNode);
		if (!x)
			throw inexistentNode;
		newNode->setNextPrev(x->getNext(), x);
		if (x->getNext())
			x->getNext()->setPrev(newNode);
		x->setNext(newNode);
	}
	else
		first = newNode;*/
}

template <class T>
void DoubleList<T>::add() {
	std::ifstream file(fileName.c_str());
	if (!file)
		throw invalidFile;
	int x = 0;
	Node<T>* aux = nullptr;
	file >> x;
	first = aux = new Node<T>(x);
	for (; file >> x; ) {
		Node<T>* newNode = new Node<T>(x);
		newNode->setPrev(aux);
		aux->setNext(newNode);
		aux = newNode;
	}
}

template <class T>
void DoubleList<T>::remove(const T& nodeToRemove) {
	if (isEmpty())
		throw emptyList;
	Node<T>* x = search(nodeToRemove);
	if (!x)
		throw inexistentNode;
	if (nodeToRemove == first->getKey()) {
		first = first->getNext();
		if (first)
			first->setPrev(nullptr);
	}
	else {
		x->getPrev()->setNext(x->getNext());
		x->getNext()->setPrev(x->getPrev());
	}
	x->setNextPrev(nullptr);
	delete x;
}


/*template<class T>
class Node {
	Node<T>* prev;
	Node<T>* next;
	T key;
public:
	Node() { key = 0; prev = next = nullptr; }
	Node(const T& key) { this->key = key; next = prev = nullptr; }
	Node(Node<T>* prev, Node<T>* next) { this->next = next; this->prev = prev; key = 0; }
	Node<T>* getPrev() const { return prev; }
	Node<T>* getNext() const { return next; }
	T getKey() const { return key; }
	void setPrev(Node<T>* prev ) { this->prev = prev; }
	void setNext(Node<T>* next) { this->next = next; }
	void setKey(const T& key) { this->key = key; }
};

template<class T>
class DoubleList {
	Node<T>* first;
public:
	DoubleList() { first = nullptr; }
	DoubleList(Node<T>* first) { this->first = first; }
	Node<T>* search(const T& x);
	void add(Node<T>* newNode, const T& existingNode);
	void addToFirst(Node<T>* newNode);
	void remove(const T& nodeToRemove);
	void removeFirst();
	bool isEmpty() const { return first; }
	void deleteList();
	~DoubleList() { deleteList(); }
};

template<class T>
Node<T>* DoubleList<T>::search(const T& x) {
	Node<T>* t = first;
	while (t && t->getKey() != x)
		t = t->getNext();
	return t;
}

template<class T>
void DoubleList<T>::remove(const T& nodeToRemove) {
	if (isEmpty)
		throw emptyList;
	Node<T>* t = search(nodeToRemove);
	if (!t)
		throw inexistentNode;
	t->getPrev()->setNext(t->getNext());
	t->getNext()->setPrev(t->getPrev());
	t->setPrev(nullptr);
	t->setNext(nullptr);
	delete t;
}

template<class T>
void DoubleList<T>::removeFirst() {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = first;
	aux->setNext(nullptr);
	delete aux;
	first = first->getNext();
	first->setPrev(nullptr);
}

template<class T>
void DoubleList<T>::add(Node<T>* newNode, const T& existingNode) {
	if (isEmpty())
		throw emptyList;
	Node<T>* t = search(existingNode);
	if (!t)
		throw inexistentNode;
	newNode->setNext(t->getNext());
	newNode->setPrev(t);
	t->getNext()->setPrev(newNode);
	t->setNext(newNode);
}

template<class T>
void DoubleList<T>::addToFirst(Node<T>* newNode) {
	if (first) {
		newNode->setNext(first);
		first->setPrev(newNode);
	}
	first = newNode;
}

template<class T>
void DoubleList<T>::deleteList() {
	while (Node<T>* aux = first) {
		first = first->getNext();
		aux->setNext(nullptr);
		aux->setPrev(nullptr);
		delete aux;
	}
}*/

int main() {
	DoubleList<int> dl;
	try {
		dl.add();
		/*dl.add(new Node<int>(5), 0);
		dl.add(new Node<int>(8), 5);
		dl.remove(5);
		dl.remove(8);*/
	}
	catch (const error& e) {
		if (e == emptyList)
			cerr << "EMPTY LIST" << endl;
		else
			if (e == inexistentNode)
				cerr << "INEXISTENT NODE" << endl;
			else
				if (e == invalidFile)
					cerr << "INVALID FILE" << endl;
		return -1;
	}
	catch (...) {
		cerr << "UNKNOWN ERROR" << endl << "Quitting..." << endl;
		return -2;
	}
	return 0;
}