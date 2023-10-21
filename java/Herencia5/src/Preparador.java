public class Preparador extends Estudiante{
	
	private int Sueldo, Horas;
	private short Nota;
	private boolean Comp;
	
	public Preparador(String n, String a, String nci, String c, short s, short mp, short mi, short mr, float p, int h, short no, boolean com)
	{
		super (n, a, nci, c, s, mp, mi, mr, p);
		Sueldo = 400;
		Horas = h;
		Nota = no;
		Comp = com;
	}
	
	public void Sueldo()
	{
		int aux = Horas / 6;
		if (Comp == true)
			Sueldo += 400 * aux;
		
		else
			Sueldo -= 400;
	}
	
	public String toString()
	{
		return ". El estudiante es un preparador. El número de horas trabajadas (hasta ahora) es de " + Horas + ". Su nota con la que pasó la materia es de " + Nota + " y su sueldo es de " + Sueldo;
	}
}
