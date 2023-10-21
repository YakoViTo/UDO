public class Obrero extends Empleado 
{
	private double SueldoT;
	private boolean Comp;
	
	public Obrero(String n, String a, String nci, int s, boolean sw)
	{
		super (n, a, nci, s);
		SueldoT = 0;
		Comp = sw;
	}
	
	public String CalcularSueldo()
	{
		if (Comp)
		{
			SueldoT = (super.Sueldo * 0.10) - 2520 - 4255 - 2650;
			return super.toString() + ". El empleado es un obrero y su sueldo total es de " + SueldoT;
		}
		
		else
		{
			SueldoT = super.Sueldo - 2520 - 4255 - 2650;
			return super.toString() + ". El empleado es un obrero y su sueldo total es de " + SueldoT;
		}
	}
}