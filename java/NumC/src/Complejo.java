public class Complejo{
	
	private int Pr,Pi,Pr2,Pi2,repr,repi;
	
	public Complejo(int k, int d, int h, int c){
		
		Pr=k;
		Pi=d;
		Pr2=h;
		Pi2=c;
		repr=0;
		repi=0;		
	}

	
	public void Suma(){
		
		
		repr=Pr+Pr2;
		repi=Pi+Pi2;
		
		if(repi>=0)
			System.out.println("El resultado es: " + repr + "+" + repi + "i\n");
		else
			System.out.println("El resultado es: " + repr + "" + repi + "i\n");
	}
	
	public void Resta(){
		
		
		repr=-Pr-Pr2;
		repi=-Pi-Pi2;
		
		if(repi>=0)
			System.out.println("El resultado es: " + repr + "+" + repi + "i\n");
		else
			System.out.println("El resultado es: " + repr + "" + repi + "i\n");
	}
	
	
	

}
