
public class Prueba{
	
	public static BufferedReader Leer(){
		
		BufferedReader br=new BufferedReader(new ImputStreamReader(System.in));
		return br;
	}
	
	public static int LeerEntero(){
		
		int i=0;
		boolean sw;
		do{
			sw=false;
			try{
				i=Integer.parseInt(Leer().readLine());
			}
			catch(Exception e){
				
				System.out.print("Ha ocurrido un erre.");
				sw=true;
			}
		}while(sw);
	return i;
	}
	
	public static float LeerFloat(){
		
		float i=0;
		boolean sw;
		do{
			sw=false;
			try{
				i=Float.parseFloat(Leer().readLine);
			}
			catch(Exception e){
				
				System.out.print("Ha ocurrido un error.");
				sw=true;
			}
		}while(sw);
	return i;
	}
	
	public static void main(String a[]){
		
		FiguraG f;
		int opc=0;
		float x,y;
		do{
			opc=LeerEntero("1.Circulo\n2.Rectangulo\n3.Salir\nOpcion:");
			switch(opc){
				case 1:
					x=LeerFloat("Radio:?");
					f=new Circulo(x);
					break;
				case 2:
					x=LeerFloat("Base:?");
					y=LeerFloat("Altura:?");
					f=new Rectangulo(x,y);
					break;
			}
			if(f!=null){
				f.CalcularArea();
				mostrar(f.toString());
			}
			else
				mostrar("Figura incorrecta!");
		}while(opc!=3);
	}//Findel main

	private static void mostrar(String M) {
		
		System.out.println(M);
	}
}//Fin de la clase
