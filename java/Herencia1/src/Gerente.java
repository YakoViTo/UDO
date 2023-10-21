public class Gerente extends Empleado{

	private double SueldoT;
	private boolean Quincena;
	
	public Gerente(String n,String a,String nci,int s,boolean q){
		
		super(n,a,nci,s);
		SueldoT=0;
		Quincena=q;
	}
	
	public String CalcularSueldo(){
		
		if(Quincena){
			SueldoT=super.Sueldo+100000-10520-9325;
			return super.toString()+".El empleado es un gerente y su sueldo total es de"+SueldoT;
		}
		else{
			SueldoT=super.Sueldo-10520-9325;
			return super.toString()+".El empleado es un gerente y su sueldo total es de"+SueldoT;
		}
	}
}
