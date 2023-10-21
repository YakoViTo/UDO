import java.io.*;

public class PruebaNumC {

    public static void mostrar(String m){
    	System.out.println(m);
    }
    
    public static String cadena(String m){
    	InputStreamReader isr=new InputStreamReader(System.in);
    	BufferedReader br = new BufferedReader (isr);
    	String x="";
    	try{
    		mostrar(m);
    		x=br.readLine();
    	}
    	catch(Exception ex){
    		mostrar("Error" + ex.toString());
    	}
    	return x;
    }
    
    public static int leerEntero(String m){
    	int x=0;
    	boolean ban;
    	do{
    		ban=false;
    		try{
    			x=Integer.parseInt(cadena(m));
    		}
    		catch(Exception ex){
    			ban=true;
    			mostrar("Error! intente de nuevo");
    		}
    	}while(ban);
    	return x;
    }
 
 public static Fraccion leerFraccion(String s){
 	int a,b;
 	mostrar (s);
 	a=leerEntero("Numerador: ");
 	b=leerEntero("Denominador: ");
 	Fraccion f=new Fraccion(a,b);
 	return f;
 }
 
  public static NumC leerNumC(String s){
 	Fraccion a,b;
 	mostrar (s);
 	a=leerFraccion("Parte real: ");
 	b=leerFraccion("Parte Imaginaria: ");
 	NumC n=new NumC(a,b);
 	return n;
 }
 
    
    public static void main(String[] args) {
    	NumC n1,n2,nr=new NumC();
    	int a,b,c,d,opc=0;
    	Fraccion f1,f2;	
    	do{
    		opc=leerEntero("Men�\n1.Sumar n�meros complejos\n2.Restar n�meros complejos\n3.Salir");
    		switch(opc){
    			case 1:
    				n1=leerNumC("Ingrese el primer n�mero complejo");
    				n2=leerNumC("Ingrese el segundo n�mero complejo");		
    				nr.sumar(n1,n2);
    				mostrar(nr.toString());
    				break;
    			case 2:
    				n1=leerNumC("Ingrese el primer n�mero complejo");
    				n2=leerNumC("Ingrese el segundo n�mero complejo");
    				nr.restar(n1,n2);
    				mostrar(nr.toString());
    				break;
    			case 3:
    				mostrar("Chaito pues!");
    				break;
    			default:
    				mostrar("Opci�n inv�lida");
    		}
    	}while(opc!=3);
    	
    }
}
