public abstract class Figura 
{
	protected double Area;
	
	public Figura()
	{
		Area = 0;
	}
	
	public abstract String CalcularArea();
	
	public String toString()
	{
		return ". El area de la figura es " + Area;
	}
	
	public double getArea(){return Area;}
}