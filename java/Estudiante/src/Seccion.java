public class Seccion{
	
	private Estudiante e[];
	private int Contador;
	
	public Seccion(int x){
		
		e = new Estudiante[x];
		Contador = 0;
	}
	
	public int Buscar(String d){
				
		for(int i = 0; i < Contador; i++){
			
			if(d.equalsIgnoreCase(e[i].getNci()))
				return i;
		}
		return -1;
	}
	
	public String Agregar(Estudiante k){
		
		int i = Buscar(k.getNci());
		if(i == -1){
			e[Contador++] = k;
			return "Se a agregado el estudiante.\n";
		}
		return "El estudiante ya se encuentra.\n";
	}
	
	public String Retirar(String Nci){
		
		int i = Buscar(Nci);
		if(i != -1){
			
			for(int d = 0; d < Contador; d++)
				e[i] = e[i++];
			Contador--;
			return "Se ha eliminado el estudiante.\n";
		}
		return "El estudiante no se encuentra.\n";
	}
	
	public String Listar(){
		
		String Metodo = "";
		for(int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(e[i].toString()+"\n");
		return Metodo;
	}
	
	public int getContador(){return Contador;}	

}
