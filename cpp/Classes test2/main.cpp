#include <iostream>
#include <ctime>
#include "Box.h"
using namespace std;

void sumar (int * a, int b) {
    *a += b;
}

int * getRandom( )
{
  static int  r[10];
 
  // set the seed
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }
 
  return r;
}


int main()
{
    Box caja;
    Box caja_pequena ("pequeña", 14, 25);
    
    int * ptr = NULL;
    int * ptt = NULL;
    int prr = 6;
    int t = 7;
    char g[] = "Yo";
    int ff[] = {51, 56, 85, 52};
    char * tt = &g[1];
    int **multiple;
    Box * pp = NULL;
    pp = &caja;
    int * p = new int;
    *p = 5;
    
    ptr = &prr;
    ptt = &t;
    multiple = &ptr;
    
    cout << *p << endl;
    cout << caja.getName() << endl;
    cout << caja.addition() << endl;
    cout << caja.substract() << endl;
    cout << caja.multiply() << endl;
    cout << caja.divide() << endl;
    
    cout << caja_pequena.getName() << endl;
    cout << caja_pequena.addition() << endl;
    cout << caja_pequena.substract() << endl;
    cout << caja_pequena.multiply() << endl;
    cout << caja_pequena.divide() << endl;
    
    cout << ptr << " " << *ptr << " " << &prr << endl;
    cout << ptt << " " << *ptt << endl;
    
    ptt = ptr;
    cout << ptt << " " << *ptt << endl;
    
    pp->setNum1(5);
    pp->setNum2(8);
    
    cout << pp->addition() << " " << pp->getName() << endl;
    cout << caja.getName() << " " << caja.addition() << endl;
    
    cout << endl << *tt << endl;
    
    tt--;
    
    cout << *tt << endl << endl;
    
    for (int * f = ff; f <= &ff[3]; f++)
        cout << *f << endl;
    
    int i = 0;
    for (int * prt[i]; i < 4; i++) {
         prt[i] = &ff[i];
         cout << *prt[i] << endl;
    }
       
    cout << "Multiple: " << multiple <<  " "  << *multiple << " " << **multiple << endl;
    
    sumar (ptt, 5);
    cout << *ptt << endl;     

 
   p = getRandom();
   for ( int i = 0; i < 10; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *p++ << endl;
   }
 
   return 0;

    
    cin.ignore();
    return 0;
}
