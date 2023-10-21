import java.io.*;

public class PruebaBanco {
	
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
	
	public static double LeerDouble()
	{
		double i = 0;
		boolean sw;
		do
		{
			sw = false;
			try
			{
				i = Double.parseDouble(Leer().readLine());
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
		int Cantidad, Op;
		double Prestamo, Mensual;
		String FechaIni, FechaFin, Nombre, Ape, NCI;
		System.out.print("Ingrese cantidad de deudores: ");
		Cantidad = LeerEntero();
		Banco b = new Banco(Cantidad);
		do
		{
			System.out.print("¿Que desea hacer? \n1.Agregar deudor. \n2.Mostrar deudores. \n3.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch(Op)
			{
			 case 1:
				 if (b.getContador() < Cantidad)
				 {
					 System.out.print("Ingrese nombre del deudor: ");
					 Nombre = LeerCadena();
					 System.out.print("Ingrese apellido: ");
					 Ape = LeerCadena();
					 System.out.print("Ingrese cedula: ");
					 NCI = LeerCadena();
					 System.out.print("Ingrese prestamo: ");
					 Prestamo = LeerDouble();
					 
					 do
					 {
						 System.out.print("Ingrese cuotas mensuales: ");
						 Mensual = LeerDouble();
						 if (Mensual > Prestamo)
							 System.out.println("Debe ingresar una cuota correcta. No debe superar el monto del prestamo total.");
					 } while (Mensual > Prestamo);
					 
					 System.out.print("Ingrese fecha de inicio: ");
					 FechaIni = LeerCadena();
					 System.out.print("Ingrese fecha de culminación: ");
					 FechaFin = LeerCadena();
					 Deudores d = new Deudores(Prestamo, Mensual, FechaIni, FechaFin, Nombre, Ape, NCI);
					 b.Agregar(d);
					 System.out.println("Se ha agregado al deudor.");
				 }
				 
				 else
					 System.out.println("No se pueden agregar más deudores.");
				 
				 break;
				 
			 case 2:
				 if (b.getContador() == 0)
					 System.out.println("Debe agregar al menos un deudor.");
				 
				 else
					 System.out.println(b.Listar()); 
					 
				 break;
				 
			 default:
				 System.out.println("Opcion invalida.");
			}
		} while (Op != 3);
	}

}
