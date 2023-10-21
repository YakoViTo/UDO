#include <iostream>
using namespace std;

/*
    Try This! - Write a program that prints out the alphabet characters, including their uppercase 
    relatives.

*/

int main()
{
    for (char c = 'A'; c < 'z'; c++) {
        if (c == 90)
            c = 98;
        cout << c << " " << (int)c << endl;
    }
    
    return 0;
}
