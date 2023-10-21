#include <iostream>
#include "Box.h"
using namespace std;

int readInt (string sentence) {
    int value = 0;
    cout << sentence;
    cin >> value;
    return value;
}

string readString (string sentence) {
    string word = "";
    cout << sentence;
    cin >> word;
    return word;
}

void number (int& a) {
    a++;
}

int main()
{
    string name = "";
    int side = 0;
    int numb = 0;
    Box obj1;
    Box obj2(45, "Boxy");
    
    cout << "Enter a name for the obj1: ";
    cin >> name;
    cout << "Enter a side for the obj1: ";
    cin >> side;
    
    obj1.setName(name);
    obj1.setSide(side);
    
    cout << obj2.getName() << " " << obj2.getSide() << endl;
    cout << obj1.getName() << " " << obj1.getSide() << endl;
    
    name = readString ("Enter a name for the obj1: ");
    side = readInt ("Enter a side for the obj1: ");
    
    Box obj3 (side, name);
    cout << obj3.getName() << " " << obj3.getSide() << endl;
    
    cout << numb << " ";
    
    number(numb);
    
    cout << numb;
    
    return 0;
}
