
public class Circulo extends FiguraG{
	
	private float radio;
	public Circulo(float r){
		
		super();
		radio=r;
	}
	public void CalcularArea(){
		
		area=(float) (2*Math.PI*radio);
	}
	public String toString(){
		
		return"El circulo de radio"+radio+"tiene un area de"+area;
	}
}
