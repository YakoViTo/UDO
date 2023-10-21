import java.awt.Color;
import javax.swing.JApplet;


public class AppletEjemplo extends JApplet
{
    
    private static final long serialVersionUID = -883268879068691460L;

   
    public void init()
    {
        LienzoParaArrastrarFiguras c = new LienzoParaArrastrarFiguras();
        c.addFigura(new Rectangulo(2, 3, 50, 33, Color.RED));
        c.addFigura(new Rectangulo(7, 22, 150, 10, Color.GREEN));
        c.addFigura(new Rectangulo(11, 44, 20, 100, Color.CYAN));
        c.addFigura(new Circunferecia(6, 8, 34, Color.YELLOW));
        c.addFigura(new Circunferecia(34, 8, 55, Color.WHITE));
        c.addFigura(new Circunferecia(64, 8, 22, Color.BLUE));
        add(c);
    }
}
