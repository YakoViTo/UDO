#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*

    10 - Operation between two floating-point numbers.

*/

int main () {

    string operation = "?";
    double operand1, operand2;
    operand1 = operand2 = 0.0;
    double result {0.0};

    cout << "Enter operation to perform between numbers: ";
    cin >> operation;

    cout << "Enter number one: ";
    cin >> operand1;

    cout << "Enter number two: ";
    cin >> operand2;

    if (operation == "+" || operation == "plus" || operation == "addition") {
        cout << "+ ";
        result = operand1 + operand2;
    }
    else
        if (operation == "-" || operation == "minus" || operation == "subtraction") {
            cout << "- ";
            result = operand1 - operand2;
        }
        else
            if (operation == "x" || operation == "multiplication" || operation == "mul" || operation == "*") {
                cout << "x ";
                result = operand1 * operand2;
            }
            else
                if (operation == "/" || operation == "division" || operation == "div") {
                    cout << "/ ";
                    result = operand1 / operand2;
                }
                else
                    if (operation == "mod" || operation == "modulo") {
                        cout << "Mod ";
                        int op1 {operand1};
                        int op2 {operand2};
                        result = op1 % op2;
                    }
                    else {
                        cout << "Not an operation I know." << endl;
                        return 0;
                    }

    cout << operand1 << " " << operand2 << " = " << result << endl;

    keep_window_open();

    return 0;
}
