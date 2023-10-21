 void main(){
#include <iostream.h>
#include <conio.h>
#include <stdio.h>
void main(){

int reves,num,aux;
reves=0;
aux=num;
if(num>=0)
{reves=reves*10+aux%10;
aux=aux/10;
}
if(num>=10)
{reves=reves*10+aux%10;
aux=aux/10;}
if(num>=1000)
{reves=reves*10+aux%10;
aux=aux/10;}
if(num>=1000)
{reves=reves*10+aux%10;
aux=aux/10;}
if(num>=10000)
{reves=reves*10+aux%10;
aux=aux/10; }
getch();
}
