public class Ejemplos {

    
    public static void main(String[] args) {
        //Empezamos con el ingreso de valores a la lista
        Lista Numeros = new Lista(); //Declaramos nuestra nueva lista
        boolean Exito = false; //variable booleana en la que se almacenara si se ha realizado con exito la operaicion
        for (int i = 1; i<= 20; i++)
        {
            Numeros.AgregarNodo(i); //Ingresamos 20 valores a la lista
        }
        //Imprimimos los valores de la lista
        System.out.println("Elementos en la lista: " + Numeros.ImpimirLista());
        //Procedemos a alterar valores
        Nodo T = new Nodo(); //Declaramos un nuevo nodo
        int i = 0; //variable que guardara el valor de los indices
        //Obtenemos el nodo que tiene el dato 12 y le cambiasmos el dato por otro valor numerico, como un 100
        System.out.println("Cambiamos el valor del nodo con dato 12 por un 100");
        T = Numeros.ObtenerNodoPorDato(12);
        T.Dato = 100; //Cambiamos el valor
        //Hacemos lo mismo para otros nodos.....
        System.out.println("Cambiamos el valor del nodo con dato 20 por un 1234567");
        T = Numeros.ObtenerNodoPorDato(20);
        T.Dato = 1234567; //Cambiamos el valor
        System.out.println("Cambiamos el valor del nodo con dato 7 por un 23");
        T = Numeros.ObtenerNodoPorDato(7);
        T.Dato = 23; //Cambiamos el valor
        //------------------------------
        System.out.println("Cambiamos el valor del primero de la lista de 1 a 44");
        T = Numeros.ObtenerNodoPorIndice(1); //Probamos haciendo la busqueda por indice
        T.Dato = 44; //Cambiamos el valor
        //Mostramos de nuevo la lista
        
        //Procedemos a elminar varios nodos en la lista
        Exito = Numeros.ElminarNodo(44); //Eliminamos el 44
        if (Exito == true)// Si se desea hacer validaciones, este seria la manera de hacerlo
        {
            System.out.println("Eliminamos el primer nodo - 44");
        }
        else
        {
            System.out.println("No paso nada");
        }
        //Mostramos la lista
        System.out.println("Elementos en la lista: " + Numeros.ImpimirLista());
        //Eliminamos otros datos
        Exito = Numeros.ElminarNodo(2); //Eliminamos el 44
        Exito = Numeros.ElminarNodo(13); //Eliminamos el 13
        Exito = Numeros.ElminarNodo(1234567); //Eliminamos el 1234567
        Exito = Numeros.ElminarNodo(18); //Eliminamos el 18
        System.out.println("Se elimino el 2,13, 1234567 y el 18 de la lista");
        System.out.println("Elementos en la lista: " + Numeros.ImpimirLista());
    }
}
