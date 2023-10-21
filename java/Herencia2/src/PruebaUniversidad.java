import java.io.*;

public class PruebaUniversidad {
	
	public static BufferedReader Leer()
	{
		BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
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
	
	public static short LeerShort()
	{
		short i = 0;
		boolean sw;
		do
		{
			sw = false;
			try
			{
				i = Short.parseShort(Leer().readLine());
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
		Universidad u = new Universidad();
		String n, a, nci, fn, ec, d, num;
		n = a = nci = fn = ec = d = num = "";
		short Nota = 0;
		System.out.print("Ingrese nombre: ");
		n = LeerCadena();
		System.out.print("Ingrese apellido: ");
		a = LeerCadena();
		System.out.print("Ingrese cedula: ");
		nci = LeerCadena();
		System.out.print("Ingrese fecha de nacimiento: ");
		fn = LeerCadena();
		do
		{
			System.out.print("Ingrese estado civil: ");
			ec = LeerCadena();
		} while (!ec.equalsIgnoreCase("Soltero") && !ec.equalsIgnoreCase("Casado") && !ec.equalsIgnoreCase("Casada") && !ec.equalsIgnoreCase("Soltera"));
		System.out.print("Ingrese direccion: ");
		d = LeerCadena();
		System.out.print("Ingrese numero: ");
		num = LeerCadena();
		do
		{
			System.out.print("Ingrese nota sacada: ");
			Nota = LeerShort();
		} while (Nota < 0 || Nota > 10);
		Estudiante e = new Estudiante (n, a, nci, fn, ec, d, num, Nota);
		System.out.println(u.Agregar(e));
	}

}
