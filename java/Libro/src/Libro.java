public class Libro{
	
	private String titulo,autor,editorial;
	private int nropag,a�o,pg;
	
	public Libro(){
		
		titulo="Libro"; autor=""; editorial="";
		nropag=100; a�o=2016; pg=0;
	}
	
	public void Marcar(int p){
		
		pg=p;
	}
	
	public String toString(){
		
		return " El libro "+titulo+" de "+autor+" publicado por "+editorial+" el a�o "+a�o+" tiene "+nropag+" paginas ";
	}
	
	public Libro(String t,String a,String e,int np,int a�){
		
		titulo=t;
		autor=a;
		editorial=e;
		nropag=np;
		a�o=a�;
		pg=0;
	}
	
	public void setTitulo(String t){titulo=t;}
	public void setAutor(String a){autor=a;}
	public void setEditorial(String e){editorial=e;}
	public void setNropag(int t){nropag=t;}
	public void setA�o(int t){a�o=t;}
	public String getTitulo(){return titulo;}
	public String getAutor(){return autor;}
	public String getEditorial(){return editorial;}
	public int getNropag(){return nropag;}
	public int getA�o(){return a�o;}
	public int getPag(){return pg;}

}
