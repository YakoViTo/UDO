#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main(){

int num1,num2,num3;

printf("ingrese el primer numero:");
cin>>num1;
printf("ingrese el segundo numero:");
cin>>num2;
printf("ingrese el tercer numero:");
cin>>num3;

//if(num1>num2&&num1>num3) printf("primer numero es mayor");
//if(num1<num2&&num2<num3) printf("tercer numero es mayor");
//if(num1<num2&&num2>num3) printf("segundo numero es mayor");

if(num1<=num2)
    if(num3>=num2)
    printf("el tercer numero es mayor");
else
    printf("el segundo numero es mayor");
else
    printf("el primer numero es mayor");




getch();


}
