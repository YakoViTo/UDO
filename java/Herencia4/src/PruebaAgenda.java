import java.io.*;

public class PruebaAgenda {
	
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
	
	public static Persona Datos(Persona x)
	{
		Persona aux;
		String n, ape, dt, c, to, tc, dr, tca, fc, par, car, em;
		n = ape = dt = c = to = tc = dr = tca = fc = par = car = em = "";
		System.out.print("Ingrese nombre: ");
		n = LeerCadena();
		System.out.print("Ingrese apellido: ");
		ape = LeerCadena();
		System.out.print("Ingrese direccion de trabajo: ");
		dt = LeerCadena();
		System.out.print("Ingrese e-mail: ");
		c = LeerCadena();
		System.out.print("Ingrese telefono de oficina: ");
		to = LeerCadena();
		System.out.print("Ingrese telefono de celular: ");
		tc = LeerCadena();
		if (x.getClass().getSimpleName().equalsIgnoreCase("Familiares"))
		{
			System.out.print("Ingrese direccion de casa: ");
			dr = LeerCadena();
			System.out.print("Ingrese telefono local: ");
			tca = LeerCadena();
			System.out.print("Ingrese fecha cumple: ");
			fc = LeerCadena();
			System.out.print("Ingrese parentesco: ");
			par = LeerCadena();
			return aux = new Familiares(n, ape, dt, c, to, tc, dr, tca, fc, par);
		}
		
		else if (x.getClass().getSimpleName().equalsIgnoreCase("Amigos"))
		{
			System.out.print("Ingrese direccion de casa: ");
			dr = LeerCadena();
			System.out.print("Ingrese telefono local: ");
			tca = LeerCadena();
			System.out.print("Ingrese fecha cumple: ");
			fc = LeerCadena();
			System.out.print("Ingrese apodo: ");
			par = LeerCadena();
			return aux = new Amigos(n, ape, dt, c, to, tc, dr, tca, fc, par);
		}
		
		else
		{
			System.out.print("Ingrese cargo: ");
			car = LeerCadena();
			System.out.print("Ingrese nombre de empresa: ");
			em = LeerCadena();
			return aux = new Negocios(n, ape, dt, c, to, tc, car, em);
		}
	}
	
	public static void main(String [] args)
	{
		Persona p;
		String n, ape, dt, c, to, tc;
		n = ape = dt = c = to = tc = "";
		int Cantidad, Op, Metodo;
		Cantidad = Op = Metodo = 0;
		System.out.print("Ingrese cantidad de personas: ");
		Cantidad = LeerEntero();
		Agenda a = new Agenda(Cantidad);
		do
		{
			System.out.print("Que desea hacer? \n1.Agregar. \n2.Borrar. \n3.Buscar. \n4.Editar. \n5.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch (Op)
			{
				case 1:
					if (a.getContador() < Cantidad)
					{
						System.out.print("Ingrese nombre: ");
						n = LeerCadena();
						System.out.print("Ingrese apellido: ");
						ape = LeerCadena();
						System.out.print("Ingrese direccion de trabajo: ");
						dt = LeerCadena();
						System.out.print("Ingrese e-mail: ");
						c = LeerCadena();
						System.out.print("Ingrese telefono de oficina: ");
						to = LeerCadena();
						System.out.print("Ingrese telefono de celular: ");
						tc = LeerCadena();
						
						do
						{
							System.out.print("Que desea agregar? \n1.Familiar. \n2.Amigo. \n3.Negocio. \nOpcion: ");
							Op = LeerEntero();
							switch (Op)
							{
								case 1:
									String dr, tca, fc, par;
									dr = tca = fc = par = "";
									System.out.print("Ingrese direccion de casa: ");
									dr = LeerCadena();
									System.out.print("Ingrese telefono de casa: ");
									tca = LeerCadena();
									System.out.print("Ingese fecha de cumple: ");
									fc = LeerCadena();
									System.out.print("Ingrese parentesco: ");
									par = LeerCadena();
									p = new Familiares (n, ape, dt, c, to, tc, dr, tca, fc, par);
									System.out.println(a.Agregar(p));
									break;
									
								case 2:
									String apo = "";
									System.out.print("Ingrese direccion de casa: ");
									dr = LeerCadena();
									System.out.print("Ingrese telefono de casa: ");
									tca = LeerCadena();
									System.out.print("Ingese fecha de cumple: ");
									fc = LeerCadena();
									System.out.print("Ingrese apodo: ");
									apo = LeerCadena();
									p = new Amigos(n, ape, dt, c, to, tc, dr, tca, fc, apo);
									System.out.println(a.Agregar(p));
									break;
									
								case 3:
									String car, em;
									car = em = "";
									System.out.print("Ingrese cargo: ");
									car = LeerCadena();
									System.out.print("Ingrese nombre de empresa: ");
									em = LeerCadena();
									p = new Negocios(n, ape, dt, c, to, tc, car, em);
									System.out.println(a.Agregar(p));
									break;
									
								default:
									System.out.println("Opcion invalida.");
							}
						} while (Op < 1 || Op > 3);
					}
					break;
					
				case 2:
					if (a.getContador() != 0)
					{
						System.out.print("Ingrese nombre: ");
						n = LeerCadena();
						System.out.print("Ingrese apellido: ");
						ape = LeerCadena();
						System.out.println(a.Borrar(n, ape));
					}
					
					else
						System.out.println("Debe haber al menos una persona.");
					break;
					
				case 3:
					if (a.getContador() != 0)
					{
						System.out.print("Ingrese nombre: ");
						n = LeerCadena();
						System.out.print("Ingrese apellido: ");
						ape = LeerCadena();
						System.out.println(a.BuscarPersona(n, ape));
					}
					
					else
						System.out.println("Debe haber al menos una persona.");
					break;
					
				case 4:
					Persona aux;
					System.out.print("Ingrese nombre: ");
					n = LeerCadena();
					System.out.print("Ingrese apellido: ");
					ape = LeerCadena();
					aux = a.Devolver(n, ape);
					if (!aux.getNombre().equals(""))
					{
						p = Datos(aux);
						System.out.println(a.EditarValor(p, n, ape));
					}
					
					else
						System.out.println("La persona no se encuentra.");
					break;
			}
		} while (Op != 5);
	}

}
