#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*
    Try This! - Write a program that convert foreign currencies (Yen, Euro and Pound only) to USD.
    Note: These values are taken from x-rates.com as from 6/10/16

*/

int main () {
    
    char currency = '?';    //Type of currency ('y', 'e' or 'p').
    const double yen_to_usd = 0.009352;     //1 Japanese Yen to USD value.
    const double euro_to_usd = 1.12518;     //1 Euro to USD value.
    const double pound_to_usd = 1.425828;   //1 British Pound to USD value.
    double amount = 0.0;    //Holds the amount entered by the user.
    
    cout << "Please enter an amount followed by the desired currency (y, e or p) to calculate USD value: ";
    cin >> amount >> currency;
    
    switch (currency) {
        case 'e': case 'E':
            cout << amount * euro_to_usd;
            break;
        case 'y': case 'Y':
            cout << amount * yen_to_usd;
            break;
        case 'p': case 'P':
            cout << amount * pound_to_usd;
            break;
        default:
            cout << "Not a value I know.";
            break;
    }
    
   /* if (currency == 'y' || currency == 'Y')
        cout << amount * yen_to_usd;
    else
        if (currency == 'e' || currency == 'E')
            cout << amount * euro_to_usd;
        else
            if (currency == 'p' || currency == 'P')
                cout << amount * pound_to_usd;
            else
                cout << "Not a currency I know.";
    */
    cout << endl;
    
    keep_window_open();

    return 0;
}
