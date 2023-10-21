import java.io.*;

public class PruebaEmpresa 
{
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
	
	public static void main(String [] args0)
	{
		Empleado em;
		String n, a, nci;
		n = a = nci = "";
		int Cantidad, Op, s, ContO, ContS, ContG;
		Cantidad = Op = s = ContO = ContS = ContG = 0;
		boolean Comp, CompTi;
		Comp = CompTi = false;
		System.out.print("Ingrese cantidad de empleados: ");
		Cantidad = LeerEntero();
		Empresa e = new Empresa(Cantidad);
		do
		{
			System.out.print("Que desea hacer? \n1.Agregar. \n2.Retirar. \n3.Mostrar. \n4.Salir. \nOpcion: ");
			Op = LeerEntero();
			switch (Op)
			{
				case 1:
					if (e.getContador() < Cantidad)
					{
						System.out.print("Ingrese nombre: ");
						n = LeerCadena();
						System.out.print("Ingrese apellido: ");
						a = LeerCadena();
						System.out.print("Ingrese cedula: ");
						nci = LeerCadena();
						System.out.print("Ingrese sueldo: ");
						s = LeerEntero();
						do
						{
							System.out.print("Que desea agregar? \n1.Obrero. \n2.Supervisor. \n3.Gerente. \nOpcion: ");
							Op = LeerEntero();
							switch (Op)
							{
								case 1:
									ContO++;
									do
									{
										System.out.print("Trabajo horas extras? \n1.Si \n2.No. \nOpcion: ");
										Op = LeerEntero();
										switch (Op)
										{
											case 1:
												Comp = true;
												break;
												
											case 2:
												Comp = false;
												break;
												
											default:
												System.out.println("Opcion invalida.");
										}
										
									} while (Op < 1 || Op > 2);
									em = new Obrero(n, a, nci, s, Comp);
									System.out.println(e.Agregar(em));
									break;
									
								case 2:
									ContS++;
									do
									{
										System.out.print("Trabajo horas extras? \n1.Si. \n2.No. \nOpcion: ");
										Op = LeerEntero();
										switch (Op)
										{
											case 1:
												Comp = true;
												break;
												
											case 2:
												Comp = false;
												break;
												
											default:
												System.out.println("Opcion invalida.");
										}
									} while (Op < 1 || Op > 2);
									
									do
									{
										System.out.print("Cumplio las horas correspondidas? \n1.Si. \n2.No. \nOpcion: ");
										Op = LeerEntero();
										switch (Op)
										{
											case 1:
												CompTi = true;
												break;
												
											case 2:
												CompTi = true;
												break;
												
											default:
												System.out.println("Opcion invalida.");
										}
									} while (Op < 1 || Op > 2);
									em = new Supervisor(n, a, nci, s, Comp, CompTi);
									System.out.println(e.Agregar(em));
									break;
									
								case 3:
									ContG++;
									do
									{
										System.out.print("Es su segunda quincena? \n1.Si. \n2.No. \nOpcion: ");
										Op = LeerEntero();
										switch (Op)
										{
											case 1:
												Comp = true;
												break;
												
											case 2:
												Comp = true;
												break;
												
											default:
												System.out.println("Opcion invalida.");
										}
									} while (Op < 1 || Op > 2);
									em = new Gerente(n, a, nci, s, Comp);
									System.out.println(e.Agregar(em));
									break;
									
								default:
									System.out.println("Opcion invalida.");
							}
						} while (Op < 1 || Op > 3);
					}
					
					else
						System.out.println("No se puede agregar más.");
					
					break;
					
				case 2:
					if (e.getContador() != 0)
					{
						System.out.print("Ingrese cedula: ");
						nci = LeerCadena();
						System.out.println(e.Retirar(nci));
					}
					
					else
						System.out.println("Debe haber al menos un empleado.");
					
					break;
					
				case 3:
					if (e.getContador() != 0)
						System.out.println(e.Listar(ContG, ContS, ContO));
					
					else
						System.out.println("Debe haber al menos un empleado.");
					break;
			}
		} while (Op != 4);
	}
}