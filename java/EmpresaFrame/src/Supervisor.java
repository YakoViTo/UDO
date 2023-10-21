public class Supervisor extends Empleado
{
	private double SueldoT;
	private boolean Comp, CompTi;
	
	public Supervisor(String n, String a, String nci, int s, boolean sw, boolean ct)
	{
		super (n, a, nci, s);
		SueldoT = 0;
		Comp = sw;
		CompTi = ct;
	}
	
	public String CalcularSueldo()
	{
		if (Comp && CompTi)
		{
			SueldoT = (super.Sueldo * 0.04) - 4050 - 7950 - 5155 + 50000;
			return super.toString() + ". El empleado es un supervisor y su sueldo total es de " + SueldoT;
		}
		
		else if (!Comp && CompTi)
		{
			SueldoT = super.Sueldo - 4050 - 7950 - 5155 + 50000;
			return super.toString() + ". El empleado es un supervisor y su sueldo total es de " + SueldoT;
		}
		
		else if (Comp && !CompTi)
		{
			SueldoT = (super.Sueldo * 0.04) - 4050 - 7950 - 5155;
			return super.toString() + ". El empleado es un supervisor y su sueldo total es de " + SueldoT;
		}
		
		else
		{
			SueldoT = super.Sueldo - 4050 - 7950 - 5155;
			return ". El empleado es un supervisor y su sueldo total es de " + SueldoT;
		}
	}
}