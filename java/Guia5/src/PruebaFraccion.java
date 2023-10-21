import java.io.*;

public class PruebaFraccion{
	
	public static BufferedReader Leer(){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		return br;
	}
	
	public static int LeerEntero(){
		
		int i = 0;
		boolean sw;
		do{
			
			sw = false;
			try{
				
				i = Integer.parseInt(Leer().readLine());
			}
			
			catch(Exception e){
				
				System.out.println("Ha ocurrido un error. Intente de nuevo");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static void main(String [] args){
		
		int Num1,Num2,Den1,Den2,opc;
		opc = 0;
		System.out.print("Ingrese numerador (primera fraccion): ");
		Num1 = LeerEntero();
		do{
			
			System.out.print("Ingrese denominador (primera fraccion): ");
			Den1 = LeerEntero();
		}while(Den1==0);
		System.out.print("Ingrese numerador (segunda fraccion): ");
		Num2 = LeerEntero();
		do{
			
			System.out.print("Ingrese denominador (segunda fraccion): ");
			Den2 = LeerEntero();
		}while(Den2==0);
		Operaciones o = new Operaciones(Num1, Den1, Num2, Den2);
		do{
			
			System.out.print("¿Que desea hacer? \n1.Sumar.\n2.Restar.\n3.Multiplicar.\n4.Dividir.\n5.Salir.\nOpcion: ");
			opc = LeerEntero();
			switch(opc){
			
			case 1:
				o.sumar();
				break;
				
			case 2:
				o.restar();
				break;
			
			case 3:
				o.multiplicar();
				break;
			
			case 4:
				o.dividir();
				break;
				
			case 5:
				System.out.println("Listo. \n");
				break;
				
			default:
				System.out.println("Ingrese una opcion valida.");
				break;
			}
		}while(opc != 5);
	}
}