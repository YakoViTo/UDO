public class Uni {
	
	private Estudiante e[];
	private int Contador;
	
	public Uni(int x)
	{
		e = new Estudiante[x];
		Contador = 0;
	}
	
	public int Buscar(String d)
	{
		for (int i = 0; i < Contador; i++)
			if (e[i].getNCI().equalsIgnoreCase(d))
				return i;
		
		return -1;
	}
	
	public String Agregar(Estudiante k)
	{
		int i = Buscar(k.getNCI());
		if (i != -1)
		{
			e[Contador++] = k;
			return "Se ha agregado al estudiante.";
		}
		
		return "El estudiante ya se encuentra.";
	}
	
	public String Calcular()
	{
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(e[i].toString() + "\n");
		
		return Metodo;
	}
}
