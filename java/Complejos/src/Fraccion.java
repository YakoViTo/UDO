public class Fraccion{
	
	private int num,den;
	
	public Fraccion(int n,int den){
		
		num = n;
		this.den = den;
	}
	public Fraccion(){
		
		num = 0;
		den = 1;
	}
	public void sumar(Fraccion f1,Fraccion f2){
		
		num = f1.num*f2.den+f1.den*f2.num;
		den = f1.den*f2.den;
	}
	public static Fraccion restar(Fraccion f1,Fraccion f2){
		
		Fraccion x = new Fraccion();
		x.num = f1.num*f2.den-f1.den*f2.num;
		x.den = f1.den*f2.den;
		return x;
	}
	public String toString(){
		
		return num+"/"+den;
	}
}
