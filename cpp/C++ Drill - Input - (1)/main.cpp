#include "C:\Users\Gonzalo\Documents\cpp\std_lib_facilities.h"

int main () {

   string first_name = "?";                                          //Just to initialize the variables
   string friend_name = "?";
   int age = 0;
   char friend_sex = 0;

   cout << "Enter the name of the person you want to write to: ";    //Prints in the screen
   cin >> first_name;                                                //Grab the name

   cout << "Dear " << first_name << "," << endl << endl;           //Shows "Dear first_name," in the screen and double line break
   cout << "\tHow are you doing? I am fine. Everyone around here is okay too. " << endl;
   cout << "When are you returning? I'm bored. Staying here kall-day isn't very productive." << endl;
   cout << "Even the food is not tasting good. Probably it just got spoiled in the meanwhile." << endl;
   cout << "It's been rainy here also. Not a sign that the sun's coming soon, I guess." << endl;
   cout << "Anyway, whenever you are, we are welcome to having you back." << endl;

   cout << "Please enter a friend's name: ";
   cin >> friend_name;

   cout << "...Oh, but wait, have you seen " << friend_name << " lately?" << endl;

   cout << "Enter friend's sex (Just 'f' or 'm'): ";
   cin >> friend_sex;

   cout << "If you see " << friend_name << " please ask ";
   if (friend_sex == 'm')
      cout << "him ";
      else
         if (friend_sex == 'f')
            cout << "her ";
   cout << "to call me." << endl;

   cout << "Enter your recipient's age: ";
   cin >> age;

   if (age <= 0 || age >= 100)
      simple_error("You're kidding!");
   else
      cout << "I hear you just had a birthday and you are " << age << " years old." << endl;

   if (age > 0 && age < 100) {
      if (age < 12)
         cout << "Next year you will be " << age + 1 << endl;
      else
         if (age == 17)
            cout << "Next year you'll be able to vote." << endl;
         else
            if (age > 70)
               cout << "I hope you are enjoying retirement." << endl;
   }

   cout << "\t\t\tYours sincerely, ___________" << endl;
   cout << "\t\t\tGonzalo Rodulfo" << endl;

   keep_window_open();

   return 0;
}
