public class Figura 
{
	private int X, Y, Ancho, Alto;
	private String Tipo;
	
	public Figura(int x, int y, int an, int al, String t)
	{
		X = x;
		Y = y;
		Ancho = an;
		Alto = al;
		Tipo = t;
	}
	
	public int getX(){return X;}
	public int getY(){return Y;}
	public int getAncho(){return Ancho;}
	public int getAlto(){return Alto;}
	public String getTipo(){return Tipo;}
}