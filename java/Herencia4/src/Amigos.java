public class Amigos extends Persona{
	
private String DirCasa, TelCasa, FechaCumple, Apodo;
	
	public Amigos(String n, String a, String dt, String c, String to, String tc, String dr, String tca, String fc, String apo)
	{
		super (n, a, dt, c, to, tc);
		DirCasa = dr;
		TelCasa = tca;
		FechaCumple = fc;
		Apodo = apo;
	}
	
	public String Editar(Persona aux)
	{
		SetNombre(aux.getNombre());
		SetApellido(aux.getApellido());
		SetDirTrabajo(aux.getDirTrabajo());
		SetCorreo(aux.getCorreo());
		SetTelOfi(aux.getTelOfi());
		SetTelCel(aux.getTelCel());
		SetDirCasa(((Amigos) aux).getDirCasa());
		SetTelCasa(((Amigos) aux).getTelCasa());
		SetFechaCumple(((Amigos) aux).getFechaCumple());
		SetApodo(((Amigos) aux).getApodo());
		return "Se han editado los datos.";
	}
	
	public String toString()
	{
		return super.toString() + ". Su direccion de casa es " + DirCasa + ". Su telefono fijo es " + TelCasa + ". Su fecha de cumple es el " + FechaCumple + " y su apodo es " + Apodo;
	}
	
	public void SetDirCasa(String k){DirCasa = k;}
	public void SetTelCasa(String d){TelCasa = d;}
	public void SetFechaCumple(String k){FechaCumple = k;}
	public void SetApodo(String d){Apodo = d;}
	
	public String getDirCasa(){return DirCasa;}
	public String getTelCasa(){return TelCasa;}
	public String getFechaCumple(){return FechaCumple;}
	public String getApodo(){return Apodo;}

}
