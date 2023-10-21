public class Familiares extends Persona
{
	private String DirCasa, TelCasa, FechaCumple, Parentesco;
	
	public Familiares(String n, String a, String dt, String c, String to, String tc, String dr, String tca, String fc, String p)
	{
		super (n, a, dt, c, to, tc);
		DirCasa = dr;
		TelCasa = tca;
		FechaCumple = fc;
		Parentesco = p;
	}
	
	public String Editar(Persona aux)
	{
		SetNombre(aux.getNombre());
		SetApellido(aux.getApellido());
		SetDirTrabajo(aux.getDirTrabajo());
		SetCorreo(aux.getCorreo());
		SetTelOfi(aux.getTelOfi());
		SetTelCel(aux.getTelCel());
		SetDirCasa(((Familiares) aux).getDirCasa());
		SetTelCasa(((Familiares) aux).getTelCasa());
		SetFechaCumple(((Familiares) aux).getFechaCumple());
		SetParentesco(((Familiares) aux).getParentesco());
		return "Se han editado los datos.";
	}
	
	public String toString()
	{
		return super.toString() + ". Su direccion de casa es " + DirCasa + ". Su telefono fijo es " + TelCasa + ". Su fecha de cumple es el " + FechaCumple + " y su parentesco es " + Parentesco;
	}
	
	public void SetDirCasa(String k){DirCasa = k;}
	public void SetTelCasa(String d){TelCasa = d;}
	public void SetFechaCumple(String k){FechaCumple = k;}
	public void SetParentesco(String d){Parentesco = d;}
	
	public String getDirCasa(){return DirCasa;}
	public String getTelCasa(){return TelCasa;}
	public String getFechaCumple(){return FechaCumple;}
	public String getParentesco(){return Parentesco;}
}