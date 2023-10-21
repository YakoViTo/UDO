
package pruebaviaje;

public abstract class Viaje {
    protected float dis,vel,tiempo;
    protected String ptoPar,ptoLL;
    
    public Viaje(float d,float v,String p,String ll){
        dis=d;
        vel=v;
        ptoPar=p;
        ptoLL=ll;
    }
    public Viaje() {
    }
    public abstract String calcularT();

    public float getDis() {
        return dis;
    }
    public String getPtoLL() {
        return ptoLL;
    }
    public String getPtoPar() {
        return ptoPar;
    }
    public float getVel() {
        return vel;
    }

    public float getTiempo() {
        return tiempo;
    }
    
    
        