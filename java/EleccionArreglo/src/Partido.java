
public class Partido {

	private String NombrePar, NombreCan, ApeCan;
	private int Votos;
	private double Porcentaje;
	
	public Partido (String np, String nc, String ac)
	{
		NombrePar = np;
		NombreCan = nc;
		ApeCan = ac;
		Votos = 0;
		Porcentaje = 0;
	}
	
	public String toString()
	{
		return "El partido " + NombrePar + " con el candidarto " + ApeCan + ", " + NombreCan + " saco " + Votos + " votos; con un porcentaje de " + Porcentaje + "%.";
	}
	
	public void SetVotos(int d){Votos = d;}
	public void SetPorcentaje(double k){Porcentaje = k;}
	public int getVotos(){return Votos;}
	public double getPorcentaje (){return Porcentaje;}
	public String getNombrePar(){return NombrePar;}
}
