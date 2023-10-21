#include <iostream.h>
#include <conio.h>

void main()
{
	gotoxy(23,1);
	cout<<"Republica Bolivariana de Venezuela";
	gotoxy(20,2);
	cout<<"Universidad de Oriente. Nucleo Anzoategui";
	gotoxy(19,3);
	cout<<"Taller de Programacion Orientada a Objetos";
	gotoxy(35,12);
	cout<<"Practico 4";
	gotoxy(34,17);
	cout<<"Realizado por:";
	gotoxy(34,18);
	cout<<"Eduardo Lunar";
	gotoxy(33,19);
	cout<<"C.I.24.513.298";
	gotoxy(35,20);
	cout<<"Seccion:21";
	gotoxy(28,24);
	cout<<"Barcelona, Mayo del 2015";
	getch();
	clrscr();
	int cont[2],hola[4][4]={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7};
	for(cont[0]=0;cont[0]<4;cont[0]++)
	{for(cont[1]=0;cont[1]<4;cont[1]++)
		{cout<<hola[cont[1]][cont[0]];
		}
		if(cont[0]<4)
		cout<<"\n";
}getch();}

