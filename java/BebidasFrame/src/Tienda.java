public class Tienda 
{
	private Bebida b[];
	private int Contador;
	private double MontoV, MontoC;
	
	public Tienda(int x)
	{
		b = new Bebida[x];
		Contador = 0;
		MontoV = MontoC = 0;
	}
	
	public int Buscar(String d)
	{
		for (int i = 0; i < Contador; i++)
			if (b[i].getNombre().equalsIgnoreCase(d))
				return i;
		
		return -1;
	}
	
	public String Comprar(Bebida k, int d)
	{
		int i = Buscar(k.getNombre());
		if (i == -1)
		{
			b[Contador] = k;
			b[Contador].SetCantidad(d);
			b[Contador].CalcularMonto();
			MontoC += (b[Contador].getMonto() * d);
			Contador++;
			return "Se ha comprado la bebida.";
		}
		
		else
		{
			int aux = b[i].getCantidad();
			b[i].SetCantidad(aux + d);
			MontoC += (b[i].getMonto() * d);
			return "Se ha comprado más cantidad de la bebida.";
		}
	}
	
	public String Vender(String d, int k)
	{
		int i = Buscar(d);
		if (i != -1)
		{
			if (b[i].getCantidad() > k)
			{
				int aux = b[i].getCantidad();
				b[i].SetCantidad(aux - k);
				MontoV += (b[i].getMonto() * k);
				return "Se ha vendido " + k + " unidades de la bebida ";
			}
		}
		
		return "La bebida no se encuentra.";
	}
	
	public void Ordenar()
	{
		int Cont = 0;
		for (int i = 0; i < Contador; i++)
		{
			if (b[i].getClass().getSimpleName().equalsIgnoreCase("Alcoholica"))
			{
				Bebida aux = b[i];
				b[i] = b[Cont];
				b[Cont] = aux;
				Cont++;
			}
		}
		
		for (int i = 0; i < Contador; i++)
		{
			if (b[i].getClass().getSimpleName().equalsIgnoreCase("NoAlcoholica"))
			{
				Bebida aux = b[i];
				b[i] = b[Cont];
				b[Cont] = aux;
				Cont++;
			}
		}
	}
	
	public String Mostrar()
	{
		String Metodo = "";
		Ordenar();
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(b[i].CalcularMonto() + "\n");
		
		return Metodo;
	}
	
	public String MostratSabores()
	{
		String Metodo = "";
		int aux = 1;
		for (int i = 0; i < Contador; i++)
			if (b[i].getClass().getSimpleName().equalsIgnoreCase("NoAlcoholica"))
			{
				Metodo = Metodo.concat("#" + aux + ". " + (((NoAlcoholica) b[i]).getSabor()) + "\n");
				aux++;
			}
		
		return Metodo;
	}
	
	public String MostrarGrado()
	{
		String Metodo = "";
		int aux = 1;
		for (int i = 0; i < Contador; i++)
			if (b[i].getClass().getSimpleName().equalsIgnoreCase("Alcoholica"))
			{
				Metodo = Metodo.concat("#" + aux + ". " + (((Alcoholica) b[i]).getGrado() + "\n"));
				aux++;
			}
		
		return Metodo;
		
	}
	
	public String MostartEs(String k, float d, boolean sw)
	{
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
		{
			if (sw)
			{
				if (((NoAlcoholica) b[i]).getSabor().equalsIgnoreCase(k))
					Metodo = Metodo.concat(b[i].toString() + "\n");
			}
			
			else
			{
				if (((Alcoholica) b[i]).getGrado() == d)
					Metodo = Metodo.concat(b[i].toString() + "\n");
			}
		}
		
		return Metodo;
	}
	
	public boolean ComprobarSabor(String x)
	{
		for (int i = 0; i < Contador; i++)
		{
			if (((NoAlcoholica) b[i]).getSabor().equalsIgnoreCase(x))
				return true;
		}
		
		return false;
	}
	
	public boolean ComprobarGrado(float x)
	{
		for (int i = 0; i < Contador; i++)
		{
			if (((Alcoholica) b[i]).getGrado() == x)
				return true;
		}
		
		return false;
	}
	
	public String MontoGanado()
	{
		return "El monto ganado en ventas es de " + MontoV + " y el gasto de compras es de " + MontoC;
	}
	
	public int getContador(){return Contador;}
}