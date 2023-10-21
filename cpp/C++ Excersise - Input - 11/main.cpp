#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*

    11 - Money currency program.

*/

int main () {

    int pennies, nickels, dimes, quarters, half_dollars, one_dollar;
    pennies = nickels = dimes = quarters = half_dollars = one_dollar = 0;
    
    double total {0};

    cout << "How many pennies do you have?: ";
    cin >> pennies;

    cout << "How many nickels do you have?: ";
    cin >> nickels;

    cout << "How many dimes do you have?: ";
    cin >> quarters;

    cout << "How many half-dollars do you have?: ";
    cin >> half_dollars;

    cout << "How many one-dollar coins do you have?: ";
    cin >> one_dollar;

    total = pennies + nickels + dimes + quarters + half_dollars + one_dollar;

    if (pennies > 0) {
        cout << "You have " << pennies;
        if (pennies == 1)
            cout << " penny." << endl;
        else
            cout << " pennies." << endl;
    }

        if (nickels > 0) {
            cout << "You have " << nickels;
            if (nickels == 1)
                cout << " nickel." << endl;
            else
                cout << " nickels." << endl;
        }

            if (dimes > 0) {
                cout << "You have " << dimes;
                if (dimes == 1)
                    cout << " dime." << endl;
                else
                    cout << " dimes." << endl;
            }

                if (quarters > 0) {
                    cout << "You have " << quarters;
                    if (quarters == 1)
                        cout << " quarter." << endl;
                    else
                        cout << " quarters." << endl;
                }

                    if (half_dollars > 0) {
                        cout << "You have " << half_dollars;
                        if (half_dollars == 1)
                            cout << " half dollar." << endl;
                        else    
                            cout << " half dollars." << endl;
                    }
                    if (one_dollar > 0) {
                            cout << "You have " << one_dollar;
                            if (one_dollar == 1)
                                cout << " one-dollar coin." << endl;
                            else
                                cout << " one-dollar coins." << endl;
                        }

    cout << "The total value of all your coins is $" << total/100 << " or " << total << " cents." << endl;

    keep_window_open();

    return 0;
}
