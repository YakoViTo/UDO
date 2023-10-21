public class Ayudante extends Estudiante{

	private String Cargo;
	private int Sueldo;
	private boolean Comp;
	
	public Ayudante(String n, String a, String nci, String c, short s, short mp, short mi, short mr, float p, String car, boolean com)
	{
		super(n, a, nci, c, s, mp, mi, mr, p);
		Cargo = c;
		Sueldo = 250;
		Comp = com;
	}
	
	public void Sueldo()
	{
		if (Comp == true)
			Sueldo += 250;
		
		else
			Sueldo -= 250;
	}
	
	public String toString()
	{
		return super.toString() + ". El estudiante es un ayudante, su cargo es " + Cargo + " y su sueldo total es de " + Sueldo;
	}
	
	public void SetComp(boolean k){Comp = k;}
}
