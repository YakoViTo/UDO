import java.io.*;

public class PruebaFactura 
{
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
				System.out.println("Ha ocurrido un error");
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
				System.out.println("Ha ocurrido un error");
				sw = true;
			}
		} while (sw); 
		return i;
	}
	
	public static void main(String [] args)
	{
		Factura f = new Factura();
		String Producto = "";
		boolean sw = false;
		int Op, Opcion;
		Opcion = 0;
		Op = 0;
		
		do
		{
			System.out.println("¿Que desea hacer? \n1.Comprar. \n2.Pagar. \nOpcion:");
			Op = LeerEntero();
			switch (Op)
			{
				case 1:
					System.out.println("¿Que desea comprar? \n1.Pulsera. \n2.Collar. \n3.Anillo.");
					Opcion = LeerEntero();
					switch (Opcion)
					{
						case 1:
							Producto = "Pulsera";
							f.Comprar(Producto);
							break;
							
						case 2:
							Producto = "Collar";
							f.Comprar(Producto);
							break;
							
						case 3:
							Producto = "Anillo";
							f.Comprar(Producto);
							break;
							
						default:
							System.out.println("No se encuentra el producto. \n");
							break;
					}
					break;
					
				case 2:
					if (f.getMontoT() != 0)
					{
						f.Fac();
						sw = true;
					}
					
					else
					{
						System.out.println("Compre al menos un producto. \n");
						sw = false;
					}
						
					break;
			}
		} while (sw);
	}
}