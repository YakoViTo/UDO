import java.io.*;

public class PruebaClase {
	
	public static BufferedReader Leer()
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
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
		Clase c = new Clase();
		String n, a, nci;
		n = a = nci = "";
		byte nota, s;
		nota = s = 0;
		int Op = 0;
		do
		{
			System.out.print("Que desea hacer? \n1.Agregar alumno. \n2.Mostrar alumnos. \n3.Ver la nota mas repetida. \n4.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch (Op)
			{
				case 1:
					if (c.getContador() < 40)
					{
						System.out.print("Ingrese nombre: ");
						n = LeerCadena();
						System.out.print("Ingrese apellido: ");
						a = LeerCadena();
						System.out.print("Ingrese cedula: ");
						nci = LeerCadena();
						System.out.print("Ingrese seccion: ");
						s = LeerByte();
						
						do
						{
							System.out.print("Ingrese nota (entre 0 y 10): ");
							nota = LeerByte();
						} while (nota < 0 || nota > 10);
						Estudiante e = new Estudiante (n, a, nci, nota, s);
						c.Agregar(e);
						System.out.println("Se ha agregado el alumno.");
					}
					
					else
						System.out.println("No se puede agregar mas alumnos.");
					break;
					
				case 2:
					if (c.getContador() != 0)
						System.out.println(c.Listar());
					
					else
						System.out.println("Debe haber al menos un alumno en la seccion.");
					break;
					
				case 3:
					if (c.getContador() != 0)
						System.out.println(c.ListarNota());
					
					else
						System.out.println("Debe haber al menos un alumno en la seccion.");
					break;
			}
		} while (Op != 4);
	}

}
