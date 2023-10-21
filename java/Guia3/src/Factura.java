public class Factura 
{
	private int Monto, MontoT, Contador;
	private String Productos[];
	
	public Factura()
	{
		Monto = 1500;
		MontoT = Contador = 0;
		Productos = new String[50];
	}
	
	public void Comprar(String k)
	{
		Productos[Contador++] = k;
		MontoT += 1500;
	}
	
	public void Fac()
	{	
		System.out.println("Productos:                     Precio:");
		for (int i = 0; i < Contador; i++)
		{
			System.out.println("" + (i + 1) + Productos[i] + "                     " + Monto);
		}
		
		System.out.println("\nMonto a cancelar: " + MontoT);
	}
	
	public int getMontoT(){return MontoT;}
}
