public class Triangulo extends Area{
	
	public Triangulo(double ba, double al){
		
		super(ba,al);
		Area = 0;		
	}
	
	public double CalcularArea(){
		
		Area = (Base*Altura)/2;
		return Area;
	}
}
