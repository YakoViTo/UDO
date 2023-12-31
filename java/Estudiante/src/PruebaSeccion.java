import java.io.*;

public class PruebaSeccion{
	
	public static BufferedReader Leer(){
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		return br;
	}
	
	public static String LeerCadena(){
		
		String i = "";
		boolean sw;
		do{
			sw = false;
			try{
				
				i = Leer().readLine();
			}
			catch(Exception e){
				
				System.out.println("Ha ocurrido un error. Intente de nuevo.");
				sw = true;
			}
		}while(sw);
		return i;
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
				
				System.out.println("Ha ocurrido un error. Intente de nuevo.");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static float LeerFloat(){
		
		float i = 0;
		boolean sw;
		do{
			sw = false;
			try{
				i = Float.parseFloat(Leer().readLine());
			}
			catch(Exception e){
				
				System.out.println("Ha ocurrido un error. Intente de nuevo.");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static void main(String args[]){
		
		String n, nci;
		n = nci = "";
		int n1, n2, n3, opc, Cantidad;
		n1 = n2 = n3 =0;
		System.out.print("Ingrese cantidad de estudiantes: ");
		Cantidad = LeerEntero();
		Seccion s = new Seccion(Cantidad);
		do{
			System.out.print("�Que desea hacer?\n1.Agregar.\n2.Eliminar.\n3.mostrar listado de Estudiantes.\n4.Salir.\nOpcion: ");
			opc = LeerEntero();
			switch(opc){
			
				case 1: 
					if(s.getContador() < Cantidad){
						
						System.out.print("Ingrese nombre: ");
						n = LeerCadena();
						System.out.print("Ingrese cedula: ");
						nci = LeerCadena();
						System.out.print("Ingrese nota del 1er parcial: ");
						n1 = LeerEntero();
						System.out.print("Ingrese nota del 2do parcial: ");
						n2 = LeerEntero();
						System.out.print("Ingrese nota del 3er parcial: ");
						n3 = LeerEntero();
						Estudiante es = new Estudiante(n, nci, n1, n2, n3);
						System.out.print(s.Agregar(es));
					}
					else
						System.out.print("No se puede agregar mas estudiantes.");
					break;
					
				case 2:
					if(s.getContador() != 0){
						
						System.out.print("Ingrese cedula del estudiante: ");
						nci = LeerCadena();
						System.out.println(s.Retirar(nci));
					}
					else
						System.out.println("Debe haber almenos un estudiante.");
					break;
					
				case 3:
					if(s.getContador() != 0)
						
						System.out.print(s.Listar());
					
					else
						System.out.println("Debe haber almenos un estudiante.");
					break;
					
				case 4:
					System.out.println("Listo");
					break;
					
				default:
					System.out.println("Opcion invalida.");
					break;
			}
		}while(opc != 4);
	}

}
