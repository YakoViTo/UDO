#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

int main () {

    string number_spelled = "?";

    cout << "Type a spelled-out number: ";
    cin >> number_spelled;

    cout << "You entered... ";
    if (number_spelled == "zero" || number_spelled == "ZERO" || number_spelled == "Zero")
        cout << 0;
    else
        if (number_spelled == "one" || number_spelled == "ONE" || number_spelled == "One")
            cout << 1;
        else
            if (number_spelled == "two" || number_spelled == "TWO" || number_spelled == "Two")
                cout << 2;
            else
                if (number_spelled == "three" || number_spelled == "THREE" || number_spelled == "Three")
                    cout << 3;
                else
                    if (number_spelled == "four" || number_spelled == "FOUR" || number_spelled == "Four")
                        cout << 4;
                    else
                        cout << "hmm, not a number I know.";

    cout << endl;

    keep_window_open();

    return 0;
}
