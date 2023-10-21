public abstract class Persona {
	
protected String Nombre, Apellido, DirTrabajo, Correo, TelOfi, TelCel;
	
	public Persona(String n, String a, String dt, String c, String to, String tc)
	{
		Nombre = n;
		Apellido = a;
		DirTrabajo = dt;
		Correo = c;
		TelOfi = to;
		TelCel = tc;
	}
	
	public abstract String Editar(Persona aux);
	
	public String toString()
	{
		return "La persona " + Nombre + ", " + Apellido + "; su trabajo se encuentra en " + DirTrabajo + ". Su e-mail es " + Correo + ". Su telefono de oficina es " + TelOfi + " y su telefono de celular es " + TelCel;
	}
	
	public void SetNombre(String k){Nombre = k;}
	public void SetApellido(String d){Apellido = d;}
	public void SetDirTrabajo(String k){DirTrabajo = k;}
	public void SetCorreo(String d){Correo = d;}
	public void SetTelOfi(String k){TelOfi = k;}
	public void SetTelCel(String d){TelCel = d;}
	
	public String getNombre(){return Nombre;}
	public String getApellido(){return Apellido;}
	public String getDirTrabajo(){return DirTrabajo;}
	public String getCorreo(){return Correo;}
	public String getTelOfi(){return TelOfi;}
	public String getTelCel(){return TelCel;}

}
