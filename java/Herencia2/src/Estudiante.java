public class Estudiante extends Persona{
	
private short Nota;
	
	public Estudiante(String n, String a, String nci, String fn, String ec, String d, String num, short nota)
	{
		super (n, a, nci, fn, ec, d, num);
		Nota = nota;
	}
	
	public String toString()
	{
		return super.toString() + " y su nota fue de " + Nota;
	}
	
	public short getNota(){return Nota;}

}
