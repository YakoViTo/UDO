#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main(){
int num;
system("cls");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%42s","kavir");

getch();
system("cls");

printf("ingrese un numero:");
cin>>num;

(num%2==0)? printf("el numero es par")
          : printf("el numero es impar");

getch();
}
