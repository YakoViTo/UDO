#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

/*
   6 - Prompt two integers

*/

int main () {

   int val1, val2, val3, smallest_val, biggest_val;
   val1 = val2 = val3 = smallest_val = biggest_val = 0;

   cout << "Enter three integer numbers: ";
   cin >> val1 >> val2 >> val3;

   if (val1 > val2 && val1 > val3)
      biggest_val = val1;
   else
      if (val2 > val1 && val2 > val3)
         biggest_val = val2;
      else
         if (val3 > val1 && val3 > val2)
            biggest_val = val3;

   if (val1 < val2 && val1 < val3)
      smallest_val = val1;
   else
      if (val2 < val1 && val2 < val3)
         smallest_val = val2;
      else
         if (val3 < val1 && val3 < val2)
            smallest_val = val3;

    cout << smallest_val << ", ";
    if (val1 > smallest_val && val1 < biggest_val)
      cout << val1;
    else
      if (val2 > smallest_val && val2 < biggest_val)
         cout << val2;
      else
         if (val3 > smallest_val && val3 < biggest_val)
            cout << val3;
   cout << ", " << biggest_val << endl;

   //With strings
   string name1, name2, name3, biggest_name, smallest_name;
   name1 = name2 = name3 = biggest_name = smallest_name = "?";

   cout << endl << "With Strings" << endl;

   cout << "Enter three strings: ";
   cin >> name1 >> name2 >> name3;

   if (name1 > name2 && name1 > name3)
      biggest_name = name1;
   else
      if (name2 > name1 && name2 > name3)
         biggest_name = name2;
      else
         if (name3 > name1 && name3 > name2)
            biggest_name = name3;

   if (name1 < name2 && name1 < name3)
         smallest_name = name1;
   else
      if (name2 < name1 && name2 < name3)
         smallest_name = name2;
      else
         if (name3 < name1 && name3 < name2)
            smallest_name = name3;

   cout << smallest_name << ", ";
   if (name1 > smallest_name && name1 < biggest_name)
      cout << name1;
   else
      if (name2 > smallest_name && name2 < biggest_name)
         cout << name2;
     else
         if (name3 > smallest_name && name3 < biggest_name)
            cout << name3;

   cout << ", " << biggest_name << endl;

   keep_window_open();

   return 0;
}
