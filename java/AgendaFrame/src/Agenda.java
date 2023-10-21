public class Agenda 
{
	private Persona p[];
	private int Contador;
	
	public Agenda(int x)
	{
		p = new Persona[x];
		Contador = 0;
	}
	
	public int Buscar(String k, String d)
	{
		for (int i = 0; i < Contador; i++)
			if (p[i].getNombre().equalsIgnoreCase(k) && p[i].getApellido().equalsIgnoreCase(d))
				return i;
		
		return -1;
	}
	
	public String Agregar(Persona d)
	{
		int i = Buscar(d.getNombre(), d.getApellido());
		if (i == -1)
		{
			p[Contador++] = d;
			return "Se ha agregado a la persona.";
		}
		
		return "La persona ya se encuentra.";
	}
	
	public String Borrar(String d, String k)
	{
		int i = Buscar(d, k);
		if (i != -1)
		{
			for (; i < Contador - 1; i++)
				p[i] = p[i++];
						
			Contador--;
			return "Se ha borrado a la persona.";
		}
		
		return "La persona no se encuentra.";
	}
	
	public String BuscarPersona(String k, String d)
	{
		int i = Buscar(k, d);
		if (i != -1)
			return p[i].toString();
		
		else
			return "La persona no se encuentra.";
	}
	
	public Persona Devolver(String k, String d)
	{
		int i = Buscar(k, d);
		if (i != -1)
			return p[i];
		
		else
		{
			String n, a, dt, c, to, tc, dr, tca, fc, p;
			n = a = dt = c = to = tc = dr = tca = fc = p = "";
			Persona aux = new Familiares(n, a, dt, c, to, tc, dr, tca, fc, p);
			return aux;
		}
	}
	
	public String EditarValor(Persona aux, String nombre, String ape)
	{
		int i = Buscar(nombre, ape);
		return p[i].Editar(aux);
	}
	
	public int getContador(){return Contador;}
}