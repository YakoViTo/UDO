public class Rectangulo extends Figura
{
	private int Base, Altura;
	
	public Rectangulo(int b, int a)
	{
		super();
		Base = b;
		Altura = a;
	}
	
	public String CalcularArea()
	{
		Area = Base * Altura;
		return "La figura es un rectangulo; su base es " + Base + " y su altura es " + Altura + super.toString();
	}
}