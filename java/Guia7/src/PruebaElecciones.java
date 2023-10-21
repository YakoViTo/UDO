import java.io.*;

public class PruebaElecciones{
	
	public static BufferedReader Leer(){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		return br;
	}
	
	public static int LeerEntero(){
		
		int i =0;
		boolean sw;
		do{
			
			sw = false;
			try{
				
				i = Integer.parseInt(Leer().readLine());
			}
			
			catch(Exception e){
				
				System.out.println("Ha ocuriido un error. Intente de nuevo.");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static void main(String [] args){
		
		Elecciones e = new Elecciones();
		int opc = 0;
		boolean Operacion, Metodo;
		Metodo = false;
		do{
			
			System.out.print("¿Que desea hacer? \n1.Votar.\n2.Ver resultados.\nOopcion: ");
			opc = LeerEntero();
			switch(opc){
			
				case 1:
					do{
						
						Operacion = false;
						System.out.print("¿Por quien desea votar?\n1.MAG (Nombre del candidato: Perez Pedro).\n2.SS (Nombre del candidato: Garcia Pablo).\nOpcion: ");
						opc = LeerEntero();
						switch(opc){
						
						case 1:
							e.votar("MAG");
							break;
						
						case 2:
							e.votar("SS");
							break;
							
						default:
							System.out.println("Opcion invalida. Intente de nuevo");
							Operacion = true;
							break;
						}
					}while(Operacion != false);
					break;
					
				case 2:
					if(e.getContador() == 0 && e.getContador2() == 0){
						
						System.out.println("Un partido debe tener almenos un voto. \n");
						Metodo = false;
					}
					
					else{
						
						System.out.println(e.toString());
						Metodo = true;
					}
					break;
					
				default:
					System.out.println("Opncion invalida. Intente de nuevo. \n");
					break;
			}			
		}while(!Metodo);
	}
}