#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*
   7 - Test integer value to determine if it's odd or even
*/

int main () {

    int number = 0;

    cout << "Enter a integer number: ";
    cin >> number;

    cout << "The value " << number << " is an ";
    if (number % 2 == 0)
        cout << "even ";
    else
        cout << "odd ";
    cout << "number." << endl;

    keep_window_open();

    return 0;
}
