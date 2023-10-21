#include <iostream>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>
#include <random>
using std::cin;
using std::cout;
using std::vector;
using std::cerr;
using std::endl;
using std::string;
using std::transform;


class BadTemp { };
class BadInput { };
class BadDay { };
class NegativeSqrt { };
class NumberGreaterThanAllowed { };
class SumGreaterThanInt { };

//For 4
double ctok(const double c) {
    constexpr double lowestTemp = -273.15;  
    if (c < lowestTemp)
        throw BadTemp {};
    return c + abs(lowestTemp);
}

double ktoc(const double k) {
    constexpr double lowestTemp = -273.15;
    if (k < lowestTemp)
        throw BadTemp {};
    return k - abs(lowestTemp);
}

double ctof(const double c) {
    constexpr double absoluteZero = -273.15; //Celsius
    if (c < absoluteZero)
        throw BadTemp {};
    return c * 9 / 5 + 32;
}

double ftoc(const double f) {
    constexpr double absoluteZero = -459.67; //Fahrenheit
    if (f < absoluteZero)
        throw BadTemp {};
    return (f - 32) * 5 / 9;
}

double rootOp(const double a, const double b, const double c) {
    double root {pow(b, 2) - 4 * a * c};
    if (root < 0)
        throw NegativeSqrt { };
    return root;
}

double quadraticEquation(const double a, const double b, const double c, const bool op) {
    double root = sqrt(rootOp(a, b, c));
    if (op)     //If "true", do addition. Else, do subtraction.
        return (-b + root) / (2 * a);
    return (-b - root) / (2 * a);
}

int sumNumbers (const unsigned n, const vector<int>& v) {
    if (n > v.size())
        throw NumberGreaterThanAllowed { };
    
    unsigned int sum {0};
    
    for (unsigned int i {0}; i < n; ++i)
        sum += v.at(i);
    if (sum >= std::numeric_limits<int>::max())
        throw SumGreaterThanInt { };
    return sum;
}

double sumNumbers (const unsigned n, const vector<double>& v) {
    if (n > v.size())
        throw NumberGreaterThanAllowed { };
    
    unsigned int sum {0};
    
    for (unsigned int i {0}; i < n; ++i)
        sum += v.at(i);
    if (sum >= std::numeric_limits<int>::max())
        throw SumGreaterThanInt { };
    return sum;
}

string searchForNumbers(const vector<short>& ints, short& b, short input) {
    short c {0};
    for (short i = ints.size() - 1; i >= 0; input /= 10, --i)
        for (short j = ints.size() - 1; j >= 0; --j)
            if (ints.at(j) == input % 10) {
                (i == j) ? b++ : c++;
                break;
            }
                
    return std::to_string(b) + " Bulls and " + std::to_string(c) + " Cows";
}

bool checkForRepeatedInVector(const vector<short>& ints, const short number) {
    if (ints.size() > 0)
        for (short s : ints)
            if (s == number)
                return true;
    return false;
}

int searchForDayOfWeek(const string& s, const vector<string>& v) {
    for (unsigned int i = 0, vSize = v.size(); i < vSize; i += 2)
        if (v.at(i) == s || v.at(i + 1) == s)
            return (i % 2) ? (i - 1) / 2 : i / 2;
    return -1;
}

int sumDayOfWeek(const int& index, const vector<vector<int>>& v) {
    unsigned int sum {0};
    for (unsigned int i {0}, vSize {v.at(index).size()}; i < vSize; i++) 
        sum += v.at(index).at(i);
    return sum;
}

int main() {
    /*//2 — Program that takes input a temperature value in Celsius and converts it to Kelvin. Correct the code.
    double c {0};
    std::cin >> c;
    double k {ctok(c)};
    std::cout << k << '\n';*/
    
    //3 - Place a check in the main program that will produce an error if a temperature is given below -273.15C
    /*constexpr int lowestTemp = -273.15;
    double c {0};
    std::cin >> c;
    
    if (c < lowestTemp)
        std::cerr << "Temperature below -273.15. Try again.\n";
    else {
        double k {ctok(c)};
        std::cout << k << '\n';
    }*/
    
    //4 - Handle the error inside ctok()
    /*double c {0};
    std::cin >> c;
    try {
        if (!std::cin)
            throw BadInput { };
        double k {ctok(c)};
        std::cout << k << '\n';
    }
    catch (BadTemp) {
        std::cerr << "BadTemp in ctok()\n";
    }
    catch (BadInput) {
        std::cerr << "BadInput in main()\n";
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    catch(...) {
        std::cerr << "Unknown error\n";
    }*/
    
    //5 - Add to the program so that it can also convert from Kelvin to Celsius
    /*double value {0};
    for (char unit {'c'}; std::cin >> value >> unit;) {
        try {
            switch(unit) {
            case 'c': case 'C':
                std::cout << ctok(value) << "K\n";
                break;
            case 'k': case 'K':
                std::cout << ktoc(value) << "C\n";
                break;
            default:
                throw BadInput { };
            }
        }
        catch (BadTemp) {
            std::cerr << "BadTemp in ctok(). Min: 273.15\n";
        }
        catch (BadInput) {
            std::cerr << "BadInput in main(). Unit not supported\n";
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        catch(...) {
            std::cerr << "Unknown error\n";
        }
    }
    try {
        if (!std::cin)
            throw BadInput {};
    }
    catch (BadInput) {
        std::cerr << "BadInput in main()\n";
    }*/
    
    //6 - Write a program that converts from Celsius to Fahrenheit and vice versa.
    /*double value {0};
    
    for (char unit {'c'}; std::cin >> value >> unit; ) {
        try {
            switch(unit) {
            case 'c': case 'C':
                std::cout << ctof(value) << "f\n";
                break;
            case 'f': case 'F':
                std::cout << ftoc(value) << "c\n";
                break;
            default:
                throw BadInput {};
            }
        }
        catch(BadInput) {
            std::cerr << "BadInput in main(). Unsupported unit\n";
        }
        catch(BadTemp) {
            std::cerr << "BadTemp in ctof() or ftoc(). Value mustn't be below absolute zero\n";
        }
        catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        catch(...) {
            std::cerr << "Unknown error caught in main()\n";
        }
    }
    try {
        if(!std::cin)
            throw BadInput {};
    }
    catch (BadInput) {
        std::cerr << "BadInput() in main(). Input not allowed.\n";
    }
    */
    
    //7 - Quadratic equations
    /*std::cout << "Enter a, b and c. Don't enter the variables. E.g.: 4 5 1.\n";
    for (double a, b, c; std::cin >> a >> b >> c; ) {
        try {
            std::cout << "x1: " << quadraticEquation(a, b, c, true) << std::endl;
            std::cout << "x2: " << quadraticEquation(a, b, c, false) << std::endl;
        }
        catch (NegativeSqrt) {
            std::cerr << "NegativeSqrt() in quadraticEquation(). Negative Square Root detected.\n";
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (...) {
            std::cerr << "Unknown error in main()\n" << std::endl;
        }
    }
    try {
        if (!std::cin)
            throw BadInput { };
    }
    catch (BadInput) {
        std::cerr << "BadInput() in main(). Input not allowed.\n";
    }*/
    
    //8
    /*int n {0};
    std::cout << "Please enter the number of values you want to sum: ";
    try {
        std::cin >> n;
        if (!std::cin) 
            throw BadInput {};
        n = abs(n);
    }
    catch (BadInput) {
        std::cerr << "BadInput() in main(). You entered a not allowed input.\n";
        return -1;
    }
    
    std::vector<int> values;
    for (int value; std::cin >> value && value != '|';)
        values.push_back(value);
    try {
        std::cout << "Sum of the first " << n << " numbers: " << sumNumbers(n, values) << std::endl;
    }
    catch (NumberGreaterThanAllowed) {
        std::cerr << "NumberGreaterThanAllowed() in sumNumbers(). 'n' value (" << n << ") is greater than vector size.\n";
    }
    catch(...) {
        std::cerr << "Unknown error in main()\n";
    }*/
    
    //9
    /*int n {0};
    cout << "Please enter the number of values you want to sum: ";
    try {
        cin >> n;
        if (!cin) 
            throw BadInput {};
        n = abs(n);
    }
    catch (BadInput) {
        cerr << "BadInput() in main(). You entered a not allowed input.\n";
        return -1;
    }
    
    vector<int> values;
    for (int value; cin >> value && value != '|';)
        values.push_back(value);
    try {
        cout << "Sum of the first " << n << " numbers: " << sumNumbers(n, values) << endl;
    }
    catch (NumberGreaterThanAllowed) {
        cerr << "NumberGreaterThanAllowed() in sumNumbers(). 'n' value (" << n << ") is greater than vector size.\n";
    }
    catch (SumGreaterThanInt) {
        cerr << "SumGreaterThanInt() in sumNumbers(). \'sum\' value is greater than int"; 
    }
    catch(...) {
        cerr << "Unknown error in main()\n";
    }*/
    
    //10
    /*double n {0};
    cout << "Please enter the number of values you want to sum: ";
    try {
        cin >> n;
        if (!cin) 
            throw BadInput {};
        n = abs(n);
    }
    catch (BadInput) {
        cerr << "BadInput() in main(). You entered a not allowed input.\n";
        return -1;
    }
    
    vector<double> values;
    vector<double> differences(n - 1);
    for (double value; cin >> value && value != '|';)
        values.push_back(value);
    
    double total {values.at(0)};
    for (size_t i = 1; i < n; ++i) {
        total += values.at(i);
        differences.at(i - 1) = values.at(i) - values.at(i - 1);
    }
        
        
    try {
        cout << "The total is: " << total << endl;
        cout << "The differences are: ";
        for (double d : differences) {
            cout << d << endl;
        }
        cout << "Sum of the first " << n << " numbers: " << sumNumbers(n, values) << endl;
    }
    catch (NumberGreaterThanAllowed) {
        cerr << "NumberGreaterThanAllowed() in sumNumbers(). 'n' value (" << n << ") is greater than vector size.\n";
    }
    catch (SumGreaterThanInt) {
        cerr << "SumGreaterThanInt() in sumNumbers(). \'sum\' value is greater than int"; 
    }
    catch(...) {
        cerr << "Unknown error in main()\n";
    }*/
    
    //11

    /*unsigned int fibValue1 {1}, fibValue2 {1}, fibValue {0};
    cout << fibValue1 << ' ' << fibValue2 << ' ';
    for (; (fibValue1 + fibValue2) < std::numeric_limits<int>::max(); ) {
        fibValue = fibValue1 + fibValue2;
        cout << fibValue << ' ';
        fibValue1 = fibValue2;
        fibValue2 = fibValue;
    }*/
    
    //12 - Bulls and Cows (HARDCODED)
    
    /*constexpr short amount {4};
    short guessNumber {0}, bulls {0};
    vector<short> integers = {1, 2, 3, 4};
    
    try {
        do {
            bulls = 0;
            cout << "Please enter guess number: ";
            cin >> guessNumber;
            if (!cin)
                throw BadInput {};
            cout << searchForNumbers(integers, bulls, guessNumber) << endl;
        } while (bulls != amount);
        cout << "Congratulations!" << endl;
    }
    catch (BadInput) {
        cerr << "BadInput() in main(). You entered a not allowed input.\n";
        return -1;
    }*/
    
    //13 - Bulls and Cows (Random)
    
    /*unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 9);
    
    constexpr short amount {4};
    short guessNumber {0}, bulls {0};
    vector<short> integers;
    
    for (unsigned short i = 0, number = 0; i < amount; ++i) {
        do {
            number = distribution(generator);
        } while(checkForRepeatedInVector(integers, number));
        integers.push_back(number);
    }
        
    try {
        do {
            bulls = 0;
            cout << "Please enter guess number: ";
            cin >> guessNumber;
            if (!cin)
                throw BadInput {};
            cout << searchForNumbers(integers, bulls, guessNumber) << endl;
            for (short s : integers)
                cout << s << ' ';
        } while (bulls != amount);
        cout << "Congratulations!" << endl;
    }
    catch (BadInput) {
        cerr << "BadInput() in main(). You entered a not allowed input.\n";
        return -1;
    }*/
    
    //14 - Read (day-of-the-week,value) pairs from standard input.
    
    vector<vector<int> > dayOfWeek_value(7);
    vector<string> dayOfWeek {"monday", "mon", "tuesday", "tue", "wednesday", "wed", "thursday", "thur", "friday", "fri", "saturday", "sat", "sunday", "sun"};
    
    string day = "";
    int value = 0;
        try {
            cout << "Enter Day-of-the-Week and a value (e.g.: Thursday, 25): " << endl;
            for (; cin >> day >> value; ) {
                transform(day.begin(), day.end(), day.begin(), ::tolower);
                int dayOfWeek_index = searchForDayOfWeek(day, dayOfWeek);
                if (dayOfWeek_index == -1)
                    throw BadDay { };
                dayOfWeek_value.at(dayOfWeek_index).push_back(value);
            }
        }
        catch (BadDay) {
            cerr << "BadDay() in main(). You entered an invalid Day of the Week.\n";
            cout << "\"" << day << ", " << value << "\"" << endl;
        }
        catch (BadInput) {
            cerr << "BadInput() in main(). You entered a not allowed input.\n";
            return -1;
        }
        
    for (unsigned int i {0}, vSize {dayOfWeek.size()}; i < vSize; i += 2) {
        unsigned int index = (i % 2) ? (i - 1) / 2 : i / 2;
        cout << dayOfWeek.at(i) << ": " << sumDayOfWeek(index, dayOfWeek_value) << endl;
    }
    
    return 0;
}
