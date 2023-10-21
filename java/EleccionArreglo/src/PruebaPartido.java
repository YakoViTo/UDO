import java.io.*;

public class PruebaPartido {

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
				System.out.println("Ha ocurrido un error.");
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
				System.out.println("Ha ocurrido un error.");
				sw = true;
			}
		} while (sw);
		return i;
	}
	
	public static void main(String [] args)
	{
		Elecciones e = new Elecciones();
		String np, nc, ac, Par = "";
		np = nc = ac = "";
		int Op = 0;
		do
		{
			System.out.print("Que desea hacer? \n1.Agregar partido. \n2.Votar. \n3.Mostrar ganador. \n4.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch(Op)
			{
			 case 1:
				 if (e.getContador() < 4)
				 {
					 System.out.print("Ingrese nombre del partido: ");
					 np = LeerCadena();
					 System.out.print("Ingrese nombre del candidato: ");
					 nc = LeerCadena();
					 System.out.print("Ingrese apellido del candidato: ");
					 ac = LeerCadena();
					 Partido p = new Partido (np, nc, ac);
					 System.out.println(e.Agregar(p));
				 }
				 
				 else
					 System.out.println("No se puede agregar mas candidatos.");
				 
				 break;
				 
			 case 2:
				 if (e.getContador() != 0 && e.getContador() < 4)
				 {
					 System.out.println("Escriba el nombre del partido por el cual desea votar: \n" + e.toString());
					Par = LeerCadena();
					System.out.println(e.Votar(Par));
				 }
				
				 else
					 System.out.println("Debe haber al menos un partido.");
				 break;
				 
			 case 3:
				 if (e.getContador() != 0)
					 System.out.println(e.Ganador());
				 
				 else
					 System.out.print("Debe haber al menos un partido.");
				 break;
				 
			 case 4:
				 System.out.println("Listo.");
				 break;
				 
			 default:
				 System.out.println("Opcion invalida.");
			}
		} while (Op != 4);
	}
}
