public class Operaciones{
	
	private Fraccion f1, f2;
	private int Res;
	private float Resultado;
	
	public Operaciones(int k, int d, int h, int c){
		
		f1 = new Fraccion(k,d);
		f2 = new Fraccion(h,c);
		Res = 0;
		Resultado = 0;
	}
	
	public void sumar(){
		
		Res = ((f1.getNum()*f2.getDen()) + (f1.getDen()*f2.getNum())) / (f1.getDen()*f2.getDen());
		Resultado = ((f1.getNum()*f2.getDen()) + (f1.getDen()*f2.getNum())) / (f1.getDen()*f2.getDen());
		System.out.println("El resultado es: " + Res + "\n En flotante: " + Resultado + "\n");
	}
	
	public void restar(){
		
		Res = ((f1.getNum()*f2.getDen()) - (f1.getDen()*f2.getNum())) / (f1.getDen()*f2.getDen());
		Resultado = ((f1.getNum()*f2.getDen()) - (f1.getDen()*f2.getNum())) / (f1.getDen()*f2.getDen());
		System.out.println("El resultado es: " + Res + "\n En flotante: " + Resultado + "\n");
	}
	
	public void multiplicar(){
		
		Res = (f1.getNum()*f2.getNum()) / (f1.getDen()*f2.getDen());
		Resultado = (f1.getNum()*f2.getNum()) / (f1.getDen()*f2.getDen());
		System.out.println("El resultado es: " + Res + "\n En flotante: " + Resultado + "\n");
	}
	
	public void dividir(){
		
		Res = (f1.getNum()*f2.getDen()) / (f1.getDen()*f2.getNum());
		Resultado = (f1.getNum()*f2.getNum()) / (f1.getDen()*f2.getDen());
		System.out.println("El resultado es: " + Res + "\n En flotante: " + Resultado + "\n");
	}
}