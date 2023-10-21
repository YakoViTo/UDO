public class Lista {
    int NumElementos = 0; //Variable que almacena el numero de elementos actuales en la lista
    Nodo Primero;   //Apuntador hacia el primero elemento de la lista
    Nodo Ultimo;    //Apuntador hacia el ultimo elemento de la lista
    public boolean EsVacio()
    {
        if(NumElementos==0){return true;}
        else {return false;}
    }
    //------------------------
    //Constructores
    public Lista()
    {
        this.NumElementos = 0;
        this.Primero = null;
        this.Ultimo = null;
    }
    
    public Lista(int elementos, Nodo primero, Nodo ultimo)
    {
    }
    
    //------------------------
    /*
     * Funcion booleana para agregar un nuevo elemento a la lista
     * devuelve: true si se ha ingresado sin errores, false si se ha encontrado un error
     */
    public void AgregarNodo(Nodo Nuevo)
    {
        try
        {
           //Primero revisamos si la lista esta vacia
            if (EsVacio()==true)
            {   //Si la lista esta vacia el nuevo nodo es el primer y ultimo elemento de la lista
                Primero = Nuevo;
                Ultimo = Nuevo;
            }
            else    //Si la lista no esta vacia, se agrega el nodo al final de la lista
            {
                Ultimo.Siguiente = Nuevo;
            }
            NumElementos++; //Aumentos el numero de elementos en la lista
        }
        catch (Exception Ex)
        {
            //Se encontro un error
        }
    }
    //Metodo para agregar un nodo con un valor numerico como parametro
    public void AgregarNodo(int Dato)
    {
        try
        {
            Nodo Nuevo = new Nodo(Dato);
           //Primero revisamos si la lista esta vacia
            if (EsVacio()==true)
            {   //Si la lista esta vacia el nuevo nodo es el primer y ultimo elemento de la lista
                Primero = Nuevo;
                Ultimo = Nuevo;
            }
            else    //Si la lista no esta vacia, se agrega el nodo al final de la lista
            {
                Ultimo.Siguiente = Nuevo;
                Ultimo = Nuevo;
            }
            NumElementos++; //Aumentos el numero de elementos en la lista
        }
        catch (Exception Ex)
        {
            //Se encontro un error
        }
    }
    /*
     * Funcion que devuelve el inidice que inidica la posicion de cierto nodo en la lista,
     * de no econtarse el nodo devuelve -1
     */
    public int ObtenerIndiceNodo(int Dato)
    {
        try
        {
            if (EsVacio()!=true)
            {
                Nodo Temp = Primero;
                int dat = -1;
                int contador = 1;
                while (Temp!=null)
                {
                    dat = Temp.Dato;
                    if (dat == Dato)//Son iguales, si existe el nodo
                    {
                        return contador;    //Se devuelve el indice que indica la posicion del nodo en la lista
                    }
                    contador++; //Se incrementa la posicion del contador
                    Temp = Temp.Siguiente;  //Se acccede al nodo siguiente en la lista
                }
                return -1;
            }
            else{return -1;}
        }
        catch(Exception Ex)
        {
            return -1;
        }
    }
    /*
     * Funcion que devuelve un nodo, mediante el parametro dato, devuleve un varlor nulo, si no encuentra el nodo
     */
    public Nodo ObtenerNodoPorDato(int Dato)
    {
        try
        {
            if (EsVacio()!=true)
            {
                Nodo Temp = Primero;
                int dat = -1;
                int contador = 1;
                while (Temp!=null)
                {
                    dat = Temp.Dato;
                    if (dat == Dato)//Son iguales, si existe el nodo
                    {
                        return Temp;    //Se devuelve el indice que indica la posicion del nodo en la lista
                    }
                    contador++; //Se incrementa la posicion del contador
                    Temp = Temp.Siguiente;  //Se acccede al nodo siguiente en la lista
                }
                return null;
            }
            else{return null;}
        }
        catch(Exception Ex)
        {
            return null;
        }
    }
    /*
     * Funcion que retorna un nodo tomando como parametro la posicion
     * de este en la lista
     */
    public Nodo ObtenerNodoPorIndice(int posicion)
    {
        try
        {
            if (EsVacio()!=true)
            {
                Nodo Temp = Primero;
                for (int i=1;i<posicion;i++)
                {
                    Temp = Temp.Siguiente;
                }
                return Temp;
            }
            else{return null;}
        }
        catch(Exception Ex)
        {
            return null;
        }
    }
    
    /*
     * Funcion que devuelve verdadero si se ha eliminado el nodo de la lista
     * y devuelve falso en cualquier caso contrario o en caso de error
     */
    public boolean ElminarNodo(int Dato)
    {
        try
        {
            if (EsVacio()!=true)
            {
                int pos = ObtenerIndiceNodo(Dato);//Se obtiene la posicion del nodo en la lista
                if (pos==1 && NumElementos == 1)//Si el elemento que se busca es el primero y no hay mas en la lista
                {
                    Primero = Ultimo = null; //El primero y el ultimo se hacen nulos
                }
                else if (pos ==1 && NumElementos>1)//Si se desea elminiar el primero pero hay mas en la lista
                {
                    Nodo Temp = Primero.Siguiente; //Se obtiene el nodo siguiente
                    Primero.Siguiente = null; //Se desvincula al primero de la lista
                    Primero = Temp; //El siguiente nodo pasa a ser el primero de la lista
                }
                else if (pos > 1 && pos == NumElementos)//Si se desea elminiar el ultimo nodo
                {
                    Nodo Temp = ObtenerNodoPorIndice(pos-1); //Se obtiene el nodo anterior
                    Temp.Siguiente = null; //Se desvincula al ultimo nodo de la lista
                    Ultimo = Temp; //El penultimo nodo pasa a ser el ultimo
                }
                else //Es un nodo intermedio
                {
                    Nodo Temp = ObtenerNodoPorIndice(pos-1); //Se obtiene el nodo anterior
                    Nodo Aux = Temp.Siguiente; //Se crea un nodo axuliar
                    Temp.Siguiente = Aux.Siguiente; //Se re-arreglan los apuntadores
                    Aux.Siguiente = null; //Se desvincula el nodo a eliminar
                }
                NumElementos--;
                return true;
            }
            else{return false;}
        }
        catch(Exception Ex){return false;}
    }
    /*
     * Funcion booleana utlizada para saber si existe o no un nodo en la lista
     */
    public boolean Existe(int Dato)
    {
        try
        {
            if (EsVacio()!=true)
            {
                Nodo Temp = Primero;
                int dat = -1;
                while (Temp!=null)
                {
                    dat = Temp.Dato;
                    if (dat == Dato)//Son iguales, si existe el nodo
                    {
                        return true;
                    }
                    Temp = Temp.Siguiente;
                }
                return false;
            }
            else{return false;}
        }
        catch(Exception Ex)
        {
            return false;
        }
    }
    
    /*
     * Metodo que devuelve la lista de los elementos actuales en la lista
     */
    public String ImpimirLista()
    {
        try
        {
            String cadena = "";
            Nodo Temp = Primero;
            for (int i = 1; i<NumElementos;i++)
            {
                cadena = cadena + String.valueOf(Temp.Dato); //Se convierte el valor numerico a string
                cadena = cadena + ",";
                Temp = Temp.Siguiente; //Se avanza al siguiente nodo
            }
            cadena = cadena + String.valueOf(Temp.Dato); //Se convierte el valor numerico a string
            return cadena;
        }
        catch(Exception Ex)
        {
            return "Ha ocurrido un error";
        }
    }

}