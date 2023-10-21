
public class Elecciones {
	
	private Partido p[];
	private byte Contador;
	
	public Elecciones()
	{
		p = new Partido[4];
		Contador = 0;
	}
	
	public String Agregar (Partido d)
	{
		if (Contador < 4)
		{
			p[Contador++] = d;
			return "Se ha agregado el partido.";
		}
		
		return "No se puede agregar mas partidos";
	}
	
	public int Buscar(String k)
	{
		for (int i = 0; i < Contador; i++)
		{
			if (p[i].getNombrePar().equalsIgnoreCase(k))
				return i;
		}
		
		return -1;
	}
	
	public String Votar(String x)
	{
		int i = Buscar(x);
		if (i != -1)
		{
			p[i].SetVotos(p[i].getVotos() + 1);
			return "El voto ha sido exitoso.";
		}
		
		return "El voto no ha sido valido.";
	}
	
	public void Calculo()
	{
		double Porcentaje = 0;
		int Total = 0;
		for (int i = 0; i < Contador; i++)
		{
			Total += p[i].getVotos();
		}
		
		for (int i = 0; i < Contador; i++)
		{
			Porcentaje = (p[i].getVotos() * 100) / Total;
			p[i].SetPorcentaje(Porcentaje);
		}
	}
	
	public String Ganador()
	{
		String Metodo = "";
		Calculo();
		int Gan = p[0].getVotos(), Pos = 0;
		for (int i = 1; i < Contador; i++)
		{
			if (Gan < p[i].getVotos())
			{
				Gan = p[i].getVotos();
				Pos = i;
			}
		}
		
		for (int i = 0; i < Contador; i++)
		{
			Metodo = Metodo.concat(p[i].toString() + "\n");
		}
		
		return Metodo + "El ganador es " + p[Pos].getNombrePar();
	}
	
	public String toString()
	{
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
		{
			Metodo = Metodo.concat(p[i].toString() + "\n");
		}
		return Metodo;
	}
	
	public int getContador(){return Contador;}

}
