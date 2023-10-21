public class Elecciones{
	
	private String Nom,Ap,Par,Nom1,Ap1,Par1;
	private short Contador,Contador2;
	
	public Elecciones(){
		
		Contador = Contador2 = 0;
		
		Nom = "Pedro";
		Ap = "Perez";
		Par = "MAG";
		
		Nom1 = "Pablo";
		Ap1 = "Garcia";
		Par1 = "SS";
	}
	
	public void votar(String k){
		
		if(Par == k){
			
			Contador++;
			System.out.println("Su voto ha sido exitoso. \n");
		}
		
		else if(Par1 == k){
			
			Contador2++;
			System.out.println("Su voto ha sido exitoso. \n");
		}
		
		else
			System.out.println("El partido no se encuentra. \n");
	}
	
	public String toString(){
		
		if(Contador > Contador2)
			return "El partido "+Par+" con el candidato "+Ap+","+Nom+" saco "+Contador+" votos, ha ganado las elecciones";
		
		else
			return "El partido "+Par1+" con el candidato "+Ap1+","+Nom1+" saco "+Contador2+" votos, ha ganado las elecciones";	
	}
	
	public short getContador(){return Contador;}
	public short getContador2(){return Contador2;}
}