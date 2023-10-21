public class Empresa 
{
	private Empleado e[];
	private int Contador;
	
	public Empresa(int x)
	{
		e = new Empleado [x];
		Contador = 0;
	}
	
	public int Buscar(String k)
	{
		for (int i = 0; i < Contador; i++)
			if (e[i].getNCI().equalsIgnoreCase(k))
				return i;
		
		return -1;
	}
	
	public String Agregar (Empleado d)
	{
		int i = Buscar(d.getNCI());
		if (i == -1)
		{
			e[Contador++] = d;
			return "Se ha agregado al empleado.";
		}
			
		else
			return "El empleado ya se encuentra.";
	}
	
	
	
	public String Retirar(String k)
	{
		int i = Buscar(k);
		if (i != -1)
		{
			for (int j = 0; j < Contador - 1; j++)
				e[j] = e[j++];
			
			Contador--;
			return "Se ha retirado al empleado.";
		}
		
		return "El empleado no se encuentra.";
	}
	
	public void Ordenar()
	{
		int Cont = 0;
		for (int i = 0; i < Contador; i++)
		{
			if (e[i].getClass().getSimpleName().equalsIgnoreCase("Gerente"))
			{
				Empleado aux = e[i];
				e[i] = e[Cont];
				e[Cont] = aux;
				Cont++;
			}
		}
		
		for (int i = Cont; i < Contador; i++)
		{
			if (e[i].getClass().getSimpleName().equalsIgnoreCase("Supervisor"))
			{
				Empleado aux = e[i];
				e[i] = e[Cont];
				e[Cont] = aux;
				Cont++;
			}
		}
		
		for (int i = Cont; i < Contador; i++)
		{
			if (e[i].getClass().getSimpleName().equalsIgnoreCase("Obrero"))
			{
				Empleado aux = e[i];
				e[i] = e[Cont];
				e[Cont] = aux;
				Cont++;
			}
		}
	}
	
	public String Listar()
	{
		Ordenar();
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(e[i].CalcularSueldo() + "\n");
		
		return Metodo; //+ "La cantidad de gerentes es de " + d + ". La cantidad de supervisores es de " + k + ". La cantidad de obreros es de " + h;
	}
	
	public int getContador(){return Contador;}
}