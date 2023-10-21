import java.io.*;

public class PruebaUni {

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
	
	public static void main(String [] args)
	{
		Estudiante e;
		int Cantidad, Op, h;
		Cantidad = Op = h = 0;
		short s, mp, mi, mt, nota;
		s = mp = mi = mt = nota = 0;
		boolean Comp = false;
		String n, a, nci, c;
		n = a = nci = c = "";
		float p = 0;
		System.out.print("Ingrese cantidad de estudiantes: ");
		Cantidad = LeerEntero();
		Uni u = new Uni(Cantidad);
		do
		{
			System.out.print("¿Que desea hacer? \n1.Agregar. \n2.Sueldo. \n3.Salir, \nOpción: ");
			Op = LeerEntero();
			switch(Op)
			{
				case 1:
					System.out.print("Ingrese nombre: ");
					n = LeerCadena();
					System.out.print("Ingrese apellido: ");
					a = LeerCadena();
					System.out.print("Ingrese cedula: ");
					nci = LeerCadena();
					System.out.print("Ingrese carrera: ");
					c = LeerCadena();
					System.out.print("Ingrese número de semestres cursados: ");
					s = LeerShort();
					System.out.print("Ingrese cantidad de materias pasadas: ");
					mp = LeerShort();
					System.out.print("Ingrese cantidad de materias inscritas: ");
					mi = LeerShort();
					System.out.print("Ingrese cantidad de materias retiradas: ");
					mt = LeerShort();
					System.out.print("Ingrese promedio: ");
					p = LeerFloat();
					do
					{
						System.out.print("¿Que desea agregar? \n1.Ayudante. \n2.Preparador. \nOpción: ");
						Op = LeerEntero();
						switch(Op)
						{
							case 1:
								String cargo = "";
								System.out.print("Ingrese cargo: ");
								cargo = LeerCadena();
								do
								{
									System.out.print("¿Cumplio las horas? \n1.Si. \n2.No. \nOpción: ");
									Op = LeerEntero();
									switch(Op)
									{
										case 1:
											Comp = true;
											break;
											
										case 2:
											Comp = false;
											break;
											
										default:
											System.out.println("Opción invalida.");
									}
								} while (Op < 1 || Op > 2);
								e = new Ayudante (n, a, nci, c, s, mp, mi, mt, p, cargo, Comp);
								System.out.println(u.Agregar(e));
								break;
								
							case 2:
								System.out.print("Ingrese horas trabajadas: ");
								h = LeerEntero();
								System.out.print("Ingrese nota con que paso la materia (debe ser mayor o igual a 8): ");
								nota = LeerShort();
								if (nota < 8 || nota > 10)
								{
									System.out.println("Debe ingresar una nota correcta.");
									break;
								}
								do
								{
									System.out.print("¿Cumplio las horas? \n1.Si. \n2.No. \nOpción: ");
									Op = LeerEntero();
									switch(Op)
									{
										case 1:
											Comp = true;
											break;
											
										case 2:
											Comp = false;
											break;
											
										default:
											System.out.println("Opción invalida.");
									}
								} while (Op < 1 || Op > 2);
								e = new Preparador(n, a, nci, c, s, mp, mi, mt, p, h, nota, Comp);
								System.out.println(u.Agregar(e));
								break;
						}
					} while (Op < 1 || Op > 2);
					
					break;
					
				case 2:
					System.out.println(u.Calcular());
					break;
					
				case 3:
					break;
					
				default:
					System.out.println("Opción invalida.");
			}
		} while (Op != 3);
	}
}
