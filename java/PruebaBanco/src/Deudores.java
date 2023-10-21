
public class Deudores {
	
	private double Prestamo, Mensual, Tasa;
	private String FechaIni, FechaFin, Nombre, Apellido, NCI;
	
	public Deudores(double p, double m, String fi, String ff, String n, String a, String nci)
	{
		Prestamo = p;
		Mensual = m;
		FechaIni = fi;
		FechaFin = ff;
		Nombre = n;
		Apellido = a;
		NCI = nci;
		Tasa = 0.5;
	}
	
	public Deudores()
	{
		Prestamo = Mensual = 0; 
		Tasa = 0.5;
		FechaIni = FechaFin = Nombre = Apellido = NCI = "";
	}
	
	public String toString()
	{
		return "La persona " + Apellido + ", " + Nombre + " con cedula '" + NCI + "' tiene una deuda de " + Prestamo + " (con interes: " + (Prestamo * Tasa) + "). Sus cuotas mensuales son de " + Mensual + ". Su fecha de inicio fue el " + FechaIni + " y su fecha de culminación " + FechaFin;
	}
	
	public double getPrestamo(){return Prestamo;}

}
