
package pruebaviaje;
import java.awt.*;
import javax.swing.*;
public class CalcularFrame extends JFrame{
    JLabel lm;
    ArregloViaje aa;
    Container c;
    public CalcularFrame(ArregloViaje i){
        super("Calcular Tiempo");
        setLayout(new FlowLayout());
        c=getContentPane();
        aa=i;
        lm=new JLabel(aa.reCalcular());
        c.add(lm);          
    }
    public void paint (Graphics g){
        super.paint(g);
    } 
}
