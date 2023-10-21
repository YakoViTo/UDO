#ifndef BOX_H
#define BOX_H
#include <iostream>
using namespace std;

class Box
{
        int num1, num2;
        string name;
    
    public:
        Box();
        Box(string name, int num1, int num2);
        ~Box();
        int addition();
        int substract();
        int multiply();
        int divide();
        string getName();
        void setNum1 (int num1);
        void setNum2 (int num2);
};

#endif // BOX_H
