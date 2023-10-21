//Split a integer Stack into two different Stacks: One for positive integers and the other with the negative ones.

#include <iostream>
#include "Stack.h"
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main() {
	Stack<int> s;
	Stack<int> pos;
	Stack<int> neg;
	try {
		s.push(5);
		s.push(-1);
		s.push(8);
		s.push(0);
		s.push(-8);
		s.splitStack(pos, neg);
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