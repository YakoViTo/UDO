import java.io.*;

public class PruebaLista 
{
	public static BufferedReader Leer()
	{
		BufferedReader br = new BufferedReader(new InputStreamReader (System.in));
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
				System.out.println("Ha ocurrido un error");
				sw = true;
			}
		} while(sw);
		return i;
	}
	
	public static void main(String [] args)
	{
		int val, op;
		val = op = 0;
		Lista l = new Lista();
		do
		{
			System.out.print("Que desea hacer? \n1.Agregar. \n2.Eliminar. \n3.Mostrar. \n4.Salir. \nOpcion: ");
			op = LeerEntero();
			switch(op)
			{
				case 1:
					System.out.print("Ingrese valor: ");
					val = LeerEntero();
					Nodo n = new Nodo(val);
					System.out.println(l.agregar(n));
					break;
					
				case 2:
					System.out.print("Ingrese valor: ");
					val = LeerEntero();
					System.out.println(l.eliminar(val));
					break;
					
				case 3:
					String a = "";
					int k = 0;
					Nodo aux = l.getInicio();
					System.out.println(l.Mostrar(a, k, aux));
					break;
					
				case 4:
					break;
					
				default:
					System.out.println("Opcion invalida.");
			}
		} while (op != 4);
	}
}