
public class Estudiante {
	
	private String Nombre, Apellido, NCI;
	private byte Nota, Seccion;
	
	public Estudiante(String n, String a, String nci, byte nota, byte s)
	{
		Nombre = n;
		Apellido = a;
		NCI = nci;
		Nota = nota;
		Seccion = s;
	}
	
	public String toString()
	{
		return "El alumno " + Apellido + ", " + Nombre + " con cedula '" + NCI + "'; de la seccion " + Seccion + " saco " + Nota + " en el primer parcial.";
	}
	
	public byte getNota(){return Nota;}

}
