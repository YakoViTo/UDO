import java.io.*;

public class PruebaSeccion {

	public static BufferedReader Leer()
	{
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		return br;
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
				System.out.println("Ha ocurrido un error.");
				sw = true;
			}
		} while (sw);
		return i;
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
				System.out.println("Ha ocurrido un error.");
				sw = true;
			}
		} while (sw);
		return i;
	}
	
	public static byte LeerByte()
	{
		byte i = 0;
		boolean sw;
		do
		{
			sw = false;
			try
			{
				i = Byte.parseByte(Leer().readLine());
			}
			
			catch (Exception e)
			{
				System.out.println("Ha ocurrido un error.");
				sw = true;
			}
		} while (sw);
		return i;
	}
	
	public static void main(String [] args)
	{
		String n, a, nci, c;
		n = a = nci = c = "";
		int n1, n2, n3, Cantidad, Op;
		n1 = n2 = n3 = 0;
		byte Parcial = 0;
		System.out.print("Ingrese cantidad de alumnos: ");
		Cantidad = LeerEntero();
		Seccion s = new Seccion(Cantidad);
		do
		{
			System.out.print("Que desea hacer? \n1.Agregar. \n2.Retirar. \n3.Vaciar notas de una evaluacion. \n4.Mostrar inscritos. \n5.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch (Op)
			{
			 case 1:
				 if (s.getContador() < Cantidad)
				 {
					 System.out.print("Ingrese nombre: ");
					 n = LeerCadena();
					 System.out.print("Ingrese apellido: ");
					 a = LeerCadena();
					 System.out.print("Ingrese cedula: ");
					 nci = LeerCadena();
					 System.out.print("Ingrese carrera que cursa: ");
					 c = LeerCadena();
					 System.out.print("Ingrese nota del primer parcial: ");
					 n1 = LeerEntero();
					 System.out.print("Ingrese nota del segundo parcial: ");
					 n2 = LeerEntero();
					 System.out.print("Ingrese nota del tercer parcial: ");
					 n3 = LeerEntero();
					 Alumno al = new Alumno(n, a, nci, c, n1, n2, n3);
					 System.out.println(s.Agregar(al));
				 }
				
				 else
					 System.out.println("No se puede agregar mas alumnos.");
				 
				 break;
				 
			 case 2:
				 if (s.getContador() != 0)
				 {
					 System.out.print("Ingrese cedula del alumno: ");
					 nci = LeerCadena();
					 System.out.println(s.Retirar(nci));
				 }
					 
				 else
					 System.out.println("Debe haber al menos un alumno.");
				 break;
				 
			 case 3:
				 if (s.getContador() != 0)
				 {
					 do
					 {
						 System.out.println("Ingrese parcial (entre 1 y 3): ");
						 Parcial = LeerByte();
						 System.out.println(s.VaciarNotas(Parcial));
					 } while(Parcial < 1 || Parcial > 3);
					 
				 }
				 
				 else
					 System.out.println("Debe haber al menos un alumno.");
				
				 break;
				 
			 case 4:
				 if (s.getContador() != 0)
					 System.out.println(s.Listar());
				 
				 else
					 System.out.println("Debe haber al menos un alumno.");
				 break;
				 
			 case 5:
				 System.out.println("Listo.");
				 break;
				 
			 default:
				 System.out.println("Opcion invalida.");
			}
		} while (Op != 5);
	}
}
