public class Triangulo extends Figura
{
	private int Base, Altura;
	
	public Triangulo(int b, int a)
	{
		super ();
		Base = b;
		Altura = a;
	}
	
	public String CalcularArea()
	{
		Area = (Base * Altura) / 2;
		return "La figura es un triangulo; su base es " + Base + " y su altura es " + Altura + super.toString();
	}
}