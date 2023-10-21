#include <iostream>
#include "Box.h"
using namespace std;

Box::Box() {
    side = 0;
    name = "";
}

Box::Box(int side, string name) {
    this->side = side;
    this->name = name;
}

Box::~Box(){
}

string Box::getName() {
    return name;
}

int Box::getSide() {
    return side;
}

void Box::setName(string name) {
    this->name = name;
}

void Box::setSide(int side) {
    this->side = side;
}
