
public class Clase {
	
	private Estudiante e[];
	private int Contador;
	private byte NotaRepetida;
	
	public Clase()
	{
		e = new Estudiante[40];
		Contador = NotaRepetida = 0;
	}
	
	public void Agregar(Estudiante k)
	{
		e[Contador++] = k;
	}
	
	public String Listar()
	{
		String Metodo = "";
		for (int i = 0; i < Contador; i++)
			Metodo = Metodo.concat(e[i].toString() + "\n");
		
		return Metodo;
	}
	
	public String ListarNota()
	{
		byte Temporal = 0, Comun = e[0].getNota();;
		int Cont, ConTemp = 1; 
		
		for (int i = 0; i < Contador - 1; i++)
		{
			Cont = 0;
			Temporal = e[i].getNota();
			for (int j = 1; j < Contador; j++)
			{
				if (Temporal == e[j].getNota())
					Cont++;
			}
			
			if (Cont > ConTemp)
			{
				Comun = Temporal;
				ConTemp = Cont;
			}
		}
		return "La nota mas comun es " + Comun;
	}
	
	public int getContador(){return Contador;}

}
