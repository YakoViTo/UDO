#include <iostream>
//#include <string>
#include <conio.h>
using namespace std;
void buscar_y_remplazar(string& frase, string buscar, string rempl){
	int pos=frase.find(buscar);
   while(pos!=-1){
   	frase.replace(pos,buscar.size(),rempl);
      pos=frase.find(buscar,pos+rempl.size());
   }
}

int main(){
	string frase,p1,p2;
   getline(cin,frase);
   cin>>p1>>p2;
   buscar_y_remplazar(frase,p1,p2);
   cout<<frase<<endl;
return 0;
}
