
public class Conce {
	
	private Carro c[];
	private int Contador;
	
	public Conce(int x)
	{
		c = new Carro[x];
		Contador = 0;
	}
	
	public void Agregar(Carro k)
	{
		c[Contador++] = k;
	}
	
	public int getContador(){return Contador;}

}
