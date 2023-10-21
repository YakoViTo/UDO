public class Rectangulo extends Area{
			
	public Rectangulo(double ba, double al){
		
		super(ba,al);
		Area = 0;		
	}
	
	public double CalcularArea(){
		
		Area = Base*Altura;
		return Area;
	}
}
