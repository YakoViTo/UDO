import java.io.*;

public class PruebaComplejo{
	
	public static BufferedReader Leer(){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		return br;
	}
	
	public static int LeerEntero(){
		
		int i=0;
		boolean sw;
		do{
			sw=false;
			try{
				i=Integer.parseInt(Leer().readLine());
			}
			catch(Exception e){
				
				System.out.println("Ha ocurrido un error. Intente de nuevo");
				sw=true;
			}
		}while(sw);
		return i;
	}
	
	public static void main(String[] args){
		
		int opc, pr,pr2,pi,pi2;
		opc = 0;
		System.out.print("Ingrese parte real (1er renglon): ");
		pr = LeerEntero();
		
			
		System.out.print("Ingrese parte imaginaria (1er renglon): ");
		pi = LeerEntero();
		
		System.out.print("Ingrese parte real (2do renglon): ");
		pr2 = LeerEntero();
		
			
		System.out.print("Ingrese parte imaginaria (2do renglon): ");
		pi2 = LeerEntero();
		
		Complejo c = new Complejo(pr, pi, pr2, pi2);
		do{
			
			System.out.print("¿Que desea hacer? \n1.Sumar.\n2.Restar.\n3.Salir.\nOpcion: ");
			opc = LeerEntero();
			switch(opc){
			
			case 1:
				c.Suma();
				break;
				
			case 2:
				c.Resta();
				break;
				
			case 3:
				System.out.println("Listo. \n");
				break;
				
			default:
				System.out.println("Ingrese una opcion valida.");
				break;
			}
		}while(opc != 3);
	}

}
