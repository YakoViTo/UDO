public class Circulo extends Figura
{
	private int Radio;
	
	public Circulo(int r)
	{
		super ();
		Radio = r;
	}
	
	public String CalcularArea()
	{
		Area = Math.PI * (Radio * Radio);
		return "La figura es un circulo; su radio es " + Radio + super.toString();
	}
}