import java.io.*;

public class PruebaCarro {

	public static BufferedReader Leer()
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		return br;
	}
	
	public static int LeerEntero()
	{
		int i = 0;
		boolean sw;
		do
		{
			sw = false;
			try
			{
				i = Integer.parseInt(Leer().readLine());
			}
			
			catch (Exception e)
			{
				System.out.println("Ha ocurrido un error, intente de nuevo.");
				sw = true;
			}
		} while (sw);
		return i;
	}
	
	public static String LeerCadena()
	{
		String i = "";
		boolean sw;
		do
		{
			sw = false;
			try
			{
				i = Leer().readLine();
			}
			
			catch (Exception e)
			{
				System.out.println("Ha ocurrido un error, intente de nuevo.");
				sw = true;
			}
		} while (sw);
		return i;
	}
	
	public static void main(String [] args)
	{
		int Cantidad, Op, ContModelo1, ContModelo2, ContModelo3, ContModelo4, ContModelo5, ContTipo1, ContTipo2, ContPago1, ContPago2, ContPago3, ContNPuertas1, ContNPuertas2, ContNPuertas3;
		String Modelo, Tipo, Color, FormaPago;
		Modelo = Tipo = Color = FormaPago = "";
		ContModelo1 = ContModelo2 = ContModelo3 = ContModelo4 = ContModelo5 = ContTipo1 = ContTipo2 = ContPago1 = ContPago2 = ContPago3 = ContNPuertas1 = ContNPuertas2 = ContNPuertas3 = 0;
		byte NPuertas = 0;
		System.out.print("Ingrese cantidad de personas: ");
		Cantidad = LeerEntero();
		Conce c = new Conce(Cantidad);
		do
		{
			System.out.print("Que desea hacer? \n1Agregar vehiculo a persona. \n2.Mostrar el vehiculo mas solicitado (por categorias). \n3.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch(Op)
			{
			 case 1:
				 if (c.getContador() < Cantidad)
				 {
					 int Operacion = 0;
					 do
					 {
						 System.out.print("Que modelo desea? \n1.Convertible. \n2.Compacto. \n3.4x4. \n4.Camioneta. \n5.Pick-Up. \nOpcion: ");
						 Operacion = LeerEntero();
						 switch(Operacion)
						 {
						 	case 1:
						 		Modelo = "Convertible";
						 		ContModelo1++;
						 		break;
						 	
						 	case 2:
						 		Modelo = "Compacto";
						 		ContModelo2++;
						 		break;
						 		
						 	case 3:
						 		Modelo = "4x4";
						 		ContModelo3++;
						 		break;
						 		
						 	case 4:
						 		Modelo = "Camioneta";
						 		ContModelo4++;
						 		break;
						 		
						 	case 5:
						 		Modelo = "Pick-Up";
						 		ContModelo5++;
						 		break;
						 		
						 	default:
						 		System.out.println("Opcion invalida.");
						 }
					 } while (Operacion < 1 || Operacion > 5);
					 
					 Operacion = 0;
					 
					 do
					 {
						 System.out.print("Que color desea? \n1.Negro. \n2.Verde. \n3.Azul. \n4.Rojo. \n5.Gris. \n6.Amarillo. \nOpcion: ");
						 Operacion = LeerEntero();
						 switch(Operacion)
						 {
						 	case 1:
						 		Color = "Negro";
						 		break;
						 		
						 	case 2:
						 		Color = "Verde";
						 		break;
						 		
						 	case 3:
						 		Color = "Azul";
						 		break;
						 		
						 	case 4:
						 		Color = "Rojo";
						 		break;
						 		
						 	case 5:
						 		Color = "Gris";
						 		break;
						 		
						 	case 6:
						 		Color = "Amarillo";
						 		break;
						 		
						 	default:
						 		System.out.println("Opcion invalida.");
						 }
					 } while (Operacion < 1 || Operacion > 6);
					 
					 Operacion = 0;
					 
					 do
					 {
						 System.out.print("Que tipo de vehiculo desea? \n1.Automatico. \n2.Sincronico. \nOpcion: ");
						 Operacion = LeerEntero();
						 switch (Operacion)
						 {
						  case 1:
							  Tipo = "Automatico";
							  ContTipo1++;
							  break;
							  
						  case 2:
							  Tipo = "Sincronico";
							  ContTipo2++;
							  break;
							  
						  default:
							  System.out.println("Opcion invalida.");
						 }
					 } while (Operacion < 1 || Operacion > 2);
					 
					 Operacion = 0;
					 
					 do
					 {
						 System.out.print("Forma de pago: \n1.Contado. \n2.Credito. \n3.Financiado. \nOpcion: ");
						 Operacion = LeerEntero();
						 switch (Operacion)
						 {
						  case 1:
							  FormaPago = "Contado";
							  ContPago1++;
							  break;
							  
						  case 2:
							  FormaPago = "Credito";
							  ContPago2++;
							  break;
							  
						  case 3:
							  FormaPago = "Financiado";
							  ContPago3++;
							  break;
							  
						  default:
							  System.out.println("Opcion invalida.");
						 }
					 } while (Operacion < 1 || Operacion > 3);
					 
					 Operacion = 0;
					 
					 do
					 {
						 System.out.print("Cuantas puertas desea? \n1.3 puertas. \n2.4 Puertas. \n3.5 puertas. \nOpcion: ");
						 Operacion = LeerEntero();
						 switch(Operacion)
						 {
						  case 1:
							  NPuertas = 3;
							  ContNPuertas1++;
							  break;
							  
						  case 2:
							  NPuertas = 4;
							  ContNPuertas2++;
							  break;
							  
						  case 3:
							  NPuertas = 5;
							  ContNPuertas3++;
							  break;
							  
						  default:
							  System.out.println("Opcion invalida.");
						 }
					 } while (Operacion < 1 || Operacion > 3);
					 Carro car = new Carro(Modelo, Color, Tipo, FormaPago, NPuertas);
					 c.Agregar(car);
					 System.out.println("Se ha asignado el vehiculo.");
				 }
				 
				 else
					 System.out.println("No se puede asignar mas vehiculos.");
				 
				 break;
				 
			 case 2:
				 if (ContModelo1 > ContModelo2 && ContModelo1 > ContModelo3 && ContModelo1 > ContModelo4 && ContModelo1 > ContModelo5)
					 System.out.println("El modelo mas solicitado es el convertible");
				 
				 else if (ContModelo2 > ContModelo1 && ContModelo2 > ContModelo3 && ContModelo2 > ContModelo4 && ContModelo2 > ContModelo5)
					 System.out.println("El modelo mas solicitado es el compacto");
				 
				 else if (ContModelo3 > ContModelo1 && ContModelo3 > ContModelo2 && ContModelo3 > ContModelo4 && ContModelo3 > ContModelo5)
					 System.out.println("El modelo mas solicitado es el 4x4");
				 
				 else if (ContModelo4 > ContModelo1 && ContModelo4 > ContModelo2 && ContModelo4 > ContModelo3 && ContModelo4 > ContModelo5)
					 System.out.println("El vehiculo mas solicitado es la camioneta");
				 
				 else if (ContModelo5 > ContModelo1 && ContModelo5 > ContModelo2 && ContModelo5 > ContModelo3 && ContModelo5 > ContModelo4)
					 System.out.println("El vehiculo mas solicitado es la Pick-Up");
				 
				 
				 if (ContTipo1 > ContTipo2)
					 System.out.println("El tipo de vehiculo mas solicitado es el automatico");
				 
				 else
					 System.out.println("El vehiculo mas solicitado es el sincronico");
				 
				 
				 if (ContPago1 > ContPago2 && ContPago1 > ContPago3)
					 System.out.println("De forma de pago es de manera contada");
				 
				 else if (ContPago2 > ContPago1 && ContPago2 > ContPago3)
					 System.out.println("De forma de pago es de credito");
				 
				 else if (ContPago3 > ContPago1 && ContPago3 > ContPago2)
					 System.out.println("De forma de pago es a travez de financiamiento");
				 
				 
				 if (ContNPuertas1 > ContNPuertas2 && ContNPuertas1 > ContNPuertas3)
					 System.out.println("La cantidad de puertas mas solicitada son 3");
				 
				 else if (ContNPuertas2 > ContNPuertas1 && ContNPuertas2 > ContNPuertas3)
					 System.out.println("La cantidad de puertas mas solicitada son 4");
				 
				 else if (ContNPuertas3 > ContNPuertas1 && ContNPuertas3 > ContNPuertas2)
					 System.out.println("La cantidad de puertas mas solicitada son 5");
					 
				 break;
			}
		} while (Op != 3);
	}
}
