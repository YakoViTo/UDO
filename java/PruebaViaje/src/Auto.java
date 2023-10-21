package pruebaviaje;
public class Auto extends Viaje{
    public Auto(float d,float v,String partida,String llegada) {
    	super(d,v,partida,llegada); 	
    }
    public String calcularT() {
        tiempo=(float)((dis/vel)*60);
           return "Tiempo por avion es:"+tiempo;
    }
    public String toString(){
        return "Viaje en Auto de "+ptoPar+" hasta "+ptoLL
                +" recorriendo una distancia de "+dis
                +"km, con una velocidad "+vel
                +"km/h, durante un tiempo de "+tiempo
                +"min/h";             
    }

}
