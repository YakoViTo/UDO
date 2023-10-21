
public class Alumno {

	private String Nombre, Apellido, NCI, Carrera;
	private int Nota1, Nota2, Nota3;
	private double Promedio;
	
	public Alumno(String n, String a, String nci, String c, int n1, int n2, int n3)
	{
		Nombre = n;
		Apellido = a;
		NCI = nci;
		Carrera = c;
		Nota1 = n1;
		Nota2 = n2;
		Nota3 = n3;
		Promedio = 0;
	}
	
	public Alumno()
	{
		Nombre = Apellido = NCI = Carrera = "";
		Nota1 = Nota2 = Nota3 = 0;
		Promedio = 0;
	}
	
	public String toString()
	{
		return "El alumno " + Apellido + ", " + Nombre + " con cedula '" + NCI + "'; cursa la carrera '" + Carrera + "'. Sus notas son: " + Nota1 + ", " + Nota2 + " y " + Nota3;
	}
	
	public void SetNota1(int k){Nota1 = k;}
	public void SetNota2(int d){Nota2 = d;}
	public void SetNota3(int k){Nota3 = k;}
	public void SetPromedio(double d){Promedio = d;}
	public int getNota1(){return Nota1;}
	public int getNota2(){return Nota2;}
	public int getNota3(){return Nota3;}
	public double getPromedio(){return Promedio;}
	public String getNCI(){return NCI;}
}
