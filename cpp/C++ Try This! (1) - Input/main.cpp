#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

int main () {
   //1 - Age in months
   string first, second = "???";
   double age = 0.0;

   cout << "Please enter your first and second names: ";
   cin >> first >> second;    //read two strings

   cout << "Please enter your age in years: ";
   cin >> age;

   age *= 12;

   cout << "Hello, " << first << " " << second << ", your are " << age << " months old" << endl;


   //2 - Operators
   int n, m;
   double nsq = n;
   cout << "\nPlease enter two integer values: ";
   cin >> n >> m;
   nsq = sqrt(nsq);
   cout << "n == " << n
         << "\nm == " << m
         << "\nn + 1 == " << n + 1
         << "\nthree times n == " << 3 * n
         << "\ntwice n == " << n + n
         << "\nn squared == " << n * n
         << "\nhalf of n == " << n/2
         << "\nModulo of both == " << n%m
         << "\nn/m * m + n%m == n  ==  " << n/m * m + n%m
         << "\nsquare root of n == " << nsq
         << '\n'; // another name for newline ("end of line") in output


   //3 - Repeated Words Detection Program
  /* string previous = "";
   string current;
   while (cin >> current) {
      if (previous == current)
         cout << "repeated word: " << current << '\n';
      previous = current;
   } */

   //4 - Squeezing types
   double d = 0;
   while (cin >> d) {
      int i = d;     //Try to squeeze a double into an int
      char c = i;    //Try to squeeze an int into a char
      int i2 = c;    //get the integer value of the character
      cout << "d == " << d          //The original double
            << " i == " << i        //converted to int
            << " i2 == " << i2      //int value of char
            << " char(" << c << ")\n";    //the char
   }

   keep_window_open();
}
