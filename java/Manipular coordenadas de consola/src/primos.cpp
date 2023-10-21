#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main(){
int num;

printf("Ingrese un numero de dos cifras:");
cin>>num;

if((num%2!=0||num==2)&&(num%3!=0||num==3)&&(num%5!=0||num==5)&&(num%7!=0||num==7)&&(num!=1)&&(num!=0))
    printf("El numero es primo");
else
    printf("El numero no es primo");




getch();
}
