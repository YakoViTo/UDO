
public class Banco {
	
	private Deudores d[];
	private int Contador;
	
	public Banco(int x)
	{
		d = new Deudores[x];
		Contador = 0;
	}
	
	public void Agregar(Deudores k)
	{
		d[Contador++] = k;
		
	}
	
	
	public String Listar()
	{
		String Metodo = "";
		
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(d[i].toString() + "\n");
		
		return Metodo;
	}
	
	public int getContador(){return Contador;}

}
