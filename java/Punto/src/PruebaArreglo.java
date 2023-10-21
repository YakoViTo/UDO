import java.io.*;

public class PruebaArreglo{
	
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
				
				System.out.println("Ha ocurrido un error, intente de nuevo.");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static double LeerDouble(){
		
		double i = 0;
		boolean sw;
		do{
			
			sw = false;
			try{
				
				i = Double.parseDouble(Leer().readLine());
			}
			
			catch(Exception e){
				
				System.out.println("Ha ocurrido un error, intente de nuevo.");
				sw = true;
			}
		}while(sw);
		return i;
	}
	
	public static void main(String [] args){
		int opc, Cantidad;
		double al,ba,x,y;
		
		
		do{
			
			System.out.print("¿Que desea mostrar? \n1.Puntos ordenados al origen.\n2.Rectangulos ordenados por areas.\n3.Triangulos ordenados por area.\n4.Salir.\nOpcion: ");
			opc = LeerEntero();
			switch(opc){
			
				case 1:
					System.out.print("Ingrese cantidad de puntos: ");
					Cantidad = LeerEntero();
					Arreglo a1 = new Arreglo(Cantidad);
					do{
						
						System.out.print("¿Que desea hacer? \n1.Agregar.\n2.Mostrar.\n3.Salir.\nOpcion: ");
						opc = LeerEntero();
						switch(opc){
						
							case 1:
								if (a1.getContador() < Cantidad){
									System.out.print("coord.x: ");
									x = LeerDouble();
									System.out.print("coord.y: ");
									y = LeerDouble();
									Origen p = new Origen(x,y);
									a1.AgregarP(p);
								}
								
								 else
									 System.out.println("No se puede agregar mas puntos.");
								break;
								
							case 2:
								if (a1.getContador() != 0)
									 System.out.println(a1.ListarP());
								 
								 else
									 System.out.println("Debe haber al menos un punto.");
								break;
								
							case 3:
								System.out.print("Listo.");
								break;
								
							default:
								System.out.println("Opncion invalida.");
								break;
						}
					}while(opc != 3);
					break;
					
				case 2:
					System.out.print("Ingrese cantidad de rectangulos: ");
					Cantidad = LeerEntero();
					Arreglo a2 = new Arreglo(Cantidad);					
					do{
						
						System.out.print("¿Que desea hacer?\n1.Agregar.\n2.Mostrar.\n3.Salir.\nOpcion: ");
						opc = LeerEntero();
						switch(opc){
						
							case 1:
								if (a2.getContador() < Cantidad){
									System.out.print("Base: ");
									ba = LeerDouble();
									System.out.print("Altura: ");
									al = LeerDouble();
									Area a = new Rectangulo(ba,al);
									a2.AgregarR(a);
								}
								
								 else
									 System.out.println("No se puede agregar mas rectangulos.");
								break;
									
							case 2:
								if (a2.getContador() != 0)
									 System.out.println(a2.ListarR());
								 
								 else
									 System.out.println("Debe haber al menos un rectangulo.");
								break;
								
							case 3: 
								System.out.print("Listo.");
								break;
								
							default:
								System.out.println("Opcion invalida.");
								break;
						}
					}while(opc != 3);
					break;
					
				case 3:
					System.out.print("Ingrese cantidad de triangulos: ");
					Cantidad = LeerEntero();
					Arreglo a3 = new Arreglo(Cantidad);					
					do{
						
						System.out.print("¿Que desea hacer?\n1.Agregar.\n2.Mostrar.\n3.Salir.\nOpcion: ");
						opc = LeerEntero();
						switch(opc){
						
							case 1:
								if (a3.getContador() < Cantidad){
									System.out.print("Base: ");
									ba = LeerDouble();
									System.out.print("Altura: ");
									al = LeerDouble();
									Area a = new Triangulo(ba,al);
									a3.AgregarT(a);
								}
								
								 else
									 System.out.println("No se puede agregar mas rectangulos.");
								break;
									
							case 2:
								if (a3.getContador() != 0)
									 System.out.println(a3.ListarT());
								 
								 else
									 System.out.println("Debe haber al menos un rectangulo.");
								break;
								
							case 3: 
								System.out.print("Listo.");
								break;
								
							default:
								System.out.println("Opcion invalida.");
								break;
						}
					}while(opc != 3);
					break;
					
				case 4:
					System.out.print("Listo");
					break;
					
				default:
					System.out.println("Opcion invalida.");
					break;
			}
			
		}while(opc != 4);
	}

}
