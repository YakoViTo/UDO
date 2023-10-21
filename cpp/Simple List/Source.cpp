#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::endl;
using std::cerr;

enum error {
	repeatedKey = 0,
	inexistentNode,
	emptyList
};

template<class T>
class Node {
	Node<T>* next;
	T key;
public:
	Node() { next = nullptr; T = 0; }
	Node(Node<T>* next) { this->next = next; T = 0; }
	Node(const T& key) { next = nullptr; this->key = key; }
	Node(const T& key, const Node<T>*& next) { this->next = next; this->key = key; }
	Node<T>* getNext() const { return next; }
	T getKey() const { return key; }
	void setKey(const T& key) { this->key = key; }
	void setNext(Node<T>* next) { this->next = next; }
};

template<class T>
class SimpleList {
	Node<T>* first;
public:
	SimpleList() { first = nullptr; }
	SimpleList(Node<T>* first) { this->first = first; }
	Node<T>* search(const T& x);
	Node<T>* searchPrevious(const T& x);
	void add(Node<T>* newNode, const T& nodeToSearch);
	void addToFirst(Node<T>* newNode);
	void remove(const T& nodeToRemove);
	void removeFirst();
	bool isEmpty() const { return first == nullptr; }
	void deleteList();
	~SimpleList() { deleteList(); }
};

template<class T>
void SimpleList<T>::removeFirst() {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = first;
	first = first->getNext();
	first->setNext(nullptr);
	delete aux;
}

template<class T>
Node<T>* SimpleList<T>::searchPrevious(const T& x) {
	Node<T>* t = first;
	while (t->getNext() && t->getNext()->getKey() != x)
		t = t->getNext();
	return t;
}

template<class T>
void SimpleList<T>::remove(const T& nodeToRemove) {
	if (isEmpty())
		throw emptyList;
	Node<T>* aux = search(nodeToRemove);
	if (!aux)
		throw inexistentNode;
	else {
		if (aux == first)
			first = first->getNext();
		else {
			Node<T>* t = searchPrevious(nodeToRemove);
			t->setNext(aux->getNext());
		}
		aux->setNext(nullptr);
		delete aux;
	}
}

template<class T>
void SimpleList<T>::deleteList() {
	while (Node<T>* aux = first) {
		first = first->getNext();
		aux->setNext(nullptr);
		delete aux;
	}
}

template<class T>
void SimpleList<T>::addToFirst(Node<T>* newNode) {
	if (first) {
		if (first->getKey() == newNode->getKey())
			throw repeatedKey;
		newNode->setNext(first);
	}
	first = newNode;
}

template<class T>
Node<T>* SimpleList<T>::search(const T& x) {
	Node<T>* z = first;
	while (z->getNext() && z->getKey() != x)
		z = z->getNext();
	return z;
}

template<class T>
void SimpleList<T>::add(Node<T>* newNode, const T& nodeToSearch) {
	Node<T>* t = search(nodeToSearch);
	if (!t)
		throw inexistentNode;
	else
		if (t->getKey() == newNode->getKey())
			throw repeatedKey;
	newNode->setNext(t->getNext());
	t->setNext(newNode);
}

int main() {
	SimpleList<int> sl;
	try {
		sl.addToFirst(new Node<int>(5));
		sl.remove(5);
		sl.remove(6);
	}
	catch (const error& e) {
		if (e == emptyList)
			cerr << "EMPTY LIST!" << endl;
		else
			if (e == inexistentNode)
				cerr << "INEXISTENT NODE" << endl;
			else
				if (e == repeatedKey)
					cerr << "REPEATED KEY" << endl;
	}
	return 0;
}