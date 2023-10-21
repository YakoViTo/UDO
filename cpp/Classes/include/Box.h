#ifndef BOX_H
#define BOX_H
#include <iostream>
using namespace std;

class Box {
    private:
        int side;
        string name;
        
    public:
        Box (int side, string name);
        Box ();
        string getName ();
        int getSide ();
        void setName (string name);
        void setSide (int side);
        virtual ~Box();

};

#endif // BOX_H
