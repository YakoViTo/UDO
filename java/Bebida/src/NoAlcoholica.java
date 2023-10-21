public class NoAlcoholica extends Bebida{
	
private String Sabor;
	
	public NoAlcoholica(String n, String m, String s)
	{
		super(n, m);
		Sabor = s;
	}
	
	public String CalcularMonto()
	{
		Monto = 200;
		return super.toString() + ". La bebida no es alcoholica, es de sabor " + Sabor + " y su monto es de " + Monto + ". Se encuentran " + Cantidad + " unidades disponibles.";
	}
	
	public String getSabor(){return Sabor;}
}
