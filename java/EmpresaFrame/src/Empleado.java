public abstract class Empleado 
{
	protected int Sueldo;
	protected String Nombre, Apellido, NCI;
	
	public Empleado(String n, String a, String nci, int s)
	{
		Nombre = n;
		Apellido = a;
		NCI = nci;
		Sueldo = s;
	}
	
	public abstract String CalcularSueldo();
	
	public String toString()
	{
		return "El empleado " + Nombre + ", " + Apellido + " con cedula " + NCI + " tiene un sueldo de " + Sueldo;
	}
	
	public String getNCI(){return NCI;}
	public String getNombre(){return Nombre;}
	public String Apellido(){return Apellido;}
	public int getSueldo(){return Sueldo;}
}