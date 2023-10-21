#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*
   Miles to Kilometers program

*/

int main () {

   double miles, kilometers;
   miles = kilometers = 0;

   cout << "Enter miles to convert: ";
   cin >> miles;

   if (miles < 0)
      simple_error("Don't enter negative numbers");
   else {
      kilometers = miles * 1.609;
      cout << "Miles: " << miles << endl;
      cout << "Kilometers: " << kilometers << endl;
   }

   keep_window_open();

}
