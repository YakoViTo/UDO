public class Arreglo 
{
	private Figura f[];
	private int Contador;
	
	public Arreglo(int x)
	{
		f = new Figura[x];
		Contador = 0;
	}
	
	public String Agregar(Figura k)
	{
		f[Contador++] = k;
		return "Se ha agregado la figura.";
	}
	
	public void Ordenar()
	{
		int Cont = 0;
		boolean sw;
			sw = false;
			for (int i = 0; i < Contador; i++)
			{
				if (f[i].getClass().getSimpleName().equalsIgnoreCase("Rectangulo"))
				{
					Figura aux = f[i];
					f[i] = f[Cont];
					f[Cont] = aux;
					Cont++;
					sw = true;
				}
			}
			
			for (int i = 0; i < Contador; i++)
			{
				if (f[i].getClass().getSimpleName().equalsIgnoreCase("Triangulo"))
				{
					Figura aux = f[i];
					f[i] = f[Cont];
					f[Cont] = aux;
					Cont++;
					sw = true;
				}
			}
			
			for (int i = 0; i < Contador; i++)
			{
				if (f[i].getClass().getSimpleName().equalsIgnoreCase("Circulo"))
				{
					Figura aux = f[i];
					f[i] = f[Cont];
					f[Cont] = aux;
					Cont++;
					sw = true;
				}
			}
			
			for (int i = 0; i < Contador; i++)
			{
				if (f[i].getClass().getSimpleName().equalsIgnoreCase("Cuadrado"))
				{
					Figura aux = f[i];
					f[i] = f[Cont];
					f[Cont] = aux;
					Cont++;
					sw = true;
				}
			}
		
	}
	
	public String Mostrar()
	{
		String Metodo = "";
		Ordenar();
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(f[i].CalcularArea() + "\n");
		
		return Metodo;
	}
	
	public int getContador(){return Contador;}
}
