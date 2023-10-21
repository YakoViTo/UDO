#include <iostream>
#include "Queue.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
	Queue<char> q;
	Queue<char> t;
	try {
		t.enQueue('a');
		t.enQueue('b');
		t.enQueue('c');
		q.mirror(t);
	}
	catch (const error& e) {
		if (e == overflow)
			cerr << "OVERFLOW EXCEPTION CAUGHT" << endl;
		else
			cerr << "UNDERFLOW EXCEPTION CAUGHT" << endl;
		return -1;
	}
	catch (...) {
		cerr << "UNKNOWN EXCEPTION CAUGHT" << endl;
		return -2;
	}
	return 0;
}