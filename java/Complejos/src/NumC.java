public class NumC{
	
	private Fraccion pr,pi;
	
	public NumC(Fraccion pr,Fraccion pi){
		
		this.pr = pr;
		this.pi = pi;
	}
	public void sumar(NumC a,NumC b){
		
		pr.sumar(a.pr,b.pr);
		pi.sumar(a.pi,b.pi);
	}
	public static NumC restar(NumC a,NumC b){
		
		NumC x = new NumC();
		x.pr = Fraccion.restar(a.pr,b.pr);
		x.pi = Fraccion.restar(a.pi,b.pi);
		return x;
	}
	public String toString(){
		
		return pr.toString()+" + "+pi.toString()+" i ";
	}
	public NumC(){
		
		pr = new Fraccion();
		pi = new Fraccion();
	}
}
