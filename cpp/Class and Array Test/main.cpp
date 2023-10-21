#include <iostream>
using namespace std;

int main() {
    
    int d = 0;
    int *p = &d;
    int *f = p;
    int *t = p;
    
    
    
    cout << p << endl;
    cout << *p << endl;
    cout << &d << endl;
    cout << *f << endl;
    cout << ++t << endl;
    
    return 0;
}
