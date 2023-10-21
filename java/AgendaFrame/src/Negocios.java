public class Negocios extends Persona
{
	private String Cargo, Empresa;
	
	public Negocios (String n, String a, String dt, String c, String to, String tc, String car, String e)
	{
		super (n, a, dt, c, to, tc);
		Cargo = car;
		Empresa = e;
	}
	
	public String Editar(Persona aux)
	{	
		SetNombre(aux.getNombre());
		SetApellido(aux.getApellido());
		SetDirTrabajo(aux.getDirTrabajo());
		SetCorreo(aux.getCorreo());
		SetTelOfi(aux.getTelOfi());
		SetTelCel(aux.getTelCel());
		SetCargo(((Negocios) aux).getCargo());
		SetEmpresa(((Negocios) aux).getEmpresa());
		return "Se han editado los datos.";
	}
	
	public void SetCargo(String k){Cargo = k;}
	public void SetEmpresa(String d){Empresa = d;}
	
	public String getCargo(){return Cargo;}
	public String getEmpresa(){return Empresa;}
}