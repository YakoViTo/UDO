public abstract class Persona {
	
private String Nombre, Apellido, NCI, FechaNac, EstadoCiv, Direccion, Num;
	
	public Persona(String n, String a, String nci, String fn, String ec, String d, String num)
	{
		Nombre = n;
		Apellido = a;
		NCI = nci;
		FechaNac = fn;
		EstadoCiv = ec;
		Direccion = d;
		Num = num;
	}
	
	public String toString()
	{
		return "El alumno " + Nombre + ", " + Apellido + " de cedula " + NCI + "; nacio el " + FechaNac + ", su estado civil es " + EstadoCiv + ". Su direccion es " + Direccion + " y su numero es " + Num;
	}

}
