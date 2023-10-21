#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits>
#include <string>
using namespace std;

double totalDistance(const vector<double>& v) {
    double sum = 0;
    for (double x : v)
        sum += x;
    return sum;
}

double smallestDistance(const vector<double>& v) {
    double value = v[0];
    for (double x : v)
        if (x < value)
            value = x;
    return value;
}

double greatestDistance(const vector<double>& v) {
    double value = v.at(0);
    for (double x : v)
        if (x > value)
            value = x;
    return value;
}

double meanDistance (const vector<double>& v) {
    return totalDistance(v) / v.size();
}

short changeToNumber (const string x, const vector<string>& numbers) {
    if (isalpha(x.front()))
        for (unsigned char i = 0; i < numbers.size(); ++i) {
            if (numbers.at(i).compare(x) == 0)
                return i;
        }
    else
        if (isdigit(x.front()) && (stoi(x) >= 0 && stoi(x) < 10))
            return stoi(x);
    return -1;
}

string decideWinner (const short user, const short program) {
    if ((program) % 3 + 1 == user)
        return "You win!";
    else
        if ((user) % 3 + 1 == program)
            return "You lose";
    return "It's a draw";
}

string showName (const short x) {
    switch (x) {
    case 1:
        return "Rock";
        break;
    case 2:
        return "Paper";
        break;
    case 3:
        return "Scissors";
        break;
    default:
        return "Something went wrong. Restart the game";
    }
    
}

/*bool isPrime (const short number, const vector<short>& primes) {
    for (unsigned short i = 0; i < primes.size(); ++i)
        if (!(number % primes.at(i)))
            return false;
    return true;
}*/

bool isPrime (const short number, const vector<short>& primes) {
    for (unsigned short i = 0; i < primes.size(); ++i)
        if (!(number % primes.at(i)) && number != primes.at(i))
            return false;
    return true;
}

bool stringComparisson (const string& s, const string& s2) {
    if (s.size() > s2.size()) 
        return true;
    else
        if (s.size() == s2.size()) {
            for (unsigned int i = 0; i < s.size(); ++i)
                return s[i] > s2[i];
        }
    return false;
}

void selectionSort (vector<string>& words) {
    for (unsigned int i = 0; i < words.size() - 1; ++i) {
        unsigned int minIndex = i;
        for (unsigned int j = i + 1; j < words.size(); ++j)
            if (stringComparisson(words.at(minIndex), words.at(j)))
                minIndex = j;
        if (minIndex != i) {
            string tmp = words.at(i);
            words.at(i) = words.at(minIndex);
            words.at(minIndex) = tmp;
        }
    }
}

double quadraticEquation (const double squareRoot, const double a, const double b, const char op) {
    switch (op) {
    case '+':
        return (-b + squareRoot) / (2*a);
        break;
    case '-':
        return (-b - squareRoot) / (2*a);
        break;
    default:
        return -1;
    }
    return -1;
}

bool isStringAlpha (const string& s) {
    for (unsigned int i = 0; i < s.size(); ++i)
        if (isdigit(s.at(i)))
            return true;
    return false;
}

bool isNameRepeated (const vector<string>& v, const string name) {
    for (string a : v) {
        if (name == a)
            return true;
    }
    return false;
}

int findName (const vector<string>& v, const string name) {
    for (unsigned int i = 0, vectorSize = v.size(); i < vectorSize; ++i)
        if (name == v.at(i))
            return i;
    return -1;
}

string findScore (const vector<string>& names, const vector<unsigned short>& scores, const unsigned short score) {
    string s = "";
    for (unsigned int i = 0, vectorSize = scores.size(); i < vectorSize; ++i)
        if (score == scores.at(i))
            s.append(names.at(i) + "\n");
    if (s.empty())
        return "Score not found\n";
    return s;
}


int main() {
    //#3
    /*vector<double> temps;
    for (double temp; cin >> temp; )
        temps.push_back(temp);
    
    sort(temps.begin(), temps.end());
    
    cout << "Total distance: " << totalDistance(temps) << endl;
    cout << "Mean distance: " << meanDistance(temps) << endl;
    cout << "Smallest distance: " << smallestDistance(temps) << endl;
    cout << "Greatest distance: " << greatestDistance(temps) << endl;*/
    
    //#5
    /*char op = '+';
    for (double num1, num2; cin >> num1 >> num2 >> op;) {
        switch (op) {
        case '+':
            cout << "The sum of " << num1 << " and " << num2 << " is " << num1 + num2 << endl;
            break;
        case '-':
            cout << "The subtraction of " << num1 << " and " << num2 << " is " << num1 - num2 << endl;
            break;
        case '*':
            cout << "The multiplication of " << num1 << " and " << num2 << " is " << num1 * num2 << endl;
            break;
        case '/':
            if (isinf(num1 / num2))
                cout << "The division of " << num1 << " and " << num2 << " is infinite" << endl;
            else
                if (isnan(num1 / num2))
                    cout << "The division of " << num1 << " and " << num2 << " is 0" << endl;
                else
                    cout << "The division of " << num1 << " and " << num2 << " is " << num1 / num2 << endl;
            break;
        default:
            cout << "Operation not available" << endl;
        }
    }*/
    
    //#6
    /*vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    for (string number; cin >> number; ) {
        
        if (isalnum(number.front())) {
            if (isdigit(number.front())) {
                if (stoi(number) >= 0 && stoi(number) < 10)
                    cout << numbers.at(stoi(number)) << endl;
                else
                    cout << "Not a valid number" << endl;
            }
            else {
                unsigned char i = 0;
                for (; i < numbers.size(); ++i) {
                    if (numbers.at(i).compare(number) == 0) {
                        cout << int(i) << endl;
                        break; 
                    }
                }
                if (i == numbers.size())
                    cout << "Not a valid number" << endl;
            }
        }
        else
            cout << "Not a valid character" << endl;
            
    }*/
    
    //#7
    /*vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    char op = '+';
   
    for (string num1, num2; cin >> num1 >> num2 >> op;) {
        
        if (isalnum(num1.front()) && isalnum(num2.front())) {
            
            short x1 = changeToNumber(num1, numbers);
            short x2 = changeToNumber(num2, numbers);
            
            if (x1 == -1 || x2 == -1)
                cout << "One (or both) numbers are not allowed" << endl;
            else
                switch (op) {
                case '+':
                    cout << "The sum of " << x1 << " and " << x2 << " is " << x1 + x2 << endl;
                    break;
                case '-':
                    cout << "The subtraction of " << x1 << " and " << x2 << " is " << x1 - x2 << endl;
                    break;
                case '*':
                    cout << "The multiplication of " << x1 << " and " << x2 << " is " << x1 * x2 << endl;
                    break;
                case '/':
                    if (isinf(x1 / x2))
                        cout << "The division of " << x1 << " and " << x1 << " is infinite" << endl;
                    else
                        if (isnan(x1 / x2))
                            cout << "The division of " << x1 << " and " << x2 << " is 0" << endl;
                        else
                            cout << "The division of " << x1 << " and " << x2 << " is " << x1 / x2 << endl;
                    break;
                default:
                    cout << "Operation not available. Use '+', '-', '*', or '/'." << endl;
                }
        }
        else
            cout << "Please enter single-digit numbers either digits or spelled out" << endl;
       
    }*/
    
    //#8 - Modified
    //*NOTA: Como el ejercicio pide hasta un millardo de granos de arroz. No es necesario establecer los 64 cuadrados 
    //del tablero del ajedrez, lo máximo sería 30 cuadrados = un millardo y pico.
    //DE OTRA MANERA, SE CAMBIARÍA EL TIPO DE DATO A UN UNSIGNED LONG.
    /*const unsigned int maxAmount = 1000000000;
    const char maxChessSquare = 30;
    short chessSquare = maxChessSquare;
    
    unsigned int amountRiceGrains = 0;
    do {
        cout << "Amount of rice grains to input (Max. 1 billion): " << endl;
        cin >> amountRiceGrains;
    } while (amountRiceGrains > maxAmount || amountRiceGrains < 0);
   
    for (unsigned int totalGrains = 0, currentGrains = 0; chessSquare >= 0 && totalGrains != amountRiceGrains; --chessSquare) {
        currentGrains = pow(2, chessSquare);
        if (currentGrains + totalGrains <= amountRiceGrains) {
            totalGrains += currentGrains;
            cout << "Square #" << chessSquare + 1 << " - " << currentGrains << endl; 
        }
    }*/
    
    //#9
    /*const unsigned int maxAmount = 10000000000;
    const char maxChessSquare = 30;
    short chessSquare = maxChessSquare;
    
    double amountRiceGrains = 0;
    cin >> amountRiceGrains;
    do {
        cout << "Amount of rice grains to input (Max. 1 billion): " << endl;
        cin >> amountRiceGrains;
    } while (amountRiceGrains > maxAmount || amountRiceGrains < 0);
   
    for (int totalGrains = 0, currentGrains = 0; chessSquare >= 0 && totalGrains != amountRiceGrains; --chessSquare) {
        currentGrains = pow(2, chessSquare);
        if (currentGrains + totalGrains <= amountRiceGrains) {
            totalGrains += currentGrains;
            cout << "Square #" << chessSquare + 1 << " - " << currentGrains << endl; 
        }
    }*/
    
    //#10
    /*vector <short> answer = {1, 3, 2, 1, 3, 1, 2, 3, 2, 1, 3, 3, 2};
    short userAnswer, programAnswer;
    do {
        cout << "Rock, paper, scissors!" << endl;
        cout << "1 - Rock\n2 - Paper\n3 - Scissors\n4 - Exit" << endl;
        cin >> userAnswer;
        
        switch (userAnswer) {
        case 1: case 2: case 3:
            programAnswer = answer.back();
            cout << decideWinner(userAnswer, programAnswer) << " - Program used: " << showName(programAnswer) << endl;
            answer.pop_back();
            answer.push_back(userAnswer); 
            break;
        case 4:
            break;
        default:
            cout << "Not a valid answer" << endl;
        }
        
    } while (userAnswer != 4);*/
    
    //#11
    /*vector <short> primes = {2, 3, 5, 7};
    vector <short> primeNumbers = primes;
    const unsigned short max = 100;
    
    for (unsigned short i = 2; i <= max; ++i)
        if (isPrime(i, primes))
            primeNumbers.push_back(i);
    for (unsigned short number : primeNumbers)
        cout << number << endl;*/
        
    //#12
    /*vector <short> primes = {2, 3, 5, 7};
    for (unsigned short maxValue; cin >> maxValue;) {
        vector <short> primeNumbers;
        for (unsigned short i = 2; i <= maxValue; ++i)
            if (isPrime(i, primes))
                primeNumbers.push_back(i);
        for (unsigned short number : primeNumbers)
            cout << number << endl;
    }*/
    
    //#13 - Sieve of Eratosthenes
    /*cout << "Primes from 1 to 100 using Sieve of Eratosthenes" << endl;
    vector<bool> values(101);
    
    for (unsigned short i = 2; i < values.size(); ++i)
        values.at(i) = true;
    
    for (unsigned short i = 2; i <= sqrt(values.size()); ++i) {
        if (values.at(i)) {
            for (unsigned short k = 0, j = 0; j < values.size(); ++k) {
                j = pow(i, 2) + (k * i);
                if (j < values.size())
                    values.at(j) = false;
            }
        }
    }
    
    for (unsigned short i = 2; i < values.size(); ++i) 
        if (values.at(i))
            cout << i << endl;*/
            
    //#14
    /*cout << "Primes from 1 to max using Sieve of Eratosthenes" << endl;
    
    unsigned short maxValue = 2;
    
    do {
        cout << "Enter a max. value (Min. value: 2): ";
        cin >> maxValue;
    } while (maxValue < 2 || maxValue >= numeric_limits<unsigned short>::max());
        
    vector<bool> values (maxValue + 1);
    
    for (unsigned short i = 2; i < values.size(); ++i)
        values.at(i) = true;
        
    for (unsigned short i = 2; i < sqrt(values.size()); ++i) {
        if (values.at(i)) {
            for (unsigned short k = 0, j = 0; j < values.size(); ++k) {
                j = pow(i, 2) + (k * i);
                if (j < values.size())
                    values.at(j) = false;
            }
        }
    }
    
    for (unsigned short i = 2; i < values.size(); ++i) 
        if (values.at(i))
            cout << i << endl;
   */
   
   //#15
   /*unsigned int maxAmount = 0;
   
   do {
        cout << "Enter max. amount (More or equal than 1): ";
        cin >> maxAmount;
   } while (maxAmount < 1);
   
   
   cout << "Primes 1 to " << maxAmount << ". Find first \'n\' primes: ";
   
   vector<bool> values (maxAmount - 2);
   
   unsigned int n = 0;
   
   do {
        cin >> n;
   } while (n < 0);
   
   for (unsigned short i = 2; i < maxAmount; ++i)
        values.at(i-2) = true;
   
   for (unsigned short i = 2; i < sqrt(maxAmount); ++i) {
        if (values.at(i - 2)) {
            for (unsigned short k = 0, j = 0; j < maxAmount; ++k) {
                j = pow(i, 2) + (k * i);
                if (j < maxAmount)
                    values.at(j - 2) = false;
            }
        }
    }
    
    for (unsigned short i = 2, k = 0; k != n && i < maxAmount; ++i) 
        if (values.at(i-2)) {
             cout << i << endl;
             k++;
        }*/
    
    //#16
    /*unsigned int mode = 0;
    vector<unsigned int> values;
    
    for (unsigned int i = 0; cin >> i; )
        values.push_back(i);
    
    sort(values.begin(), values.end());
    
    unsigned int minValue = values.front();
    unsigned int maxValue = values.back();
    
    for (unsigned int i = 0, counter = 0, number = values.front(), maxCounter = 0; i < values.size(); ++i) {
        if (values.at(i) == number)
            counter++;
        else {
            if (maxCounter < counter) {
                maxCounter = counter;
                mode = number;
            }
            counter = 1;
            number = values.at(i);
        }
            
    }
    
    cout << "The minimum value is: " << minValue << endl;
    cout << "The maximum value is: " << maxValue << endl;
    cout << "The mode is: " << mode << endl;*/
    
    //#17
    /*string mode = "";
    vector<string> words;
    vector<string> minWord;
    vector<string> maxWord;
    
    cout << "Enter some words" << endl;
    
    for (string word; cin >> word; )
        words.push_back(word);
    
    selectionSort(words);
    
    for (string x : words) 
        cout << x << endl;
    
    for (string x : words)
        if (x.length() == words.front().length())
            minWord.push_back(x);
   
    for (string x : words)
        if (x.size() == words.back().size())
            maxWord.push_back(x);
    
    string word = words.front();
    
    for (unsigned int i = 0, counter = 0, maxCounter = 0; i < words.size(); ++i) {
        if (words.at(i) == word)
            counter++;
        else {
            if (maxCounter < counter) {
                maxCounter = counter;
                mode = word;
            }
            counter = 1;
            word = words.at(i);
        }
    }
    
    cout << "The minimum word is: ";
    
    for (string x : minWord)
        cout << x << " ";
    
    cout << endl << "The maximum word is: ";
    
    for (string x : maxWord)
        cout << x << " ";
    
    cout << endl << "The mode is: " << mode << endl;*/
    
    //#18 - Quadratic Equations
    
    /*cout << "Enter a quadratic equation (Note that you should input just the coefficients, not the variables): " << endl;
    cout << "e.g.: \'2\', \'4\' and \'1\' equals to \"2x^2 + 4x + 1 = 0\"" << endl;
    
    for (double a = 0, b = 0, c = 0, squareRoot = 0; cin >> a >> b >> c; ) {
        squareRoot = sqrt(pow(b, 2) - (4*a*c));
        if (squareRoot < 0)
            cout << "Imaginary square root. Check input." << endl << endl;
        else {
            cout << squareRoot << endl;
            cout << "X1 = " << quadraticEquation(squareRoot, a, b, '+') << endl;
            cout << "X2 = " << quadraticEquation(squareRoot, a, b, '-') << endl << endl;
        }
    }*/
    
    //#19
    /*vector<string> names;
    vector<unsigned int> scores;
    
    unsigned int score = 0;
    for (string name = ""; cin >> name >> score && (name != "noname" || name != "NoName" || score != 0); ) {
        if (isStringAlpha(name))
            cerr << "Name is alphanumerical. Please use just alphabets." << endl;
        else
            if (isNameRepeated(names, name)) {
                 cerr << "Name is repeated. Terminating" << endl;
                 break;
            }
            else {
                names.push_back(name);
                scores.push_back(score);
            }
    } 
    
    for (unsigned int i = 0; i < names.size(); ++i)
        cout << names.at(i) << " " << scores.at(i) << endl;*/
    
    //#20
    /*vector<string> names;
    vector<unsigned int> scores;
    
    unsigned int score = 0;
    for (string name = ""; cin >> name >> score && (name != "noname" || name != "NoName" || score != 0); ) {
        if (isStringAlpha(name))
            cerr << "Name is alphanumerical. Please use just alphabets." << endl;
        else
            if (isNameRepeated(names, name)) {
                 cerr << "Name is repeated. Terminating" << endl;
                 break;
            }
            else {
                names.push_back(name);
                scores.push_back(score);
            }
    } 
    cout << "Enter a name: ";
    for (string name; cin >> name;) {
        int index = findName(names, name);
        if (index != -1)
            cout << "Score: " << scores.at(index) << endl << endl;
        else
            cout << "Name not found" << endl << endl;
    }*/
    
    //#21
    vector<string> names;
    vector<unsigned short> scores;
    
    unsigned int score = 0;
    for (string name = ""; cin >> name >> score && (name != "noname" && name != "NoName" || score != 0); ) {
        if (isStringAlpha(name))
            cerr << "Name is alphanumerical. Please use just alphabets." << endl;
        else
            if (isNameRepeated(names, name)) {
                 cerr << "Name is repeated. Terminating" << endl;
                 break;
            }
            else {
                names.push_back(name);
                scores.push_back(score);
            }
    }
    
    cout << endl << "Enter a score: ";  
    for (unsigned short i = 0; cin >> i; )
        cout << findScore(names, scores, i) << endl;
        
    return 0;
}
    
    
    
