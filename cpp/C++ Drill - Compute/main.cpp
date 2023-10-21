#include <iostream>
#include <vector>
using namespace std;

/*
    Drill - From 1 to 11

*/

int main()
{
    /*int value1, value2;       //Upon using these variables, please set in comment the other ones, because they have the
    value1 = value2 = 0;        //same name.
    
    int larger, smaller;
    larger = smaller = 0;*/
    
    double number1, number2, larger, smaller;
    number1 = number2 = smaller = larger = 0.0;
    
    //double difference {1.0/100};    //To check whether both numbers have a small gap in being equals.
    string unit = "?";   //For the unit case in 7.
    double sum = 0.0;    //For the sum case in 9.
    constexpr double m_to_cm = 100;    //1 meter to cm.
    constexpr double in_to_cm = 2.54;  //1 inches to cm.
    constexpr double ft_to_in = 12;    //1 feet to inches.
    constexpr double ft_to_cm = 30.48; //1 feet to cm.
    constexpr double m_to_in = 39.370; //1 meter to in.
    constexpr double m_to_ft = 3.2808; //1 meter to foot.
    
    //1
   /* while (cin >> value1 >> value2)
        cout << value1 << " " << value2 << endl; */
        
    //2
    /*while (cin >> value1 >> value2) {
        if (value1 > value2) {
            larger = value1;
            smaller = value2;
        }
        else {
            larger = value2;
            smaller = value1;
        }
        cout << "The smaller value is: " << smaller << endl;
        cout << "The larger value is: " << larger << endl;
    }*/
    
    
    //3
   /* while (cin >> value1 >> value2) {
        if (value1 > value2) {
            larger = value1;
            smaller = value2;
        }
        else
            if (value2 > value1) {
                larger = value2;
                smaller = value1;
            }
            else {
                cout << "The numbers are equal." << endl;
                continue;
            }
        cout << "The smaller value is: " << smaller << endl;
        cout << "The larger value is: " << larger << endl;    
    }*/
    
    //4
    /*while (cin >> number1 >> number2) {
        if (number1 > number2) {
            larger = number1;
            smaller = number2;
        }
        else
            if (number2 > number1) {
                smaller = number1;
                larger = number2;
            }
            else {
                cout << "The numbers are equal." << endl;
                continue;
            }
        cout << "The smaller value is: " << smaller << endl;
        cout << "The larger value is: " << larger << endl;
    }*/
    
    //5
    /*while (cin >> number1 >> number2) {
        if (number1 > number2) {
            larger = number1;
            smaller = number2;
        }
        else
            if (number2 > number1) {
                smaller = number1;
                larger = number2;
            }
            else {
                cout << "The numbers are equal." << endl;
                continue;
            }
        if (larger - smaller <= difference) 
            cout << "The numbers are almost equal." << endl;
        else {
            cout << "The smaller value is: " << smaller << endl;
            cout << "The larger value is: " << larger << endl;
        }    
    }*/
   
    //6
   /* while (cin >> number1) {
        cout << number1;
        if (larger == 0 && smaller == 0) {
            larger = smaller = number1;
            cout << " - The smallest and the largest so far.";
        }
        else
            if (number1 >= larger) {    
                larger = number1;
                cout << " - The largest so far.";
            }
            else
                if (number1 <= smaller) {
                    smaller = number1;
                    cout << " - The smallest so far.";
                }
        cout << endl;
    }*/
    
    //7 and 8 - I think it's this way
    /*while (cin >> number1 >> unit) {
        if (unit == "m" || unit == "M") {
             cout << "to cm: " << number1 * m_to_cm << endl;
             cout << "to in: " << number1 * m_to_in << endl;
             cout << "to ft: " << number1 * m_to_ft << endl;
        }
        else
            if (unit == "in" || unit == "IN") {
                cout << "to cm: " << number1 * in_to_cm << endl;
                cout << "to m: " << number1 / m_to_in << endl;
                cout << "to ft: " << number1 / ft_to_in << endl;
            }
            else
                if (unit == "ft" || unit == "FT") {
                    cout << "to in: " << number1 * ft_to_in << endl;
                    cout << "to cm: " << number1 * ft_to_cm << endl;
                    cout << "to m: " << number1 / m_to_ft << endl;
                }
                else
                    if (unit == "cm" || unit == "CM") {
                       cout << "to m: " << number1 / m_to_cm << endl;
                       cout << "to in: " << number1 / in_to_cm << endl;
                       cout << "to ft: " << number1 / ft_to_cm << endl;
                    }  
                    else
                        cout << "Not an unit I know." << endl;
    }*/
    
    //9
    /*int values = 0;
    while (cin >> number1 >> unit) {
       
        if (unit == "cm") 
            sum += number1 / m_to_cm;
        else
            if (unit == "ft")
                sum += number1 / m_to_ft;
            else
                if (unit == "in")
                    sum += number1 / m_to_in;
                else {
                    cout << "Not an unit I know." << endl;
                    continue;
                }
                
        if (larger == 0 && smaller == 0) 
            larger = smaller = number1;
        else
            if (number1 > larger)  
                larger = number1;
            else
                if (number1 < smaller)
                    smaller = number1;
        ++values;
    }
    
    cout << "The sum is: " << sum << "m" << endl;
    cout << "The smaller value is: " << smaller << endl;
    cout << "The larger value is: " << larger << endl;
    cout << "The number of values entered are: " << values << endl;*/
    
    //10 and 11
    int number_count = 0;
    double converted_value = 0.0;
    vector <double> values;
    
    for ( ; cin >> number1 >> unit; number_count++) {
        
        if (unit == "cm" || unit == "CM")
            converted_value = number1 / m_to_cm;
        else
            if (unit == "in" || unit == "IN")
                converted_value = number1 / in_to_cm;
            else
                if (unit == "ft" || unit == "FT")
                    converted_value = number1 / m_to_ft;
                else {
                    cout << "Not a value I know." << endl;
                    continue;
                }
       
        values.push_back(converted_value);
        
        if (smaller == 0 && larger == 0)
            smaller = larger = converted_value;
        else
            if (number1 < smaller)
                smaller = converted_value;
            else
                if (number1 > larger)
                    larger = converted_value;
    }
    
    sort(values);
    
    return 0;
}
