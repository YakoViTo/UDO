public class Cuadrado extends Figura
{
	private int Lado;
	
	public Cuadrado(int l)
	{
		super ();
		Lado = l;
	}
	
	public String CalcularArea()
	{
		Area = Lado * Lado;
		 
		return "La figura es un cuadrado; su lado es " + Lado + super.toString();
	}
}