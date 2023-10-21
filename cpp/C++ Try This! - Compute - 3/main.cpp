#include <iostream>
using namespace std;

int square (int x) {
    int result = 0;
    for (int i = 0; i < x; i++)
        result += x;
    return result;    
}

int main(){
    int number = 0;
    
    cout << "Enter a number to return square of it: ";
    cin >> number;
    
    cout << "The square of the given number is: " << square(number) << endl;
    
    return 0;
}
