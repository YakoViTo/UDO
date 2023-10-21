public class Origen extends Punto{
	
	protected double distancia;
	
	public Origen(double x, double y){
		
		super(x,y);
		distancia = 0;
	}
	
	public double distancia(){
		
		return sqrt(X*X+Y*Y);
	}

	private double sqrt(double d){
		
		return 0;
	}
	
	void suma(Punto p){
		
		X=X+p.X;Y=Y+p.Y;
	}
}
