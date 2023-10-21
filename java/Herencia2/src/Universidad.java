public class Universidad {
	
private Estudiante e;
	
	public Universidad()
	{
		
	}
	
	public String Agregar(Estudiante x)
	{
		e = x;
		if (e.getNota() >= 6 && e.getNota() <= 10)
			return e.toString() + ", pasando el examen de admision.";
		
		else
			return e.toString() + ", no pudiendo pasar el examen de admision";
	}

}
