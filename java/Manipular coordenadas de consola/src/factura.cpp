#include <stdio.h>
#include <stdlib.h>
//using namespace std;
int main(){

char nombre[60], apellido[60], producto1[60], producto2[60], producto3[60];
long int c;
int  n1, n2, n3, p1, p2, p3, mt;
printf("Introduzca nombre del cliente:");
scanf("%s",&nombre);
printf("Introduzca apellido del cliente:");
scanf("%s",&apellido);
//cin.getline(nombre,60);
printf("Introduzca cedula del cliente:");
scanf("%ld",&c);
printf("Introduzca producto 1:");
scanf("%s",&producto1);
printf("Introduzca cantidad 1:");
scanf("%d",&n1);
printf("introduzca costo 1:");
scanf("%d",&p1);
printf("Introduzca producto 2:");
scanf("%s",&producto2);
printf("Introduzca cantidad 2:");
scanf("%d",&n2);
printf("introduzca costo 2:");
scanf("%d",&p2);
printf("Introduzca producto 3:");
scanf("%s",&producto3);
printf("Introduzca cantidad 3:");
scanf("%d",&n3);
printf("introduzca costo 3:");
scanf("%d",&p3);
mt = n1*p1+n2*p2+n3*p3;
printf("\t\t\t\n");
printf("Nombre cliente: %s %s\n",nombre,apellido);
printf("Cedula cliente: %ld\n",c);
printf("\t\t\t\t\n");
printf("Producto\tCantidad\tCosto\t\tMonto\n");
printf("-----------------------------------------------------\n");
printf("%s\t\t%d\t\t%d\t\t%d\n",producto1,n1,p1,p1*n1);
printf("%s\t\t%d\t\t%d\t\t%d\n",producto2,n2,p2,p2*n2);
printf("%s\t\t%d\t\t%d\t\t%d\n",producto3,n3,p3,p3*n3);
printf("-----------------------------------------------------\n");
printf("\t\t\t\t   Monto Total: %d\n",mt);
system("PAUSE");
return 0;

}
