public class Nodo {
    public int Dato;        //Variable numerica
    public Nodo Siguiente;  //Apuntador hacia un siguiente nodo
    
    
    /*
     * Se ha definido tres distintos constructores para poder asi variar el modo de
     * inicializacion y creacion de un nuevo nodo.
     */
    
    public Nodo(int dato, Nodo sig)    //Constructor con parametros de Dato y Siguiente
    {
        this.Dato = dato;
        this.Siguiente = sig;
    }
    
    public Nodo(int dato)              //Constructor con parametro dato
    {
        this.Dato = dato;
        this.Siguiente = null;
    }
    
    public Nodo()                      //Constructor sin parametros
    {
        this.Dato = 0;
        this.Siguiente = null;
    }
    
}
