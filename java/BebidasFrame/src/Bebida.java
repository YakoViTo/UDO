public abstract class Bebida 
{
	protected String Nombre, Marca;
	protected double Monto;
	protected int Cantidad;
	
	public Bebida(String n, String m)
	{
		Nombre = n;
		Marca = m;
		Monto = 0;
		Cantidad = 0;
	}
	
	public abstract String CalcularMonto();
	
	public String toString()
	{
		return "La bebida " + Nombre + " de marca " + Marca;
	}
	
	public void SetCantidad(int k){Cantidad = k;}
	public int getCantidad(){return Cantidad;}
	public String getNombre(){return Nombre;}
	public double getMonto(){return Monto;}
}