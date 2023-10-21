import java.io.*;

public class PruebaTienda {
	
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
	
	public static float LeerFloat()
	{
		float i = 0;
		boolean sw;
		do
		{
			sw = false;
			try
			{
				i = Float.parseFloat(Leer().readLine());
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
		Bebida b;
		int Cantidad, Op, Cant;
		Cantidad = Op = Cant = 0;
		short t = 0;
		String n, m, s;
		n = m = s = "";
		float g = 0;
		boolean Comp = false;
		System.out.print("Ingrese cantidad de bebidas que puede almacenar la tienda: ");
		Cantidad = LeerEntero();
		Tienda ti = new Tienda(Cantidad);
		do
		{
			System.out.print("Que desea hacer? \n1.Comprar bebida. \n2.Vender. \n3.Mostrar. \n4.Mostrar todas las bebidas depiendo de un sabor/grado especifico. \n5.Mostrar ganancia. \n6.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch(Op)
			{
				case 1:
					if (ti.getContador() < Cantidad)
					{
						do
						{
							System.out.print("Que desea comprar? \n1.Bebida no alcoholica. \n2.Bebida alcoholica. \nOpcion: ");
							Op = LeerEntero();
							switch(Op)
							{
								case 1:
									System.out.print("Ingrese nombre de la bebida: ");
									n = LeerCadena();
									System.out.print("Ingrese marca de la bebida: ");
									m = LeerCadena();
									System.out.print("Ingrese sabor de la bebida: ");
									s = LeerCadena();
									System.out.print("Ingrese la cantidad que desea comprar: ");
									Cant = LeerEntero();
									b = new NoAlcoholica(n, m, s);
									System.out.println(ti.Comprar(b, Cant));
									break;
									
								case 2:
									System.out.print("Ingrese nombre: ");
									n = LeerCadena();
									System.out.print("Ingrese marca: ");
									m = LeerCadena();
									System.out.print("Ingrese grado: ");
									g = LeerFloat();
									System.out.print("Ingrese el tiempo de la bebida: ");
									t = LeerShort();
									System.out.print("Ingrese la cantidad que desea comprar: ");
									Cant = LeerEntero();
									b = new Alcoholica(n, m, g, t);
									System.out.println(ti.Comprar(b, Cant));
									break;
									
								default:
									System.out.println("Opcion invalida.");
							}
						} while (Op < 1 || Op > 2);
					}
					
					else
						System.out.println("No se puede agregar mas bebidas.");
					
					break;
					
				case 2:
					if (ti.getContador() != 0)
					{
						System.out.println("Todas las bebidas disponibles: \n" + ti.Mostrar() + "Ingrese el nombre de la bebida que desea vender: ");
						n = LeerCadena();
						System.out.print("Ingrese la cantidad que desea vender: ");
						Cant = LeerEntero();
						System.out.println(ti.Vender(n, Cant));
					}
					
					else
						System.out.println("Debe haber al menos una bebida en la tienda.");
					break;
					
				case 3:
					if (ti.getContador() != 0)
						System.out.println(ti.Mostrar());
					
					else
						System.out.println("Debe haber al menos una bebida.");
					break;
					
				case 4:
					boolean aux = false;
					do 
					{
						System.out.print("1.No alcoholica. \n2.Alcoholica. \nOpcion: ");
						Op = LeerEntero();
						switch(Op)
						{
							case 1:
								do
								{
									System.out.print("Todos los sabores diponibles: \n" + ti.MostratSabores() + "Ingrese el sabor: ");
									s = LeerCadena();
									Comp = true;
									aux = ti.ComprobarSabor(s);
								} while (!aux);
								System.out.println(ti.MostartEs(s, 0, Comp));
								
								break;
								
							case 2:
								String a = "";
								do
								{
									System.out.print("Todos los grados disponibles: \n" + ti.MostrarGrado() + "Ingrese grado: ");
									g = LeerFloat();
									Comp = false;
									aux = ti.ComprobarGrado(g);
								} while (!aux);
								
								System.out.println(ti.MostartEs(a, g, Comp));
								break;
						}
					} while (Op < 1 || Op > 2);
					break;
					
				case 5:
					if (ti.getContador() != 0)
						System.out.println(ti.MontoGanado());
					
					else
						System.out.println("Debe haber al menos una compra.");
					
				case 6:
					break;
					
				default:
					System.out.println("Opcion invalida.");
					break;
			}
		} while (Op != 6);
	}
}
