
public class Carro {
	
	private String Modelo, Color, Tipo, FormaPago;
	private byte NPuertas;
	
	public Carro(String m, String c, String t, String fp, byte np)
	{
		Modelo = m;
		Color = c;
		Tipo = t;
		FormaPago = fp;
		NPuertas = np;
	}
	
	public String getModelo(){return Modelo;}
	public String getTipo(){return Tipo;}
	public String getPago(){return FormaPago;}
	public byte getNPuertas(){return NPuertas;}

}
