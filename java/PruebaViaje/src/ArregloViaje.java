
package pruebaviaje;
public class ArregloViaje {
    private int ind;
    private Viaje v[];

    public ArregloViaje() {
        ind=0;
        v=new Viaje[50];
    }
    
    public String agregarViaje(Viaje x){
        if(ind<v.length){
            if(v.getClass().getSimpleName().equals("Avion")){
                agregarAvion((Avion)(x));
                return "Viaje en `Avion` guardado";
            }
            if(v.getClass().getSimpleName().equals("Auto")){
                agregarAuto((Auto)(x));
                return "Viaje en `Auto` guardado";
            }  
        }
        return "No hay viaje";
    }
    
    public void agregarAvion(Avion x){
        String par,ll;
        float d,ve;
        par=x.getPtoPar();
        ll=x.getPtoLL();
        d=x.getDis();
        ve=x.getVel();
        v[ind++]=new Avion(d,ve,par,ll);
    }
    public void agregarAuto(Auto x){
        String par,ll;
        float d,ve;
        par=x.getPtoPar();
        ll=x.getPtoLL();
        d=x.getDis();
        ve=x.getVel();
        v[ind++]=new Auto(d,ve,par,ll);
    }
    public String reCalcular(){
        String n="";
        for(int j=0;j<ind;j++)
           n=v[j].calcularT();
        return n;
        
    }
  
    
    public String ListarTodo(){
        String s="";
        for(int i=0;i<ind;i++){
            s=s+v.toString()+"\n";
        }
        return s;
    }
   
}
