public class PruebaLibro{
	
	public static void main(String args[]){
		
		Libro Librito1;
		Librito1=new Libro();
		Libro Libro2=new Libro("historia","Redfel","Pearson",158,2016);
		
		System.out.println(Librito1.toString());
		System.out.println(Libro2.toString());
		Libro2.setTitulo("Lenguaje Java");
		System.out.println(Libro2.toString());
		
	}

}
