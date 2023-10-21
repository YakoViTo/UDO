public class Celular{
	
	private int Saldo;
	
	public Celular(){
		
		Saldo = 1500;
	}
	
	public boolean Llamar(){
		
		if(Saldo > 450){
			
			Saldo -= 450;
			return true;
		}
		else
			return false;
	}
	
	public boolean Mensaje(){
		
		if(Saldo > 150){
			
			Saldo -= 150;
			return true;
		}
		else
			return false;
	}
	
	public String toString(){
		
		return "Su saldo es de " + Saldo;
	}
	
	public int getSaldo(){return Saldo;}
}