#include "Box.h"

Box::Box()
{
    num1 = num2 = 1;
    name = "Caja";
}

Box::Box(string name, int num1, int num2) {
    this->num1 = num1;
    this->num2 = num2;
    this->name = name;
}

Box::~Box()
{
    
}

int Box::addition() {
    return num1 + num2;
}

int Box::substract() {
    return num1 - num2;
}

int Box::multiply() {
    return num1 * num2;
}

int Box::divide() {
    return num1 / num2;
}

string Box::getName() {
    return name;
}

void Box::setNum1(int num1) {
    this->num1 = num1;
}

void Box::setNum2(int num2) {
    this->num2 = num2;
}
