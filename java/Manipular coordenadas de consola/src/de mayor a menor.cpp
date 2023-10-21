#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int main(){

int a,b,c,num1,num2,num3;
printf("ingrese numero 1:");
cin>>num1;
printf("ingrese numero 2:");
cin>>num2;
printf("ingrese numero 3:");
cin>>num3;

if(num1>num2){
    a=num1;
    c=num2;
}
else{
    a=num2;
    c=num1;
}
if(num1>num3)
{
    if(num3>num1){
        b=num3;
        c=num2;
    }
}
else{
    a=num3;
    b=num1;
}

printf("a es el mayor");




getch();

}
