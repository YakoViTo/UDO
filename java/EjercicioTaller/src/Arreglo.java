public class Arreglo 
{
	private Figura f[];
	private int Contador;
	
	public Arreglo(int x)
	{
		f = new Figura[x];
		Contador = 0;
	}
	
	public String Agregar(Figura d)
	{
		f[Contador++] = d;
		return "Se ha agregado la figura";
	}
	
	public int getContador(){return Contador;}
	public Figura[] getAr(){return f;}
}