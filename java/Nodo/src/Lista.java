public class Lista 
{
	private Nodo Inicio, Final, Aux;
	private byte Contador;
	
	public Lista(Nodo i)
	{
		Inicio = i;
		Contador = 0;
		Final = Aux = null;
	}
	
	public Lista()
	{
		Inicio = Final = Aux = null;
		Contador = 0;
	}
	
	public String agregar(Nodo d)
	{
		Nodo a;
		
		if (Inicio == null)
		{
			Inicio = d;
			Contador++;
			return "El nuevo nodo es el inicial";
		}
		
		else
		{
			if (d.getVal() < Inicio.getVal())
			{
				d.setSte(Inicio);
				Inicio = d;
			}
			
			else
			{
				a = Aux;
				Aux = Inicio;
				Final = Inicio;
				while ((d.getVal() < Aux.getVal()) && a.getSte() != null)
				{
					Final = Aux;
					Aux = Aux.getSte();
				}
				
				if (d.getVal() < Aux.getVal())
					Aux.setSte(d);
				
				else
				{
					d.setSte(Aux);
					Final.setSte(d);
				}
			}
		}
			
		Contador++;	
		return "Se ha agregado el nodo a la lista.";	
	}
	
	public String eliminar(int k)
	{
		Nodo eli = Inicio, aux = null;
		int i = Buscar(k), cont = 0;
		if (i != -1)
		{
			
			while (eli != null)
			{
				if (i == cont)
				{
					if (aux == null)
					{
						Inicio = Inicio.getSte();
					}
					
					else
					{
						aux.setSte(eli.getSte());
					}
					
					eli = null;
				}
				
				else
				{
					aux = eli;
					eli = eli.getSte();
					cont++;
				}
			}
			Contador--;
			return "Se ha eliminado el valor.";
		}
		
		else
			return "El valor " + k + " no se encuentra.";
	}
	
	public int Buscar(int k)
	{
		int aux = 0;
		for (Nodo i = Inicio; i.getSte() != null; i = i.getSte(), aux++)
			if (i.getVal() == k)
				return aux;
		
		return -1;
	}
	
	/*public String Mostrar()
	{
		String Metodo = "";
		int aux = 0;
		for (Nodo i = Inicio; aux < Contador; aux++)
		{
			Metodo = Metodo.concat(i.getVal() + "\n");
			i = i.getSte();
		}
		
		return Metodo;
		
	}*/

	
	public String Mostrar(String a, int k, Nodo aux)
	{
		if (k == Contador)
			return a;
		
		else
		{
			a = a.concat(aux.getVal() + "\n");
			aux = aux.getSte();
			k++;
			return Mostrar(a, k, aux);
		}
	}
	
	public Nodo getInicio(){return Inicio;}
}