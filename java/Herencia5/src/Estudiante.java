public abstract class Estudiante {

	protected String Nombre, Apellido, NCI, Carrera;
	protected short Semestres, MatPas, MatIns, MatRet;
	protected float Promedio;
	
	public Estudiante(String n, String a, String nci, String c, short s, short mp, short mi, short mr, float p)
	{
		Nombre = n;
		Apellido = a;
		NCI = nci;
		Carrera = c;
		Semestres = s;
		MatPas = mp;
		MatIns = mi;
		MatRet = mr;
		Promedio = p;
	}
	
	public String toString()
	{
		return "El estudiante " + Nombre + ", " + Apellido + " con cedula " + NCI + " cursa " + Carrera + ". Está por el semestre #" + Semestres + "; ha pasado " + MatPas + ", ha inscrito " + MatIns + " y ha retirado " + MatRet + " materias. Su promedio es de " + Promedio;
	}
	
	public abstract void Sueldo();
	
	public String getNCI(){return NCI;}
}
