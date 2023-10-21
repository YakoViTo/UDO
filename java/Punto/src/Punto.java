public abstract class Punto {
	
	protected double X,Y,distancia;
	
	public Punto(double x,double y){
		
		X = x;
		Y = y;
		distancia = 0;		
	}
	

	public Punto(){		
		
		X = Y = 0;
		distancia = 0;
	}
	
	public double getX(){return X;}
	public double getY(){return Y;}
	public void SetX(double k){X = k;}
	public void SetY(double d){Y = d;}
	
	public double distancia(){return sqrt(X*X+Y*Y);}
	private double sqrt(double d){return 0;}	
	void suma(Punto p){X=X+p.X;Y=Y+p.Y;}
}
