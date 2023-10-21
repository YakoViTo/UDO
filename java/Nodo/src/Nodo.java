public class Nodo 
{
	private int Val;
	private Nodo Ste;
	
	public Nodo(int v)
	{
		Val = v;
		Ste = null;
	}
	
	public int getVal(){return Val;}
	public Nodo getSte(){return Ste;}
	public void setSte(Nodo k){Ste = k;}
}