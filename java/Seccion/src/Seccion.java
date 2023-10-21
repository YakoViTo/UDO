
public class Seccion {
	
	private Alumno a[];
	private int Contador;
	
	public Seccion (int x)
	{
		a = new Alumno[x];
		Contador = 0;
	}
	
	public String Agregar (Alumno k)
	{
		int i = Buscar(k.getNCI());
		if (i == -1)
			{
				a[Contador++] = k;
				return "Se ha inscrito al alumno.";
			}
		return "El alumno ya se encuentra.";
	}
	
	public int Buscar(String d)
	{
		for (int i = 0; i < Contador; i++)
		{
			if (d.equalsIgnoreCase(a[i].getNCI()))
				return i;
		}
		return -1;
	}
	
	public String Retirar (String nci)
	{
		int i = Buscar(nci);
		if (i != -1)
		{
			for (int d = 0; d < Contador; d++)
				a[i] = a[i++];
			
			Contador--;
			return "Se ha retirado al alumno.";
		}
		
		return "El alumno no se encuentra.";
	}
	
	public String VaciarNotas(byte k)
	{
		if (k == 1)
			for (int i = 0; i < Contador; i++)
				a[i].SetNota1(0);
		
		else if (k == 2)
			for (int i = 0; i < Contador; i++)
				a[i].SetNota2(0);
		
		else 
			for (int i = 0; i < Contador; i++)
				a[i].SetNota3(0);
		
		return "Se han vaciado las notas del parcial #" + k;
	}
	
	public void Ordenar()
	{
		double p;
		for (int i = 0; i < Contador; i++)
		{
			p = ((a[i].getNota1() + a[i].getNota2() + a[i].getNota3()) / 3) * 0.5;
			a[i].SetPromedio(p);
		}
		
		
		for (int i = 0; i < Contador - 1; i++)
		{
			for (int j = 0; j < Contador - 1; j++)
			{
				if (j == i)
					j++;
					
				if (a[i].getPromedio() < a[j].getPromedio())
				{
					Alumno aux = new Alumno();
					aux = a[j];
					a[j] = a[i];
					a[i] = aux;
				}
			}
		}
		
	}
	
	public String Listar()
	{
		Ordenar();
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(a[i].toString() + "\n");
		
		return Metodo;
	}
	
	public int getContador(){return Contador;}

}
