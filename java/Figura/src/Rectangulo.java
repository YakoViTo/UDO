
public class Rectangulo extends FiguraG {

	private float base,altura;
	public Rectangulo(float b,float a){ 
		
		super();
		base=b;
		altura=a;
	}
	public void CalcularArea(){
		
		area=base+altura;
	}
	public String toString(){
		
		return"El rectangulo de dimensiones"+base+"x"+altura+"tienes un area de "+area;
	} 
	
}//Fin clase

