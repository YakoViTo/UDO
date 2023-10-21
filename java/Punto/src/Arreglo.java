public class Arreglo{
	
	private int Contador;
	private Punto p[];
	private Area a[];
	
	public Arreglo(int x){
		
		p = new Punto[x];
		a = new Area[x];
		Contador = 0;
	}
	
	public void AgregarP(Punto k){
		
		p[Contador++] = k;
	}
	
	
	public void OrdenarP()
	{
		Punto aux;
		int i,cambio;
		do{cambio=0;
		for(i=0;i<Contador-1;i++)
		if(p[i].distancia()>p[i+1].distancia()){
		aux=p[i];
		p[i]=p[i+1];
		p[i+1]=aux;
		cambio=1;
		}
		}while(cambio!=0);
	}
	
	public String ListarP()
	{
		OrdenarP();
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat("(" + p[i].getX() + " ; " + p[i].getY() + ")\n");
		
		return Metodo;
	}
	
	public void AgregarR(Area k){
		
		a[Contador++] = k;
	}
	
	public void OrdenarR(){
		
		Area aux;
		int i,cambio;
		do{cambio=0;
		for(i=0;i<Contador-1;i++)
		if(a[i].CalcularArea()>a[i+1].CalcularArea()){
		aux=a[i];
		a[i]=a[i+1];
		a[i+1]=aux;
		cambio=1;
		}
		}while(cambio!=0);
	}
	
	public String ListarR(){
		
		OrdenarR();
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(a[i].CalcularArea() + "\n");
		
		return Metodo;
	}
	
public void AgregarT(Area k){
		
		a[Contador++] = k;
	}
	
	public void OrdenarT(){
		
		Area aux;
		int i,cambio;
		do{cambio=0;
		for(i=0;i<Contador-1;i++)
		if(a[i].CalcularArea()>a[i+1].CalcularArea()){
		aux=a[i];
		a[i]=a[i+1];
		a[i+1]=aux;
		cambio=1;
		}
		}while(cambio!=0);
	}
	
	public String ListarT(){
		
		OrdenarT();
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(a[i].CalcularArea() + "\n");
		
		return Metodo;
	}
	
	
	public int getContador(){return Contador;}

}
