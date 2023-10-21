package pruebaviaje;
public class Avion extends Viaje{
    public Avion(float d,float v,String partida,String llegada) {
    	super(d,v,partida,llegada);
    	
    }
    public String calcularT(){
       tiempo=(float)((dis/vel*1.852f)*60);
       return "Tiempo por avion es:"+tiempo;
    }
    public String toString(){
        return "Viaje en Avion de "+ptoPar+" hasta "+ptoLL
                +" recorriendo una distancia de "+dis
                +"km, con una velocidad "+vel
                +"km/h, durante un tiempo de "+tiempo
                +"min/h";
    }
    

    	

}
