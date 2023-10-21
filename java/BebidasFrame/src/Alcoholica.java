public class Alcoholica extends Bebida
{
	private float Grado;
	private short Tiempo;
	
	public Alcoholica(String n, String m, float g, short t)
	{
		super(n, m);
		Grado = g;
		Tiempo = t;
	}
	
	public String CalcularMonto()
	{
		Monto = 400 / Grado;
		return super.toString() + ". La bebida es alcoholica con un grado de alcohol de " + Grado + " y su monto es de " + Monto + ". Tiene " + Tiempo + " tiempo en reserva. Se encuentran " + Cantidad + " unidades disponibles.";
	}
	
	public float getGrado(){return Grado;}
}