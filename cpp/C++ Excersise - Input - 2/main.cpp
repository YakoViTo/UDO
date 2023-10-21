#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*
   4 - Prompt two integers

*/

int main () {

   int val1, val2;
   val1 = val2 = 0;

   cout << "Please enter two integer numbers: ";
   cin >> val1 >> val2;

   cout << "The smaller number is: ";
   if (val1 > val2) {
       cout << val2 << endl;
       cout << "The larger is: " << val1 << endl;
   }
   else {
      cout << val1 << endl;
      cout << "The larger is: " << val2 << endl;
   }

   cout << "The product of both is: " << val1*val2 << endl;

   cout << "The difference of both is: " << val1-val2 << endl;

   cout << "The ratio of both numbers is: " << val1 << ":" << val2 << endl;

   cout << endl << "Modified with floating-point values: " << endl;

   double decimal_num, decimal_num2;
   decimal_num = decimal_num2 = 0;

   cout << "Please enter two integer numbers: ";
   cin >> decimal_num >> decimal_num2;

   cout << "The smaller number is: ";
   if (decimal_num > decimal_num2) {
       cout << decimal_num2 << endl;
       cout << "The larger is: " << decimal_num << endl;
   }
   else {
      cout << decimal_num << endl;
      cout << "The larger is: " << decimal_num2 << endl;
   }

   cout << "The product of both is: " << decimal_num*decimal_num2 << endl;

   cout << "The difference of both is: " << decimal_num-decimal_num2 << endl;

   cout << "The ratio of both numbers is: " << decimal_num << ":" << decimal_num2 << endl;

   keep_window_open();

   return 0;
}
