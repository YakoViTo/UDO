public abstract class Area {
	
	protected double Base, Altura, Area;
	
	public Area(double ba, double al){
		
		Base = ba;
		Altura = al;
		Area = 0;
	}
	
	public Area(){
		
		Base = Altura = 0;
		Area = 0;
	}
	
	public abstract double CalcularArea();
	
	public double getBase(){return Base;}
	public double getAltura(){return Altura;}
	public void SetX(double k){Base = k;}
	public void SetY(double d){Altura = d;}
	public double getArea(){return Area;}

}
